/*
 * bmv700.h
 *
 *  Created on: Sep 18, 2021
 *      Author: Antonio Escamez Alvarez
 */

#ifndef INC_BMV700_H_
#define INC_BMV700_H_

#include "stdint.h"

struct datos_bmv700 {
	char bateria[4];
};

struct datos_bmv700 leer_sensor_bmv700();

#endif /* INC_BMV700_H_ */
