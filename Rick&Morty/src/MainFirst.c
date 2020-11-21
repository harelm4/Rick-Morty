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
#include <ctype.h>

#include "Planet.h"
#include "Origin.h"
#include <stdbool.h>
#include "PhysicalCharacteristics.h"
#include "Jerry.h"

	//helpers:
	void upperString(char *s){
		int i=0;
		while(s[i]){
		  putchar(toupper(s[i]));
		  i++;
	   }
	}
	//====================================================
	void PrintAllJerries(int numOfJerrys, jerry **jerrys) {
		for (int i = 0; i < numOfJerrys; i++) {
			printJerry(jerrys[i]);
		}
	}
	void PrintAllPlanets(int numOfPlanets, planet **planets) {
		for (int i = 0; i < numOfPlanets; i++) {
			printPlanet(planets[i]);
		}
	}


	void printJerryByPlanet(char *planetName,int numOfJerrys,jerry **jerrys){
		int i;
		int found = 0;
		for(i=0;i<numOfJerrys;i++){
			if (strcmp(jerrys[i]->planetP->name,planetName)){
				printJerry(jerrys[i]);
				found =1;
			}
		}

		upperString(planetName);
		if (found != 1){
			printf("RICK I NEVER HEARD ABOUT %s ! ",planetName);
		}
	}

	void printJerrybyPchar(jerry **jerrys,char *answer,int numOfJerrys){
		int i,j=0;
		int found = 0;
		for(i=0;i<numOfJerrys;i++){
			for(j=0;j<jerrys[i]->numOfChars;j++){
				if (strcmp(jerrys[i]->pChars[j].name,answer)){
						printJerry(jerrys[i]);
						found =1;
				}

			}
		}

		upperString(answer);
		if (found != 1){
			printf("OH NO! I DON'T KNOW ANY JERRY'S %s !",answer);
		}
	}


int main(int argc,char *argv[]) {
	int i;
	int numOfPlanets = atoi(argv[1]);
	int numOfJerrys = atoi(argv[2]);
	char *tmpPlanetName=NULL;
	char *tmpID=NULL,*tmpDimantionName=NULL;int tmpHappiness;
	float tmpX,tmpY,tmpZ;
	planet *tmpPlanet=NULL;
	origin *tmpOrigin=NULL;
	pChar tmpPchar;
	char *tmpPcharName=NULL;
	float tmpPcharValue;



	//creating planets jerrys array
	planet **planets =(planet **) malloc(sizeof(planet) * numOfPlanets );
	jerry **jerrys =(jerry **) malloc(sizeof(jerry) * numOfJerrys );

	FILE *file;
	file = fopen(argv[3],"r");
	char inputRow[400];
	fgets(inputRow,400,file);//"planets"

	for (i=0 ; i<numOfPlanets;i++){//for each planet
		fgets(inputRow,400,file);
		sscanf(inputRow,"%s,%f,%f,%f",tmpPlanetName,&tmpX,&tmpY,&tmpZ);
		planets[i] = planetCreate(tmpPlanetName,tmpX,tmpY,tmpZ);
	}

	fgets(inputRow,400,file);//"Jerries"
	for (i=0 ; i<numOfJerrys;i++){//for each Jerry
			fgets(inputRow,400,file);
			sscanf(inputRow,"%s,%s,%s,%d",tmpID,tmpDimantionName,tmpPlanetName,&tmpHappiness);
			//searching for planet and assigning him for tmpPlanet:
			for (i=0;i<numOfPlanets;i++){
				if (strcmp(planets[i]->name,tmpPlanetName)){
					tmpPlanet= planets[i];
				}
			}
			tmpOrigin->dimension = tmpDimantionName;
			tmpOrigin->planet = tmpPlanet;

			jerrys[i] = jerryCreate(tmpID , tmpHappiness , tmpPlanet,tmpOrigin);
			//assigning pChars
			fgets(inputRow,400,file);//first pChar
			while ('\t'==(char)inputRow[0]){
				sscanf(inputRow,"	%s:%f",tmpPcharName,&tmpPcharValue);
				tmpPchar.name = tmpPcharName;
				tmpPchar.value = tmpPcharValue;
				addChar(jerrys[i],tmpPchar);
				fgets(inputRow,400,file);
			}


	}

	int choice = 0;
	char *ID=NULL;
	char *answer=NULL;
	while (choice != 7) {
		printf("AW JEEZ RICK, what do you want to do now ?\n");
		printf("1 : Print all Jerries\n");
		printf("2 : Print all Planets\n");
		printf("3 : Add physical characteristic to Jerry\n");
		printf("4 : Remove physical characteristic from Jerry\n");
		printf("5 : Print Jerries by a planet\n");
		printf("6 : Print Jerries by a physical characteristic\n");
		printf("7 : Go home\n");
		scanf("%d",&answer);
		switch (choice)
		{
			case 1: // Print all Jerrys
				PrintAllJerries(numOfJerrys,jerrys);
				break;
			case 2: // Print all Planets
				PrintAllPlanets(numOfPlanets,planets);
				break;
			case 3: // Add physical characteristic to Jerry-SAAR IS WORKING ON IT
				printf("What is your Jerry's ID ?");
				scanf("%s",answer);
				break;
			case 5: // print jerrys by planet name and prints
				printf("What planet is your Jerry from ?\n");
				scanf("%s",answer);
				printJerryByPlanet(answer,numOfJerrys,jerrys);

				break;
			case 4: // Remove physical characteristic from Jerry
			case 6: // Print Jerries by a physical characteristic
				printf("What do you know about your Jerry ? ");
				scanf("%s",answer);
				printJerrybyPchar(jerrys,answer,numOfJerrys);
				break;

		}
	}
	//add functions here to delete all created objects in case of exit

	 return argc;
}

