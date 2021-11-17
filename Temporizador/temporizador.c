/*
 * temporizador.c
 *
 *  Created on: Nov 17, 2021
 *      Author: Antonio
 */
#include "temporizador.h"

void temporizador_init(uint32_t tiempo_encendido, uint32_t tiempo_apagado,GPIO_TypeDef *puerto_pin, uint16_t pin, temporizador *temporizador){
	temporizador->_tiempo_encendido = tiempo_encendido;
	temporizador->_tiempo_apagado = tiempo_apagado;
	temporizador->_puerto_pin = puerto_pin;
	temporizador->_pin = pin;
	temporizador->_estado = 0;
	temporizador->_tiempo_en_el_que_acaba_de_apagarse = 0;
	temporizador->_tiempo_en_el_que_acaba_de_encenderse = 0;
	temporizador->_temporizador_habilitado = 0;
}
void temporizador_start(temporizador *temporizador){
	temporizador->_temporizador_habilitado = HABILITADO;
}
void temporizador_stop(temporizador *temporizador){
	temporizador->_temporizador_habilitado = DESHABILITADO;
}

void comprobar_temporizador(temporizador *temporizador){
	if ( temporizador->_temporizador_habilitado == HABILITADO){
		if(temporizador->_estado == ENCENDIDO){
			if(HAL_GetTick() - temporizador->_tiempo_en_el_que_acaba_de_encenderse >= temporizador->_tiempo_encendido){
				HAL_GPIO_WritePin(temporizador->_puerto_pin, temporizador->_pin, APAGADO);
				temporizador->_estado = APAGADO;
				temporizador->_tiempo_en_el_que_acaba_de_apagarse = HAL_GetTick();
			}
		}else if (temporizador->_estado == APAGADO){
			if(HAL_GetTick() - temporizador->_tiempo_en_el_que_acaba_de_apagarse >= temporizador->_tiempo_apagado){
				HAL_GPIO_WritePin(temporizador->_puerto_pin, temporizador->_pin, ENCENDIDO);
				temporizador->_estado = ENCENDIDO;
				temporizador->_tiempo_en_el_que_acaba_de_encenderse = HAL_GetTick();
			}
		}
	}
}


