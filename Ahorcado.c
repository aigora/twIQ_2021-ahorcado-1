#include<stdio.h>

int main () {
	char opcion, modo, solitario, equipos, equipo1, equipo2,A,B;

	// Menu de entrada
	printf ("----------AHORCADO----------\n");

	do {

		printf("A - Jugar\n");
		printf("B - Salir del juego\n");
		fflush(stdin);
		scanf("%c", &opcion);		
		switch(opcion) {
			case 'A' :

				printf("Bienvenid@ al ahorcado\n");
				do {


					printf("Elige el modo de juego:\n");
					fflush(stdin);
					printf("A - Solitario\n");
					printf("B - En equipo\n");
					scanf("%c", &modo);

					switch(modo) {


						case 'A' :
							do {
								printf("A - Instrucciones\n");
								printf("B - EMPEZAR\n");
								fflush(stdin);
								scanf("%c", &solitario);
								switch(solitario) {
									case 'A' :
										printf("-Para comenzar introduzca su usuario\n-A continuacion le aparecera una palabra que tiene q adivinar\n-Recuerda q solo tiene siete intentos\n-Se realizaran 3 rondas de 5 palabras\n-Seras el ganador si aciertas todas\n");

										break;
									case 'B' :
										printf("Aqui empieza la programacion del solitario");
										fflush(stdin);
										break;
									default:
										printf("La opcion es incorrecta\n");
								}
							} while(solitario!='B');
							break;
						case 'B' :
							do {
							printf("A - Instrucciones\n");
							printf("B - EMPEZAR\n");
							fflush(stdin);
							scanf("%c", &equipos);
							switch(equipos) {
								case 'A' :
									printf("-Para comenzar introduzca el nombre de ambos equipos\n-A continuacion les iran apareciendo palabras elegidas por el otro equipo que tendran q adivinar\n-Recordad q solo teneis siete intentos\n-Se realizaran 3 rondas de 5 palabras\n-El equipo que acierte mas palabras sera el ganador\n");

									break;
								case 'B' :
									printf("Introduce el nombre del equipo 1\n");
									fflush(stdin);
									scanf("%c", &equipo1);
									printf("Introduce el nombre del equipo 2\n");
									fflush(stdin);
									scanf("%c", &equipo2);
									printf("Aqui empezaria la programacion del juego por equipos\n");
									break;
								default:
									printf("La opcion es incorrecta\n");
							}
							} while(equipos!='B');
							break;
						default:
							printf("La opcion es incorrecta\n");
							
					}
				} while((modo!='A')&& (modo!='B'));
				break;
				case 'B' :
				printf("Gracias por jugar, hasta pronto!");
				break;
			default:
				printf("La opcion es incorrecta\n");
		}
	} while ((opcion!='A') && (opcion!='B'));
	return 0;

}
