/*
 * Copyright (C) 2012 Hermann Meyer, Andreas Degert, Pete Shorthose
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


#pragma once

#ifndef SRC_HEADERS_GX_RESAMPLER_H_
#define SRC_HEADERS_GX_RESAMPLER_H_

#include <zita-resampler/resampler.h>
#include <stdint.h>
#include <assert.h>
#include <cmath>
#include <cstring>

namespace gx_resample
{

#define MAX_UPSAMPLE 8


class FixedRateResampler {
private:
    Resampler r_up, r_down;
    int inputRate, outputRate;
    int last_in_count;
public:
    int setup(int _inputRate, int _outputRate);
    int up(int count, float *input, float *output);
    void down(float *input, float *output);
    int max_out_count(int in_count) {
	return static_cast<int>(ceil((in_count*static_cast<double>(outputRate))/inputRate)); }
};

class SimpleResampler
{
private:
  Resampler r_up, r_down;
  int32_t m_fact;
  int32_t ratio_a;
  int32_t ratio_b;
public:
  SimpleResampler(): r_up(), r_down(), m_fact() {}
  void setup(int32_t sampleRate, uint32_t fact);
  int32_t up(int32_t count, float *input, float *output);
  void down(int32_t count, float *input, float *output);
  int32_t get_max_out_size(int32_t i_size)
  {
    return (i_size * ratio_b) / ratio_a + 1;
  }
};

class BufferResampler: Resampler
{
public:
  float *process(int32_t fs_inp, int32_t ilen, float *input, int32_t fs_outp, int32_t* olen);
};

class StreamingResampler: Resampler
{
private:
  int32_t ratio_a;
  int32_t ratio_b;
public:
  bool setup(int32_t srcRate, int32_t dstRate, int32_t nchan);
  int32_t get_max_out_size(int32_t i_size)
  {
    return (i_size * ratio_b) / ratio_a + 1;
  }
  int32_t process(int32_t count, float *input, float *output);
  int32_t flush(float *output); // check source for max. output size
};

}
#endif  // SRC_HEADERS_GX_RESAMPLER_H_
#include "gx_resampler.cc"
#include "resampler.cc"
#include "resampler-table.cc"

