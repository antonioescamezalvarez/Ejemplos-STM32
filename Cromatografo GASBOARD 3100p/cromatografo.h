/*
 * cromatografo.h
 *
 *  Created on: Feb 1, 2022
 *      Author: Antonio
 */

#ifndef INC_CROMATOGRAFO_H_
#define INC_CROMATOGRAFO_H_

#include "stdint.h"
struct datos_cromatografo{
	float CO;
	float CO2;
	float CH4;
	float CmHn;
	float H2;
	float O2;
	float LHV;
	float N2;
};

struct datos_cromatografo leer_cromatografo();

#endif /* INC_CROMATOGRAFO_H_ */
