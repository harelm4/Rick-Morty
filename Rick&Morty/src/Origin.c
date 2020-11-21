/*
 * Origin.c
 *
 *  Created on: Nov 17, 2020
 *      Author: harel
 */
 #include  "Origin.h"
#include "Planet.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

origin* originCreate(planet *planet , char *dimension){
	origin *originP = (origin *) malloc(sizeof(origin));
	originP->dimension = (char *) malloc(sizeof (dimension));
	strcpy(originP->dimension,dimension);
	originP->planet = planet;
	return originP;
}
void destroyOrigin(origin *origin){
	free(origin->dimension);
	free(origin);
}
