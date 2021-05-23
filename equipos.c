#include <stdio.h>
#include <string.h>

struct datos 
{
	char palabra[100];
	int nivel;
};
int main() 
{
	struct datos palabras[100];
	char palabraOriginal[100];
	char letra;
	int posicion=0;
	int i,j,k;
	int palabraCompleta=1;
	int letraEncontrada=0;
	int fallos,acertado;
	char letras[100];
	int repetida = 0;

	for(k=0; k<3; k++) 
	{



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
							if(palabras[i].palabra[j] != letra) acertado++;
							else repetida = 1;
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
					printf("\n"); 
					if(repetida == 1) printf("Ya has puesto esa letra \n"); 
					printf("\n");
					printf("Letras Acertadas: %d\n",acertado);

					printf("Oportunidades Restantes: %d\n\n",8-fallos);
					repetida = 0;
				} while(letraEncontrada==0 && fallos != 8);
				
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
			} while(palabraCompleta == 0 && fallos!=8);
			
			for(j = 0; j<strlen(palabras[i].palabra); j++)
			{
				letras[j] = 0;		
			}
					
			if(fallos == 8) 
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
