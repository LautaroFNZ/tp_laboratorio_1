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
#include <ctype.h>


int GetInt(char *msj);
float GetFloat(char *msj);
void GetString(char *msj, char value[]);
char GetChar(char *msj);

int get_StringLetters(char* message, char* value,char* messageError);
int get_Stringnumber(char* message, char* value,char* messageError);

int isNaN(char* value);

#endif /* INPUTS_H_ */
