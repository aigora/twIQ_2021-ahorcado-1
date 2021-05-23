#include <stdio.h>

int main () {

int letra;
	do {
		printf("Introduce una letra\n");
		fflush(stdin);
		scanf("%c", &letra);
		switch (letra) {
			case 'C': printf("La C se encuentra en la primera posicion: C _ _ _ \n");
			case 'A': printf("La A se encuentra en: _ A _ A \n");
			case 'S': printf("La S se encuentra en la tercera posicion: _ _ S _\n");
			}
		
	} while ((letra!='C') && (letra!='A') && (letra!='S'));
}
