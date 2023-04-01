/*
 * Copyright (C) 2012 Hermann Meyer, Andreas Degert, Pete Shorthose, Steve Poskitt
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 * --------------------------------------------------------------------------
 */


////////////////////////////// LOCAL INCLUDES //////////////////////////

#include "gx_common.h"      // faust support and denormal protection (SSE)
#include "gxmetal_head.h"        // define struct PortIndex
#include "gx_resampler.h"
#include "gx_convolver.h"
#include "impulse_former.h"
#include "gx_pluginlv2.h"   // define struct PluginLV2

namespace gx_metalhead {
#include "gxmetal_head.cc"    // dsp class generated by faust -> dsp2cc
#ifndef __SSE__
#include "noiser.cc"
#endif
#include "cab_data.cc"

////////////////////////////// PLUG-IN CLASS ///////////////////////////

class Gxmetal_head
{
private:
  // internal stuff
  float*                       output;
  float*                       input;
  uint32_t                     s_rate;
  int32_t                      prio;
  uint32_t                     bufsize;
  PluginLV2*                   tubevib;
#ifndef __SSE__
  PluginLV2*                   wn;
#endif
  gx_resample::BufferResampler resamp;
  GxSimpleConvolver            cabconv;
  Impf                         impf;
  // LV2 stuff
  LV2_URID_Map*                map;

  inline void run_dsp_mono(uint32_t n_samples);
  inline void connect_mono(uint32_t port,void* data);
  inline void init_dsp_mono(uint32_t rate, uint32_t bufsize_);
  inline void connect_all_mono_ports(uint32_t port, void* data);
  inline void activate_f();
  inline void deactivate_f();
  inline void clean_up();
public:
  // LV2 Descriptor
  static const LV2_Descriptor descriptor;
  // static wrapper to private functions
  static void deactivate(LV2_Handle instance);
  static void cleanup(LV2_Handle instance);
  static void run(LV2_Handle instance, uint32_t n_samples);
  static void activate(LV2_Handle instance);
  static void connect_port(LV2_Handle instance, uint32_t port, void* data);
  static LV2_Handle instantiate(const LV2_Descriptor* descriptor,
                                double rate, const char* bundle_path,
                                const LV2_Feature* const* features);
  Gxmetal_head();
  ~Gxmetal_head();
};

// constructor
Gxmetal_head::Gxmetal_head() :
  output(NULL),
  input(NULL),
  tubevib(gxmetal_head::plugin()),   
  cabconv(GxSimpleConvolver(resamp)),
  impf(Impf())
 {};

// destructor
Gxmetal_head::~Gxmetal_head()
{
  // just to be sure the plug have given free the allocated mem
  // it didn't hurd if the mem is already given free by clean_up()
  if (tubevib->activate_plugin !=0)
    tubevib->activate_plugin(false, tubevib);
  // delete DSP class
  tubevib->delete_instance(tubevib);
  cabconv.stop_process();
  cabconv.cleanup();
};

////////////////////////////// PRIVATE CLASS  FUNCTIONS ////////////////

void Gxmetal_head::init_dsp_mono(uint32_t rate,uint32_t bufsize_)
{
  AVOIDDENORMALS(); // init the SSE denormal protection
  bufsize = bufsize_;
  s_rate = rate;

#ifndef __SSE__
  wn = noiser::plugin();
  wn->set_samplerate(rate, wn);
#endif

  tubevib->set_samplerate(rate, tubevib); // init the DSP class

    if (bufsize )
    {
#ifdef _POSIX_PRIORITY_SCHEDULING
      int priomax = sched_get_priority_max(SCHED_FIFO);
      if ((priomax/2) > 0) prio = priomax/2;
#endif
      cabconv.cab_count = cab_data_4x12.ir_count;
      cabconv.cab_sr = cab_data_4x12.ir_sr;
      cabconv.cab_data = cab_data_4x12.ir_data;
      impf.compute(cabconv.cab_count, cabconv.cab_data, cabconv.cab_data, 10);
      
      cabconv.set_samplerate(rate);
      cabconv.set_buffersize(bufsize);
      cabconv.configure(cabconv.cab_count, cabconv.cab_data, cabconv.cab_sr);
      while (!cabconv.checkstate());
      if(!cabconv.start(prio, SCHED_FIFO))
        printf("cabinet convolver disabled\n");
    }
  else
    {
      printf("convolver disabled\n");
    }
}

// connect the Ports used by the plug-in class
void Gxmetal_head::connect_mono(uint32_t port,void* data)
{
  switch ((PortIndex)port)
    {
    case EFFECTS_OUTPUT:
      output = static_cast<float*>(data);
      break;
    case EFFECTS_INPUT:
      input = static_cast<float*>(data);
      break;
    default:
      break;
    }
}

void Gxmetal_head::activate_f()
{
  // allocate the internal DSP mem
  if (tubevib->activate_plugin !=0)
    tubevib->activate_plugin(true, tubevib);
}

void Gxmetal_head::clean_up()
{
#ifndef __SSE__
  wn->delete_instance(wn);;
#endif
  // delete the internal DSP mem
  if (tubevib->activate_plugin !=0)
    tubevib->activate_plugin(false, tubevib);
}

void Gxmetal_head::deactivate_f()
{ 
  // delete the internal DSP mem
  if (tubevib->activate_plugin !=0)
    tubevib->activate_plugin(false, tubevib);
}

void Gxmetal_head::run_dsp_mono(uint32_t n_samples)
{
  if (n_samples< 1) return;
#ifndef __SSE__
  wn->mono_audio(static_cast<int>(n_samples), input, input, wn);;
#endif
  tubevib->mono_audio(static_cast<int>(n_samples), input,
                        output, tubevib);
  cabconv.run_static(n_samples, &cabconv, output);
}

void Gxmetal_head::connect_all_mono_ports(uint32_t port, void* data)
{
  // connect the Ports used by the plug-in class
  connect_mono(port,data); 
  // connect the Ports used by the DSP class
  tubevib->connect_ports(port,  data, tubevib);
}

///////////////////////// STATIC CLASS  FUNCTIONS /////////////////////

LV2_Handle
Gxmetal_head::instantiate(const LV2_Descriptor*     descriptor,
            double                    rate,
            const char*               bundle_path,
            const LV2_Feature* const* features)
{
  // init the plug-in class
  Gxmetal_head *self = new Gxmetal_head();
  if (!self)
    {
      return NULL;
    }
const LV2_Options_Option* options  = NULL;
  uint32_t bufsize = 0;
  //printf(" %s\n",descriptor->URI);

  for (int32_t i = 0; features[i]; ++i)
    {
      if (!strcmp(features[i]->URI, LV2_URID__map))
        {
          self->map = (LV2_URID_Map*)features[i]->data;
        }
      else if (!strcmp(features[i]->URI, LV2_OPTIONS__options))
        {
          options = (const LV2_Options_Option*)features[i]->data;
        }
    }
  if (!self->map)
    {
      fprintf(stderr, "Missing feature uri:map.\n");
    }
  else if (!options)
    {
      fprintf(stderr, "Missing feature options.\n");
    }
  else
    {
      LV2_URID bufsz_max = self->map->map(self->map->handle, LV2_BUF_SIZE__maxBlockLength);
      LV2_URID atom_Int = self->map->map(self->map->handle, LV2_ATOM__Int);

      for (const LV2_Options_Option* o = options; o->key; ++o)
        {
          if (o->context == LV2_OPTIONS_INSTANCE &&
              o->key == bufsz_max &&
              o->type == atom_Int)
            {
              bufsize = *(const int32_t*)o->value;
            }
        }

      if (bufsize == 0)
        {
          fprintf(stderr, "No maximum buffer size given.\n");
        }
      printf("using block size: %d\n", bufsize);
    }
  self->init_dsp_mono((uint32_t)rate, bufsize);

  return (LV2_Handle)self;
}

void Gxmetal_head::connect_port(LV2_Handle instance,
                                uint32_t   port,
                                void*      data)
{
  // connect all ports
  static_cast<Gxmetal_head*>(instance)->connect_all_mono_ports(port, data);
}

void Gxmetal_head::activate(LV2_Handle instance)
{
  // allocate needed mem
  static_cast<Gxmetal_head*>(instance)->activate_f();
}

void Gxmetal_head::run(LV2_Handle instance, uint32_t n_samples)
{
  // run dsp
  static_cast<Gxmetal_head*>(instance)->run_dsp_mono(n_samples);
}

void Gxmetal_head::deactivate(LV2_Handle instance)
{
  // free allocated mem
  static_cast<Gxmetal_head*>(instance)->deactivate_f();
}

void Gxmetal_head::cleanup(LV2_Handle instance)
{
  // well, clean up after us
  Gxmetal_head* self = static_cast<Gxmetal_head*>(instance);
  self->clean_up();
  delete self;
}

const LV2_Descriptor Gxmetal_head::descriptor =
{
  GXPLUGIN_URI "#metal_head",
  instantiate,
  connect_port,
  activate,
  run,
  deactivate,
  cleanup,
  NULL
};
} //end namespace gx_metalhead
///////////////////////////// LV2 DESCRIPTOR ///////////////////////////

LV2_SYMBOL_EXPORT
const LV2_Descriptor*
lv2_descriptor(uint32_t index)
{
  switch (index)
    {
    case 0:
      return &gx_metalhead::Gxmetal_head::descriptor;
    default:
      return NULL;
    }
}

///////////////////////////// FIN //////////////////////////////////////
