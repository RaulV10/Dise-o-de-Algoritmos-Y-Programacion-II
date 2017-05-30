#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{ 
	long int numCliente;
	char placas[6];
	char propietario[30];
	char marca[30];
	char modelo[30];
	char color[30];
	int anio;
}FACTURA;

// Prototipos de Funcion
void AgregarSecuencial(FILE *, FACTURA);
void MostrarTodosSecuencial(FILE *, FACTURA);
int MostrarUnoSecuencial(FILE *, FACTURA);
void EditarSecuencial(FILE *, FACTURA);
void BorrarLogicoSecuencial(FILE *, FACTURA);
void BorrarFisicoSecuencial(FILE *, FILE *,FACTURA);
int BuscarSecuencial(FILE *, FACTURA, long int);

int main() {
	FACTURA factura;
	char salir, placaBuscar;
	int opc, band = 0;
	FILE *arch;
	FILE *tmp;
	
	do {
		system("cls");
		printf("Menu\n");
		printf("1. Agregar factura\n");
		printf("2. Mostrar todas las facturas\n");
		printf("3. Mostrar una factura\n");
		printf("4. Editar una factura\n");
		printf("5. Borrar una factura LOGICA\n");
		printf("6. Borrar una factura FISICA\n");
		printf("7. Borrar Todo\n");
		printf("8. salir\n");
		printf("Seleccione una opcion: ");
		scanf("%d",&opc);
		
		switch(opc) {
			case 1:
				AgregarSecuencial(arch, factura);
			break;
			case 2:
				MostrarTodosSecuencial(arch,factura);
			break;
			case 3:
				band=MostrarUnoSecuencial(arch,factura);
			    if(band==0) {
					printf("No se encontro en el archivo\n");
				}
			break;
			case 4:
				EditarSecuencial(arch, factura);
			break;
			case 5:
				BorrarLogicoSecuencial(arch, factura);
			break;
			case 6:
				BorrarFisicoSecuencial(arch, tmp, factura);
			break;
			case 7:
				printf("Esta seguro de borrar la informacion? [S/N] :");
				fflush(stdin);
				scanf("%c",&salir);
				if((salir=='s')||(salir=='S')) {
				    fclose(arch);
				    remove("secuencial.txt");
				    printf("Informacion borrada\n");
			    }
			break;
			case 8:
				printf("Bye!\n");
			break;
			default: 
				printf("*****  Error ***** \n");
		}
		system("pause");
	}while(opc != 8);
	
	return 0;
}

void AgregarSecuencial(FILE *arch, FACTURA factura) { 

	int band=0;
	arch=fopen("secuencial.txt","ab+"); //abrir un archivo
	
	//comprueba errores en el archivo
	if(arch==NULL)  {
		printf("Hubo un error en el archivo\n");
	} else {
		do {
			printf("Introduzca el numero de cliente: ");
			scanf("%ld", &factura.numCliente);
			if(factura.numCliente <= 0) {
				printf("El numero no puede ser negativo o cero\n");
			}
		} while(factura.numCliente <= 0);
		
		band=BuscarSecuencial(arch,factura, factura.numCliente);
		
		// significa que no existe el reg con esa clave
		if(band==0) {
			printf("Introduzca las placas: ");
			fflush(stdin);
			gets(factura.placas);
		    printf("Introduzca el nombre del nuevo propietario: ");
			fflush(stdin);
			gets(factura.propietario);
			printf("Introduzca la marca del carro: ");
			fflush(stdin);
			gets(factura.marca);
			printf("Introduzca el modelo: ");
			fflush(stdin);
			gets(factura.modelo);
			printf("Introduzca el color: ");
			fflush(stdin);
			gets(factura.color);
			printf("Introduzca el anio: ");
			scanf("%d", &factura.anio);
			fwrite(&factura,sizeof(FACTURA),1,arch);
	    } else { 
			printf("Ya existe un registro con ese numero");
	    }
	}
	fclose(arch);
}

void MostrarTodosSecuencial(FILE * arch, FACTURA factura) {
	arch=fopen("secuencial.txt","rb+"); //abrir un archivo
	
	//comprueba errores en el archivo
	if(arch==NULL) {
		printf("No existe informacion ...\n");
	} else {
		rewind(arch);
		fread(&factura,sizeof(FACTURA),1,arch);
		while(!feof(arch)) { 
			if(factura.numCliente != 0) {
				printf("***** INFORMACION DE FACTURA *****");
				printf("\n\n***********************************\n\n");
				printf("Numero de Cliente: %ld \n", factura.numCliente);
				printf("Placas: %s \n", factura.placas);
				printf("Nombre de Propietario: %s \n", factura.propietario);
				printf("Marca del Auto: %s \n", factura.marca);
				printf("Modelo: %s \n", factura.modelo);
				printf("Color: %s \n", factura.color);
				printf("Anio: %d \n", factura.anio);
				printf("\n***********************************\n");
			}
		fread(&factura,sizeof(FACTURA),1,arch);
		}
		rewind(arch);
	}
	fclose(arch);
}

int MostrarUnoSecuencial(FILE *arch, FACTURA factura) {
	int band=0;
	long int numbuscar;
	arch=fopen("secuencial.txt","rb+"); //abrir un archivo
	
	//comprueba errores en el archivo
	if(arch==NULL) {
		printf("Hubo un error en el archivo\n");
	} else {
	    band=0;
		
		printf("Introduzca el numero de cliente a buscar: ");
		scanf("%ld",&numbuscar);
		rewind(arch);
		
		do {
			fread(&factura,sizeof(FACTURA),1,arch);
			if((numbuscar == factura.numCliente)&&(factura.numCliente != 0)) {
				printf("***** INFORMACION DE FACTURA *****");
				printf("\n\n***********************************\n\n");
				printf("Numero de Cliente: %ld \n", factura.numCliente);
				printf("Placas: %s \n", factura.placas);
				printf("Nombre de Propietario: %s \n", factura.propietario);
				printf("Marca del Auto: %s \n", factura.marca);
				printf("Modelo: %s \n", factura.modelo);
				printf("Color: %s \n", factura.color);
				printf("Anio: %d \n", factura.anio);
				printf("\n***********************************\n");
				band=1;
				break;
		    }
			
		}while(!feof(arch));
		rewind(arch);
		
	}
	fclose(arch);	
	return band;
}

void EditarSecuencial(FILE *arch, FACTURA factura) {
	int band=0;
	long int numbuscar;
	arch=fopen("secuencial.txt","rb+"); //abrir un archivo
	//comprueba errores en el archivo
	if(arch==NULL) {
		printf("Hubo un error en el archivo\n");
	} else {
	    band=0;
		printf("Introduzca el numero del cliente que quiera editar: ");
		scanf("%ld",&numbuscar);
		rewind(arch);
		do {
			fread(&factura,sizeof(FACTURA),1,arch);
			if(numbuscar == factura.numCliente) {
				printf("***** INFORMACION DE FACTURA *****");
				printf("\n\n***********************************\n\n");
				printf("Numero de Cliente: %ld \n", factura.numCliente);
				printf("Placas: %s \n", factura.placas);
				printf("Nombre de Propietario: %s \n", factura.propietario);
				printf("Marca del Auto: %s \n", factura.marca);
				printf("Modelo: %s \n", factura.modelo);
				printf("Color: %s \n", factura.color);
				printf("Anio: %d \n", factura.anio);
				printf("\n***********************************\n");
				
				do {
					printf("Introduzca el numero de cliente: ");
					scanf("%ld", &factura.numCliente);
					if(factura.numCliente <= 0) {
						printf("El numero no puede ser negativo o cero\n");
					}
				} while(factura.numCliente <= 0);
			    
				printf("Introduzca las placas: ");
				fflush(stdin);
				gets(factura.placas);
			    printf("Introduzca el nombre del nuevo propietario: ");
				fflush(stdin);
				gets(factura.propietario);
				printf("Introduzca la marca del carro: ");
				fflush(stdin);
				gets(factura.marca);
				printf("Introduzca el modelo: ");
				fflush(stdin);
				gets(factura.modelo);
				printf("Introduzca el color: ");
				fflush(stdin);
				gets(factura.color);
				printf("Introduzca el anio: ");
				scanf("%d", &factura.anio);
				fseek(arch,ftell(arch)-sizeof(factura),SEEK_SET);
				fwrite(&factura,sizeof(FACTURA),1,arch);
				band=1;
				break;
			}
		
		}while(!feof(arch));
		rewind(arch);
		if(band==0) {
			printf("No se encontro en el archivo\n");
		}
	}
	fclose(arch);
}

void BorrarLogicoSecuencial(FILE *arch, FACTURA factura) {
	char salir;
	int band=0;
	long int numbuscar;
	arch=fopen("secuencial.txt","rb+"); //abrir un archivo
	
	//comprueba errores en el archivo
	if(arch==NULL) {
		printf("Hubo un error en el archivo\n");
	} else {
	    band=0;
		printf("Introduzca el numero de cliente que desee borrar: ");
		scanf("%ld",&numbuscar);
		rewind(arch);
		
		do {
			fread(&factura,sizeof(FACTURA),1,arch);
			if(numbuscar == factura.numCliente) {
				printf("***** INFORMACION DE FACTURA *****");
				printf("\n\n***********************************\n\n");
				printf("Numero de Cliente: %ld \n", factura.numCliente);
				printf("Placas: %s \n", factura.placas);
				printf("Nombre de Propietario: %s \n", factura.propietario);
				printf("Marca del Auto: %s \n", factura.marca);
				printf("Modelo: %s \n", factura.modelo);
				printf("Color: %s \n", factura.color);
				printf("Anio: %d \n", factura.anio);
				printf("\n***********************************\n");
				printf("Esta seguro de borrar la informacion? [S/N] :");
				fflush(stdin);
				scanf("%c",&salir);
				if((salir=='s')||(salir=='S')) {
					factura.numCliente = 0;
					strcpy(factura.placas, " ");
					strcpy(factura.propietario, " ");
					strcpy(factura.marca, " ");
					strcpy(factura.modelo, " ");
					strcpy(factura.color, " ");
					factura.anio = 0;
					fseek(arch,ftell(arch)-sizeof(factura),SEEK_SET);
					fwrite(&factura,sizeof(FACTURA),1,arch);
					printf("Registro borrado \n");
				}
				band=1;
				break;
		    }
		}while(!feof(arch));
		rewind(arch);
		if(band==0) {
			printf("No se encontro en el archivo\n");
		}
	}
	fclose(arch);
}

void BorrarFisicoSecuencial(FILE *arch, FILE *tmp,FACTURA factura) {
    arch=fopen("secuencial.txt","rb+"); //abrir un archivo
    tmp=fopen("secuencial.tmp","wb+"); //abrir un archivo
    
    //comprueba errores en el archivo
    if((arch==NULL)||(tmp==NULL)) {
    	printf("Hubo un error en el archivo\n");
    } else {
		rewind(arch);
	    fread(&factura,sizeof(FACTURA),1,arch);
		while(!feof(arch)) { 
			if(factura.numCliente != 0) {
				printf("***** PASANDO INFORMACION *****");
				printf("\n\n***********************************\n\n");
				printf("Numero de Cliente: %ld \n", factura.numCliente);
				printf("Placas: %s \n", factura.placas);
				printf("Nombre de Propietario: %s \n", factura.propietario);
				printf("Marca del Auto: %s \n", factura.marca);
				printf("Modelo: %s \n", factura.modelo);
				printf("Color: %s \n", factura.color);
				printf("Anio: %d \n", factura.anio);
				printf("\n***********************************\n");
				fwrite(&factura,sizeof(FACTURA),1,tmp);
		    }
			fread(&factura,sizeof(FACTURA),1,arch);
		}
		rewind(arch);
    }
    fclose(arch);
    fclose(tmp);
    remove("secuencial.txt");
    rename("secuencial.tmp","secuencial.txt");
    printf("Archivo compactado\n");
}

int BuscarSecuencial(FILE *arch, FACTURA factura, long int numCliente){ 
	int band=0;
	arch=fopen("secuencial.txt","rb+"); //abrir un archivo

	//comprueba errores en el archivo
	if(arch==NULL) {
		printf("Hubo un error en el archivo\n");
	}
	else{
	    band=0;
		
		rewind(arch);
		fread(&factura,sizeof(FACTURA),1,arch);
		while(!feof(arch)) {
			if((numCliente == factura.numCliente)&&(factura.numCliente != 0)) {
				band=1;
				break;
		    }
			fread(&factura,sizeof(FACTURA),1,arch);
	    }	
		
		rewind(arch);
		
	}
	fclose(arch);	
	return band;
}
