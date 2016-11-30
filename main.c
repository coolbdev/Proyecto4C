#include <stdio.h>
#define nA 2
#define nB 3
#define nC 5
int a, b, c;

typedef struct
{
    char nombre[22];
    char dni[10];
}Datos;
typedef struct
{
    Datos datos;
    char clase;
    int idOperacion;
}Pasaje;
void menuClase()
{
    printf("\nElija la clase en la que desae viajar:\n");
    printf("(A) - Clase A\n");
    printf("(B) - Clase B\n");
    printf("(C) - Clase C\n");
}
char seleccionaClase()
{
    char clase;
    clase = 'W';
    while(clase)
    {
        menuClase();
        scanf("%c",&clase);
        if(clase == 'A' || clase == 'B' || clase == 'C')
            break;
    }
    return clase;
}

Datos leeDatos()
{
    Datos datos;
    printf("Nombre");
    scanf("%s",&datos.nombre);
    printf("\nDNI");
    scanf("%s",&datos.dni);
    return datos;
}

Pasaje reservacion(int a , int b, int c)
{
    Pasaje pasaje;
    char clase;
    clase = seleccionaClase();
    switch(clase)
    {
        case 'A':
            if(a >= nA)
            {
                printf("No hay asientos disponibles\n");
                break;
            }
            else
            {
            	a = a+1;
                pasaje.datos = leeDatos();
                pasaje.clase = 'A';
                pasaje.idOperacion = a;
            }
        break;
        case 'B':
            if(b >= nB)
            {
                printf("No hay asientos disponibles\n");
                break;
            }
            else
            {
            	b = b+1;
                pasaje.datos = leeDatos();
                pasaje.clase = 'B';
                pasaje.idOperacion = b+2;
            }
        break;
        case 'C':
            if(c >= nC)
            {
                printf("No hay asientos disponibles\n");
                break;
            }
            else
            {
            	c = c+1;
                pasaje.datos = leeDatos();
                pasaje.clase = 'C';
                pasaje.idOperacion = c+5;
            }
        break;
    }
    return pasaje;
}
void imprimeBoleto(Pasaje pasaje)
{
	printf("\n*****************************************\n");
	printf("Nombre:%s",pasaje.datos.nombre);
	printf("\nDNI:%s",pasaje.datos.dni);
	printf("\nClase: %c",pasaje.clase);
	printf("\nid Operacion: %d",pasaje.idOperacion);
	printf("\n*****************************************\n");
}

int main()
{
    a=0;
    b=0;
    c=0;
    Pasaje pasaje;
    while(a+b+c < 10)
    {
    	pasaje = reservacion(a,b,c);
    	imprimeBoleto(pasaje);
    	
	}
    
    return 0;
}
