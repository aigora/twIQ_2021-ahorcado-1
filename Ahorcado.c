#include<stdio.h>
#include<string.h>

struct datos {
    char palabra[100];
    int nivel;
};

int main () {
	char opcion, modo, solitario, equipos, equipo1, equipo2,A,B;
	struct datos palabras[9]={{"lujo",1},{"hoja", 1}, {"gato", 1}, {"abrigo", 2}, {"cable", 2},{"reloj",2},{"coleta",3}, {"sarten", 3}, {"cuadro",3}};
	char palabraOriginal[100];
	char letra;
	int posicion=0, i,palabraCompleta=1,letraEncontrada=0,j;
	
	struct datos palabras[100];
	char palabraOriginal[100];
	char letra;
	int posicion=0;
	int i,j,k;
	int palabraCompleta=1;
	int letraEncontrada=0;
	int fallos,acertado;
	char letras[100];

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
										
										for(i=0;i<9;i++){
										    printf("------------Nivel %d----------\n",palabras[i].nivel);
										    for(j = 0; j<strlen(palabras[i].palabra); j++) {
											palabraOriginal[j] = palabras[i].palabra[j];
											palabras[i].palabra[j]='_';

										    }
										    do {
											palabraCompleta=1;

											do {
											    printf("Introduzca una letra:\n");
											    fflush(stdin);
											    scanf("%c", &letra);

											    for(j = 0; j<strlen(palabras[i].palabra);j++) {
												if(letra == palabraOriginal[j]) {
												    posicion=j;
												    letraEncontrada=1;
												}

											    }
											    if(letraEncontrada == 0) {
												printf("%s\n", palabras);
											    }

											} while(letraEncontrada==0);
											palabras[i].palabra[posicion]=palabraOriginal[posicion];
											printf("%s\n", palabras[i].palabra);
											for(j= 0; j<strlen(palabras[i].palabra); j++) {
											    if(palabras[i].palabra[j]=='_') {
												palabraCompleta = 0;
											    }
											} 
											} while(palabraCompleta == 0);

											    printf("enhorabuena has acertado!\n");
										}

										}

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
									for(k=0; k<3; k++) {

										printf("EQUIPO 1\n");
										printf("introduce una palabra\n");
										scanf("%s",palabras[0].palabra);
										printf("EQUIPO 2\n");
										printf("introduce una palabra\n");
										scanf("%s",palabras[1].palabra);

										for(i=0; i<2; i++) 
										{
											fallos=0;
											acertado=0;

											printf("------------Ronda %d----------\n",i+1);
											for(j = 0; j<strlen(palabras[i].palabra); j++) 
											{
												palabraOriginal[j] = palabras[i].palabra[j];
												palabras[i].palabra[j]='_';
											}
											do 
											{
												palabraCompleta=1;

												do 
												{
													letraEncontrada=0;
													printf("Introduzca una letra:\n");
													fflush(stdin);
													scanf("%c", &letra);

													for(j = 0; j<strlen(palabras[i].palabra); j++) 
													{
														if(letra == palabraOriginal[j]) 
														{
															letras[j]=1;
															letraEncontrada=1;
															acertado++;
														}
													}

													if(letraEncontrada == 0) 	
													{
														for(j = 0; j<strlen(palabras[i].palabra); j++)
														{
															printf("\t%c",palabras[i].palabra[j]);			
														}

														printf("\n\n");
														fallos++;
													}
													printf("Letras Acertadas: %d\n",acertado);

													printf("Oportunidades Restantes: %d\n\n",7-fallos);
												} while(letraEncontrada==0 && fallos != 7);

												if(letraEncontrada == 1) 
												{
													for(j = 0; j<strlen(palabras[i].palabra); j++)
													{
														if(letras[j]) palabras[i].palabra[j]=palabraOriginal[j];		
													} 

													for(j = 0; j<strlen(palabras[i].palabra); j++)
													{
														printf("\t%c",palabras[i].palabra[j]);			
													} 

													printf("\n\n");

													for(j= 0; j<strlen(palabras[i].palabra); j++) 
													{
														if(palabras[i].palabra[j]=='_') 
														{
															palabraCompleta = 0;
														}
													}
												} 
											} while(palabraCompleta == 0 && fallos!=7);

											for(j = 0; j<strlen(palabras[i].palabra); j++)
											{
												letras[j] = 0;		
											}

											if(fallos == 7) 
											{
												printf("GAME OVER\n");
											} 
											else 
											{
												printf("¡Enhorabuena has acertado!\n");
											}
										}
									}
								return 0;
								}
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
