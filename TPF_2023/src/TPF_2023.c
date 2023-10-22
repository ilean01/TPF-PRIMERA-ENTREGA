/*
 ============================================================================
 Name        : TPF_2023.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "inicializaciones.h"


int main(void)
{
	inicio();
	inic();

	eleccion1(&eleccion);//eleccion de jugar contra maquina o un amigo
	eleccioncolor(&eleccion2);//eleccion del color del jugador 1
	// Llamar a la función para inicializar la matriz
	inicializarMatriz(matriznum,matrizlet);
	juego(eleccion, &eleccion2, matriznum, matrizlet);
	printf(YELLOW"Presiona Enter para continuar..."RESET); // Muestra un mensaje en color y espera a que el usuario presione Enter.
	while (getchar() != '\n'); // Espera a que se presione Enter.
    return 0;
}
