/*
 * funciones.h
 *
 *  Created on: 14 sep. 2021
 *      Author: Lauty
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_

/**
 * @fn float PedirOperando(float)
 * @brief esta funcion pide ingresar un dato y lo retorna
 *
 * @param numero, acumula el dato que se ingresa
 * @return retornar el numero ingresado para su utilizacion
 */
float PedirOperando(float numero);
/**
 * @fn float Sumar(float, float)
 * @brief esta funcion suma los dos float, que son ambos operandos.
 *
 * @param numero1 se usa para el primer operando (X)
 * @param numero2 se usa para el segundo operando (Y)
 * @return retorna la suma entre el numero1(x) y el numero2(y)
 */
float Sumar(float numero1, float numero2);
/**
 * @fn float Restar(float, float)
 * @brief esta funcion resta los float ingresados
 *
 * @param numero1 se usa para el primer operando (X)
 * @param numero2 se usa para el segundo operando (Y)
 * @return retorna la resta entre el numero 1(x) y el numero2(y)
 */
float Restar(float numero1, float numero2);
/**
 * @fn float Dividir(float, float)
 * @brief esta funcion hace que el primer float sea dividido por el segundo.
 *
 * @param numero1 se usa para el primer operando (X)
 * @param numero2 se usa para el segundo operando (Y)
 * @return retorna el resultado de la division entre ambos numeros.
 */
float Dividir(float numero1, float numero2);
/**
 * @fn float Multiplicar(float, float)
 * @brief esta funcion multiplica los float ingresados.
 *
 * @param numero1 se usa para el primer operando (X)
 * @param numero2 se usa para el segundo operando (Y)
 * @return retorna el producto entre ambos numeros.
 */
float Multiplicar(float numero1, float numero2);
/**
 * @fn float Factorial(float)
 * @brief esta funcion calcula el factorial de un numero.
 *
 * @param numero: esta parametro sirve para ingresar el primer o segundo operando individualmente.
 * @return retorna el resultado del factorial del numero ingresado.
 */
float Factorial(float numero);

#endif /* FUNCIONES_H_ */

