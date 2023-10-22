
/*
 * inicializacion.h
 *
 *  Created on: 6 oct. 2023
 *      Author: lp1-2023
 */
#ifndef INICIALIZACIONES_H_
#define INICIALIZACIONES_H_

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define GREEN   "\033[32m"
#define MARRON  "\033[33m"
#define CYAN    "\033[36m"
#define PURPURA "\033[35m"

#define BOLD    "\033[1m"
#define Cursiva "\033[3m"
#define Subrayado "\033[4m"
#define PARPADEO "\x1b[5m"

extern int eleccion;     // Declarar extern para usar en otros archivos
extern int eleccion2;    // Declarar extern para usar en otros archivos
extern int matriznum[5][5];   // Declarar extern para usar en otros archivos
extern char matrizlet[5][5];  // Declarar extern para usar en otros archivos

void inicio();
void inic();
void eleccion1(int *eleccion);
void eleccioncolor(int *eleccion2);
void inicializarMatriz(int matriznum[5][5], char matrizlet[5][5]);
void imprimirjuego(int matriznum[5][5], char matrizlet[5][5], int *eleccion2);
void trofeo();
void ganadorX();
void ganadorO();
void empate();
int juego(int eleccion, int *eleccion2, int matriznum[5][5], char matrizlet[5][5]);
#endif /* INICIALIZACIONES_H_ */
