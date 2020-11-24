/*
 ============================================================================
 Name        : Rick&Morty.c
 Author      : harel
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */


#include "Jerry.h"

#include <stdio.h>
#include <math.h>

	//helpers:
	void upperString(char *s){
		int i=0;
		while(s[i]){
			if (s[i] >= 'a' && s[i]<='z'){
				s[i] = s[i] -32;
			}
		  i++;
	   }
	}


	//====================================================
	status PrintAllJerries(int numOfJerrys, jerry **jerrys) {
		for (int i = 0; i < numOfJerrys; i++) {
			printJerry(jerrys[i]);

		}
		return success;
	}
	status PrintAllPlanets(int numOfPlanets, planet **planets) {
		for (int i = 0; i < numOfPlanets; i++) {
			printPlanet(planets[i]);

		}
		return success;
	}


	status printJerryByPlanet(char *planetName,int numOfJerrys,jerry **jerrys){
		int i;
		int found = 0;
		for(i=0;i<numOfJerrys;i++){
			if (strcmp(jerrys[i]->planetP->name,planetName)==0){
				printJerry(jerrys[i]);
				found =1;
			}
		}

		upperString(planetName);
		if (found != 1){
			printf("RICK I NEVER HEARD ABOUT %s ! \n",planetName);
			return failure;
		}
		return success;
	}

	status printJerrybyPchar(jerry **jerrys,char *answer,int numOfJerrys){
		int i,j=0;
		int found = 0;
		for(i=0;i<numOfJerrys;i++){
			for(j=0;j<jerrys[i]->numOfChars;j++){
				if (strcmp(jerrys[i]->pChars[j].name,answer)==0){
						printJerry(jerrys[i]);
						found =1;
				}

			}
		}

		upperString(answer);
		if (found != 1){
			printf("OH NO! I DON'T KNOW ANY JERRY'S %s ! \n",answer);
			return failure;
		}
		return success;
	}
	jerry *searchJerry(int numOfJerries, jerry **jerrys, char *id) {
		int i;
		for (i = 0; i < numOfJerries; i++) {
			if (strcmp(id,jerrys[i]->ID) == 0) {
				return jerrys[i];
			}
		}
		return NULL;
	}


int main(int argc,char *argv[]) {
	int i,j;
	int numOfPlanets = atoi(argv[1]);
	int numOfJerrys = atoi(argv[2]);
	char *tmpPlanetName;
	char *tmpID=NULL,*tmpDimantionName, *tmpHappiness;
	char *tmpX,*tmpY,*tmpZ;
	planet *tmpPlanet=NULL;
	origin *tmpOrigin=NULL;
	//pChar tmpPchar;
	char *tmpPcharName=NULL;
	float tmpPcharValue;
	const char commaArr[2] = ",";
	char *token;
	int tmpHappinessInt;
	char *tmpPcharValueString;
	char *endfilecheck;



	//creating planets jerrys array
	planet **planets =(planet **) malloc(sizeof(planet) * numOfPlanets );
	if (planets == NULL)
		exit(1);
	jerry **jerrys =(jerry **) malloc(sizeof(jerry) * numOfJerrys );
	if (jerrys == NULL)
		exit(1);

	FILE *file;
	file = fopen(argv[3],"r");
	char inputRow[400];
	fgets(inputRow,400,file);//"planets"

	for (i=0 ; i<numOfPlanets;i++){//for each planet
		fgets(inputRow,400,file);
		token = strtok(inputRow,commaArr);
		tmpPlanetName = token;
		token = strtok(NULL,commaArr);
		tmpX = token;
		token = strtok(NULL,commaArr);
		tmpY = token;
		token = strtok(NULL,commaArr);
		tmpZ = token;
		float x = atof(tmpX);
		float y = atof(tmpY);
		float z = atof(tmpZ);

		planets[i] = planetCreate(tmpPlanetName,x,y,z);
	}
	fgets(inputRow,400,file);//"Jerries"
	fgets(inputRow,400,file); // First Jerry
	for (j=0 ; j<numOfJerrys;j++){//for each Jerry
			token = strtok(inputRow,commaArr);
			tmpID= token;
			token = strtok(NULL,commaArr);
			tmpDimantionName = token;
			token = strtok(NULL,commaArr);
			tmpPlanetName = token;
			token = strtok(NULL,commaArr);
			tmpHappiness = token;
			tmpHappinessInt = atoi(tmpHappiness);
			//searching for planet and assigning him for tmpPlanet:
			for (i=0;i<numOfPlanets;i++){
				if (strcmp(planets[i]->name,tmpPlanetName) == 0){
					tmpPlanet= planets[i];
					break;
				}
			}
			tmpOrigin=originCreate(tmpPlanet,tmpDimantionName);

			jerrys[j] = jerryCreate(tmpID , tmpHappinessInt , tmpPlanet,tmpOrigin);
			//assigning pChars
			fgets(inputRow,400,file);//first pChar or next jerry if there is no pChar
			while ('\t'==(char)inputRow[0]){
				tmpPcharName = strtok(inputRow,"\t:\n");
				tmpPcharValueString = strtok(NULL,"\t:\n");
				tmpPcharValue = atof(tmpPcharValueString);
				addChar(jerrys[j],charsCreate(tmpPcharName,tmpPcharValue));
				endfilecheck = fgets(inputRow,400,file);
				if (endfilecheck == NULL)
					break;
			}



	}
	fclose(file);
	int choice = 0;
	float pCharValueToAdd = 0;
	char answer[400];
	char ID[400], pCharName[400], pCharNameUpperCase[400];
	jerry *jerry;
	int isScanOk;
	char c[300];


	while (choice != 7) {
		begin_loop:{
		printf("AW JEEZ RICK, what do you want to do now ? \n");
		printf("1 : Print all Jerries \n");
		printf("2 : Print all Planets \n");
		printf("3 : Add physical characteristic to Jerry \n");
		printf("4 : Remove physical characteristic from Jerry \n");
		printf("5 : Print Jerries by a planet \n");
		printf("6 : Print Jerries by a physical characteristic \n");
		printf("7 : Go home \n");
	}
		isScanOk = scanf("%d",&choice);
		if(isScanOk != 1 ){
			printf("RICK WE DON'T HAVE TIME FOR YOUR GAMES ! \n");
			scanf("%s",c);
			goto begin_loop;
		}
		if (choice>7 || choice<1){
			printf("RICK WE DON'T HAVE TIME FOR YOUR GAMES ! \n");
			choice = 0 ;
			goto begin_loop;
		}
		switch (choice)
		{
			case 1: // Print all Jerrys
				PrintAllJerries(numOfJerrys,jerrys);
				break;
			case 2: // Print all Planets
				PrintAllPlanets(numOfPlanets,planets);
				break;
			case 3: // Add physical characteristic to Jerry-SAAR IS WORKING ON IT
				printf("What is your Jerry's ID ? \n");
				scanf("%s",ID);
				jerry = searchJerry(numOfJerrys,jerrys,ID);
				if (NULL == jerry)
					printf("OH NO! I CAN'T FIND HIM RICK ! \n");
				else {
					printf("What physical characteristic can you add to Jerry - %s ? \n",ID);
					scanf("%s",pCharName);
					strcpy(pCharNameUpperCase,pCharName);
					upperString(pCharNameUpperCase);

					if (isCharExist(jerry,pCharName))
						printf("RICK I ALREADY KNOW HIS %s ! \n",pCharNameUpperCase);
					else {
						printf("What is the value of his %s ? \n",pCharName);
						scanf("%f",&pCharValueToAdd);
						addChar(jerry,charsCreate(pCharName,pCharValueToAdd)); //creating new char and adding to the jerry
						printJerry(jerry);
					}
				}

				break;
			case 4: // Remove physical characteristic from Jerry
				printf("What is your Jerry's ID ? \n");
				scanf("%s",ID);
				jerry = searchJerry(numOfJerrys,jerrys,ID);
				if (NULL == jerry)
					printf("OH NO! I CAN'T FIND HIM RICK ! \n");
				else {
					printf("What physical characteristic do you want to remove from Jerry - %s ? \n",ID);
					scanf("%s",pCharName);
					strcpy(pCharNameUpperCase,pCharName);
					upperString(pCharNameUpperCase);

					if (isCharExist(jerry,pCharName)){
						delChar(jerry,pCharName);
						printJerry(jerry);
					}
					else {
						printf("RICK I DON'T KNOW HIS %s ! \n",pCharNameUpperCase);
						}

				}
				break;


			case 5: // print jerrys by planet name and prints
				printf("What planet is your Jerry from ? \n");
				scanf("%s",answer);
				printJerryByPlanet(answer,numOfJerrys,jerrys);

				break;
			case 6: // Print Jerries by a physical characteristic
				printf("What do you know about your Jerry ? \n");
				scanf("%s",answer);
				printJerrybyPchar(jerrys,answer,numOfJerrys);
				break;
			case 7:
				for (i=0;i<numOfJerrys;i++){
					destroyJerry(jerrys[i]);
				}
				free(jerrys);


				for (i=0;i<numOfPlanets;i++){
					destroyPlanet(planets[i]);
				}
				free(planets);
				printf("AW JEEZ RICK, ALL THE JERRIES GOT FREE ! ");
				exit(1);

		}
	}

	 return argc;
}

