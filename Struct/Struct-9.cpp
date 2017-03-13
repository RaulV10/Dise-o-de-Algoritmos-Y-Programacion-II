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
    long int *matricula;
    char *nombre;
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
	m.alumno.nombre = (char *) malloc(20*sizeof(char));
	
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
	
	// Llamar a la funcion Mostrasr
	mostrar(m);
	
	// Liberar Memoria
	free(m.alumno.matricula);
	free(m.alumno.nombre);
	
	return 0;
}

void mostrar(materias m) {
	
	// Mostrar Informacino
	printf("\n***** INFORMACION DE LA MATERIA *****\n");
	printf("Clave de la materia: %s\n", m.claveMateria);
	printf("Nombre de la materia: %s\n", m.nombreMateria);
	
	printf("\n ***** DATOS DEL ALUMNO ***** \n");
	printf("Matricula: %ld\n", *m.alumno.matricula);
	printf("Nombre: %s\n", m.alumno.nombre);
	printf("Promedio: %.2f\n", m.alumno.promedio);
	
}
