
#include <stdio.h>
#include <stdlib.h>
#define capacidad 10 //A2 B3 C5
#define claseA 2
#define claseB 3
#define claseC 5
typedef struct
{
	//char nombre[33];
	//char dni[9];
}Pasaje;

void sendToDatabase(FILE *fichero, char clase, int asiento);
void imprimir(Pasaje pasaje, char clase, int asiento);
Pasaje leerDatos();

int main()
{
	FILE *fichero;
	
	int asientos;
	int A, B,C;
	int i,j,k;
	i=0;j=2;k=5;
	int opt;
	A = claseA;
	B = claseB;
	C = claseC;
	char clase;
	Pasaje pasaje;
	
	asientos = capacidad;
	
	do{
		printf("\nSeleccione la clase en la que desea reservar su asiento:\t");
		scanf("%c",&clase);
		fflush(stdin);
		if(clase == 'A')
		{
			if(A == 0)
			{
				printf("No hay asientos disponibles; "); 
				break;
			}//Sale del bucle
			else
				printf("\nReservar asiento?\t(1)-si\t(2)-no\n");
				do{
					scanf("%d",&opt);
				}while(opt<1 || opt >2);
				if(opt == 1)
				{
					A = A-1;
					i=i+1;
					fichero = fopen("database.csv","w");//Se abre el fichero para escribir
					fflush(stdin);
					pasaje = leerDatos();
					imprimir(pasaje, clase, i);
					sendToDatabase(fichero,clase,i);
					fclose(fichero);
				}
		}
		else if(clase == 'B')
		{
			if(B == 0)continue;//Sale del bucle
			else
				printf("\nReservar asiento?\t(1)-si\t(2)-no\n");
				do{
					scanf("%d",&opt);
				}while(opt<1 || opt >2);
				if(opt == 1)
				{
					B = B-1;
					j=j+1;
					fichero = fopen("database.csv","w");//Se abre el fichero para escribir
					fflush(stdin);
					pasaje = leerDatos();
					imprimir(pasaje, clase, j);
					sendToDatabase(fichero,clase,k);
					fclose(fichero);
				}
		}
		else if(clase == 'C')
		{
			if(C == 0)break;//Sale del bucle
			else
				printf("\nReservar asiento?\t(1)-si\t(2)-no\n");
				do{
					scanf("%d",&opt);
				}while(opt<1 || opt >2);
				if(opt == 1)
				{
					C = C-1;
					k=k+1;
					fichero = fopen("database.csv","w");//Se abre el fichero para escribir
					fflush(stdin);
					pasaje = leerDatos();
					imprimir(pasaje, clase, k);
					sendToDatabase(fichero,clase,k);
					fclose(fichero);
				}
		}
		else
		printf("Opcion incorrecta\n");
	}while(asientos > 0);
	
	fclose(fichero);
	return 0;
}

Pasaje leerDatos()
{
	Pasaje pasaje;
	return pasaje;
}

void imprimir(Pasaje pasaje, char clase, int asiento)
{
	printf("\n******************************************\n");
	//imprime nombre
	printf("Clase:    %c\n",clase);
	printf("Asiento:  %d",asiento);
	printf("\n******************************************\n");
}
void sendToDatabase(FILE *fichero, char clase, int asiento)
{
	fprintf(fichero,"%c;%d;",clase,asiento);
	//fprintf(fichero,"%s;%s",pasaje.nombre, pasaje.dni);
	fprintf(fichero,"\n");
}
