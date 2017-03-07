//
//  Practicta-Struct-D.cpp
//
//
//  Created by Raul Villarreal on 3/7/17.
//
//

#include<stdio.h>
#include <stdlib.h>

typedef struct {
    long int id;
    char *nombrePel;
    float *precio;
}peliculas;

void mostrarPeliculas(peliculas [], int);

int main() {
	int n, i;
	
	do{
		printf("Introduzca el numero de peliculas a registrar: ");
		scanf("%d", &n);
		
		if(n<=0) {
			printf("\nIntroduzca un numero mayor a 0\n");
		}
	}while(n<=0);
	
	peliculas p[n];
	
	// Reservar Memoria
	for(i = 0; i < n; i++) {
		p[i].nombrePel = (char *) malloc(20*sizeof(char));
		p[i].precio = (float *) malloc(sizeof(float));

	}

	
	// Almacenar Informacion de las Peliculas
	for(i = 0; i < n; i++) {
		printf("PELICULA #%d\n", i+1);
		printf("Id: ");
		scanf("%ld", &p[i].id);
		
		printf("Nombre de Pelicula: ");
        scanf("%s", p[i].nombrePel);
		
		do{
			printf("Precio: $");
			scanf("%f", p[i].precio);
			
			if(*p[i].precio <= 0) {
				printf("El precio no puede ser negativo!\n");
			}
		}while(*p[i].precio <= 0 );
		
	}
	
	// Llamar a la funcion para mostrar datos de la pelicula
	mostrarPeliculas(p, n);
	
	// Liberar Memoria
	for(i = 0; i < n; i++) {
		free(p[i].nombrePel);
		free(p[i].precio);

	}
	
	return 0;
}

// Funciones
void mostrarPeliculas(peliculas pelicula[], int n) {
	int i;
	
	for(i = 0; i < n; i++) {
		printf("\n\n***** DATOS DE LA PELICULA #%d *****\n\n", i+1);
		printf("ID: %ld\n", pelicula[i].id);
		printf("NOMBRE: %s\n", pelicula[i].nombrePel);
		printf("PRECIO: %.2f\n", *pelicula[i].precio);
	}
	
}
