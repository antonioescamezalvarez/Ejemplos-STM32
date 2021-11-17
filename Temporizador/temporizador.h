/*
 * temporizador.h
 *
 *  Created on: Nov 17, 2021
 *      Author: Antonio
 */

#ifndef INC_TEMPORIZADOR_H_
#define INC_TEMPORIZADOR_H_

#include "stdint.h"
#include "stm32f4xx.h"


typedef enum ESTADO_TEMPORIZADOR{
	DESHABILITADO = 0,
	HABILITADO = 1,
	ENCENDIDO = 1,
	APAGADO = 0
};

typedef struct {
	uint32_t _tiempo_en_el_que_acaba_de_encenderse; //Variable para la lógica interna
	uint32_t _tiempo_en_el_que_acaba_de_apagarse; //Variable para la lógica interna
	uint32_t _tiempo_encendido; //Tiempo que queremos que este encendido
	uint32_t _tiempo_apagado; //Tiempo que queremos que este apagado
	GPIO_TypeDef *_puerto_pin;
	uint16_t _pin;
	uint8_t _estado; //Variable para la lógica interna, guarda si el pin está encendido o apagado
	uint8_t _temporizador_habilitado; //Variable que habilita o deshabilita el temporizador
} temporizador;

void temporizador_init(uint32_t tiempo_encendido, uint32_t tiempo_apagado,GPIO_TypeDef *puerto_pin, uint16_t pin,temporizador *temporizador);
void temporizador_start(temporizador *temporizador);
void temporizador_stop(temporizador *temporizador);
void comprobar_temporizador(temporizador *temporizador);
#endif /* INC_TEMPORIZADOR_H_ */
