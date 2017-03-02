/*
    ChibiOS - Copyright (C) 2006..2015 Giovanni Di Sirio

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/

#include "ch.h"
#include "hal.h"
#include "codec.h"
#include "testme.h"
#include "mmcfs_sdc.h"

/*
 * LED blinker thread, times are in milliseconds.
 */
static THD_WORKING_AREA(waThread1, 128);
static THD_FUNCTION(Thread1, arg) {

  (void)arg;
  chRegSetThreadName("blinker");
  while (true) {
    palClearPad(GPIOD, 12);
    chThdSleepMilliseconds(500);
    palSetPad(GPIOD, 12);
    chThdSleepMilliseconds(500);
  }
}

/*
 * Application entry point.
 */
int main(void) {
  uint8_t arra[10];
  arra[0] = 0x11;
  arra[1] = 0x22;
  arra[2] = 0x33;
  arra[3] = 0x44;
  arra[4] = 0x55;
  arra[5] = 0x66;
  arra[6] = 0x77;
  arra[7] = 0x88;
  arra[8] = 0x99;
  arra[9] = 0xBB;


  /*
   * System initializations.
   * - HAL initialization, this also initializes the configured device drivers
   *   and performs the board-specific initializations.
   * - Kernel initialization, the main() function becomes a thread and the
   *   RTOS is active.
   */
  halInit();
  chSysInit();

  /*
   * Activates the serial driver 2 using the driver default configuration.
   */
  codec_hw_init();
  sdStart(&SD2, NULL);
  initMmcfsSdc();
  /*
   * Creates the blinker thread.
   */
  chThdCreateStatic(waThread1, sizeof(waThread1), NORMALPRIO, Thread1, NULL);
//  test_43l22_beep(BEEP_MULTIPLE);
//  codec_sendBeep();

  /*
   * Normal main() thread activity, in this demo it does nothing except
   * sleeping in a loop and check the button state.
   */
  codec_i2s_init(100,10);
  while (true) {
    arra[0] = 0x11;
    arra[1] = 0x22;
    arra[2] = 0x33;
    arra[3] = 0x44;
    arra[4] = 0x55;
    arra[5] = 0x66;
    arra[6] = 0x77;
    arra[7] = 0x88;
    arra[8] = 0x99;
    arra[9] = 0xBB;
    codec_audio_send(&arra[0],10);
    chThdSleepMilliseconds(500);
  }
}
