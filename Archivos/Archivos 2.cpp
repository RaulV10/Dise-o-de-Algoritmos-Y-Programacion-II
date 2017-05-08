#include<stdio.h>
#include<string.h>
#include<stdlib.h>
// Mostrar la informacion del archivo
int main(){
	
	FILE *fptr;
	char alumno[50];
	char c;
	
	if((fptr=fopen("c://Archivos/da2.txt","r"))==NULL){ // fopen abrir un archivo en el mode de apartura de escritoria o w
		printf("Fallo al abrir el archivo de texto.txt\n");
		exit(1); /* Se sale del programa */
	}else{
		do{
		c = fscanf(fptr,"%s",alumno);
		if(c==EOF){
		break;
		}
		printf("%s\n",alumno);
	}while(c != EOF);
	}
	fclose(fptr);
	return 0;
}
