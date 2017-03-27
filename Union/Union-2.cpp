#include<stdio.h>
#include<stdlib.h>

typedef struct {
	float b;
	float h;
}TRIANG;

typedef union{
	float lado;
	float area;
	char nombre[10];
	int edad;
	TRIANG t;
}DATOS;

int main() {
	DATOS d;
	
	printf("***** CUADRADO *****\n\n");
	printf("Introduzca el lado de un cuadrado: ");
	scanf("%f", &d.lado);
	d.area = d.lado * d.lado;
	printf("\nEl area del cuadrado es: %.2f", d.area);
	printf("\nEl lado del cuadrado es: %.2f", d.lado);
	
	printf("\n\n");
	
	printf("***** TRIANGULO *****\n\n");
	
	printf("Introduzca la base del triangulo: ");
	scanf("%f", &d.t.b);
	
	printf("Introduzca la altura del triangulo: ");
	scanf("%f", &d.t.h);
	
	d.area = (d.t.b * d.t.h)/2;
	
	printf("\nEl area del triangulo es: %.2f", d.area);
	return 0;
}
