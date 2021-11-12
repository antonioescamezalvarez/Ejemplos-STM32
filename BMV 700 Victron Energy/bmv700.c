/*
 * bmv700.c
 *
 *  Created on: Sep 18, 2021
 *      Author: Antonio Escamez Alvarez
 */

#include "bmv700.h"
#include "stm32f4xx_hal.h"
#include "string.h"

extern UART_HandleTypeDef huart2;

struct datos_bmv700 leer_sensor_bmv700() {

	uint8_t buffer_rx[100]; //Lee el uart
	uint8_t *SOC;
	uint16_t *datos_recibidos = 0;
	struct datos_bmv700 datos;

	HAL_UARTEx_ReceiveToIdle(&huart2, buffer_rx, 100, datos_recibidos, 450);
	if (strstr((const char*)buffer_rx, "\r\nSOC\t")) {
		SOC = (uint8_t*)strstr((const char*) buffer_rx, "\r\nSOC\t");
		memcpy(datos.bateria, SOC+6, 4);
	}else{
		strcpy(datos.bateria, "-1");
	}
	return datos;
}

