//
//  Practicta-Struct-B.cpp
//
//
//  Created by Raul Villarreal on 3/6/17.
//
//

#include<stdio.h>
#include <stdlib.h>

typedef struct {
    long int id;
    char *nombrePel;
    float *precio;
}peliculas;

void mostrarPeliculas(peliculas *);

int main() {
	
	peliculas *p;
	
	// Reservar memoria para "p"
	p = (peliculas *) malloc(sizeof(peliculas));
	
	// Reservar Memoria
	p->nombrePel = (char *) malloc(20*sizeof(char));
	p->precio = (float *) malloc(sizeof(float));
	
	// Introducir Informacion
	printf("Id: ");
	scanf("%ld", &p->id);
	
	printf("Nombre de Pelicula: ");
	scanf("%s", p->nombrePel);
	
	do{
		printf("Precio: $");
		scanf("%f", p->precio);
		
		if(*p->precio <= 0) {
			printf("El precio no puede ser negativo!\n");
		}
	}while(*p->precio <= 0 );
	
	// Llamar a la funcion para mostrar datos de la pelicula
	mostrarPeliculas(p);
	
	// Liberar Memoria
	free(p->nombrePel);
	free(p->precio);
	free(p);
		
	return 0;
}

// Funciones
void mostrarPeliculas(peliculas *pelicula) {
	printf("\n\n***** DATOS DE LA PELICULA *****\n\n");
	printf("ID: %ld\n", pelicula->id);
	printf("NOMBRE: %s\n", pelicula->nombrePel);
	printf("PRECIO: %.2f\n", *pelicula->precio);
}
