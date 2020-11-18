/*
 * Jerry.h
 *
 *  Created on: Nov 17, 2020
 *      Author: harel
 */

#ifndef JERRY_H_
#define JERRY_H_
#include "Planet.h"
#include "Origin.h"
#include <stdbool.h>
#include "PhysicalCharacteristics.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct jerry_s{
	char *ID;
	int happiness;
	planet *planetP;
	pChar *pChars;
	int numOfChars;
	origin *originP;


}jerry;

jerry jerryCreate(char *ID , int happiness , planet *planetP,origin *originP);
bool isCharExist(jerry jerryArg,char *charName);
void addChar(jerry jerryArg,pChar Char);
bool delChar(jerry jerryArg, char *nameOfChar);
void printJerry(jerry jerryArg);



#endif /* JERRY_H_ */
