//
//  Practicta-Archivos-1.cpp
//  Universidad Autonoma de Chihuahua
//  Diseño de Algoritmos y su Programacion II
//
//  Created by Raul E. Villarreal Sigala on 5/3/17.
//

#include<stdio.h>
#include<unistd.h>

int main() {
	FILE *ftpr;
	char ch;
	char archivo[50];
	int caracteres = 0, lineas = 0;
	bool archivoExiste = false;
	
	do {
		printf("Introduzca el nombre del archivo .cpp: ");
		gets(archivo);
		
		if( access(("%s", archivo), F_OK ) != -1 ) {
			
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
	
	return 0;
}
