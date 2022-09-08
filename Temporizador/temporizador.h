/*
 * temporizador.h
 *
 *  Created on: Sep 8, 2022
 *      Author: Antonio
 */

#ifndef INC_TEMPORIZADOR_H_
#define INC_TEMPORIZADOR_H_

#include "stdint.h"
#include "stm32f4xx.h"


typedef enum ESTADO_TEMPORIZADOR {
	ENCENDIDO = 1,
	APAGADO = 0
}estado_temporizador;

typedef struct Temporizador {
	uint32_t _tiempo_en_el_que_acaba_de_encenderse;
	uint32_t _tiempo_en_el_que_acaba_de_apagarse;
	uint32_t _tiempo_que_debe_estar_encendido; // ms
	uint32_t _tiempo_que_debe_estar_apagado; //ms
	GPIO_TypeDef *_puerto_pin;
	uint16_t _pin;
	estado_temporizador _estado_temporizador;
} temporizador;

void temporizador_init(uint32_t tiempo_encendido, uint32_t tiempo_apagado,GPIO_TypeDef *puerto_pin, uint16_t pin,temporizador *temporizador);
void temporizador_start(temporizador *temporizador);
void temporizador_stop(temporizador *temporizador);
void temporizador_actualizar(temporizador *temporizador);

#endif /* INC_TEMPORIZADOR_H_ */
