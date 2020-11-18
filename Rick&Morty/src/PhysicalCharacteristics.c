/*
 * PhysicalCharacteristics.c
 *
 *  Created on: Nov 17, 2020
 *      Author: harel
 */

#include "Planet.h"
#include "PhysicalCharacteristics.h"

pChar charsCreate(char *name,float value){
	pChar pChar;
	pChar.name = name;
	pChar.value = value;
	return pChar;


}
