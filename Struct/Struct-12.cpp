//
//  Struct-12.cpp
//
//
//  Created by Raul Villarreal on 3/13/17.
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
	alumnos *alumno;
	float promedioGeneral;
	int numAlumnos;
}materias;

void mostrar(materias *);

int main() {
	materias *m;
	int i;
	
	// Reservar Memoria a Materias
	m = (materias *) malloc(sizeof(materias));
	
	// Almacenar informacion
	printf("***** Materia *****\n");
	printf("Clave de materia: ");
	fflush(stdin);
	gets(m->claveMateria);
	
	printf("Nombre de materia: ");
	fflush(stdin);
	gets(m->nombreMateria);
	printf("Numero de alumnos: ");
	scanf("%d", &m->numAlumnos);
	
	// Reservar Memoria
	m->alumno = (alumnos *) malloc(m->numAlumnos*sizeof(alumnos));
	
	for(i = 0; i < m->numAlumnos; i++) {
		m->alumno->matricula = (long int*) malloc(sizeof(long int));
		m->alumno->nombre = (char *) malloc(20*sizeof(char));
		m->alumno++;
	}
	
	// Regresar a la direccion de memoria inicial
	m->alumno = m->alumno - m->numAlumnos;
	
	// Almacenar Informacion
	for(i = 0; i < m->numAlumnos; i++) {
		
		printf("***** Alumno #%d *****\n", (i+1));
		
		printf("Matricula: ");
		scanf("%ld", m->alumno->matricula);
		
		printf("Nombre: ");
		scanf("%s", m->alumno->nombre);
		
		do {
			printf("Introduzca Promedio: ");
			scanf("%f", &m->alumno->promedio);
			if(m->alumno->promedio < 0 || m->alumno->promedio > 10) {
				printf("Error: Promedio fuera de rango");
			}
		}while(m->alumno->promedio < 0 || m->alumno->promedio > 10);
		
		m->alumno++;
	}
	
	// Regresar a la direccion de memoria inicial
	m->alumno = m->alumno - m->numAlumnos;
	
	// Llamar a la funcion Mostrasr
	mostrar(m);
	
	// Liberar Memoria
	for(i = 0; i < m->numAlumnos; i++) {
		free(m->alumno->matricula);
		free(m->alumno->nombre);
		m->alumno++;
	}
	
	// Regresar a la direccion de memoeria inicial
	m->alumno = m->alumno - m->numAlumnos;
	
	// Liberar Memoria Para Alumno
	free(m->alumno);
	free(m);
	
	return 0;
}

void mostrar(materias *m) {
	
	int i;
	
	// Mostrar Informacino
	printf("\n***** INFORMACION DE LA MATERIA *****\n");
	printf("Clave de la materia: %s\n", m->claveMateria);
	printf("Nombre de la materia: %s\n", m->nombreMateria);
	
	for(i = 0; i < m->numAlumnos; i++) {
		printf("\n ***** DATOS DEL ALUMNO #%d***** \n", (i+1));
		printf("Matricula: %ld\n", *m->alumno->matricula);
		printf("Nombre: %s\n", m->alumno->nombre);
		printf("Promedio: %.2f\n", m->alumno->promedio);	
		
		m->alumno++;
	}
	
	// Regresar a la direccion de memoria inicial
	m->alumno = m->alumno - m->numAlumnos;
}
