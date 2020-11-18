/*
 * Origin.h
 *
 *  Created on: Nov 17, 2020
 *      Author: harel
 */

#ifndef ORIGIN_H_
#define ORIGIN_H_
#include "Planet.h"

typedef struct origin_s{
	planet planet;
	char *dimension;
}origin;

origin* originCreate(planet planet , char *dimension);
void destroyOrigin(origin *origin);

#endif /* ORIGIN_H_ */
