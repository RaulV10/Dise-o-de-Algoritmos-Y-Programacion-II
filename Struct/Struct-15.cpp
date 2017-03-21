//
//  Struct-15.cpp
//
//
//  Created by Raul Villarreal on 3/21/17.
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
	alumnos alumno[50];
	float promedioGeneral;
	int numAlumnos;
}materias;

void mostrar(materias [], int);

int main() {
	materias m[50];
	int i, j, numMaterias;
	
	// Pedir el numero de materias a evaluar
	do{
		printf("Numero de Materias: ");
		scanf("%d", &numMaterias);
		
		if(numMaterias <= 0) {
			printf("\nEl numero de materias debe ser un valor mayor a 0!\n\n");
		}
		
	}while(numMaterias <= 0);
	
	// Reservar Memoria a Materias
	//m = (materias *) malloc(numMaterias*sizeof(materias));
	
	// Almacenar informacion
	for(j = 0; j < numMaterias; j++) {
		printf("***** Materia #%d*****\n", (j+1));
		printf("Clave de materia: ");
		fflush(stdin);
		gets(m[j].claveMateria);
		
		printf("Nombre de materia: ");
		fflush(stdin);
		gets(m[j].nombreMateria);
		printf("Numero de alumnos: ");
		scanf("%d", &m[j].numAlumnos);
		
		// Reservar Memoria
		//m->alumno = (alumnos *) malloc(m->numAlumnos*sizeof(alumnos));
		
		for(i = 0; i < m[j].numAlumnos; i++) {
			m[j].alumno[i].matricula = (long int*) malloc(sizeof(long int));
			m[j].alumno[i].nombre = (char *) malloc(20*sizeof(char));
			//m->alumno++;
		}
		
		// Regresar a la direccion de memoria inicial
		//m->alumno = m->alumno - m->numAlumnos;
		
		// Almacenar Informacion
		for(i = 0; i < m[j].numAlumnos; i++) {
			
			printf("***** Alumno #%d *****\n", (i+1));
			
			printf("Matricula: ");
			scanf("%ld", m[j].alumno[i].matricula);
			
			printf("Nombre: ");
			scanf("%s", m[j].alumno[i].nombre);
			
			do {
				printf("Introduzca Promedio: ");
				scanf("%f", &m[j].alumno[i].promedio);
				if(m->alumno[i].promedio < 0 || m[j].alumno[i].promedio > 10) {
					printf("Error: Promedio fuera de rango");
				}
			}while(m[j].alumno[i].promedio < 0 || m[j].alumno[i].promedio > 10);
			
			//m->alumno++;
		}
		
		// Regresar a la direccion de memoria inicial
		//m->alumno = m->alumno - m->numAlumnos;
		
		// Avanza a la siguiente direccion de memoria para materias
		//m++;
	}
	
	// Regresar a la direccion inicial
	//m = m - numMaterias;
	
	// Llamar a la funcion Mostrasr
	mostrar(m, numMaterias);
	
	// Liberar Memoria
	for(j=0; j<numMaterias; j++) {
		for(i = 0; i < m->numAlumnos; i++) {
			free(m[j].alumno[i].matricula);
			free(m[j].alumno[i].nombre);
			//m->alumno++;
		}
	}
	
	
	// Regresar a la direccion de memoeria inicial
	//m->alumno = m->alumno - m->numAlumnos;
	
	// Liberar Memoria Para Alumno
	//free(m->alumno);
	//free(m);
	
	return 0;
}

void mostrar(materias m[], int nm) {
	
	int i, j;
	
	// Mostrar Informacino
	for(j = 0; j < nm; j++) {
		printf("\n***** INFORMACION DE LA MATERIA #%d *****\n", (j+1));
		printf("Clave de la materia: %s\n", m[j].claveMateria);
		printf("Nombre de la materia: %s\n", m[j].nombreMateria);
		
		for(i = 0; i < m->numAlumnos; i++) {
			printf("\n ***** DATOS DEL ALUMNO #%d ***** \n", (i+1));
			printf("Matricula: %ld\n", *m[j].alumno[i].matricula);
			printf("Nombre: %s\n", m[j].alumno[i].nombre);
			printf("Promedio: %.2f\n", m[j].alumno[i].promedio);	
			
			//m->alumno++;
		}
		
		// Regresar a la direccion de memoria inicial
		//m->alumno = m->alumno - m->numAlumnos;
		
		//m++;
	}
	
	// Regresar a la direccion de memoria inicial
	//m = m - nm;
}
