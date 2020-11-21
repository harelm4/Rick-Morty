/*
 ============================================================================
 Name        : Rick&Morty.c
 Author      : harel
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Planet.h"
#include "Origin.h"
#include <stdbool.h>
#include "PhysicalCharacteristics.h"
#include "Jerry.h"

int main(int argc,char *argv[]) {
	int i;
	int isName;
	int numOfPlanets = atoi(argv[1]);
	int numOfJerrys = atoi(argv[2]);

	//creating planets jerrys array
	planet **planets =(planet **) malloc(sizeof(planet) * numOfPlanets );
	jerry **jerrys =(jerry **) malloc(sizeof(jerry) * numOfjerrys );
/*
	FILE *file;
	char inputRow[400];
	fgets(inputRow,400,file);
	for (i=0 ; i<intAgs[1];i++){//for each planet
		fgets(inputRow,400,file);

		for (i=0;i<4;i++){//for each planet argument
			isName = 0;
			while( strcmp(buf[i],",") ) {
				if (isName == 0){

				}
			}
	}


	}

*/
	 return argc;
}
