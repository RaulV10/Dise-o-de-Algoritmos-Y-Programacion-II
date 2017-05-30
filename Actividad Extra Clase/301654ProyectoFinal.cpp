#include<stdio.h>
#include <stdlib.h>
#include<unistd.h>
#include<conio.h>

// Estructura FACTURA Secuencial
typedef struct{ 
	long int numCliente;
	char placas[6];
	char propietario[30];
	char marca[30];
	char modelo[30];
	char color[30];
	int anio;
}FACTURA;

// Estructura FACTURAD Directo
typedef struct{ 
	long int numCliente;
	char placas[6];
	char propietario[30];
	char marca[30];
	char modelo[30];
	char color[30];
	int anio;
}FACTURAD;

// Estructura Cliente Practica-4
typedef struct Cliente{
	long int num;
	char *nombre;
	struct Cliente *sig;
}NODO;

typedef struct Cliente *Tlista;

// Funcion Practica 1
void abrirProgramaContarLineas();

// Funciones Practica 2
void abrirPractica2();

int mostrarMenu();
bool repetir();
void clearScreen();

void crearPrograma();
void mostrarPrograma();
void compilarPrograma();

// Funciones Practica 3
void abrirSecuencial();
void abrirDirecto();

// Secuencial
void AgregarSecuencial(FILE *, FACTURA);
void MostrarTodosSecuencial(FILE *, FACTURA);
int MostrarUnoSecuencial(FILE *, FACTURA);
void EditarSecuencial(FILE *, FACTURA);
void BorrarLogicoSecuencial(FILE *, FACTURA);
void BorrarFisicoSecuencial(FILE *, FILE *,FACTURA);
int BuscarSecuencial(FILE *, FACTURA, long int);

// Directo
void AgregarDirecto(FILE *, FACTURAD);
int MostrarUnoDirecto(FILE *, FACTURAD);
void EditarDirecto(FILE *, FACTURAD);
void BorrarLogicoDirecto(FILE *, FACTURAD);
int BuscarDirecto(FILE *, FACTURAD, long int);

// Funciones y Variables Practica 4
NODO *primero=NULL, *ultimo=NULL;
long int cont=0;

void abrirListas();
void Agregar();
void BuscarSeq(int num);
void Eliminar();
//void Ordenar(NODO, int);
void MostrarTodo();
void MostrarPila();
void MostrarCola();

int main() {
	
	int opc, secDir;
	
	do{
		system("cls");
		printf("MENU\n");
		printf("1) Abrir un programa en c y contar cuantas líneas y caracteres se tienen\n");
		printf("2) Crear un programa en c, compilarlo y ejecutarlo\n");
		printf("3) Utilizando los ejemplos de Archivos secuencial y directo (considere todas las opciones del menú) con la Facturación\n");
		printf("4) Ejercicio de Listas\n");
		printf("5) Salir\n");
		
		printf("Introduzca el numero de la practica: ");
		scanf("%d",&opc);	
		
		switch(opc) {
		case 1: abrirProgramaContarLineas();
			break;
		case 2: 
			abrirPractica2();
			break;
		case 3:
			do {
				system("cls");
				printf("***** Seleccione Tipo de Archivo *****\n\n");
				printf("1) Secuencial\n");
				printf("2) Directo\n");
				printf("Seleccione tipo de archivo: ");
				scanf("%d", &secDir);
				
				if(secDir == 1) {
					abrirSecuencial();
				} else if(secDir == 2) {
					abrirDirecto();
				}
				
			}while(secDir < 1 || secDir > 2);
			break;
		case 4:
			abrirListas();
			break;
		case 5:
			printf("Bye!\n\n");
			exit(EXIT_SUCCESS);
			break;	
		default:
			break;
		} 
		
		system("pause");
	}while(opc != 5);
	
	abrirProgramaContarLineas();
	
	return 0;
}

// Funcion Practica 1
void abrirProgramaContarLineas() {
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
}

// Funciones Practica 2
void abrirPractica2() {
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

// Funciones Practica 3 - Secuencial
void abrirSecuencial() {
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
				arch=fopen("secuencial.txt","rb+");
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

// Funciones Practica 3 - Directo
void abrirDirecto() {
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
				arch=fopen("directo.txt","rb+");
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
}

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

// Funciones Practica 4
void abrirListas() {
	int opc;
	long int num;
	do{ 
		system("cls");
		printf("MENU\n");
		printf("1. Agregar\n");
		printf("2. Buscar\n");
		printf("3. Eliminar\n");
		printf("4. Ordenar\n");
		printf("5. Mostrar todo\n");
		printf("6. Mostrar pila\n");
		printf("7. Mostrar cola\n");
		printf("8. Ordenar\n");
		printf("9. Salir\n");
		printf("Dame la opc\n");
		scanf("%d",&opc);
		switch(opc) {
			case 1: Agregar();
				break;
			case 2: 
				printf("Cual es el num que quiere buscar\n");
				scanf("%ld",&num);
				BuscarSeq(num);
				break;
			case 3:
				Eliminar();
				break;
			case 4:
				//Ordenar();
				break;
			case 5:
				MostrarTodo();
				break;	
			case 6: 
				//printf("Pila");
				break;	
			case 7:
				MostrarCola();
				break;	
			case 8:
				//Ordenar();
				break;	
			case 9:
				printf("Bye!\n\n");
				break;	
			default:
				break;
		} system("pause");
		
	}while(opc!=9);
}

void Agregar() {
	NODO *nuevo;
	cont++;
    nuevo=(NODO *)malloc(sizeof(NODO));
    //Reservamos memoria para nombre
    nuevo->nombre=(char *) malloc(30*sizeof(char));
    //El numero lo consideramos de tama?o
	// Introducimos los datos
	printf("Dame el nombre\n");
	fflush(stdin);
	gets(nuevo->nombre);
	nuevo->num=cont;
	if(primero==NULL) {
        primero=nuevo;
        ultimo=nuevo;
        nuevo->sig=NULL;
        return;
    }
    ultimo->sig=nuevo;
    ultimo=nuevo;
    nuevo->sig=NULL;
    
    return;
}

void BuscarSeq(int num) {
	NODO *aux;
	int b=0;
    aux=primero;
    if(aux==NULL) {
        printf("LISTA VACIA \n");
    }
    while(aux!=NULL) {
        if(aux->num==num) {
            printf("Num: %ld - Nombre: %s \n", aux->num, aux->nombre);
            b=1;
        }
        aux=aux->sig;
    }
     
    if(b==0) {
        printf("No se encontraron resultados\n");
    }
 
}

void Eliminar(){
	
      NODO* anterior = NULL;
      NODO* actual = primero;
     
      int op;
      printf("Num a eliminar?");
      scanf("%d", &op);
     
      while(actual != NULL){
      	
        if(actual->num == op){
          // Para eliminar el primero
          if (anterior == NULL){
          	primero = actual->sig;
          	free(actual);
		  }else{
		  	anterior->sig = actual->sig;
		  
		  
          free(actual);
          actual = anterior->sig;
      		}
        }else{
          anterior = actual;
          actual = actual->sig;
        }
      }
}

void MostrarTodo() {
	NODO *aux;
    aux=primero;
    if(aux==NULL) {
        printf("Lista vacia");
        
        return;
    }
    
    while(aux!=NULL) {
        printf("%d -> %s\n", aux->num, aux->nombre);
        aux=aux->sig;
    }
    
    return;
}

void MostrarCola() {
	NODO *aux;
    aux=primero;
    if(aux==NULL) {
        printf("Lista vacia");
        
        return;
    }
    
    while(aux!=NULL) {
        printf("%d -> %s\n", aux->num, aux->nombre);
        aux=aux->sig;
    }
    
    return;
}
