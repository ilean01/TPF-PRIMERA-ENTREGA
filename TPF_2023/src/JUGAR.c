/*
 * JUGAR.c
 *
 *  Created on: 6 oct. 2023
 *      Author: lp1-2023
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "inicializaciones.h"

// Función para obtener una posición aleatoria en la matriz
int obtenerPosicionAleatoria(int *fila, int *columna) {
    int filaAleatoria, columnaAleatoria;

    // Inicializa la semilla del generador de números aleatorios
    srand(time(NULL));

    do {
        filaAleatoria = rand() % 5;     // Genera un número aleatorio de 0 a 4 para la fila
        columnaAleatoria = rand() % 5;  // Genera un número aleatorio de 0 a 4 para la columna
    } while (matriznum[filaAleatoria][columnaAleatoria] != 0);

    *fila = filaAleatoria;
    *columna = columnaAleatoria;

    return 1;  // Éxito
}
// Función para comer los dados adyacentes de forma aleatoria
void comerDadosAleatorio(int matcomer[2][4], char matrizlet[5][5], int matriznum[5][5], int fila, int columna) {
	int numerosmat[5][5];
		    for (int i = 0; i < 5; i++) {
		        for (int j = 0; j < 5; j++) {
		        	if(matriznum[i][j]<6){
		        		numerosmat[i][j] = matriznum[i][j];
		        	}else{numerosmat[i][j] =0;}
		        }
		    }
	    int suma = 0;
	    int num = 0;
	    int numerosComidos = 0;
	    int coordenadas[4][2];

	    // Comer números adyacentes
	    if (fila - 1 >= 0 && numerosmat[fila - 1][columna] != 0) {
	        coordenadas[num][0] = fila - 1;
	        coordenadas[num][1] = columna;
	        num++;
	        numerosComidos++;
	    }
	    if (fila + 1 < 5 && numerosmat[fila + 1][columna] != 0) {
	        coordenadas[num][0] = fila + 1;
	        coordenadas[num][1] = columna;
	        num++;
	        numerosComidos++;
	    }
	    if (columna - 1 >= 0 && numerosmat[fila][columna - 1] != 0) {
	        coordenadas[num][0] = fila;
	        coordenadas[num][1] = columna - 1;
	        num++;
	        numerosComidos++;
	    }
	    if (columna + 1 < 5 && numerosmat[fila][columna + 1] != 0) {
	        coordenadas[num][0] = fila;
	        coordenadas[num][1] = columna + 1;
	        num++;
	        numerosComidos++;
	    }


	    int eleccion[4];

	    if (numerosComidos < 2) {
	    	printf("Continua.\n");
	    } else if (numerosComidos == 2) {
	        int num1 = coordenadas[0][0];
	        int num2 = coordenadas[0][1];
	        int num3 = coordenadas[1][0];
	        int num4 = coordenadas[1][1];
	        suma = matriznum[num1][num2] + matriznum[num3][num4];

	        if (suma <= 6) {
	            int randomChoice = rand() % 2; // 0 o 1 de forma aleatoria

	            if (randomChoice == 1) {
	                printf(YELLOW"Se eligió comer dos dados.\n"RESET);
	                matriznum[fila][columna] = suma;
	                matriznum[num1][num2] = 0;
	                matrizlet[num1][num2] = ' ';
	                matriznum[num3][num4] = 0;
	                matrizlet[num3][num4] = ' ';
	            } else {
	                printf(RED"No se comió ningún dado adyacente.\n"RESET);
	            }
	        } else {
	            printf(RED"La suma de los dos adyacentes supera 6.\n"RESET);
	        }
	    } else if (numerosComidos > 2) {

	        // Elegir números para comer de forma aleatoria
	        int totalSuma = 0;
	        int numComer = 0;
	        int continuar = 1;

	        do {
	            for (int i = 0; i < numerosComidos; i++) {
	                eleccion[i] = rand() % 2; // 0 o 1 de forma aleatoria

	                if (eleccion[i] == 1) {
	                    totalSuma += matriznum[coordenadas[i][0]][coordenadas[i][1]];
	                    numComer++;
	                }
	            }

	            if (numComer < 2 || totalSuma > 6) {
	            	totalSuma=0;

	            } else {

	                for (int i = 0; i < numerosComidos; i++) {
	                    if (eleccion[i] == 1) {

	                        matriznum[coordenadas[i][0]][coordenadas[i][1]] = 0;
	                        matrizlet[coordenadas[i][0]][coordenadas[i][1]] = ' ';
	                        matriznum[fila][columna]=totalSuma;
	                    }
	                }
	                continuar = 0;
	            }
	        } while (continuar);

	        if (numComer == 0) {
	            printf(RED"No se comió ningún número.\n"RESET);
	        }
	    }
	}
// Función para imprimir MATRIZ DE JUEGO
void printfas(){
	printf("\033[H\033[J");
	printf("\033[H\033[J");
	printf(YELLOW"     /======================================\\\n");
	printf( "     || __  __    _  _____  ___  ___  ____ ||\n");
	printf( "     |||  \\/  |  /_\\|_   _|| _ \\|_ _||_  / ||\n");
	printf( "     ||| |\\/| | / _ \\ | |  |   / | |  / /  ||\n");
	printf( "     |||_|  |_|/_/ \\_\\|_| _|_|_\\|___|/___| ||\n");
	printf( "     ||            |   \\ | __|             ||\n");
	printf( "     ||            | |) || _|              ||\n");
	printf( "     ||        _  _|___/ |___|___   ___    ||\n");
	printf( "     ||     _ | || | | || __|/ __| / _ \\   ||\n");
	printf( "     ||    | || || |_| || _|| (_ || (_) |  ||\n");
	printf( "     ||     \\__/  \\___/ |___|\\___| \\___/   ||\n");
	printf( "     \\======================================/\n");
	printf("\n\n"RESET);
}
// Función para obtener una posición en la matriz
int obtenerPosicion(int *fila, int *columna) {
    char entrada[5];
    int filaTemp, columnaTemp;


    do {
        printf("Ingrese la posición donde desea poner su dado (ejemplo: A2): ");
        if (scanf("%4s", entrada) != 1) {
            printf("Entrada inválida. Debe ser una letra seguida de un número.\n");
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
        } else if (strlen(entrada) != 2 || !isalpha(entrada[0]) || !isdigit(entrada[1])) {
            printf("Entrada inválida. Debe ser una letra seguida de un número.\n");
        } else {
            // Convertir la letra a mayúscula para que funcione con mayúsculas o minúsculas
            char letra = toupper(entrada[0]);
            int numero = entrada[1] - '0';

            if (letra < 'A' || letra > 'E' || numero < 1 || numero > 5) {
                printf("Posición fuera de rango. Debe ser una letra de A a E y un número de 1 a 5.\n");
            } else {
                // La entrada es válida, calculamos la fila y la columna
                filaTemp = letra - 'A';
                columnaTemp = numero - 1;
                *fila = filaTemp;
                *columna = columnaTemp;
                return 1;  // Éxito
            }
        }
    } while (1);

    return 0;  // Debería ser inalcanzable
}
// Función para verificar si una posición está ocupada
int reconocimiento(int matriznum[5][5],int fila,int columna){
			if(matriznum[fila][columna]==0){
				return 1;
			}else{
				return 0;
			}



	return 0;}

// Función para comer los dados adyacentes
void comerDados(int matcomer[2][4], char matrizlet[5][5], int matriznum[5][5], int fila, int columna) {
	int numerosmat[5][5];
	    for (int i = 0; i < 5; i++) {
	        for (int j = 0; j < 5; j++) {
	        	if(matriznum[i][j]<6){
	        		numerosmat[i][j] = matriznum[i][j];
	        	}else{numerosmat[i][j] =0;}
	        }
	    }
    int suma = 0;
    int num = 0;
    int numerosComidos = 0;
    int coordenadas[4][2];

    // Comer números adyacentes
    if (fila - 1 >= 0 && numerosmat[fila - 1][columna] != 0) {
        coordenadas[num][0] = fila - 1;
        coordenadas[num][1] = columna;
        num++;
        numerosComidos++;
    }
    if (fila + 1 < 5 && numerosmat[fila + 1][columna] != 0) {
        coordenadas[num][0] = fila + 1;
        coordenadas[num][1] = columna;
        num++;
        numerosComidos++;
    }
    if (columna - 1 >= 0 && numerosmat[fila][columna - 1] != 0) {
        coordenadas[num][0] = fila;
        coordenadas[num][1] = columna - 1;
        num++;
        numerosComidos++;
    }
    if (columna + 1 < 5 && numerosmat[fila][columna + 1] != 0) {
        coordenadas[num][0] = fila;
        coordenadas[num][1] = columna + 1;
        num++;
        numerosComidos++;
    }

    int eleccion[4];

    if (numerosComidos < 2) {
        printf(RED"No hay suficientes dados adyacentes para comer.\n"RESET);
    } else if (numerosComidos == 2) {
        int num1 = coordenadas[0][0];
        int num2 = coordenadas[0][1];
        int num3 = coordenadas[1][0];
        int num4 = coordenadas[1][1];
        suma = matriznum[num1][num2] + matriznum[num3][num4];

        if (suma <= 6) {
            do {

            	do {
            	    printf(YELLOW"Es posible comer dos dados. \n"RESET);
            	    printf("Introduzca [1] si desea comer, [0] si no:\n");
            	    int c;
            	    while ((c = getchar()) != '\n' && c != EOF);
            	} while (scanf("%d", &eleccion[0]) != 1 || (eleccion[0] != 0 && eleccion[0] != 1));

            } while (eleccion[0] != 0 && eleccion[0] != 1);
            if (eleccion[0] == 0) {
                printf(BOLD"Ningún dado adyacente se ha comido.\n"RESET);
            } else {
                matriznum[fila][columna] = suma;
                matriznum[num1][num2] = 0;
                matrizlet[num1][num2] = ' ';
                matriznum[num3][num4] = 0;
                matrizlet[num3][num4] = ' ';
            }
        } else {
            printf(RED"La suma de los dos adyacentes supera 6.\n"RESET);
        }
    } else if (numerosComidos > 2) {
        printf(YELLOW"Números adyacentes que puedes comer:\n"RESET);
        for (int i = 0; i < numerosComidos; i++) {
            printf("%c%d (valor %d)\n", 'A' + coordenadas[i][0], coordenadas[i][1] + 1, matriznum[coordenadas[i][0]][coordenadas[i][1]]);
        }

        // Elegir números para comer
        int totalSuma = 0;
        int numComer = 0;
        int continuar = 1;

        do {
        	numComer = 0;
            for (int i = 0; i < numerosComidos; i++) {
                if (i > 0) {
                    printf(" ");
                }
                do{ int c;
                while ((c = getchar()) != '\n' && c != EOF);
                printf("\nIngresa [1] para comer, [0] para no comer, ");
                printf(" %c%d: ", 'A' + coordenadas[i][0], coordenadas[i][1] + 1);
                }while(!scanf("%d", &eleccion[i]));


                if (eleccion[i] == 1) {
                    totalSuma += matriznum[coordenadas[i][0]][coordenadas[i][1]];
                    numComer++;
                }
            }

            if (numComer!=0 && (numComer < 2 || totalSuma > 6)) {
                printf(RED"La suma de los números seleccionados supera 6 o seleccionaste solo 1. Elige nuevamente.\n"RESET);
                totalSuma=0;

            } else {
                continuar = 0;
            }
        } while (continuar);

        if (numComer > 0) {
            for (int i = 0; i < numerosComidos; i++) {
                if (eleccion[i] == 1) {
                    matriznum[coordenadas[i][0]][coordenadas[i][1]] = 0;
                    matrizlet[coordenadas[i][0]][coordenadas[i][1]] = ' ';
                    matriznum[fila][columna]=totalSuma;
                }
            }
        } else {
            printf("No se comió ningún número.\n");
        }
    }
}
// Función principal del juego
int juego(int eleccion, int *eleccion2, int matriznum[5][5], char matrizlet[5][5]) {

    srand(time(NULL)); // Inicializa la semilla del generador de números aleatorios.
    int turno = 1; // Controla el turno actual (jugador 1 o jugador 2).
    int re; // Variable para manejar errores.
    int fila, columna; // Coordenadas en el tablero.
    char jugador1, jugador2; // Jugadores 1 ('x') y 2 ('o').

    if (*eleccion2 == 1) {
        jugador1 = 'x'; // Jugador 1 eligió 'x'.
        jugador2 = 'o'; // Jugador 2 es 'o'.
    } else {
        jugador1 = 'o'; // Jugador 1 eligió 'o'.
        jugador2 = 'x'; // Jugador 2 es 'x'.
    }
    printf(PARPADEO);
    printfas(); // Llama a una función para mostrar algo .
    printf(RESET);
    imprimirjuego(matriznum, matrizlet, eleccion2); // Imprime el estado inicial del juego.

    printf(YELLOW"Presiona Enter para continuar..."RESET); // Muestra un mensaje en color y espera a que el usuario presione Enter.
    while (getchar() != '\n'); // Espera a que se presione Enter.

    if (eleccion == 2) { // Modo de juego para dos jugadores.
        while (1) { // Bucle principal del juego.
            if (turno == 1) {
                printf(BOLD"Turno del Jugador 1 "RESET);
                if(jugador1=='x'){
                	printf(RED"(%c)\n\n"RESET, jugador1);
                }else{
                	printf(GREEN"(%c)\n\n"RESET, jugador1);
                }
            } else {
                printf(BOLD"Turno del Jugador 2 "RESET);
                if(jugador2=='x'){
                	printf(RED"(%c)\n\n"RESET, jugador2);
                }else{
                	printf(GREEN"(%c)\n\n"RESET, jugador2);
                }
            }
            do {
                obtenerPosicion(&fila, &columna); // Función para obtener las coordenadas del jugador.
                re = 0;
                if (reconocimiento(matriznum, fila, columna)) {
                    if (turno == 1) {
                        matriznum[fila][columna] = 1; // Actualiza el tablero con el jugador 1 ('x').
                        matrizlet[fila][columna] = jugador1;
                    } else {
                        matriznum[fila][columna] = 1; // Actualiza el tablero con el jugador 2 ('o').
                        matrizlet[fila][columna] = jugador2;
                    }
                } else {
                    printf(RED"La casilla %c%d ya esta ocupada. "RESET, (fila + 'A'), (columna + 1));
                    re = 1;
                }
            } while (re == 1);
            printfas();
            imprimirjuego(matriznum, matrizlet, eleccion2); // Muestra el tablero actualizado.

            int matcomer[2][4];
            comerDados(matcomer, matrizlet, matriznum, fila, columna); // Realiza comprobaciones y actualizaciones específicas (función no proporcionada).
            printfas();
            imprimirjuego(matriznum, matrizlet, eleccion2); // Muestra el tablero nuevamente.

            turno = (turno == 1) ? 2 : 1; // Cambia el turno entre jugador 1 y jugador 2.

            int tab_completo = 1;
               for (int i = 0; i < 5; i++) {
                   for (int j = 0; j < 5; j++) {
                       if (matriznum[i][j] == 0) {
                           tab_completo = 0; // Al menos una casilla está vacía
                           break;
                       }
                   }
                   if (!tab_completo) {
                       break; // No es necesario verificar más, ya que al menos una casilla está vacía
                   }
               }

               if (tab_completo) {
                   printf("¡Todas las casillas están ocupadas! \n");
                   printf(YELLOW"Presiona Enter para continuar..."RESET); // Muestra un mensaje en color y espera a que el usuario presione Enter.
                   while (getchar() != '\n');
                   break; // Salir del bucle
               }
        }
    } else if (eleccion == 1) { // Modo de juego contra la computadora.
        while (1) { // Bucle principal del juego.
            if (turno == 1) {
               if(jugador1=='x'){
            	   printf(RED"Tu turno (%c)\n\n"RESET, jugador1);
               }else{
            	   printf(GREEN"Tu turno (%c)\n\n"RESET, jugador1);
               }
                do {
                    obtenerPosicion(&fila, &columna); // Función para obtener las coordenadas del jugador.
                    re = 0;
                    if (reconocimiento(matriznum, fila, columna)) {
                        matriznum[fila][columna] = 1; // Actualiza el tablero con el jugador 1 ('x').
                        matrizlet[fila][columna] = jugador1;
                    } else {
                        printf(RED"La casilla %c%d ya esta ocupada. "RESET, (fila + 'A'), (columna + 1));
                        re = 1;
                    }
                } while (re == 1);
                printfas();
                imprimirjuego(matriznum, matrizlet, eleccion2); // Muestra el tablero actualizado.
                int matcomer[2][4];
                comerDados(matcomer, matrizlet, matriznum, fila, columna); // Realiza comprobaciones y actualizaciones específicas (función no proporcionada).
            } else {
                printf("Turno del computador (%c)\n\n\n", jugador2);
                do {
                    obtenerPosicionAleatoria(&fila, &columna); // Función para obtener coordenadas aleatorias (no proporcionada).
                    re = 0;
                    if (reconocimiento(matriznum, fila, columna)) {
                        matriznum[fila][columna] = 1; // Actualiza el tablero con el jugador 2 ('o').
                        matrizlet[fila][columna] = jugador2;
                    } else {
                        re = 1;
                    }
                } while (re == 1);
                int matcomer[2][4];
                comerDadosAleatorio(matcomer, matrizlet, matriznum, fila, columna); // Realiza comprobaciones y actualizaciones específicas (función no proporcionada).
                printfas();
                imprimirjuego(matriznum, matrizlet, eleccion2); // Muestra el tablero actualizado.
            }

            turno = (turno == 1) ? 2 : 1; // Cambia el turno entre jugador 1 y jugador 2.

            int tab_completo = 1;
               for (int i = 0; i < 5; i++) {
                   for (int j = 0; j < 5; j++) {
                       if (matriznum[i][j] == 0) {
                           tab_completo = 0; // Al menos una casilla está vacía
                           break;
                       }
                   }
                   if (!tab_completo) {
                       break; // No es necesario verificar más, ya que al menos una casilla está vacía
                   }
               }

               if (tab_completo) {
                   printf("¡Todas las casillas están ocupadas!\n");
                   printf(YELLOW"Presiona Enter para continuar..."RESET); // Muestra un mensaje en color y espera a que el usuario presione Enter.
                   while (getchar() != '\n');
                   break; // Salir del bucle
               }
        }
    }

    int contX=0;
    int contO=0;
    for (int i = 0; i < 5; i++) {
    	for (int j = 0; j < 5; j++) {
    		if (matrizlet[i][j] == 'x' && matriznum[i][j]==6) {
    			contX++;
             }
    		else if (matrizlet[i][j] == 'o' && matriznum[i][j]==6) {
    			contO++;
    		}
    	}
     }

        // Comprobación del ganador basado en el recuento de 'x' y 'o'.
        if (contX > contO) {
            // Animación para el ganador X .

        	printf(RED);
        	ganadorX();
        	printf(RESET);
        	trofeo();

        	} else if (contX < contO) {
            // Animación para el ganador O .
        		printf(GREEN);
        		ganadorO();
        		printf(RESET);
        		trofeo();
        } else {
            // En caso de empate, muestra un mensaje de empate.
            empate();
        }

        return 0;
    }
