/*
 * Planet.h
 *
 *  Created on: Nov 17, 2020
 *      Author: harel
 */

#ifndef PLANET_H_
#define PLANET_H_
#include "Defs.h"

typedef struct Planet_s{
	double location[3];
	char *name;

}planet;

planet* planetCreate(char *name , double x,double y , double z);
void printPlanet(planet *planet);
void destroyPlanet(planet *planet);





#endif /* PLANET_H_ */
