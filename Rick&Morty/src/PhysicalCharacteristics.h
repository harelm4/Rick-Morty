/*
 * PhysicalCharacteristics.h
 *
 *  Created on: Nov 17, 2020
 *      Author: harel
 */

#ifndef PHYSICALCHARACTERISTICS_H_
#define PHYSICALCHARACTERISTICS_H_

typedef struct char_struct{
	char *name;
	float value;

}pChar;

pChar charsCreate(char *name,float value);


#endif /* PHYSICALCHARACTERISTICS_H_ */
