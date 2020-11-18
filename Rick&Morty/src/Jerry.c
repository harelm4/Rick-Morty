/*
 * Jerry.c
 *
 *  Created on: Nov 17, 2020
 *      Author: harel
 */
#include "Planet.h"
#include "Origin.h"
#include "PhysicalCharacteristics.h"
#include "Jerry.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


jerry jerryCreate(char *ID , int happiness , planet *planet,origin *origin){
	jerry jerry;
	jerry.ID = ID;
	jerry.happiness = happiness;
	jerry.planetP = planet;
	jerry.numOfChars = 0;
	jerry.pChars = NULL;
	jerry.originP = origin;

	return jerry;
}

bool isCharExist(jerry jerryArg,char *charName){
	int i;
	jerry jerry = jerryArg;
	char *name = charName;
	if (jerry.pChars != NULL){
		for (i=0;i<jerry.numOfChars;i++){
			if ( strcmp( name,jerry.pChars[i].name ) ){
				return true;
			}
		}

	}

		return false;
}

void addChar(jerry jerryArg,pChar Char){
	jerry jerry = jerryArg;
	jerry.numOfChars++;
	char *charsP = NULL ;
	int i;
	pChar *tmpP = NULL;


	if (jerry.pChars == NULL){
		jerry.pChars =(pChar *) malloc(sizeof(pChar));//allocating designated memory for physical char
		jerry.pChars[0].name =(char *) malloc(sizeof(Char.name));//allocating heap memory for the characteristic name
		jerry.pChars[0].value = Char.value;
		strcpy(jerry.pChars[0].name,Char.name);
	}
	else{
		tmpP = (pChar *) malloc(jerry.numOfChars * sizeof(pChar));//allocating designated memory for names pointer array

		//copy all existing names to temp array of pChars
		for (i=0;i<jerry.numOfChars-1;i++){
			tmpP[i].name = (char *) malloc(sizeof(jerry.pChars[i].name));
			tmpP[i].value = jerry.pChars[i].value;
			strcpy(tmpP[i].name,jerry.pChars[i].name);
		}
		tmpP[jerry.numOfChars-1].name = (char *) malloc(sizeof(Char.name));
		//copy new pChar to tmp array
		strcpy(tmpP[jerry.numOfChars-1].name,Char.name);
		tmpP[jerry.numOfChars-1].value = Char.value;

		//freeing all copied names from existing characteristics name array
		for (i=0;i<jerry.numOfChars-1;i++){
			free(jerry.pChars[i].name);
			}
		free(jerry.pChars);//freeing original pointer
		jerry.pChars = tmpP;
	}


}

bool delChar (jerry jerryArg, char *nameOfChar){
	jerry jerry = jerryArg;
	char *name = nameOfChar;
	int i,j,k=0;
	pChar *tmpP = NULL;
	char *charsP = NULL ;
	bool isDeleted = false;

	if (jerry.pChars == NULL){
		printf("Couldn't delete,there are no characteristics in this Jerry\n");
		return false;
	}
	for (i=0;i<jerry.numOfChars;i++){
		if ( strcmp(jerry.pChars[i].name, name) ){
			isDeleted = true;
			jerry.numOfChars--;
			tmpP = (pChar *) malloc(jerry.numOfChars * sizeof(pChar));//allocating designated memory for names pointer array

			//copy all existing names to temp array of pointers
			for (j=0;j<jerry.numOfChars;j++){
				//this condition prevents from the name that we want to delete to get in the temp array
				if (j==i){
					continue;
				}
				tmpP[k].name = (char *) malloc(sizeof(name));
				strcpy(tmpP[k].name,jerry.pChars[j].name);
				tmpP[k].value = jerry.pChars[j].value;
				k++;
			}
			//freeing all copied names from existing characteristics name array
			for (i=0;i<jerry.numOfChars+1;i++){
				free(jerry.pChars[i].name);
			}
			free(jerry.pChars);//freeing original pointer
			jerry.pChars = tmpP;
			break;


		}



	}
	return isDeleted;
}

void printJerry(jerry jerryArg){
	jerry jerry=jerryArg;

	printf("Jerry , ID - %s : \n",jerry.ID);
	printf("Happiness level : %d \n",jerry.happiness);
	printf("Origin : %s \n",jerry.originP->dimension);
	printf("Planet : %s ",jerry.planetP->name);
	printPlanet(jerry.planetP);
	printf("Jerry's physical Characteristics available : \n");
	printf("\tHeight : 166.20 , LimbsNumber : 4.00 SS, Weight : 80.00");



}











