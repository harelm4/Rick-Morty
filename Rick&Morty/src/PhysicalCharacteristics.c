/*
 * PhysicalCharacteristics.c
 *
 *  Created on: Nov 17, 2020
 *      Author: harel
 */

#include "Planet.h"
#include "PhysicalCharacteristics.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

pChar charsCreate(char *name,float value){
	pChar pChar;
	pChar.name = name;
	pChar.value = value;
	return pChar;


}
