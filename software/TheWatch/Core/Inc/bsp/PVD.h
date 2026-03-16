/*
 * PVD.h
 *
 *  Created on: 13 lut 2026
 *      Author: kwojcik
 */

#ifndef INC_BSP_PVD_H_
#define INC_BSP_PVD_H_

#define BKP_RTC  0xA5A5

void PVD_Enable(void);
uint8_t WasPowerLost(void);
void BackupRtc_Save(void);


#endif /* INC_BSP_PVD_H_ */
