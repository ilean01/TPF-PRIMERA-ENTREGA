/*
 * inicializacion.c
 *
 *  Created on: 6 oct. 2023
 *      Author: lp1-2023
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "inicializaciones.h"

int eleccion;      // Definir la variable eleccion
int eleccion2;     // Definir la variable eleccion2
int matriznum[5][5];

char matrizlet[5][5];


void inicio(){
	printf("+----------------------------------------------------------------------------------------------+\n");
	    printf("\t ██████╗ ██╗███████╗███╗   ██╗██╗   ██╗███████╗███╗   ██╗██╗██████╗  ██████╗       \n");
	    printf("\t ██╔══██╗██║██╔════╝████╗  ██║██║   ██║██╔════╝████╗  ██║██║██╔══██╗██╔═══██╗      \n");
	    printf("\t ██████╔╝██║█████╗  ██╔██╗ ██║██║   ██║█████╗  ██╔██╗ ██║██║██║  ██║██║   ██║      \n");
	    printf("\t ██╔══██╗██║██╔══╝  ██║╚██╗██║╚██╗ ██╔╝██╔══╝  ██║╚██╗██║██║██║  ██║██║   ██║      \n");
	    printf("\t ██████╔╝██║███████╗██║ ╚████║ ╚████╔╝ ███████╗██║ ╚████║██║██████╔╝╚██████╔╝      \n");
	    printf("\t ╚═════╝ ╚═╝╚══════╝╚═╝  ╚═══╝  ╚═══╝  ╚══════╝╚═╝  ╚═══╝╚═╝╚═════╝  ╚═════╝      \n");
	    printf("\t\t\t\t\t █████╗                                                                           \n");
	    printf("\t\t\t\t\t██╔══██╗                                                                          \n");
	    printf("\t\t\t\t\t███████║                                                                          \n");
	    printf("\t\t\t\t\t██╔══██║                                                                          \n");
	    printf("\t\t\t\t\t██║  ██║                                                                          \n");
	    printf("\t\t\t\t\t╚═╝  ╚═╝                                                                          \n");
	    printf("\t ██████╗███████╗██████╗ ██╗  ██╗ █████╗ ██╗      ██████╗ ██████╗  ██████╗ ██████╗ \n");
	    printf("\t██╔════╝██╔════╝██╔══██╗██║  ██║██╔══██╗██║     ██╔═══██╗██╔══██╗██╔═══██╗██╔══██╗\n");
	    printf("\t██║     █████╗  ██████╔╝███████║███████║██║     ██║   ██║██████╔╝██║   ██║██║  ██║\n");
	    printf("\t██║     ██╔══╝  ██╔═══╝ ██╔══██║██╔══██║██║     ██║   ██║██╔═══╝ ██║   ██║██║  ██║\n");
	    printf("\t╚██████╗███████╗██║     ██║  ██║██║  ██║███████╗╚██████╔╝██║     ╚██████╔╝██████╔╝\n");
	    printf("\t ╚═════╝╚══════╝╚═╝     ╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝ ╚═════╝ ╚═╝      ╚═════╝ ╚═════╝ \n");
	    printf("+----------------------------------------------------------------------------------------------+\n");

	    // Esperar a que el usuario presione Enter
	    printf(GREEN"Presiona Enter para continuar..."RESET);
	    while (getchar() != '\n');


	    printf("\r");
	    printf("\033[H\033[J");
	    printf("\033[H\033[J");
	    // Imprimir las reglas del juego en colores
	    printf("\t\t\t██████╗ ███████╗ ██████╗ ██╗      █████╗ ███████╗\n");
	    printf("\t\t\t██╔══██╗██╔════╝██╔════╝ ██║     ██╔══██╗██╔════╝\n");
	    printf("\t\t\t██████╔╝█████╗  ██║  ███╗██║     ███████║███████╗\n");
	    printf("\t\t\t██╔══██╗██╔══╝  ██║   ██║██║     ██╔══██║╚════██║\n");
	    printf("\t\t\t██║  ██║███████╗╚██████╔╝███████╗██║  ██║███████║\n");
	    printf("\t\t\t╚═╝  ╚═╝╚══════╝ ╚═════╝ ╚══════╝╚═╝  ╚═╝╚══════╝\n");
	    printf(YELLOW"\t\t\tCephalopod "RESET);
	    printf("es un juego para dos jugadores que emplea un tablero de ");
	    printf(YELLOW"5x5,\n"RESET);
	    printf("\n\n");
	    printf(GREEN BOLD"-COLOCACIÓN BÁSICA:" RESET);
	    printf("\t\tLos jugadores se turnan para añadir dados de su propio color al tablero,\n");
	    printf("\t\t\tun dado por turno. Un dado recién colocado debe mostrar un uno, a menos que sea un dado de captura.\n");
	    printf("\n\n");
	    printf(GREEN BOLD "-OBJETIVO DEL JUEGO:" RESET);
	    printf("\t\tUna vez lleno completamente el tablero, el jugador\n");
	    printf("\t\t\tcuyos dados ocupen la mayoría de las casillas, gana. No pueden producirse empates en\n");
	    printf(YELLOW"\t\t\t\tCefalópodo.\n"RESET);
	    printf("\n\n");
	    printf(GREEN BOLD "-CAPTURA DE COLOCACIÓN:" RESET);
	    printf(" Si un dado se coloca horizontal o verticalmente adyacente\n");
	    printf("\t\t\ta dos dados, y la suma de los puntos (número de puntos ");
	    printf("en la superficie superior de un dado)\n\t\t\ty esos dos dados adyacentes es seis o menos, entonces el\n");
	    printf("\t\t\tdado actualmente jugado debe mostrar la suma de sus dos dados adyacentes.\n");
	    printf("\n\n");
	    printf(GREEN BOLD "-COLOCACIÓN SIN CAPTURA:" RESET);
	    printf("Un jugador puede realizar una colocación sin captura.\n");
	    printf("\t\t\tsimplemente añadiendo un dado a un cuadrado del que no es posible realizar capturas. A\n");
	    printf("\t\t\tla colocación sin captura debe mostrar solo un 1.\n");
	    printf("\n");
	    printf(GREEN"Presiona Enter para continuar..."RESET);
	    while (getchar() != '\n');
	    printf("\n\n");


}

// Función para recibir la elección de jugar con la máquina o con un amigo
void eleccion1(int *e) {
    int n;
    printf(BOLD"\nIntroduzca [1] si desea jugar con la máquina \nIntroduzca [2] si desea jugar con un amigo: "RESET);
    scanf("%d", &n);
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    while (n != 1 && n != 2) {
        printf("\nERROR: introduzca [1] si desea jugar con la máquina\nIntroduzca [2] si desea jugar con un amigo:\n ");
        scanf("%d", &n);
        while ((c = getchar()) != '\n' && c != EOF);
    }

    *e = n;

}

// Función para recibir la elección del color (rojo o verde) del jugador 1
void eleccioncolor(int *e) {
    int n=0;

    printf(BOLD"\nJUGADOR 1: Introduzca el color con el que desea jugar ([1] para rojo; [2] para verde):\n "RESET);
    scanf("%d",&n);
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    while (n!=1 && n!=2){
    	printf("ERROR, JUGADOR 1: Introduzca el color con el que desea jugar ([1] para rojo; [2] para verde):\n ");
    	scanf("%d",&n);
    	while ((c = getchar()) != '\n' && c != EOF);
    }

    *e = n;

}
// Función para inicializar una matriz de números con un valor inicial.
void inicializarMatriz(int matriznum[5][5],char matrizlet[5][5]){
	for (int i = 0; i < 5; i++){
		for (int j = 0; j < 5; j++) {
            matriznum[i][j] = 0;
            matrizlet[i][j]=' ';
        }
    }
}
void imprimirjuego(int matriznum[5][5], char matrizlet[5][5], int *eleccion2) {


    printf("      1         2        3        4        5\n");
    printf("   ┌────────┬────────┬────────┬────────┬────────┐\n");

    for (int i = 0; i < 5; i++) {
        printf("%c", 'A' + i);
        for (int x = 0; x < 3; x++) {
        	if (x == 0) {
        	printf("  │ " );}
        	else{
            	printf("   │ ");}
            for (int j = 0; j < 5; j++) {
            	if (matrizlet[i][j] == 'x') {
            		printf(RED);
            	} else if (matrizlet[i][j] == 'o') {
            		printf(GREEN);
            	}


                    if (matriznum[i][j] == 1) {
                        if (x == 0) {
                            printf("       ");
                        }
                        if (x == 1) {
                            printf("   %c   ", matrizlet[i][j]);
                        }
                        if (x == 2) {
                            printf("       ");
                        }
                        printf(RESET);
                        printf("│ ");
                    } else if (matriznum[i][j] == 2) {
                        if (x == 0) {
                            printf("       ");
                        }
                        if (x == 1) {
                            printf(" %c   %c ", matrizlet[i][j], matrizlet[i][j]);
                        }
                        if (x == 2) {
                            printf("       ");
                        }
                        printf(RESET);
                        printf("│ ");

                    } else if (matriznum[i][j] == 3) {
                        if (x == 0) {
                            printf(" %c     ", matrizlet[i][j]);
                        }
                        if (x == 1) {
                            printf("   %c   ", matrizlet[i][j]);
                        }
                        if (x == 2) {
                            printf("     %c ", matrizlet[i][j]);
                        }
                        printf(RESET);
                        printf("│ ");
                    } else if (matriznum[i][j] == 4) {
                        if (x == 0) {
                            printf(" %c   %c ", matrizlet[i][j], matrizlet[i][j]);
                        }
                        if (x == 1) {
                            printf("       ");
                        }
                        if (x == 2) {
                            printf(" %c   %c ", matrizlet[i][j], matrizlet[i][j]);
                        }
                        printf(RESET);
                        printf("│ ");
                    } else if (matriznum[i][j] == 5) {
                        if (x == 0) {
                            printf(" %c   %c ", matrizlet[i][j], matrizlet[i][j]);
                        }
                        if (x == 1) {
                            printf("   %c   ", matrizlet[i][j]);
                        }
                        if (x == 2) {
                            printf(" %c   %c ", matrizlet[i][j], matrizlet[i][j]);
                        }
                        printf(RESET);
                        printf("│ ");
                    } else if (matriznum[i][j] == 6) {
                        if (x == 0) {
                            printf(" %c   %c ", matrizlet[i][j], matrizlet[i][j]);
                        }
                        if (x == 1) {
                            printf(" %c   %c ", matrizlet[i][j], matrizlet[i][j]);
                        }
                        if (x == 2) {
                            printf(" %c   %c ", matrizlet[i][j], matrizlet[i][j]);
                        }
                        printf(RESET);
                        printf("│ ");

                    }
                    else{
                    	printf(RESET);
                    	if (x == 0) {
                    	   printf("       ");}
                    	if (x == 1) {
                    	 printf("       ");
                    	                        }
                    	if (x == 2) {
                    	   printf("       ");}

                    	      printf("│ ");


                    }
                    printf(RESET);
                }
            printf("\n");
            }

        if (i < 4) {
            printf("   ├────────┼────────┼────────┼────────┼────────┤\n");
        } else {
            printf("   └────────┴────────┴────────┴────────┴────────┘\n");
        }
    }


}
void trofeo(){
	printf(YELLOW); // Cambia el color de texto a rojo
	    printf("\t\t     ██████                              ███████     \n");
	    printf("\t\t     ████████████                   ████████████     \n");
	    printf("\t\t     ███████████████████████████████████████ ███     \n");
	    printf("\t\t     ████   █████████████████████████████    ███     \n");
	    printf("\t\t     ████   ████████████████████████████    ████     \n");
	    printf("\t\t     ████     █████████████████████████     ████     \n");
	    printf("\t\t     ████     █████████████████████████    █████     \n");
	    printf("\t\t      █████    ███████████████████████    █████      \n");
	    printf("\t\t      ██████   ███████████████████████   █████       \n");
	    printf("\t\t        ██████  █████████████████████  ██████        \n");
	    printf("\t\t          █████████████████████████████████          \n");
	    printf("\t\t            █████████████████████████████            \n");
	    printf("\t\t                 ███████████████████                 \n");
	    printf("\t\t                   █████████████                    \n");
	    printf("\t\t                     ███████████                     \n");
	    printf("\t\t                     ███████████                     \n");
	    printf("\t\t                       ███████                      \n");
	    printf("\t\t                       ███████                      \n");
	    printf("\t\t                      █████████                      \n");
	    printf("\t\t                     ███████████                     \n");
	    printf("\t\t                    █████████████                    \n");
	    printf("\t\t                  █████████████████                  \n");
	    printf("\t\t                 ███████████████████                 \n");
	    printf("\t\t                 ███████████████████                 \n");
	    printf("\t\t                 ███████████████████                 \n");
	    printf("\t\t               ███████████████████████               \n");
	    printf("\t\t               ████████████████████████               \n");
	    printf("\x1b[0m"); // Restaura el color a su valor predeterminado

}
// Función para imprimir el mensaje de victoria para el jugador X
void ganadorX(){

    printf(" _____                                                                    _____ \n");
    printf("( ___ )------------------------------------------------------------------( ___ )\n");
    printf(" |   |                                                                    |   | \n");
    printf(" |   |          __   __      _    _              ______                   |   | \n");
    printf(" |   |          \\ \\ / /     | |  | |     /\\     |___  /                   |   | \n");
    printf(" |   |           \\ V /      | |__| |    /  \\       / /                    |   | \n");
    printf(" |   |            > <       |  __  |   / /\\ \\     / /                     |   | \n");
    printf(" |   |           / . \\      | |  | |  / ____ \\   / /__                    |   | \n");
    printf(" |   |          /_/ \\_\\     |_|  |_| /_/    \\_\\ /_____|                   |   | \n");
    printf(" |   |        _____              _   _              _____     ____        |   | \n");
    printf(" |   |       / ____|     /\\     | \\ | |     /\\     |  __ \\   / __ \\       |   | \n");
    printf(" |   |      | |  __     /  \\    |  \\| |    /  \\    | |  | | | |  | |      |   | \n");
    printf(" |   |      | | |_ |   / /\\ \\   | . ` |   / /\\ \\   | |  | | | |  | |      |   | \n");
    printf(" |   |      | |__| |  / ____ \\  | |\\  |  / ____ \\  | |__| | | |__| |      |   | \n");
    printf(" |   |       \\_____| /_/    \\_\\ |_| \\_| /_/    \\_\\ |_____/   \\____/       |   | \n");
    printf(" |___|                                                                    |___| \n");
    printf("(_____)------------------------------------------------------------------(_____) \n");

}
// Función para imprimir el mensaje de victoria para el jugador O
void ganadorO(){

	 printf(" _____                                                                    _____ \n");
	    printf("( ___ )------------------------------------------------------------------( ___ )\n");
	    printf(" |   |                                                                    |   | \n");
	    printf(" |   |        ____        _    _              ______                      |   | \n");
	    printf(" |   |       / __ \\      | |  | |     /\\     |___  /                      |   | \n");
	    printf(" |   |      | |  | |     | |__| |    /  \\       / /                       |   | \n");
	    printf(" |   |      | |  | |     |  __  |   / /\\ \\     / /                        |   | \n");
	    printf(" |   |      | |__| |     | |  | |  / ____ \\   / /__                       |   | \n");
	    printf(" |   |       \\____/      |_|  |_| /_/    \\_\\ /_____|                      |   | \n");
	    printf(" |   |        _____              _   _              _____     ____        |   | \n");
	    printf(" |   |       / ____|     /\\     | \\ | |     /\\     |  __ \\   / __ \\       |   | \n");
	    printf(" |   |      | |  __     /  \\    |  \\| |    /  \\    | |  | | | |  | |      |   | \n");
	    printf(" |   |      | | |_ |   / /\\ \\   | . ` |   / /\\ \\   | |  | | | |  | |      |   | \n");
	    printf(" |   |      | |__| |  / ____ \\  | |\\  |  / ____ \\  | |__| | | |__| |      |   | \n");
	    printf(" |   |       \\_____| /_/    \\_\\ |_| \\_| /_/    \\_\\ |_____/   \\____/       |   | \n");
	    printf(" |___|                                                                    |___| \n");
	    printf("(_____)------------------------------------------------------------------(_____) \n");


}
// Función para imprimir el mensaje de empate
void empate(){
	printf(YELLOW);
	printf(" _____                                                                    _____ \n");
	    printf("( ___ )------------------------------------------------------------------( ___ )\n");
	    printf(" |   |                                                                    |   | \n");
	    printf(" |   |       ______   __  __   _____               _______   ______       |   | \n");
	    printf(" |   |      |  ____| |  \\/  | |  __ \\      /\\     |__   __| |  ____|      |   | \n");
	    printf(" |   |      | |__    | \\  / | | |__) |    /  \\       | |    | |__         |   | \n");
	    printf(" |   |      |  __|   | |\\/| | |  ___/    / /\\ \\      | |    |  __|        |   | \n");
	    printf(" |   |      | |____  | |  | | | |       / ____ \\     | |    | |____       |   | \n");
	    printf(" |   |      |______| |_|  |_| |_|      /_/    \\_\\    |_|    |______|      |   | \n");
	    printf(" |___|                                                                    |___| \n");
	    printf("(_____)------------------------------------------------------------------(_____) \n");
	    printf(RESET);
}
void inic(){
	printf("\033[H\033[J");
	printf(YELLOW);
	printf("·····························\n");
	    printf(": ___ _  _ ___ ___ ___ ___  :\n");
	    printf(":|_ _| \\| |_ _/ __|_ _/ _ \\ :\n");
	    printf(": | || .` || | (__ | | (_) |\n");
	    printf(":|___|_|\\_|___\\___|___\\___/ :\n");
	    printf("·····························\n");
	    printf(RESET);
}
