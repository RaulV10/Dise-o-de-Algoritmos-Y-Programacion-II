//
//  Practicta-Struct-G.cpp
//
//
//  Created by Raul Villarreal on 3/13/17.
//
//

#include<stdio.h>
#include <stdlib.h>

typedef struct {
    long int id;
    char *nombrePel;
    float *precio;
}peliculas;

typedef struct {
	char fecha[30];
	char nombreCliente[30];
	peliculas *pelicula;
	float total;
}renta;

void mostrarPeliculas(renta, int);

int main() {
	int n, i;
	renta r;
		
	// Almacenar Informacion
	printf("\n***** RENTA *****\n\n");
	printf("Fecha de Renta: ");
	fflush(stdin);
	gets(r.fecha);
	
	printf("Nombre del Cliente: ");
	fflush(stdin);
	gets(r.nombreCliente);
	
	// Validar datos negativos
	do{
		printf("Numero de Peliculas: ");
		scanf("%d", &n);
		
		if(n <= 0) {
			printf("\nSolo datos mayores a 0!\n\n");
		}
	}while(n <= 0);
	
	
	// Reserva de Memoria
	r.pelicula = (peliculas *) malloc(n*sizeof(peliculas));
	
	for(i = 0; i < n; i++){
		r.pelicula->nombrePel = (char *) malloc(20*sizeof(char));
		r.pelicula->precio = (float *) malloc(sizeof(float));
		r.pelicula++;
	}
	
	// Regresar a la direccion de memoria inicial
	r.pelicula = r.pelicula - n;
	
	// Almacenar Informacion
	for(i = 0; i < n; i++) {
		printf("\n***** PELICULA #%d*****\n\n", (i+1));
		printf("Id: ");
		scanf("%ld", &r.pelicula->id);
		
		printf("Nombre de Pelicula: ");
	    scanf("%s", r.pelicula->nombrePel);
	    
		do{
			printf("Precio: $");
			scanf("%f", r.pelicula->precio);
			
			if(*r.pelicula->precio <= 0) {
				printf("El precio no puede ser negativo!\n");
			}
		}while(*r.pelicula->precio <= 0 );
			
		r.total += *r.pelicula->precio;
		
		r.pelicula++;
	}
	
	// Regresar a la direccion de memoria inicial
	r.pelicula = r.pelicula - n;
	
	// Llamar a la funcion para mostrar datos de la pelicula
	mostrarPeliculas(r, n);
	
	// Liberar Memoria
	for(i = 0; i < n; i++) {
		free(r.pelicula->nombrePel);
		free(r.pelicula->precio);
		r.pelicula++;
	}
	
	// Regresar a la direccion de memoria inicial
	r.pelicula = r.pelicula - n;
	
	// Liberar Memoria para Pelicula
	free(r.pelicula);
	
	return 0;
}

// Funciones
void mostrarPeliculas(renta r, int p) {
	int i;

	printf("\n\n***** DATOS DE LA RENTA *****\n\n");
	printf("Fecha: %s\n", r.fecha);
	printf("Cliente: %s\n", r.nombreCliente);
	
	printf("\n\n***** DATOS DE LAS PELICULAS *****\n\n");
	
	for(i = 0; i < p; i++) {
		printf("Id: %ld\n", r.pelicula->id);
		printf("Nombre: %s\n", r.pelicula->nombrePel);
		printf("Precio: $%.2f\n", *r.pelicula->precio);
		printf("\n");
		r.pelicula++;
	}
	
	printf("\n-------------------------\n");
	printf("Total: %.2f\n", r.total);
	
	// Regresar a la direccion de memoria inicial
	r.pelicula = r.pelicula - p;
	
}
