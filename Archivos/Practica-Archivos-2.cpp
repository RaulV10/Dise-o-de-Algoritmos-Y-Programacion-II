//
//  Practicta-Archivos-1.cpp
//  Universidad Autonoma de Chihuahua
//  Diseño de Algoritmos y su Programacion II
//
//  Created by Raul E. Villarreal Sigala on 5/3/17.
//

#include<stdio.h>
#include <stdlib.h>
#include<unistd.h>
#include<conio.h>

// Funciones
int mostrarMenu();
bool repetir();
void clearScreen();

void crearPrograma();
void mostrarPrograma();
void compilarPrograma();

int main() {
	int opc;
	
	// Ciclo para cerrar el programa hasta que el usuario lo pida

	do{

		opc = mostrarMenu();

		switch(opc){

			case 1:
				
				// Crear Programa

				clearScreen();

				crearPrograma();

				break;

			case 2:

				clearScreen();

				mostrarPrograma();

				break;

			case 3:

				clearScreen();

				compilarPrograma();

				break;

			case 4:

				exit(EXIT_SUCCESS);

			default:

				break;

		}

	}while(repetir());
	
	return 0;
}

int mostrarMenu() {
	
	clearScreen();
	
	int opc = 0;

	printf("\n************* MENU *************\n\n");	

	printf("1) Crear Programa\n");

	printf("2) Abrir Programa\n");

	printf("3) Compilar Programa\n");

	printf("4) Salir\n");

	do {

		printf("\nSeleccione una opcion: ");

		scanf("%d", &opc);

	} while(opc < 1 || opc > 4);	

	return opc;

}

bool repetir() {

	int opc = 0;

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

		return false;

	}

}

void clearScreen() {
	system("cls");
}

void crearPrograma() {
	FILE *fp;
	char nombre[50];
	char codigo;
	int saltos = 0;
	
	printf("Nombre del archivo .cpp: ");
	fflush(stdin);
	gets(nombre);
	
	fp = fopen(("%s", nombre), "w+");
	printf("Introduzca el codigo para %s: \n", nombre);
	printf("***** PRESIONE TAB + ENTER PARA SALIR ***** \n\n");
	while((codigo=getchar()) != '\011')
	{
		putc(codigo,fp);
	}
	
	fclose(fp);
	
}

void mostrarPrograma() {
	FILE *ftpr;
	char ch;
	char archivo[50];
	int caracteres = 0, lineas = 0;
	bool archivoExiste = false;
	
	do {
		printf("Introduzca el nombre del archivo .cpp: ");
		fflush(stdin);
		gets(archivo);
		
		if(access(("%s", archivo), F_OK ) != -1 ) {
			
			archivoExiste = true;
			
	    	printf("\n\nEl contenido del archivo %s es: \n\n\n", archivo);
		
			ftpr = fopen(("%s", archivo), "rb");
			while((ch=getc(ftpr))!=EOF) {
				printf("%c", ch);
				
				if(ch == 10) {
					lineas++;
				}
				
				caracteres++;
			}
			printf("\n");
			fclose(ftpr);
			printf("\nEl archivo %s tiene %d caracteres y %d lineas de codigo", archivo, caracteres, lineas);
			
		} else {
		    printf("\n\nEl archivo %s no existe, por favor compruebe el nombre y extension.\n\n", archivo);
		}
	}while(!archivoExiste);
}

void compilarPrograma() {
	char nombre[50];
	char nombreCPP[50];
	bool archivoExiste = false;
	
	do {
		printf("Introduzca el nombre del archivo .cpp: ");
		fflush(stdin);
		gets(nombre);
		
		strcpy(nombreCPP, nombre);
		
		strcat(nombreCPP, ".cpp");
		
		if(access(("%s", nombreCPP), F_OK ) != -1 ) {
			
			archivoExiste = true;
			
			printf("\n\n");
			
	    	system(("gcc -o %s.exe %s", nombre, nombreCPP));
			system(("%s.exe", nombre));
			printf("\n");
			
		} else {
		    printf("\n\nEl archivo %s no existe, por favor compruebe el nombre y extension.\n\n", nombreCPP);
		}
	}while(!archivoExiste);
	
}
