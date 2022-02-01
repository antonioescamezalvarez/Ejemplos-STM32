/*
 * cromatografo.c
 *
 *  Created on: Feb 1, 2022
 *      Author: Antonio
 */

#include "cromatografo.h"
#include "stm32f4xx_hal.h"
extern UART_HandleTypeDef huart1;

struct datos_cromatografo leer_cromatografo(){
	//Primero montamos el mensaje de request para solicitar los datos
	uint8_t cromatografo_request[4] = {0x11,0x01,0x01,0xED};

	//Enviamos el request
	HAL_UART_Transmit(&huart1, cromatografo_request, 4, HAL_MAX_DELAY);

	//Creamos el response
	uint8_t cromatografo_response[20];

	//Leemos la respuesta
	HAL_UART_Receive(&huart1, cromatografo_response, 20, 3000);

	//Montamos el struct con los datos para devolverlos
	struct datos_cromatografo datos;
	datos.CO = ((cromatografo_response[3]*256)+cromatografo_response[4])/100.0;
	datos.CO2 = ((cromatografo_response[5]*256)+cromatografo_response[6])/100.0;
	datos.CH4 = ((cromatografo_response[7]*256)+cromatografo_response[8])/100.0;
	datos.CmHn = ((cromatografo_response[9]*256)+cromatografo_response[10])/100.0;
	datos.H2 = ((cromatografo_response[11]*256)+cromatografo_response[12])/100.0;
	datos.O2 = ((cromatografo_response[13]*256)+cromatografo_response[14])/100.0;
	datos.LHV = ((cromatografo_response[15]*256)+cromatografo_response[16])/100.0;
	datos.N2 = ((cromatografo_response[17]*256)+cromatografo_response[18])/100.0;
	return datos;
}
