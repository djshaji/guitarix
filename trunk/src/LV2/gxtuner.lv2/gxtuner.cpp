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
#include <glibmm.h>
#include "gx_common.h"      // faust support and denormal protection (SSE)
#include "gxtuner.h"        // define struct PortIndex
#include "gx_pluginlv2.h"   // define struct PluginLV2
#include "gx_resampler.h"
#include "tuner.cc"    // dsp class generated by faust -> dsp2cc
#include "gx_pitch_tracker.cpp"

#include "cab_data.cc"

////////////////////////////// PLUG-IN CLASS ///////////////////////////

class Gxtuner
{
private:
  // internal stuff
  float*                       output;
  float*                       input;
  float*                       freq;
  float                        threshold;
  float*                       threshold_;
  PluginLV2*                   tuner_adapter;

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
  Gxtuner();
  ~Gxtuner();
};

// constructor
Gxtuner::Gxtuner() :
  output(NULL),
  input(NULL),
  tuner_adapter(plugin())
 {};

// destructor
Gxtuner::~Gxtuner()
{
  // just to be sure the plug have given free the allocated mem
  // it didn't hurd if the mem is already given free by clean_up()
  if (tuner_adapter->activate_plugin !=0)
    tuner_adapter->activate_plugin(false, tuner_adapter);
  // delete DSP class
  tuner_adapter->delete_instance(tuner_adapter);

};

////////////////////////////// PRIVATE CLASS  FUNCTIONS ////////////////

void Gxtuner::init_dsp_mono(uint32_t rate)
{
  AVOIDDENORMALS(); // init the SSE denormal protection
  tuner_adapter->set_samplerate(rate, tuner_adapter); // init the DSP class
}

// connect the Ports used by the plug-in class
void Gxtuner::connect_mono(uint32_t port,void* data)
{
  switch ((PortIndex)port)
    {
    case FREQ: 
      freq = static_cast<float*>(data);
      break;
    case THRESHOLD: 
      threshold_ = static_cast<float*>(data) ;
      break;
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

void Gxtuner::activate_f()
{
  // allocate the internal DSP mem
  if (tuner_adapter->activate_plugin !=0)
    tuner_adapter->activate_plugin(true, tuner_adapter);
}

void Gxtuner::clean_up()
{
  // delete the internal DSP mem
  if (tuner_adapter->activate_plugin !=0)
    tuner_adapter->activate_plugin(false, tuner_adapter);
}

void Gxtuner::deactivate_f()
{ 
  // delete the internal DSP mem
  if (tuner_adapter->activate_plugin !=0)
    tuner_adapter->activate_plugin(false, tuner_adapter);
}

void Gxtuner::run_dsp_mono(uint32_t n_samples)
{
  tuner& self = *static_cast<tuner*>(tuner_adapter);
  threshold = *(threshold_);
  self.set_threshold_level(threshold);
    
  tuner_adapter->mono_audio(static_cast<int>(n_samples), input, output, tuner_adapter);
  *(freq) = static_cast<tuner*>(tuner_adapter)->get_freq();
  //printf("frequency  value %f\n",*(freq));
  memcpy(output, input, n_samples * sizeof(float));
}

void Gxtuner::connect_all_mono_ports(uint32_t port, void* data)
{
  // connect the Ports used by the plug-in class
  connect_mono(port,data); 
  // connect the Ports used by the DSP class
  tuner_adapter->connect_ports(port,  data, tuner_adapter);
}

///////////////////////// STATIC CLASS  FUNCTIONS /////////////////////

LV2_Handle
Gxtuner::instantiate(const LV2_Descriptor*     descriptor,
            double                    rate,
            const char*               bundle_path,
            const LV2_Feature* const* features)
{
  // init the plug-in class
  Gxtuner *self = new Gxtuner();
  if (!self)
    {
      return NULL;
    }

  self->init_dsp_mono((uint32_t)rate);
  return (LV2_Handle)self;
}

void Gxtuner::connect_port(LV2_Handle instance,
                                uint32_t   port,
                                void*      data)
{
  // connect all ports
  static_cast<Gxtuner*>(instance)->connect_all_mono_ports(port, data);
}

void Gxtuner::activate(LV2_Handle instance)
{
  // allocate needed mem
  static_cast<Gxtuner*>(instance)->activate_f();
}

void Gxtuner::run(LV2_Handle instance, uint32_t n_samples)
{
  // run dsp
  static_cast<Gxtuner*>(instance)->run_dsp_mono(n_samples);
}

void Gxtuner::deactivate(LV2_Handle instance)
{
  // free allocated mem
  static_cast<Gxtuner*>(instance)->deactivate_f();
}

void Gxtuner::cleanup(LV2_Handle instance)
{
  // well, clean up after us
  Gxtuner* self = static_cast<Gxtuner*>(instance);
  self->clean_up();
  delete self;
}

const LV2_Descriptor Gxtuner::descriptor =
{
  GXPLUGIN_URI "#tuner",
  instantiate,
  connect_port,
  activate,
  run,
  deactivate,
  cleanup,
  NULL
};

///////////////////////////// LV2 DESCRIPTOR ///////////////////////////

extern "C"
LV2_SYMBOL_EXPORT
const LV2_Descriptor*
lv2_descriptor(uint32_t index)
{
  switch (index)
    {
    case 0:
      return &Gxtuner::descriptor;
    default:
      return NULL;
    }
}

///////////////////////////// FIN //////////////////////////////////////
