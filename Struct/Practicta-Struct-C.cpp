//
//  Practicta-Struct-C.cpp
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

void mostrarPeliculas(peliculas *, int);

int main() {
	int n, i;
	peliculas *p;
	
	do{
		printf("Introduzca el numero de peliculas a registrar: ");
		scanf("%d", &n);
		
		if(n<=0) {
			printf("\nIntroduzca un numero mayor a 0\n");
		}
	}while(n<=0);
	
	// Reservar memoria para "p"
	p = (peliculas *) malloc(n*sizeof(peliculas));
	
	// Reservar Memoria
	for(i = 0; i < n; i++) {
		p->nombrePel = (char *) malloc(20*sizeof(char));
		p->precio = (float *) malloc(sizeof(float));
		
		// Cambiar a la siguiente pelicula para reservar memoria
		p++;
	}
	
	// Regresar a la pelicula inicial
	p = p - n;
	
	// Almacenar Informacion de las Peliculas
	for(i = 0; i < n; i++) {
		printf("PELICULA #%d\n", i+1);
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
		
		// Cambiar a la siguiente pelicula
		p++;
	}
	
	// Regresar a la pelicula inicial
	p = p - n;
	
	// Llamar a la funcion para mostrar datos de la pelicula
	mostrarPeliculas(p, n);
	
	// Liberar Memoria
	for(i = 0; i < n; i++) {
		free(p->nombrePel);
		free(p->precio);
		
		p++;
	}
	
	// Regresar a la pelicula inicial
	p = p - n;
	
	// Liberar Memoria
	free(p->nombrePel);
	free(p->precio);
	free(p);
	
	return 0;
}

// Funciones
void mostrarPeliculas(peliculas *pelicula, int n) {
	int i;
	
	for(i = 0; i < n; i++) {
		printf("\n\n***** DATOS DE LA PELICULA #%d *****\n\n", i+1);
		printf("ID: %ld\n", pelicula->id);
		printf("NOMBRE: %s\n", pelicula->nombrePel);
		printf("PRECIO: %.2f\n", *pelicula->precio);
		
		pelicula++;
	}
	
	pelicula = pelicula - n;
}
