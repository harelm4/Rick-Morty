/*
 * Origin.c
 *
 *  Created on: Nov 17, 2020
 *      Author: harel
 */
 #include  "Origin.h"
#include "Planet.h"
#include <stdio.h>

origin* originCreate(planet planet , char *dimension){
	origin *originP = NULL;
	originP->dimension = dimension;
	originP->planet = planet;
	return originP;
}
void destroyOrigin(origin *origin){
	free(origin->dimension);
	free(origin);
}
