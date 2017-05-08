#include<stdio.h>
#include<string.h>
#include<stdlib.h>
// Guardar informacion del archivo
int main(){
	
	FILE *fptr;
	char nombre[25];
	long int matric;
	float prom;
	
	if((fptr=fopen("c://Archivos/da2.txt","w"))==NULL){ // fopen abrir un archivo en el mode de apartura de escritoria o w
		printf("Fallo al abrir el archivo de texto.txt\n");
		exit(1); /* Se sale del programa */
	}else{
	printf("Dame el nombre: \n");
	fflush(stdin);
	gets(nombre);
	printf("Dame la matricula\n");
	scanf("%ld",&matric);
	printf("Dame el promedio: \n");
	scanf("%f",&prom);
	fprintf(fptr,"Matricula: %ld - Nombre: %s - Promedio: %f\n",matric,nombre,prom);
}
	fclose(fptr);
	return 0;
}
