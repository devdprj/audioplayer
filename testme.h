/*
 * test.h
 *
 *  Created on: 28-Feb-2017
 *      Author:
 */

#ifndef TESTME_H_
#define TESTME_H_

#include <stdint.h>


#define BEEP_SINGLE     0x01
#define BEEP_MULTIPLE   0x02
#define BEEP_CONTINOUS  0x03

#define BEEP_MIXED      0x20

#define TREB_FREQ_5KHz      0x00
#define TREB_FREQ_7KHz      0x08
#define TREB_FREQ_10KHz     0x10
#define TREB_FREQ_15KHz     0x18

#define BASS_FREQ_50Hz       0x00
#define BASS_FREQ_100Hz      0x02
#define BASS_FREQ_200Hz      0x04
#define BASS_FREQ_250Hz      0x06

#define TONE_CNTRL_ENABLE           0x01
#define TONE_CNTRL_DISABLE          0x00



void test_43l22_beep(uint8_t type);

#endif /* TESTME_H_ */
