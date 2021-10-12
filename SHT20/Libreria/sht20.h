/*
 * sht20.h
 *
 *  Created on: Oct 12, 2021
 *      Author: Antonio
 */

#ifndef INC_SHT20_H_
#define INC_SHT20_H_
#include "stm32f4xx_hal.h"
/*----------------------------------------------------------------------------*/
#define SHT20_ADDRESS					0x40
#define CMD_TO_READ_USER_REGISTER		0xE7
#define	CMD_TO_WRITE_USER_REGISTER		0xE6
#define CMD_TO_GET_TEMPERATURE_HOLD		0xE3
#define CMD_TO_GET_TEMPERATURE_NOHOLD	0xF3
#define SHT2x_HOLD_MASTER				1
#define	CMD_TO_READ_HUMIDITY_HOLD		0xE5
#define CMD_TO_READ_HUMIDITY_NOHOLD		0xF5
#define SHT2x_SOFT_RESET				0xFE
#define SHT20_TIMEOUT					1000
/*----------------------------------------------------------------------------*/
typedef enum SHT20_Resolution {
	RES_14_12 = 0x00, RES_12_8 = 0x01, RES_13_10 = 0x80, RES_11_11 = 0x81
} SHT20_Resolution;
/*----------------------------------------------------------------------------*/
void sht20_init(I2C_HandleTypeDef *hi2c);
void sht20_set_resolution(SHT20_Resolution res);
uint8_t sht20_get_user_register();
float sht20_get_temperature(uint8_t hold);
float sht20_get_humidity(uint8_t hold);

#endif /* INC_SHT20_H_ */
