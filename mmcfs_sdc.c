/*
    ChibiOS - Copyright (C) 2006..2016 Giovanni Di Sirio

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

#define _FS_READONLY 0
#include <string.h>

#include "ch.h"
#include "hal.h"
#include "ff.h"
#include "mmcfs_sdc.h"

static uint8_t sd_scratchpad[512];
static char read_data[512];
#define SDC_BURST_SIZE      16
FATFS MMC_FS;
FIL files;
/*
 * SDIO configuration.
 */
static const SDCConfig sdccfg = {
  sd_scratchpad,
  SDC_MODE_1BIT
};


int initMmcfsSdc(void)
{
  char path=0;
  FRESULT err;
  DIR dir;

  sdcStart(&SDCD1, &sdccfg);
  /* Card presence check.*/
  if (!blkIsInserted(&SDCD1)) {
//    print("Card not inserted, aborting.\r\n");
  }

  /* Connection to the card.*/
//  print("MMC Connecting...-");
  if (sdcConnect(&SDCD1)) {
//    print("failed\r\n");
  }
  else
  {
//    print("success\r\n");
  }
  err = f_mount(&MMC_FS, "0:", 1);
  if(FR_OK != err)
  {
//    print("Error while mounting SD card\r\n");
  }
  err = f_opendir(&dir, path);
  if(FR_OK == err)
  {
//    print("Error while opening directory\r\n");
  }
  if (f_open(&files, "0:file.txt", FA_READ | FA_WRITE | FA_OPEN_ALWAYS) == FR_OK)
    {
//      f_puts("This is my first file with USB and FatFS\n", &files);
//      f_puts("with USB MSC HOST library from stm32f4-discovery.com\n", &files);
//      f_puts("----------------------------------------------------\n", &files);
//      f_puts("USB total and free space:\n\n", &files);
//      f_puts("----------------------------------------------------\n", &files);
      /* Close USB file */
      f_close(&files);
    }

  if (f_open(&files, "0:filese.txt", FA_READ | FA_OPEN_ALWAYS) == FR_OK)
    {
//    f_gets(&read_data,100,&files);
//    print(&read_data);
      f_close(&files);
    }
//  print("End of SD init\r\n");
}
