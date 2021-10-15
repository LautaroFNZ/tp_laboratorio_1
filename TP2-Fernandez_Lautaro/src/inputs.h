/*
 * inputs.h
 *
 *  Created on: 12 oct. 2021
 *      Author: Lautaro
 */

#ifndef INPUTS_H_
#define INPUTS_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int GetInt(char *msj);
float GetFloat(char *msj);
void GetString(char *msj, char value[]);
char GetChar(char *msj);


#endif /* INPUTS_H_ */
