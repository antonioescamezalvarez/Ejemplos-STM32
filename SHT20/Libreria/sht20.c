/*
 * sht20.c
 *
 *  Created on: Oct 12, 2021
 *      Author: Antonio
 */

#ifndef SRC_SHT20_C_
#define SRC_SHT20_C_

#include "sht20.h"

I2C_HandleTypeDef *sht20_i2c;

void sht20_init(I2C_HandleTypeDef *hi2c) {
	sht20_i2c = hi2c;
}

void sht20_set_resolution(SHT20_Resolution res) {
	//Leo el valor del registro de usuario
	uint8_t user_register_value = sht20_get_user_register();

	// Pongo a 0 el bit 0 y el bit 7 preservando los demas con la and & 0x7e
	// Con la | user_register_value pongo la resolucion que ha pasado el usuario
	user_register_value = ( user_register_value & 0x7e ) | res;

	//Escribo el nuevo valor del registro de usuario que incorpora el nuevo valor de resolucion
	uint8_t cmd[2] = { CMD_TO_WRITE_USER_REGISTER, user_register_value };
	HAL_I2C_Master_Transmit( sht20_i2c, SHT20_ADDRESS << 1, (uint8_t*) &cmd, 2, SHT20_TIMEOUT );
}

uint8_t sht20_get_user_register() {
	uint8_t val;
	uint8_t cmd = CMD_TO_READ_USER_REGISTER;
	HAL_I2C_Master_Transmit( sht20_i2c, SHT20_ADDRESS << 1, (uint8_t*) &cmd, 1, SHT20_TIMEOUT );
	HAL_I2C_Master_Receive( sht20_i2c, SHT20_ADDRESS << 1, (uint8_t*) &val, 1, SHT20_TIMEOUT );
	return val;
}

float sht20_get_temperature(uint8_t hold) {
	uint8_t cmd;
	uint8_t val[3];
	uint16_t temperature_raw;
	if ( hold ) {
		cmd = CMD_TO_GET_TEMPERATURE_HOLD;
	} else {
		cmd = CMD_TO_GET_TEMPERATURE_NOHOLD;
	}

	HAL_I2C_Master_Transmit( sht20_i2c, SHT20_ADDRESS << 1, (uint8_t*) &cmd, 1, SHT20_TIMEOUT );
	HAL_I2C_Master_Receive( sht20_i2c, SHT20_ADDRESS << 1, (uint8_t*) &val, 3, SHT20_TIMEOUT );
	temperature_raw = ( val[0] << 8 ) | ( val[1] );
	return -46.85 + 175.72 * ( temperature_raw / 65536.0 );
}

float sht20_get_humidity(uint8_t hold) {
	uint8_t cmd;
	uint8_t val[3];
	uint16_t humidity_raw;
	if ( hold ) {
		cmd = CMD_TO_READ_HUMIDITY_HOLD;
	} else {
		cmd = CMD_TO_READ_HUMIDITY_NOHOLD;
	}

	HAL_I2C_Master_Transmit( sht20_i2c, SHT20_ADDRESS << 1, (uint8_t*) &cmd, 1, SHT20_TIMEOUT );
	HAL_I2C_Master_Receive( sht20_i2c, SHT20_ADDRESS << 1, (uint8_t*) &val, 3, SHT20_TIMEOUT );
	humidity_raw = ( val[0] << 8 ) | ( val[1] );
	return -6 + 125.00 * ( humidity_raw / 65536.0 );
}

#endif /* SRC_SHT20_C_ */
