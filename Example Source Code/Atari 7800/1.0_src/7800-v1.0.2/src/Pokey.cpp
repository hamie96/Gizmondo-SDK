// ----------------------------------------------------------------------------
//   ___  ___  ___  ___       ___  ____  ___  _  _
//  /__/ /__/ /  / /__  /__/ /__    /   /_   / |/ /
// /    / \  /__/ ___/ ___/ ___/   /   /__  /    /  emulator
//
// ----------------------------------------------------------------------------
// Copyright 2005 Greg Stanton
// 
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
// ----------------------------------------------------------------------------
// PokeySound is Copyright(c) 1997 by Ron Fries
//                                                                           
// This library is free software; you can redistribute it and/or modify it   
// under the terms of version 2 of the GNU Library General Public License    
// as published by the Free Software Foundation.                             
//                                                                           
// This library is distributed in the hope that it will be useful, but       
// WITHOUT ANY WARRANTY; without even the implied warranty of                
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Library 
// General Public License for more details.                                  
// To obtain a copy of the GNU Library General Public License, write to the  
// Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.   
//                                                                           
// Any permitted reproduction of these routines, in whole or in part, must   
// bear this legend.                                                         
// ----------------------------------------------------------------------------
// Pokey.cpp
// ----------------------------------------------------------------------------
#include <stdlib.h>
#include "Pokey.h"
#define POKEY_NOTPOLY5 0x80
#define POKEY_POLY4 0x40
#define POKEY_PURE 0x20
#define POKEY_VOLUME_ONLY 0x10
#define POKEY_VOLUME_MASK 0x0f
#define POKEY_POLY9 0x80 
#define POKEY_CH1_179 0x40
#define POKEY_CH3_179 0x20
#define POKEY_CH1_CH2 0x10
#define POKEY_CH3_CH4 0x08
#define POKEY_CH1_FILTER 0x04
#define POKEY_CH2_FILTER 0x02
#define POKEY_CLOCK_15 0x01
#define POKEY_DIV_64 28
#define POKEY_DIV_15 114
#define POKEY_POLY4_SIZE 0x000f
#define POKEY_POLY5_SIZE 0x001f
#define POKEY_POLY9_SIZE 0x01ff
#define POKEY_POLY17_SIZE 0x0001ffff
#define POKEY_CHANNEL1 0
#define POKEY_CHANNEL2 1
#define POKEY_CHANNEL3 2
#define POKEY_CHANNEL4 3
#define POKEY_SAMPLE 4

uint pokey_size = 524;

static uint pokey_frequency = 1787520;
static uint pokey_sampleRate = 31440;
static uint pokey_soundCntr = 0;
static byte pokey_audf[4];
static byte pokey_audc[4];
static byte pokey_audctl;
static byte pokey_output[4];
static byte pokey_outVol[4];
static byte pokey_poly04[POKEY_POLY4_SIZE] = {1,1,0,1,1,1,0,0,0,0,1,0,1,0,0};
static byte pokey_poly05[POKEY_POLY5_SIZE] = {0,0,1,1,0,0,0,1,1,1,1,0,0,1,0,1,0,1,1,0,1,1,1,0,1,0,0,0,0,0,1};
static byte pokey_poly17[POKEY_POLY17_SIZE];
static uint pokey_poly17Size;
static uint pokey_polyAdjust;
static uint pokey_poly04Cntr;
static uint pokey_poly05Cntr;
static uint pokey_poly17Cntr;
static uint pokey_divideMax[4];
static uint pokey_divideCount[4];
static uint pokey_sampleMax;
static uint pokey_sampleCount[2];
static uint pokey_baseMultiplier;

// ----------------------------------------------------------------------------
// Reset
// ----------------------------------------------------------------------------
void pokey_Reset( ) {
  for(int index = 0; index < POKEY_POLY17_SIZE; index++) {
    pokey_poly17[index] = rand( ) & 1;
  }
  pokey_polyAdjust = 0;
  pokey_poly04Cntr = 0;
  pokey_poly05Cntr = 0;
  pokey_poly17Cntr = 0;

  pokey_sampleMax = ((uint)pokey_frequency << 8) / pokey_sampleRate;

  pokey_sampleCount[0] = 0;
  pokey_sampleCount[1] = 0;

  pokey_poly17Size = POKEY_POLY17_SIZE;

  for(int channel = POKEY_CHANNEL1; channel <= POKEY_CHANNEL4; channel++) {
    pokey_outVol[channel] = 0;
    pokey_output[channel] = 0;
    pokey_divideCount[channel] = 0;
    pokey_divideMax[channel] = 0x7fffffffL;
    pokey_audc[channel] = 0;
    pokey_audf[channel] = 0;
  }

  pokey_audctl = 0;
  pokey_baseMultiplier = POKEY_DIV_64;
}                           

// ----------------------------------------------------------------------------
// SetRegister
// ----------------------------------------------------------------------------
void pokey_SetRegister(word address, byte value) {
	byte channelMask;
  switch(address) {
    case POKEY_AUDF1:
      pokey_audf[POKEY_CHANNEL1] = value;
      channelMask = 1 << POKEY_CHANNEL1;
      if(pokey_audctl & POKEY_CH1_CH2) {
        channelMask |= 1 << POKEY_CHANNEL2;
      }
      break;
    
    case POKEY_AUDC1:
      pokey_audc[POKEY_CHANNEL1] = value;
      channelMask = 1 << POKEY_CHANNEL1;
      break;

    case POKEY_AUDF2:
      pokey_audf[POKEY_CHANNEL2] = value;
      channelMask = 1 << POKEY_CHANNEL2;
      break;

    case POKEY_AUDC2:
      pokey_audc[POKEY_CHANNEL2] = value;
      channelMask = 1 << POKEY_CHANNEL2;
      break;

    case POKEY_AUDF3:
      pokey_audf[POKEY_CHANNEL3] = value;
      channelMask = 1 << POKEY_CHANNEL3;

      if(pokey_audctl & POKEY_CH3_CH4) {
        channelMask |= 1 << POKEY_CHANNEL4;
      }
      break;

    case POKEY_AUDC3:
      pokey_audc[POKEY_CHANNEL3] = value;
      channelMask = 1 << POKEY_CHANNEL3;
      break;

    case POKEY_AUDF4:
      pokey_audf[POKEY_CHANNEL4] = value;
      channelMask = 1 << POKEY_CHANNEL4;
      break;

    case POKEY_AUDC4:
      pokey_audc[POKEY_CHANNEL4] = value;
      channelMask = 1 << POKEY_CHANNEL4;
      break;

    case POKEY_AUDCTL:
      pokey_audctl = value;
      channelMask = 15;
      if(pokey_audctl & POKEY_POLY9) {
        pokey_poly17Size = POKEY_POLY9_SIZE;
      }
      else {
        pokey_poly17Size = POKEY_POLY17_SIZE;
      }
      if(pokey_audctl & POKEY_CLOCK_15) {
        pokey_baseMultiplier = POKEY_DIV_15;
      }
      else {
        pokey_baseMultiplier = POKEY_DIV_64;
      }
      break;

    default:
      channelMask = 0;
      break;
  }
    
  uint newValue = 0;

  if(channelMask & (1 << POKEY_CHANNEL1)) {
    if(pokey_audctl & POKEY_CH1_179) {
      newValue = pokey_audf[POKEY_CHANNEL1] + 4;
    }
    else {
      newValue = (pokey_audf[POKEY_CHANNEL1] + 1) * pokey_baseMultiplier;
    }

    if(newValue != pokey_divideMax[POKEY_CHANNEL1]) {
      pokey_divideMax[POKEY_CHANNEL1] = newValue;
      if(pokey_divideCount[POKEY_CHANNEL1] > newValue) {
        pokey_divideCount[POKEY_CHANNEL1] = 0;
      }
    }
  }

  if(channelMask & (1 << POKEY_CHANNEL2)) {
    if(pokey_audctl & POKEY_CH1_CH2) {
      if(pokey_audctl & POKEY_CH1_179) {
        newValue = pokey_audf[POKEY_CHANNEL2] * 256 + pokey_audf[POKEY_CHANNEL1] + 7;
      }
      else {
        newValue = (pokey_audf[POKEY_CHANNEL2] * 256 + pokey_audf[POKEY_CHANNEL1] + 1) * pokey_baseMultiplier;
      }
    }
    else {
      newValue = (pokey_audf[POKEY_CHANNEL2] + 1) * pokey_baseMultiplier;
    }
    if(newValue != pokey_divideMax[POKEY_CHANNEL2]) {
      pokey_divideMax[POKEY_CHANNEL2] = newValue;
      if(pokey_divideCount[POKEY_CHANNEL2] > newValue) {
        pokey_divideCount[POKEY_CHANNEL2] = newValue;
      }
    }
  }

  if(channelMask & (1 << POKEY_CHANNEL3)) {
    if(pokey_audctl & POKEY_CH3_179) {
      newValue = pokey_audf[POKEY_CHANNEL3] + 4;
    }
    else {
      newValue= (pokey_audf[POKEY_CHANNEL3] + 1) * pokey_baseMultiplier;
    }
    if(newValue!= pokey_divideMax[POKEY_CHANNEL3]) {
      pokey_divideMax[POKEY_CHANNEL3] = newValue;
      if(pokey_divideCount[POKEY_CHANNEL3] > newValue) {   
        pokey_divideCount[POKEY_CHANNEL3] = newValue;
      }
    }
  }

  if(channelMask & (1 << POKEY_CHANNEL4)) {
    if(pokey_audctl & POKEY_CH3_CH4) {
      if(pokey_audctl & POKEY_CH3_179) {
        newValue = pokey_audf[POKEY_CHANNEL4] * 256 + pokey_audf[POKEY_CHANNEL3] + 7;
      }
      else {
        newValue = (pokey_audf[POKEY_CHANNEL4] * 256 + pokey_audf[POKEY_CHANNEL3] + 1) * pokey_baseMultiplier;
      }
    }
    else {
      newValue = (pokey_audf[POKEY_CHANNEL4] + 1) * pokey_baseMultiplier;
    }
    if(newValue != pokey_divideMax[POKEY_CHANNEL4]) {
      pokey_divideMax[POKEY_CHANNEL4] = newValue;
      if(pokey_divideCount[POKEY_CHANNEL4] > newValue) {
        pokey_divideCount[POKEY_CHANNEL4] = newValue;
      } 
    }
  }

  for(byte channel = POKEY_CHANNEL1; channel <= POKEY_CHANNEL4; channel++) {
    if(channelMask & (1 << channel)) {
      if((pokey_audc[channel] & POKEY_VOLUME_ONLY) || ((pokey_audc[channel] & POKEY_VOLUME_MASK) == 0) || (pokey_divideMax[channel] < (pokey_sampleMax >> 8))) {
        pokey_outVol[channel] = pokey_audc[channel] & POKEY_VOLUME_MASK;
        pokey_divideCount[channel] = 0x7fffffff;
        pokey_divideMax[channel] = 0x7fffffff;
      }
    }
  } 
}

//LUDO:
static uint 
loc_get_int(byte *p)
{
  uint res = (((uint)(p[3])) << 24)| (((uint)(p[2])) << 16)| (((uint)(p[1])) <<  8)| ((uint)(p[0]));
  return res;
}

static void
loc_set_byte(byte *p, uint v)
{
  p[0] =  v        & 0xff;
  p[1] = (v >>  8) & 0xff;
  p[2] = (v >> 16) & 0xff;
  p[3] = (v >> 24) & 0xff;
}

// ----------------------------------------------------------------------------
// Process
// ----------------------------------------------------------------------------
void pokey_Process(uint length) 
{

  byte* buffer = pokey_buffer + pokey_soundCntr;
  byte* sampleCntrPtrB = ((byte*)&pokey_sampleCount[0]) + 1;
  uint size = length;

  while(length) {

    byte currentValue;
    byte nextEvent = POKEY_SAMPLE;
    uint eventMin = loc_get_int(sampleCntrPtrB);

    byte channel;
    for(channel = POKEY_CHANNEL1; channel <= POKEY_CHANNEL4; channel++) {
      if(pokey_divideCount[channel] <= eventMin) {
        eventMin = pokey_divideCount[channel];
        nextEvent = channel;
      }
    }
    
    for(channel = POKEY_CHANNEL1; channel <= POKEY_CHANNEL4; channel++) {
      pokey_divideCount[channel] -= eventMin;
    }

    uint new_value = loc_get_int(sampleCntrPtrB) - eventMin;
    loc_set_byte(sampleCntrPtrB, new_value);

    pokey_polyAdjust += eventMin;

    if(nextEvent != POKEY_SAMPLE) {
      pokey_poly04Cntr = (pokey_poly04Cntr + pokey_polyAdjust) % POKEY_POLY4_SIZE;
      pokey_poly05Cntr = (pokey_poly05Cntr + pokey_polyAdjust) % POKEY_POLY5_SIZE;
      pokey_poly17Cntr = (pokey_poly17Cntr + pokey_polyAdjust) % pokey_poly17Size;
      pokey_polyAdjust = 0;
      pokey_divideCount[nextEvent] += pokey_divideMax[nextEvent];

      if((pokey_audc[nextEvent] & POKEY_NOTPOLY5) || pokey_poly05[pokey_poly05Cntr]) {
        if(pokey_audc[nextEvent] & POKEY_PURE) {
          pokey_output[nextEvent] = !pokey_output[nextEvent];
        }
        else if (pokey_audc[nextEvent] & POKEY_POLY4) {
          pokey_output[nextEvent] = pokey_poly04[pokey_poly04Cntr];
        }
        else {
          pokey_output[nextEvent] = pokey_poly17[pokey_poly17Cntr];
        }
      }

      if(pokey_output[nextEvent]) {
        pokey_outVol[nextEvent] = pokey_audc[nextEvent] & POKEY_VOLUME_MASK;
      }
      else {
        pokey_outVol[nextEvent] = 0;
      }
    }
    else {
      *pokey_sampleCount += pokey_sampleMax;
      currentValue = 0;

      for(channel = POKEY_CHANNEL1; channel <= POKEY_CHANNEL4; channel++) {
        currentValue += pokey_outVol[channel];
      }

      currentValue = (currentValue << 2) + 8;
      *buffer++ = currentValue;
      length--;
    }
  }  
  
  pokey_soundCntr += size;
  if(pokey_soundCntr >= pokey_size) {
    pokey_soundCntr = 0;
  }
}

// ----------------------------------------------------------------------------
// Clear
// ----------------------------------------------------------------------------
void pokey_Clear( ) {
  for(int index = 0; index < POKEY_BUFFER_SIZE; index++) {
    pokey_buffer[index] = 0;
  }
}

