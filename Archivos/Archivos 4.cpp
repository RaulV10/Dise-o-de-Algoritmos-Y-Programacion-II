#include<stdio.h>
#include<string.h>
#include<stdlib.h>
// Mostrar la informacion del archivo
int main(){
	
	FILE *fptr;
	char alumno[50];
	char buscar[50];
	char c;
	int r;
	
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
	
// Buscar
printf("\n\nQue quiere buscar\n");
fflush(stdin);
gets(buscar);
rewind(fptr);
do{
	c = fscanf(fptr,"%s",alumno);
	if(c==EOF)
	break;
	if(strcmp(alumno,buscar)==0){
		r = 1;
		break;
	}else{
		r = 0;
	}
}while(c != EOF);

if(r==1){
	printf("Si esta en el archivo %s\n",alumno);
}else{
	printf("No esta en el archivo\n");
}

	fclose(fptr);
	return 0;
}
