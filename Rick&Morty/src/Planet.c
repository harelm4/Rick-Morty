/*
 * Planet.c
 *
 *  Created on: Nov 17, 2020
 *      Author: harel
 */

#include "Planet.h"
#include "Defs.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

planet* planetCreate(char *name , double x,double y , double z){
	planet *planetP = (planet *) malloc( sizeof(planet) );
	planetP->name= (char *)malloc(sizeof(name));
	strcpy(planetP->name,name);
	planetP->location[0] = x;
	planetP->location[1] = y;
	planetP->location[2] = z;
	return planetP;
}

void printPlanet(planet *planetP){
	printf("Planet : %s (%.2f,%.2f,%.2f) \n",planetP->name,planetP->location[0],planetP->location[1],planetP->location[2]);
}

void destroyPlanet(planet *planetP){

		free(planetP->name);
		free(planetP);


}
