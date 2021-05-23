#include <stdio.h>
#include <string.h>

struct datos {
    char palabra[100];
    int nivel;
    int puntos;
};
struct equipo {
    char nombre[100];
    int sumaPuntos;
};

// int contador(char letra, char palabras[],int  acertado, char palabraOriginal[], char letras[]);
char lecturapalabras(struct datos palabras[]);
int contador2(char palabras[], int fallos, int letraEncontrada);
void dibujo (int fallos);

int main () {
    char opcion, modo, solitario, modoEquipos, equipo1, equipo2,A,B;
    struct datos palabras[100];
    struct equipo equipos[100];
    char palabraOriginal[100];
    char palabra[100];
    char letra, nombre;
    int posicion=0;
    int i,j,k,l,r;
    int palabraCompleta=1;
    int letraEncontrada=0;
    int fallos,acertado;
    int repetida=0;
    int equipoJugador,puntos;
    int sumaPuntos = 0;
    char letras[100];
    FILE * fentrada;
    FILE * fsalida;
    FILE * fpuntos;

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
                                system("cls");
                                switch(solitario) {
                                    case 'A' :
                                        printf("-Para comenzar introduzca su usuario\n-A continuacion le aparecera una palabra que tiene que adivinar\n-Recuerda que solo tiene ocho intentos\n-Se realizaran rondas de palabras con diferentes niveles de dificultad\n-Seras el ganador si aciertas todas\n");
                                        break;

                                    case 'B' :

                                        lecturapalabras(palabras);
                                        printf("Introduzca su nombre\n");
                                        fflush(stdin);
                                        scanf("%s",&nombre);
                                        for(i=0;i<9;i++) {
                                            fallos = 0;
                                            acertado = 0;
                                            printf("------------Nivel %d----------\n", palabras[i].nivel);
                                            for (j = 0; j < strlen(palabras[i].palabra); j++) {
                                                palabraOriginal[j] = palabras[i].palabra[j];
                                                palabras[i].palabra[j] = '_';
                                            }

                                            do {
                                                palabraCompleta = 1;

                                                do {
                                                    letraEncontrada = 0;
                                                    printf("Introduzca una letra:\n");
                                                    fflush(stdin);
                                                    scanf("%c", &letra);

                                                    for (j = 0; j < strlen(palabras[i].palabra); j++) {
                                                        if (letra == palabraOriginal[j]) {
                                                            letras[j] = 1;
                                                            letraEncontrada = 1;
                                                            if (palabras[i].palabra[j] != letra) {
                                                                acertado++;
                                                            } else {
                                                                repetida = 1;
                                                            }
                                                        }

                                                    }
                                                    // acertado = contador(letra, palabras[i].palabra,acertado, palabraOriginal, letras);
                                                    fallos = contador2(palabras[i].palabra, fallos, letraEncontrada);

                                                    printf("\n");
                                                    if (repetida == 1) {
                                                        printf("Ya has puesto esa letra\n");
                                                    }
                                                    printf("Letras Acertadas: %d\n", acertado);

                                                    printf("\n");

                                                    printf("Oportunidades Restantes: %d\n", 8 - fallos);
                                                    repetida = 0;
                                                    printf("\n\n");

                                                    dibujo(fallos);

                                                } while (letraEncontrada == 0 && fallos != 8);

                                                if (letraEncontrada == 1) {
                                                    for (j = 0; j < strlen(palabras[i].palabra); j++) {
                                                        if (letras[j]) {
                                                            palabras[i].palabra[j] = palabraOriginal[j];
                                                        }
                                                        printf("\t%c", palabras[i].palabra[j]);
                                                    }
                                                    printf("\n\n");
                                                    for (j = 0; j < strlen(palabras[i].palabra); j++) {
                                                        if (palabras[i].palabra[j] == '_') {
                                                            palabraCompleta = 0;
                                                        }
                                                    }
                                                }
                                            } while (palabraCompleta == 0 && fallos != 8);
                                            for (j = 0; j < strlen(palabras[i].palabra); j++) {
                                                letras[j] = 0;
                                            }

                                            if (fallos == 8) {
                                                printf("GAME OVER\n");
                                            } else {
                                                printf("¡Enhorabuena has acertado!\n");
                                                sumaPuntos += palabras[i].puntos;
                                            }

                                        }
                                        printf("Has obtenido %d puntos\n",sumaPuntos);
                                        fsalida = fopen("salida.txt","w");
                                        if(fsalida == NULL) {
                                            printf("Error en la apertura del fichero\n");
                                            return 0;
                                        }
                                        fprintf(fsalida,"%s has obtenido:%d ptos de un total de 90 puntos",nombre,sumaPuntos);

                                        fclose(fsalida);
                                        return 0;

                                    default:
                                        printf("la opcion es incorrecta\n");
                                }


                            } while(solitario!='B');
                            break;


                        case 'B' :
                            do {
                                printf("A - Instrucciones\n");
                                printf("B - EMPEZAR\n");
                                fflush(stdin);
                                scanf("%c", &modoEquipos);
                                system("cls");
                                switch(modoEquipos) {
                                    case 'A' :
                                        printf("-Para comenzar introduzca el nombre de ambos equipos\n-A continuacion les iran apareciendo palabras elegidas por el otro equipo que tendran que adivinar\n-Recordad que solo teneis ocho intentos\n-Se realizaran 3 rondas \n-El equipo que acierte mas palabras sera el ganador\n");

                                        break;
                                    case 'B' :
                                        printf("Introduce el nombre del equipo 1\n");
                                        fflush(stdin);
                                        scanf("%s",equipos[0].nombre);
                                        printf("Introduce el nombre del equipo 2\n");
                                        fflush(stdin);
                                        scanf("%s",equipos[1].nombre);
                                        for(k=0; k<3; k++) {
                                            printf("------------Ronda %d----------\n",k);


                                            for(l=0; l<2; l++) {
                                                if(l==0) {
                                                    equipoJugador= l+1;
                                                } else if(l==1) {
                                                    equipoJugador= l-1;
                                                }
                                                printf("%s\n",equipos[l].nombre);
                                                printf("introduce una palabra\n");
                                                fflush(stdin);
                                                scanf("%s",palabra);
                                                system("cls");
                                                puntos = 10;


                                                fallos=0;
                                                acertado=0;

                                                for(j = 0; j<strlen(palabra); j++) {
                                                    palabraOriginal[j] =palabra[j];
                                                    palabra[j]='_';
                                                }
                                                do {

                                                    palabraCompleta=1;

                                                    do {

                                                        letraEncontrada=0;
                                                        printf("%s\n",equipos[equipoJugador].nombre);
                                                        printf("Introduzca una letra:\n");
                                                        fflush(stdin);
                                                        scanf("%c", &letra);

                                                        for (j = 0; j < strlen(palabra); j++) {
                                                            if (letra == palabraOriginal[j]) {
                                                                letras[j] = 1;
                                                                letraEncontrada = 1;
                                                                if (palabra[j] != letra) {
                                                                    acertado++;
                                                                } else {
                                                                    repetida = 1;
                                                                }
                                                            }

                                                        }
                                                        // acertado=contador( letra, palabras[i].palabra,acertado, palabraOriginal, letras);
                                                        fallos = contador2(palabra, fallos, letraEncontrada);

                                                        printf("\n");
                                                        if(repetida == 1) {
                                                            printf("Ya has puesto esa letra \n");
                                                        }
                                                        printf("Letras Acertadas: %d\n",acertado);
                                                        printf("\n");

                                                        dibujo(fallos);


                                                        printf("Oportunidades Restantes: %d\n",8-fallos);
                                                        repetida=0;
                                                        printf("\n\n");


                                                    } while(letraEncontrada==0 && fallos != 8);

                                                    if(letraEncontrada == 1) {

                                                        for(j = 0; j<strlen(palabra); j++) {

                                                            if(letras[j]) {
                                                                palabra[j]=palabraOriginal[j];
                                                            }
                                                            printf("\t%c",palabra[j]);
                                                        }
                                                        printf("\n\n");

                                                        for(j= 0; j<strlen(palabra); j++) {

                                                            if(palabra[j]=='_') {
                                                                palabraCompleta = 0;
                                                            }
                                                        }
                                                    }
                                                } while(palabraCompleta == 0 && fallos!=8);

                                                for(j = 0; j<strlen(palabra); j++){
                                                    letras[j] = 0;
                                                }

                                                if(fallos == 8) {
                                                    printf("GAME OVER\n");
                                                }
                                                else {
                                                    printf("¡Enhorabuena has acertado!\n");
                                                    equipos[equipoJugador].sumaPuntos+=puntos;
                                                }
                                            }
                                        }
                                        fpuntos=fopen("puntosequipos.txt","w");
                                        if(fpuntos == NULL) {
                                            printf("Error en la apertura del fichero\n");
                                            return 0;
                                        }
                                        for(r=0; r<2; r++) {
                                            printf("Has obtenido %d puntos\n",equipos[r].sumaPuntos);
                                            fprintf(fpuntos,"%s has obtenido:%d ptos de un total de 90 puntos",equipos[r].nombre,equipos[r].sumaPuntos);
                                        }

                                        fclose(fpuntos);

                                        return 0;
                                    default:
                                        printf("La opcion es incorrecta\n");
                                }


                            } while(modoEquipos != 'B');
                            break;

                        default:
                            printf("La opcion es incorrecta\n");
                    }


                }
                while((modo != 'A') && (modo != 'B'));
                break;
            case 'B' :
                printf("Gracias por jugar, ¡hasta pronto!");
                break;
            default:
                printf("La opcion es incorrecta\n");
        }
    } while ((opcion != 'A') && (opcion != 'B'));
    return 0;

}

void dibujo (int fallos) {
    switch(fallos){

        case 0: printf(" \n     ____\n    |    |\n    |\n    |\n    |\n    |\n  __|__  "); break;

        case 1: printf(" \n     ____\n    |    |\n    |    O\n    |\n    |\n    |\n    |\n  __|__  "); break;

        case 2: printf("\n     ____\n    |    |\n    |    O\n    |    |\n    |\n    |\n    |\n  __|__  "); break;

        case 3: printf("\n     ____\n    |    |\n    |    O\n    |   /|\n    |\n    |\n    |\n  __|__  ");break;

        case 4: {
            printf("\n     ____\n    |    |\n    |    O\n    |   /|");
            printf("\\\n");
            printf("    |\n    |\n    |\n  __|__");
        } break;

        case 5: {
            printf("\n     ____\n    |    |\n    |    O\n    |   /|");
            printf("\\\n");
            printf("    |    |\n    |\n    |\n  __|__");
        } break;


        case 6: {
            printf("\n     ____\n    |    |\n    |    O\n    |   /|");
            printf("\\\n");
            printf("    |    |\n    |   /\n    |\n    |\n  __|__");
        } break;

        case 7: {
            printf("\n     ____\n    |    |\n    |    O\n    |   /|");
            printf("\\\n");
            printf("    |    |\n    |   /");
            printf(" \\\n");
            printf("    |\n    |\n  __|__");
        } break;
    }
}
/*
int contador(char letra, char palabras[],int  acertado, char palabraOriginal[], char letras[]) {
    int j;

    for(j = 0; j<strlen(palabras); j++) {
        if(letra == palabraOriginal[j]) {
            letras[j]=1;
            letraEncontrada=1;
            if(palabras[i].palabra[j] !=letra) {
                acertado++;
            }
        }
    }
    return acertado;
}
*/
int contador2(char palabras[], int fallos, int letraEncontrada){
    int j;
    if(letraEncontrada == 0) {
        for(j = 0; j<strlen(palabras); j++) {
            printf("\t%c",palabras[j]);
        }
        printf("\n\n");
        fallos++;
    }
    return (fallos);
}

char lecturapalabras(struct datos palabras[]) {
	int i;
	FILE * fentrada;
	fentrada=fopen("palabras.txt", "r");

	if(fentrada==NULL) {
		printf("ERROR: el fichero no se ha encontrado\n");
	    return 0;
	}

	i=0;
	while(fscanf(fentrada,"%s %d %f",palabras[i].palabra,&palabras[i].nivel,&palabras[i].puntos)!=EOF) {
		i++;
	}
	fclose(fentrada);
}
