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
#include "gxtubetremelo.h"        // define struct PortIndex
#include "gx_pluginlv2.h"   // define struct PluginLV2
namespace gx_tubetremolo {
#include "gxtubetremelo.cc"    // dsp class generated by faust -> dsp2cc
#ifndef __SSE__
#include "noiser.cc"
#endif

////////////////////////////// PLUG-IN CLASS ///////////////////////////

class Gxtubetremelo
{
private:
  // internal stuff
  float*                       output;
  float*                       input;
  PluginLV2*                   tubevib;
#ifndef __SSE__
  PluginLV2*                   wn;
#endif

  inline void run_dsp_mono(uint32_t n_samples);
  inline void connect_mono(uint32_t port,void* data);
  inline void init_dsp_mono(uint32_t rate);
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
  Gxtubetremelo();
  ~Gxtubetremelo();
};

// constructor
Gxtubetremelo::Gxtubetremelo() :
  output(NULL),
  input(NULL),
  tubevib(gxtubetremelo::plugin()) {};

// destructor
Gxtubetremelo::~Gxtubetremelo()
{
  // just to be sure the plug have given free the allocated mem
  // it didn't hurd if the mem is already given free by clean_up()
  if (tubevib->activate_plugin !=0)
    tubevib->activate_plugin(false, tubevib);
  // delete DSP class
  tubevib->delete_instance(tubevib);
};

////////////////////////////// PRIVATE CLASS  FUNCTIONS ////////////////

void Gxtubetremelo::init_dsp_mono(uint32_t rate)
{
  AVOIDDENORMALS(); // init the SSE denormal protection
#ifndef __SSE__
  wn = noiser::plugin();
  wn->set_samplerate(rate, wn);
#endif
  tubevib->set_samplerate(rate, tubevib); // init the DSP class
}

// connect the Ports used by the plug-in class
void Gxtubetremelo::connect_mono(uint32_t port,void* data)
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

void Gxtubetremelo::activate_f()
{
  // allocate the internal DSP mem
  if (tubevib->activate_plugin !=0)
    tubevib->activate_plugin(true, tubevib);
}

void Gxtubetremelo::clean_up()
{
#ifndef __SSE__
  wn->delete_instance(wn);;
#endif
  // delete the internal DSP mem
  if (tubevib->activate_plugin !=0)
    tubevib->activate_plugin(false, tubevib);
}

void Gxtubetremelo::deactivate_f()
{ 
  // delete the internal DSP mem
  if (tubevib->activate_plugin !=0)
    tubevib->activate_plugin(false, tubevib);
}

void Gxtubetremelo::run_dsp_mono(uint32_t n_samples)
{
  if (n_samples< 1) return;
#ifndef __SSE__
  wn->mono_audio(static_cast<int>(n_samples), input, input, wn);;
#endif
  tubevib->mono_audio(static_cast<int>(n_samples), input,
                        output, tubevib);
}

void Gxtubetremelo::connect_all_mono_ports(uint32_t port, void* data)
{
  // connect the Ports used by the plug-in class
  connect_mono(port,data); 
  // connect the Ports used by the DSP class
  tubevib->connect_ports(port,  data, tubevib);
}

///////////////////////// PRIVATE CLASS  FUNCTIONS /////////////////////

LV2_Handle
Gxtubetremelo::instantiate(const LV2_Descriptor*     descriptor,
            double                    rate,
            const char*               bundle_path,
            const LV2_Feature* const* features)
{
  // init the plug-in class
  Gxtubetremelo *self = new Gxtubetremelo();
  if (!self)
    {
      return NULL;
    }

  self->init_dsp_mono((uint32_t)rate);

  return (LV2_Handle)self;
}

void Gxtubetremelo::connect_port(LV2_Handle instance,
                                uint32_t   port,
                                void*      data)
{
  // connect all ports
  static_cast<Gxtubetremelo*>(instance)->connect_all_mono_ports(port, data);
}

void Gxtubetremelo::activate(LV2_Handle instance)
{
  // allocate needed mem
  static_cast<Gxtubetremelo*>(instance)->activate_f();
}

void Gxtubetremelo::run(LV2_Handle instance, uint32_t n_samples)
{
  // run dsp
  static_cast<Gxtubetremelo*>(instance)->run_dsp_mono(n_samples);
}

void Gxtubetremelo::deactivate(LV2_Handle instance)
{
  // free allocated mem
  static_cast<Gxtubetremelo*>(instance)->deactivate_f();
}

void Gxtubetremelo::cleanup(LV2_Handle instance)
{
  // well, clean up after us
  Gxtubetremelo* self = static_cast<Gxtubetremelo*>(instance);
  self->clean_up();
  delete self;
}

const LV2_Descriptor Gxtubetremelo::descriptor =
{
  GXPLUGIN_URI "#tubetremelo",
  instantiate,
  connect_port,
  activate,
  run,
  deactivate,
  cleanup,
  NULL
};

} //end namespace gx_tubetremolo

///////////////////////////// LV2 DESCRIPTOR ///////////////////////////

LV2_SYMBOL_EXPORT
const LV2_Descriptor*
lv2_descriptor(uint32_t index)
{
  switch (index)
    {
    case 0:
      return &gx_tubetremolo::Gxtubetremelo::descriptor;
    default:
      return NULL;
    }
}

///////////////////////////// FIN //////////////////////////////////////
