/*
 * temporizador.c
 *
 *  Created on: Sep 8, 2022
 *      Author: Antonio
 */

#include "temporizador.h"

void temporizador_init(uint32_t tiempo_encendido, uint32_t tiempo_apagado,
		GPIO_TypeDef *puerto_pin, uint16_t pin, temporizador *temporizador) {
	temporizador->_tiempo_que_debe_estar_encendido = tiempo_encendido;
	temporizador->_tiempo_que_debe_estar_apagado = tiempo_apagado;
	temporizador->_tiempo_en_el_que_acaba_de_encenderse = 0;
	temporizador->_tiempo_en_el_que_acaba_de_apagarse = 0;
	temporizador->_estado_temporizador = APAGADO;
	temporizador->_puerto_pin = puerto_pin;
	temporizador->_pin = pin;

}

void temporizador_start(temporizador *temporizador) {
	temporizador->_tiempo_en_el_que_acaba_de_encenderse = HAL_GetTick();
	temporizador->_estado_temporizador = ENCENDIDO;
	HAL_GPIO_WritePin(temporizador->_puerto_pin, temporizador->_pin,
			GPIO_PIN_SET);
}

void temporizador_stop(temporizador *temporizador) {
	temporizador->_tiempo_en_el_que_acaba_de_apagarse = HAL_GetTick();
	;
	temporizador->_estado_temporizador = APAGADO;
	HAL_GPIO_WritePin(temporizador->_puerto_pin, temporizador->_pin,
			GPIO_PIN_RESET);
}

void temporizador_actualizar(temporizador *temporizador) {
	if (temporizador->_estado_temporizador == ENCENDIDO
			&& HAL_GetTick()
					- temporizador->_tiempo_en_el_que_acaba_de_encenderse
					>= temporizador->_tiempo_que_debe_estar_encendido) {
		temporizador_stop(temporizador);
	} else if (temporizador->_estado_temporizador == APAGADO
			&& HAL_GetTick() - temporizador->_tiempo_en_el_que_acaba_de_apagarse
					>= temporizador->_tiempo_que_debe_estar_apagado) {
		temporizador_start(temporizador);
	}
}
