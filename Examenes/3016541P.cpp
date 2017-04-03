#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Mostrar Menu
int menu();
bool repetir();

// Funciones en las que se pediran datos
void ordenarConsonantes();
void pila();

// Funciones en las que se mostraran datos y/o regresaran algun valor
void mostrarConsonantesOrdenadas(char *, int);
void mostrarPila(int *[10],int);

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
				ordenarConsonantes();
				break;
			case 2:
				pila();
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
	int opc = 0;
	char op;
	
	printf("\n************* MENU *************\n\n");
	
	printf("A) Ordenar Consonantes\n");
	printf("B) Pila Personas\n");
	printf("C) Salir\n");
	
	do {
		printf("\nSeleccione una opcion: ");
		scanf("%s", &op);
		
		// Validar que la opcion sea una de esas 3 letras y asignarle un valor numerico para usarlo como opcion
		if(op == 'A' || op == 'a') {
			opc = 1;
		} else if(op == 'B' || op == 'b') {
			opc = 2;
		} else if(op == 'C' || op == 'c') {
			opc = 3;
		} else {
			printf("Opcion Invalida!");
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

void ordenarConsonantes() {
	// Declaracion de variables
	char *palabra;
	int n = 0;
	
	// Reservar memoria para la palabra
	palabra = (char *) malloc(20*sizeof(char));
	
	// Pedir palabra
	printf("Introduzca la palabra: ");
	fflush(stdin);
	gets(palabra);
	
	// Obtener longitud de la palabra
	n = strlen(palabra);
	
	// Mostrar Informacion
    printf("\n********** Ordenar Consonantes *********");
    
    printf("\n--------------------------------------------\n");
    printf("\t   Informacion Registrada\n");
    printf("---------------------------------------------\n");
    
	printf("Escrito:\t\t%s", palabra);
	mostrarConsonantesOrdenadas(palabra, n);
	
	// Liberar memoria
	free(palabra);
}

void mostrarConsonantesOrdenadas(char *palabra, int n) {
	
	// Declaracion de Variables
	int i, j, aux;
	char *cons;
	
	cons = (char *) malloc(20*sizeof(char));
	
	strcpy(cons, palabra);
	
	
	//quitarVocal(cons, 'a');
	
	// Comenzar el Booble Sort para ir acomodando las consonantes de menor a mayor
	for(i=0; i < n; i++) {
		for(j= (i+1); j < n; j++) {
			// No se quitar las vocales :"( 
			if(*(cons+j) < *(cons+i)) {
				aux = *(cons + j);
				*(cons + j) = *(cons + i);
				*(cons + i) = aux;
			}
		}
	}
    
	printf("\nOrdenado:\t\t%s", cons);
	
	// Liberar Memoria
	free(cons);
}

void pila() {
	// Declaracion de variables
	int n, i;
	
	// Pedir cantidad
	do {
        printf("Introduzca el numero de personas: ");
        scanf("%d", &n);
        
        if(n<=0 || n>10) {
            printf("La cantidad debe ser entre 1 y 10\n");
        } 
        
    } while (n<=0 || n>10);
    
    // Declaracion del arreglo para los turnos
	int *turnos[n];
	
	// Reservar memoria para cada turno
    for (i=0; i<n; i++) {
        turnos[i] = (int *) malloc(sizeof(int));
    }
    
    // Almacenar los nombres
    for (i=0; i<n; i++) {
        printf("Introduzca el turno #%d: ", (i+1));
        fflush(stdin);
        scanf("%s", turnos[i]);
    }
    
    printf("\n");
    mostrarPila(turnos, n);
    
    // Liberar la Memoria
   	for(i=0;i<n;i++){
		free(turnos[i]);
	}
}

void mostrarPila(int *turnos[10],int n){
	
	// Declaracion de Variables
	int i;
    
    // Mostrar Turnos
	printf("***************** Pila *****************");
	
	printf("\n-----------------------------------------\n");
    printf("Orden Ingresado\t\tOrden en Pila\n");
    printf("------------------------------------------\n");
    
	for(i=(n-1);i>=0;i--){
		printf("%s\t\t\t%s\n", turnos[n-(i + 1)], turnos[i]);
	}	
}
