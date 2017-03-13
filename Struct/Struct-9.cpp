//
//  Struct-9.cpp
//
//
//  Created by Raul Villarreal on 3/8/17.
//
//

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    long int matricula;
    char nombre[30];
    float promedio;
}alumnos;

typedef struct {
	char claveMateria[30];
	char nombreMateria[30];
	alumnos alumno;
	float promedioGeneral;
	int numAlumnos;
}materias;

void mostrar(materias);

int main() {
	materias m;
	
	// Reservar Memoria
	m.alumno.matricula = (long int*) malloc(sizeof(long int));
	m.alumno.nombre = (char *) malloc(sizeof(char));
	
	// Almacenar informacion
	printf("Clave de materia: ");
	fflush(stdin);
	gets(m.claveMateria);
	
	printf("Nombre de materia: ");
	fflush(stdin);
	gets(m.nombreMateria);
	
	printf("Alumno\n");
	
	printf("Matricula: ");
	scanf("%ld", m.alumno.matricula);
	
	printf("Nombre: ");
	scanf("%s", m.alumno.nombre);
	
	do {
		printf("Introduzca Promeio: ");
		scanf("%f", &m.alumno.promedio);
		if(m.alumno.promedio < 0 || m.alumno.promedio > 10) {
			printf("Error: Promedio fuera de rango");
		}
	}while(m.alumno.promedio < 0 || m.alumno.promedio > 10);
	
	// Mostrar Informacino
	
	return 0;
}
