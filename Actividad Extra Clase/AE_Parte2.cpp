#include<stdio.h>
#include <stdlib.h>

typedef struct { 
		char nombreMat[30]; 
		float calif[3]; 
		float promMat;
} MAT;

typedef struct { 
	long int *matricula; 
	char nombre[30]; 
	int nMaterias;
	MAT *materias;
	float prom;
} ESTP;

void estrucuraPunteros();
void mostrarEstrucuraPunteros(ESTP *, int);

int main() {
	estrucuraPunteros();
	return 0;
}

void estrucuraPunteros() {
	// Estructura - Punteros
	
	printf("***** Estructura - Punteros *****\n\n");
	
	int n, i, j, k;
	
	// Declarar variable de estudiantes
	ESTP *e;
	
	// Validar estudiantes
	do{
		printf("Introduzca numero de estudiantes: ");
		scanf("%d", &n);
	
		if(n <= 0 || n > 40) { printf("\nEl numero de estudiantes debe ser entre 1 y 40!!!\n\n"); }

	}while(n <= 0 || n > 40);
	
	// Reservar memoria para EST
	e = (ESTP *) malloc(n*sizeof(ESTP));
	
	// Reservar Memoria para matriculas
	for(i = 0; i < n; i++) {
		e->matricula = (long int *) malloc(sizeof(long int));	
		e++;
	}
	
	// Regresar a la direccion de memoria inicial
	e = e - n;
	
	for(int i = 0; i < n; i++) {
		printf("\n*** ESTUDIANTE #%d ***\n", (i+1));
		
		printf("Matricula: "); 
		scanf("%d", e->matricula);
		
		fflush(stdin);
		printf("Nombre: "); 
		gets(e->nombre);
	
		do{
			printf("Numero de materias: ");
			scanf("%d", &e->nMaterias);
			
			if(e->nMaterias < 0 || e->nMaterias > 15) {
				printf("La cantidad de materias debe ser entre 1 y 15!!!\n");	
			}
			
		}while(e->nMaterias < 0 || e->nMaterias > 15);
		
		e->prom = 0;
		
		// Reservar memoria para MAT
		e->materias = (MAT *) malloc(e->nMaterias*sizeof(MAT));
		
		for(j = 0; j < e->nMaterias; j++) {
			printf("\n\n*** MATERIA #%d ***\n", (j+1));
			
			printf("Nombre Materia: ");
			fflush(stdin);
			gets(e->materias->nombreMat);
			
			e->materias->promMat = 0;
			
			for(k = 0; k < 3; k++) {
				do{
					printf("Calificacion Parcial %d: ", (k+1));
					scanf("%f", &e->materias->calif[k]);
					
					if(e->materias->calif[k] < 0 || e->materias->calif[k] > 10) {
						printf("La calificacion debe ser entre 0 y 10!!!\n");
					}
					
					e->materias->promMat += e->materias->calif[k];
					
				}while(e->materias->calif[k] < 0 || e->materias->calif[k] > 10);
				
			}
			
			e->materias->promMat = (e->materias->promMat)/3;
			
			e->prom += e->materias->promMat;
			
			e->materias++;	
		}
		
		e->materias = e->materias - e->nMaterias;
		
		e->prom = (e->prom)/(e->nMaterias);
		
		e++;
		
	}
	
	// Regresar a la direccion de memoria inicial
	e = e - n;
	
	// Llamar a la funcion mostrar
	mostrarEstrucuraPunteros(e, n);
	
	// Liberar Memoria
	for(i = 0; i < n; i++) {
		free(e->matricula);
		e++;
	}
	
	// Regresar a la direccion de memoria inicial
	e = e - n;
	
	free(e->materias);
	free(e);
}

void mostrarEstrucuraPunteros(ESTP *e, int n) {
	int i, j;
	// MOSTRAR DATOS
	for(i = 0; i < n; i++) {
		printf("\n\n***** DATOS DEL ALUMNO #%d *****\n", (i+1));
		
		printf("Matricula: %ld\n", *e->matricula);
		printf("Nombre: %s\n", e->nombre);
		printf("Materias: \n");
		
		for(j = 0; j < e->nMaterias; j++) {
			printf("\tNombre: %s\n", e->materias->nombreMat);
			printf("\tPromedio de la Materia: %.2f\n\n", e->materias->promMat);
			e->materias++;
		}
		
		e->materias = e->materias - e->nMaterias;
		
		printf("Promedio Total: %.2f\n", e->prom);
		
		e++;
	}
	
	// Regresar a la direccion de memoria inicial
	e = e - n;
}
