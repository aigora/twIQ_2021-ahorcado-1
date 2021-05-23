#include <stdio.h>
#include <string.h>

struct datos {
	char palabra[100];
	int nivel;
};
int main() {
	struct datos palabras[9];
	char palabraOriginal[100];
	char letra;
	int posicion=0, i,palabraCompleta=1,letraEncontrada=0,j;
	int fallos,acertado;
    FILE * fentrada;
	char letras[100];

    fentrada=fopen("palabras.txt", "r");

    if(fentrada==NULL){
        printf("ERROR: el fichero no se ha encontrado\n");
        return 0;
    }
    
    	i=0;
	while(fscanf(fentrada,"%s %d",palabras[i].palabra,&palabras[i].nivel)!=EOF){
		i++;
	} 


	for(i=0; i<9; i++) {
		fallos=0;
		acertado=0;
		printf("------------Nivel %d----------\n",palabras[i].nivel);
		for(j = 0; j<strlen(palabras[i].palabra); j++) {
			palabraOriginal[j] = palabras[i].palabra[j];
			palabras[i].palabra[j]='_';

		}
		do {
			palabraCompleta=1;


			do {
				letraEncontrada = 0;
				printf("Introduzca una letra:\n");
				fflush(stdin);
				scanf("%c", &letra);

				for(j = 0; j<strlen(palabras[i].palabra); j++) {
					if(letra == palabraOriginal[j]) {
						letras[j]==1;
						letraEncontrada=1;
						acertado++;
					}
				}

				if(letraEncontrada == 0) {
					for(j = 0; j<strlen(palabras[i].palabra); j++){
						printf("\t%c",palabras[i].palabra[j]);			
					}
					printf("\n\n");
					fallos++;
				}
				
		        printf("Letras Acertadas: %d",acertado);
		        printf("\n");
		        printf("   _______     \n");
		        printf("      |    \n");
		        if (fallos > 0) printf("      O     \n"); else printf("\n");
		        if (fallos > 3) printf("    \\ "); else printf("      ");
		        if (fallos > 1) printf("|"); else printf("\n");
		        if (fallos > 2) printf(" / \n");
		        if (fallos > 4) printf("      |\n"); else printf("\n");
		        if (fallos > 6) printf("     / "); else printf("       ");
		        if (fallos > 5) printf("\\ \n");else printf("\n");
		        printf("Oportunidades Restantes: %d",7-fallos);
		        printf("\n\n");
		
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
			
		if(fallos == 7) {
			printf("GAME OVER\n");
		} else {
			printf("¡Enhorabuena has acertado!\n");
		}

	}
	return 0;
}

