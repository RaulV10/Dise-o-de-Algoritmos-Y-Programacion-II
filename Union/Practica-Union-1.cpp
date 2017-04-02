#include<stdio.h>

typedef struct {
	float lado;
}CUBO;

typedef struct {
	float radio;
	float h;
}CONO;

typedef struct {
	float radio;
}ESFERA;

typedef union {
	CUBO cu;
	CONO co;
	ESFERA es;
	
	float volCubo;
	float volCono;
	float volEsfera;
}VOLUMEN;

int main() { 

	float const pi = 3.14159265;

	VOLUMEN vol;
	
	printf("***** CUBO *****");
	printf("\nIntroduzca el lado del cubo: ");
	scanf("%f", &vol.cu.lado);
	vol.volCubo = (vol.cu.lado * vol.cu.lado * vol.cu.lado);
	printf("\nEl volumen del cubo es: %.2f", vol.volCubo);
	
	printf("\n\n***** CONO *****");
	printf("\nIntroduzca el radio del cono: ");
	scanf("%f", &vol.co.radio);
	printf("\nIntroduzca la altura del cono: ");
	scanf("%f", &vol.co.h);
	vol.volCono = (pi * (vol.co.radio * vol.co.radio) * vol.co.h) / 3;
	printf("\nEl volumen del cono es: %.2f", vol.volCono);
	
	printf("\n\n***** ESFERA *****");
	printf("\nIntroduzca el radio de la esfera: ");
	scanf("%f", &vol.es.radio);
	vol.volEsfera = ((4) * pi * (vol.es.radio * vol.es.radio * vol.es.radio)) / 3;
	printf("\nEl volumen de la esfera es: %.2f", vol.volEsfera);
	return 0;
}
