// Raul Ernesto Villarreal Sigala - 301654
// Diseño De Algoritmos Y Su Programacion II
// Examen Parcial II - Estructuras
// Universidad Autonoma de Chihuahua

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Estructuras
typedef struct {
	long int id; // Numero o clave de la pelicula
	char *nombrePel; // nombre de la pelicula
	char *fechaEntrega; // Fecha de entrega de la pelicula
	int tipo; // Categoria y Costo
}pelicula;

typedef struct {
	long int *folio; // Numero o id de la renta
	char *nombre; // Nombre de la persona que renta la pelicula
	pelicula pelis[30]; // Las peliculas a rentar con arreglos
	float totalPagar; // Total a pagar -> Este debe ser calculado con cada pelicula (costo de renta)
	int cuantasPel; // Numero de peliculas a rentar
}rentaPel;

// Estructura que tiene peliculas como puntero
typedef struct {
	long int *folio; // Numero o id de la renta
	char *nombre; // Nombre de la persona que renta la pelicula
	pelicula *pelis; // Las peliculas a rentar con punteros
	float totalPagar; // Total a pagar -> Este debe ser calculado con cada pelicula (costo de renta)
	int cuantasPel; // Numero de peliculas a rentar
}rentaPelPuntero;

// Mostrar Menu, Repetir y Limpiar Pantalla
int menu();
bool repetir();
void limpiarPantalla();

// Funciones para leer datos
void estructuraArreglos();
void estructuraPunteros();

// Funciones para mostrar
void mostrarEstructuraArreglos(rentaPel[], int);
void mostrarEstructuraPunteros(rentaPelPuntero *, int);

int main() {
	int opc;
	const char apellido[11] = "VILLARREAL";
	char *password;
	
	// Reservar memoria para la contraseña
	password = (char *) malloc(20*sizeof(char));

	do {
	opc = menu();
		
		switch(opc){
			case 1:
				limpiarPantalla();
				estructuraArreglos();
				break;
			case 2:
				limpiarPantalla();
				estructuraPunteros();
				break;
			case 3:
				do {
					printf("Introduzca la contrase%ca: ", 164);
					fflush(stdin);
					scanf("%s", password);
					
					// Comparara que la contraseña ingresada y el apellido coincidan
					if(strcmp(password, apellido) == 0) {
						// Si conincide salir del programa
						printf("\n********** ADIOS **********\n");
						break;
					} else {
						printf("Contrase%ca incorrecta!\n", 164);
						printf("Pista, la contrase%ca es en mayusculas\n", 164);
					}
					
				} while(strcmp(password, apellido) != 0);
				exit(EXIT_SUCCESS);
				break;
			default:
				printf("error");
				break;
		}
	}while(repetir());
	
	free(password);
	return 0;
}

int menu() {
	limpiarPantalla();
	
	int opc = 0;
	
	printf("\n************* MENU *************\n\n");
	
	printf("1) Estructura - Arreglos\n");
	printf("2) Estructura - Punteros\n");
	printf("3) Salir\n");
	
	do {
		printf("\nSeleccione una opcion: ");
		scanf("%d", &opc);
		
		if(opc < 1 || opc > 3) {
			printf("Opcion Invalida!\nPor favor intente de nuevo.\n");	
		}
		
	} while(opc < 1 || opc > 3);
	
	return opc;
}

bool repetir() {
	int opc = 0;
	const char apellido[11] = "VILLARREAL";
	char *password;
	
	// Reservar memoria para la contraseña
	password = (char *) malloc(20*sizeof(char));
	
	printf("\n\n************* MENU *************\n");
	
	printf("1) Menu Principal\n");
	printf("2) Salir\n");
	
	do {
		printf("\nSeleccione una opcion: ");
		scanf("%d", &opc);
	} while(opc < 1 || opc > 2);
	
	if(opc == 1) {
		return true;
	} else {
		do {
			printf("Introduzca la contrase%ca: ", 164);
			fflush(stdin);
			scanf("%s", password);
			
			// Comparara que la contraseña ingresada y el apellido coincidan
			if(strcmp(password, apellido) == 0) {
				// Si conincide salir del programa
				printf("\n********** ADIOS **********\n");
				break;
			} else {
				printf("Contrase%ca incorrecta!\n", 164);
				printf("Pista, la contrase%ca es en mayusculas\n", 164);
			}
		} while(strcmp(password, apellido) != 0);
		return false;
	}
	
	free(password);
}

void limpiarPantalla() {
	system("cls");
}

void estructuraArreglos() {
	printf("***** Estructura - Arreglos *****\n\n");
	
	int n, i, j;
	int estreno = 0, normal = 0, promo = 0;
	
	// Validar Peliculas
	do{
		printf("Introduzca numero de rentas: ");
		scanf("%d", &n);
	
		if(n <= 0 || n > 40) { printf("\nEl numero de peliculas debe ser entre 1 y 40!!!\n\n"); }

	}while(n <= 0 || n > 40);
	
	// Declarar variable de peliculas
	rentaPel pel[n];
	
	// Reservar Memoria para folio y nombre en la estructura rentaPel;
	for(i = 0; i < n; i++) {
		pel[i].folio = (long int *) malloc(sizeof(long int));
		pel[i].nombre = (char *) malloc(20*sizeof(char));
	}
	
	for(int i = 0; i < n; i++) {
		printf("\n*** RENTA #%d ***\n", (i+1));
		
		printf("Folio: ");
		scanf("%ld", &pel[i].folio);
		
		fflush(stdin);
		printf("Nombre: "); 
		gets(pel[i].nombre);
	
		do{
			printf("Numero de peliculas: ");
			scanf("%d", &pel[i].cuantasPel);
			
			if(pel[i].cuantasPel < 0 || pel[i].cuantasPel > 30) {
				printf("La cantidad de peliculas debe ser entre 1 y 30!\n");	
			}
			
		}while(pel[i].cuantasPel < 0 || pel[i].cuantasPel > 30);
		
		pel[i].totalPagar = 0;
		
		for(j = 0; j < pel[i].cuantasPel; j++) {
			
			// Reservar Memoria para nombre de pelicula y fecha de entrega en la estructura peliculas
			pel[i].pelis[j].nombrePel = (char *) malloc(20*sizeof(char));
			pel[i].pelis[j].fechaEntrega = (char *) malloc(20*sizeof(char));
			
			printf("\n\n*** PELICULA #%d ***\n", (j+1));
			
			printf("Id: ");
			scanf("%ld", &pel[i].pelis[j].id);
			
			printf("Nombre de Pelicula: ");
			fflush(stdin);
			gets(pel[i].pelis[j].nombrePel);
			
			printf("Fecha de Entrega: ");
			fflush(stdin);
			gets(pel[i].pelis[j].fechaEntrega);
			
			do {
				printf("\nTipo\t\tCategoria\t\tCosto");
				printf("\n1\t\tEstreno\t\t\t$25.00");
				printf("\n2\t\tNormal\t\t\t$20.00");
				printf("\n3\t\tPromocion\t\t$10.00");
				printf("\n\nSeleccione el Tipo de Pelicula: ");
				scanf("%d", &pel[i].pelis[j].tipo);
				if(pel[i].pelis[j].tipo == 1) {
					estreno++;
				} else if(pel[i].pelis[j].tipo == 2) {
					normal++;
				} else if(pel[i].pelis[j].tipo == 3) {
					promo++;
				} else {
					printf("Tipo de Pelicula Invalido!\n");
				}
			}while(pel[i].pelis[j].tipo < 1 || pel[i].pelis[j].tipo > 3);
			
		}
		
		// Obtener el total a pagar
		pel[i].totalPagar = (estreno * 25) + (normal * 20) + (promo * 10);
		
		// Regresar Valores a 0
		estreno = 0;
		normal = 0;
		promo = 0;
	}
	
	// Llamar a la funcion
	mostrarEstructuraArreglos(pel, n);
	
	system("pause");
	limpiarPantalla();
}

void mostrarEstructuraArreglos(rentaPel pel[], int n) {
	int i, j;
	
	// MOSTRAR DATOS
	for(i = 0; i < n; i++) {
		printf("\n\n***** DATOS DE LA RENTA #%d *****\n", (i+1));
		
		printf("Folio: %ld\n", pel[i].folio);
		printf("Nombre: %s\n", pel[i].nombre);
		printf("Peliculas Rentadas: \n");
		
		for(j = 0; j < pel[i].cuantasPel; j++) {
			printf("\tNombre: %s\n", pel[i].pelis[j].nombrePel);
			printf("\tFecha de Entrega: %s\n", pel[i].pelis[j].fechaEntrega);
			if(pel[i].pelis[j].tipo == 1) {
				printf("\tTipo: Estreno\n");
			} else if(pel[i].pelis[j].tipo == 2) {
				printf("\tTipo: Normal\n");
			} else if(pel[i].pelis[j].tipo == 3) {
				printf("\tTipo: Promocion\n");
			}
			printf("\n");
		}
		
		printf("\nPrecio Total: %.2f\n", pel[i].totalPagar);
	}
}

void estructuraPunteros() {
	printf("***** Estructura - Punteros *****\n\n");
	
	int n, i, j;
	int estreno = 0, normal = 0, promo = 0;
	
	// Declarar variable de peliculas
	rentaPelPuntero *pel;
	
	// Validar Peliculas
	do{
		printf("Introduzca numero de rentas: ");
		scanf("%d", &n);
	
		if(n <= 0 || n > 40) { printf("\nEl numero de peliculas debe ser entre 1 y 40!!!\n\n"); }

	}while(n <= 0 || n > 40);
	
	// Reservar memoria para rentaPelPuntero
	pel = (rentaPelPuntero *) malloc(n*sizeof(rentaPelPuntero));
	
	
	// Reservar Memoria para folio y nombre en la estructura rentaPel;
	for(i = 0; i < n; i++) {
		pel->folio = (long int *) malloc(sizeof(long int));
		pel->nombre = (char *) malloc(20*sizeof(char));
		pel++;
	}
	
	// Regresar a la direccion de memoria inicial
	pel = pel - n;
	
	for(int i = 0; i < n; i++) {
		printf("\n*** RENTA #%d ***\n", (i+1));
		
		printf("Folio: ");
		scanf("%ld", &pel->folio);
		
		fflush(stdin);
		printf("Nombre: "); 
		gets(pel->nombre);
	
		do{
			printf("Numero de peliculas: ");
			scanf("%d", &pel->cuantasPel);
			
			if(pel->cuantasPel < 0 || pel->cuantasPel > 30) {
				printf("La cantidad de peliculas debe ser entre 1 y 30!\n");	
			}
			
		}while(pel->cuantasPel < 0 || pel->cuantasPel > 30);
		
		pel->totalPagar = 0;
		
		// Reservar memoria para pelicula
		pel->pelis = (pelicula *) malloc(pel->cuantasPel*sizeof(pelicula));
		
		for(j = 0; j < pel->cuantasPel; j++) {
			
			// Reservar Memoria para nombre de pelicula y fecha de entrega en la estructura peliculas
			pel->pelis->nombrePel = (char *) malloc(20*sizeof(char));
			pel->pelis->fechaEntrega = (char *) malloc(20*sizeof(char));
			
			printf("\n\n*** PELICULA #%d ***\n", (j+1));
			
			printf("Id: ");
			scanf("%ld", &pel->pelis->id);
			
			printf("Nombre de Pelicula: ");
			fflush(stdin);
			gets(pel->pelis->nombrePel);
			
			printf("Fecha de Entrega: ");
			fflush(stdin);
			gets(pel->pelis->fechaEntrega);
			
			do {
				printf("\nTipo\t\tCategoria\t\tCosto");
				printf("\n1\t\tEstreno\t\t\t$25.00");
				printf("\n2\t\tNormal\t\t\t$20.00");
				printf("\n3\t\tPromocion\t\t$10.00");
				printf("\n\nSeleccione el Tipo de Pelicula: ");
				scanf("%d", &pel->pelis->tipo);
				if(pel->pelis->tipo == 1) {
					estreno++;
				} else if(pel->pelis->tipo == 2) {
					normal++;
				} else if(pel->pelis->tipo == 3) {
					promo++;
				} else {
					printf("Tipo de Pelicula Invalido!\n");
				}
			}while(pel->pelis->tipo < 1 || pel->pelis->tipo > 3);
			
			pel->pelis++;
		}
		
		// Regresar a la posicion de memoria inicial
		pel->pelis = pel->pelis - pel->cuantasPel;
		
		// Obtener el total a pagar
		pel->totalPagar = (estreno * 25) + (normal * 20) + (promo * 10);
		
		// Regresar Valores a 0
		estreno = 0;
		normal = 0;
		promo = 0;
		
		pel++;
	}
	
	// Regresar a la direccion de memoria inicial
	pel = pel - n;
	
	// Llamar a la funcion
	mostrarEstructuraPunteros(pel, n);
	
	// Liberar Memoria
	free(pel->pelis);
	free(pel);
	
	system("pause");
	limpiarPantalla();
}

void mostrarEstructuraPunteros(rentaPelPuntero *pel, int n) {
	int i, j;
	
	// MOSTRAR DATOS
	for(i = 0; i < n; i++) {
		printf("\n\n***** DATOS DE LA RENTA #%d *****\n", (i+1));
		
		printf("Folio: %ld\n", pel->folio);
		printf("Nombre: %s\n", pel->nombre);
		printf("Peliculas Rentadas: \n");
		
		for(j = 0; j < pel->cuantasPel; j++) {
			printf("\tNombre: %s\n", pel->pelis->nombrePel);
			printf("\tFecha de Entrega: %s\n", pel->pelis->fechaEntrega);
			if(pel->pelis->tipo == 1) {
				printf("\tTipo: Estreno\n");
			} else if(pel->pelis->tipo == 2) {
				printf("\tTipo: Normal\n");
			} else if(pel->pelis->tipo == 3) {
				printf("\tTipo: Promocion\n");
			}
			printf("\n");
		}
		
		printf("\nPrecio Total: %.2f\n", pel[i].totalPagar);
		
		pel++;
	}
	
	pel = pel - n;
}
