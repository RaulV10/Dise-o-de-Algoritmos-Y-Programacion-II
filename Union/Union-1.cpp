#include<stdio.h>
#include<stdlib.h>

typedef union{
	float lado;
	float area;
	char nombre[10];
	int edad;
}DATOS;

int main() {
	DATOS d;
	printf("Introduzca el lado de un cuadrado: ");
	scanf("%f", &d.lado);
	d.area = d.lado * d.lado;
	printf("\nEl area del cuadrado es: %.2f", d.area);
	printf("\nEl lado del cuadrado es: %.2f", d.lado);
	return 0;
}
