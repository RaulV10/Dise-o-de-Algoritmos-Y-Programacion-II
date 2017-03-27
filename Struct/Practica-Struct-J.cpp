//
//  Practicta-Struct-J.cpp
//
//
//  Created by Raul Villarreal on 3/21/17.
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
	peliculas pelicula[50];
	int numPel;
	float total;
}renta;

void mostrarPeliculas(renta[], int);

int main() {
	int nr, i, j;
	renta r[50];
	
	// Validar rentas negativas
	do{
		printf("Numero de Rentas: ");
		scanf("%d", &nr);
		
		if(nr <= 0) {
			printf("\nSolo datos mayores a 0!\n\n");
		}
	}while(nr <= 0);
	
	// Reservar memoria para rentas
	//r = (renta *) malloc(nr*sizeof(renta));
		
	// Almacenar Informacion
	for(j = 0; j < nr; j++) {
		printf("\n***** RENTA #%d *****\n\n", (j + 1));
		printf("Fecha de Renta: ");
		fflush(stdin);
		gets(r[j].fecha);
		
		printf("Nombre del Cliente: ");
		fflush(stdin);
		gets(r[j].nombreCliente);
		
		printf("Numero de Peliculas: ");
		scanf("%d", &r[j].numPel);
		
		// Reserva de Memoria
		//r->pelicula = (peliculas *) malloc(r->numPel*sizeof(peliculas));
		
		r[j].total = 0;
		
		for(i = 0; i < r[j].numPel; i++){
			r[j].pelicula[i].nombrePel = (char *) malloc(20*sizeof(char));
			r[j].pelicula[i].precio = (float *) malloc(sizeof(float));
			//r->pelicula++;
		}
		
		// Regresar a la direccion de memoria inicial
		//r->pelicula = r->pelicula - r->numPel;
		
		// Almacenar Informacion
		for(i = 0; i < r[j].numPel; i++) {
			printf("\n***** PELICULA #%d*****\n\n", (i+1));
			printf("Id: ");
			scanf("%ld", &r[j].pelicula[i].id);
			
			printf("Nombre de Pelicula: ");
		    scanf("%s", r[j].pelicula[i].nombrePel);
		    
			do{
				printf("Precio: $");
				scanf("%f", r[j].pelicula[i].precio);
				
				if(*r[j].pelicula[i].precio <= 0) {
					printf("El precio no puede ser negativo!\n");
				}
			}while(*r[j].pelicula[i].precio <= 0 );
				
			r[j].total += (*r[j].pelicula[i].precio);
			
			//r->pelicula++;
		}
		
		//r->pelicula = r->pelicula - r->numPel;
		
		//r++;
		
	}
	
	// Regresar a la direccion de memoria inicial
	//r = r - nr;
	
	// Llamar a la funcion para mostrar datos de la pelicula
	mostrarPeliculas(r, nr);
	
	// Liberar Memoria
	for(i = 0; i < r[j].numPel; i++) {
		free(r[j].pelicula[i].nombrePel);
		free(r[j].pelicula[i].precio);
		//r->pelicula++;
	}
	
	// Regresar a la direccion de memoria inicial
	//r->pelicula = r->pelicula - r->numPel;
	
	// Liberar Memoria para Pelicula
	//free(r->pelicula);
	//free(r);
	
	return 0;
}

// Funciones
void mostrarPeliculas(renta r[], int nr) {
	int i, j;

	for(j = 0; j < nr; j++) {
		printf("\n\n***** DATOS DE LA RENTA #%d *****\n\n", (j+1));
		printf("Fecha: %s\n", r[j].fecha);
		printf("Cliente: %s\n", r[j].nombreCliente);
				
		printf("\n\n***** DATOS DE LAS PELICULAS RENTA #%d *****\n\n", (j+1));
		
		for(i = 0; i < r[j].numPel; i++) {
			printf("Id: %ld\n", r[j].pelicula[i].id);
			printf("Nombre: %s\n", r[j].pelicula[i].nombrePel);
			printf("Precio: $%.2f\n", *r[j].pelicula[i].precio);
			printf("\n");
			//r->pelicula++;
		}
		
		printf("\n-------------------------\n");
		
		// Regresar a la direccion de memoria inicial
		//r->pelicula = r->pelicula - r->numPel;
		
		printf("Total Renta #%d: %.2f\n",(j+1), r[j].total);
		
		//r++;
	}
	// Regresar a la direccion de memoria inicial
	//r = r - nr;
}
