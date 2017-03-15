//
//  Practicta-Struct-F.cpp
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

void mostrarPeliculas(renta *);

int main() {
	renta *r;
	
	// Reserva de Memoria
	r = (renta *) malloc(sizeof(renta));
	r->pelicula = (peliculas *) malloc(sizeof(peliculas));
	r->pelicula->nombrePel = (char *) malloc(20*sizeof(char));
	r->pelicula->precio = (float *) malloc(sizeof(float));

	
	// Almacenar Informacion
	printf("\n***** RENTA *****\n\n");
	printf("Fecha de Renta: ");
	fflush(stdin);
	gets(r->fecha);
	
	printf("Nombre del Cliente: ");
	fflush(stdin);
	gets(r->nombreCliente);
	
	printf("\n***** PELICULA *****\n\n");
	printf("Id: ");
	scanf("%ld", &r->pelicula->id);
	
	printf("Nombre de Pelicula: ");
    scanf("%s", r->pelicula->nombrePel);
    
	do{
		printf("Precio: $");
		scanf("%f", r->pelicula->precio);
		
		if(*r->pelicula->precio <= 0) {
			printf("El precio no puede ser negativo!\n");
		}
	}while(*r->pelicula->precio <= 0 );
		
	r->total = *r->pelicula->precio;
	
	// Llamar a la funcion para mostrar datos de la pelicula
	mostrarPeliculas(r);
	
	// Liberar Memoria
	free(r->pelicula->nombrePel);
	free(r->pelicula->precio);
	free(r->pelicula);
	free(r);
	
	return 0;
}

// Funciones
void mostrarPeliculas(renta *r) {

	printf("\n\n***** DATOS DE LA RENTA *****\n\n");
	printf("Fecha: %s\n", r->fecha);
	printf("Cliente: %s\n", r->nombreCliente);
	printf("\n\n***** DATOS DE LA PELICULA *****\n\n");
	printf("Id: %ld\n", r->pelicula->id);
	printf("Nombre: %s\n", r->pelicula->nombrePel);
	printf("\n-------------------------\n");
	printf("Total: %.2f\n", r->total);
	
}
