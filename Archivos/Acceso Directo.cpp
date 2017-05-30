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
}FACTURAD;

void AgregarDirecto(FILE *, FACTURAD);
int MostrarUnoDirecto(FILE *, FACTURAD);
void EditarDirecto(FILE *, FACTURAD);
void BorrarLogicoDirecto(FILE *, FACTURAD);
int BuscarDirecto(FILE *, FACTURAD, long int);

int main() { 
	FACTURAD factura, facturaTmp;
	char nombreArch[30], resp;
	long int numbuscar;
	int opc, band=0;
	
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
			       AgregarDirecto(arch, factura);
				break;
			case 2:
			       printf("Mostrar todos solo funciona en secuencial\n\n");
				break;
			case 3:
			    band=MostrarUnoDirecto(arch,factura);
			    
				if(band==0) {
					printf("No se encontro en el archivo\n");
				}
				
				break;
			case 4: //reemplazar
			     EditarDirecto(arch, factura);
				break;
				
			case 5: // Borrado l?gico
			     BorrarLogicoDirecto(arch,factura);
				break;
			case 6:
			     printf("Borrado Fisico solo funciona en secuencial");
				  break;
			case 7:
			    printf("Esta seguro de borrar la informacion [S/N]: ");
				fflush(stdin);
				scanf("%c",&resp);
				if((resp=='s')||(resp=='S'))
				{
			     fclose(arch);
			     remove("directo.txt");
			     printf("Informacion borrada\n");
			     }
			     break;	  
			case 8: printf("BYE\n");
			        break;
			default: printf("Error! \n");
		} 
		system("pause");
	}while(opc!=8);
	return 0;
}

// funciones
void AgregarDirecto(FILE *arch, FACTURAD factura) { 
	int band=0, dir_fisica;
	int num;
	arch=fopen("directo.txt","rb+"); //abrir un archivo
	
	//comprueba errores en el archivo
	if(arch==NULL) {   
		arch=fopen("directo.txt","wb"); //abrir un archivo           
	} else {
	    do{ 
			printf("Dame el numero:\n");
			scanf("%ld", &num);
			
			if (num<=0) { 
			   printf("el num no debe ser negativo o cero\n");
		    }
		    
	    }while(num<=0);
	    //Verifica si existe ese registro en el archivo
	    band=0;
		dir_fisica=num*sizeof(factura); // Calculo de la dir. fisica
	    fseek(arch,dir_fisica,SEEK_SET); //Posicionar el apuntador del archivo
		fread(&factura,sizeof(FACTURAD),1,arch);
		
		if((num == factura.numCliente)&&(factura.numCliente != 0)){
			band=1;
		}
	    
	    // significa que no existe el reg con esa clave
		if(band==0) {
			factura.numCliente = num;
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
			dir_fisica=factura.numCliente*sizeof(factura); // Calculo de la dir. fisica
		    fseek(arch,dir_fisica,SEEK_SET); //Posicionar el apuntador del archivo
			fwrite(&factura,sizeof(FACTURAD),1,arch);
	    } else { 
			printf("Ya existe un registro con ese numero");
	    }
	    
	}
	fclose(arch);	
}

int MostrarUnoDirecto(FILE *arch, FACTURAD factura) {
	int band=0;
	long int numbuscar;
	int dir_fisica;
	arch=fopen("directo.txt","rb"); //abrir un archivo
	
	//comprueba errores en el archivo
	if(arch==NULL){
		printf("Hubo un error en el archivo\n");
	} else {
		
	    band=0;
		printf("Introduzca el numero de cliente a buscar: ");
		scanf("%ld",&numbuscar);
		dir_fisica=numbuscar*sizeof(factura); // Calculo de la dir. fisica
	    fseek(arch,dir_fisica,SEEK_SET); //Posicionar el apuntador del archivo
		fread(&factura,sizeof(FACTURAD),1,arch);
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
		}
	}
	fclose(arch);	
	return band;
}

void EditarDirecto(FILE *arch, FACTURAD factura) {
	int band=0;
	long int numbuscar;
	int dir_fisica;
	arch=fopen("directo.txt","rb+"); //abrir un archivo
	
	//comprueba errores en el archivo
	if(arch==NULL) {
		printf("Hubo un error en el archivo\n");
	} else{
	     band=0;
		printf("Introduzca el numero del cliente que quiera editar: ");
		scanf("%ld",&numbuscar);
		dir_fisica=numbuscar*sizeof(factura); // Calculo de la dir. fisica
	    fseek(arch,dir_fisica,SEEK_SET); //Posicionar el apuntador del archivo
		fread(&factura,sizeof(FACTURAD),1,arch);
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
			
			fseek(arch,dir_fisica,SEEK_SET); //Posicionar el apuntador del archivo
			fwrite(&factura,sizeof(FACTURAD),1,arch);
			printf("Registro actualizado\n");
			band=1;
		}
		
		if(band==0) {
			printf("No se encontro en el archivo\n");
		}
	}
	fclose(arch);
}

void BorrarLogicoDirecto(FILE *arch, FACTURAD factura) {
	char salir;
	int band=0;
	long int numbuscar;
	int dir_fisica;
	arch=fopen("directo.txt","rb+"); //abrir un archivo
	
	//comprueba errores en el archivo
	if(arch==NULL) {
		printf("Hubo un error en el archivo\n");
	} else {
	    band=0;
		printf("Introduzca el numero de cliente que desee borrar: ");
		scanf("%ld",&numbuscar);
		dir_fisica=numbuscar*sizeof(factura); // Calculo de la dir. fisica
	    fseek(arch,dir_fisica,SEEK_SET); //Posicionar el apuntador del archivo
		fread(&factura,sizeof(FACTURAD),1,arch);
		
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
				fseek(arch,dir_fisica,SEEK_SET);
				fwrite(&factura,sizeof(FACTURAD),1,arch);
				printf("Registro borrado \n");
				band=1;
			}
		
	    }
		if(band==0) {
			printf("No se encontro en el registro\n");
		}
	}
	fclose(arch);
}
