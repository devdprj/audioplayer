/*
 * test.c
 *
 *  Created on: 28-Feb-2017
 *      Author:
 */
#include "codec.h"
#include "testme.h"


void test_43l22_beep(uint8_t type)
{
  codec_writeReg(0x1C,0xE1);
  codec_writeReg(0x1D,0x07);
  codec_writeReg(0x1E,(type<<6) | BEEP_MIXED | TREB_FREQ_5KHz | BASS_FREQ_100Hz | TONE_CNTRL_ENABLE);
}


