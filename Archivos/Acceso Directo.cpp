#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct{
	long int num;
	char nombre[30];
}datos;
void Agregar(FILE *, datos);
void MostrarTodos(FILE *, datos);
int MostrarUno(FILE *, datos);
void Editar(FILE *, datos);
void BorrarLogico(FILE *, datos);
void BorrarFisico(FILE *, FILE *,datos);
int Buscar(FILE *, datos, long int);
int main()
{ datos persona, personatmp;
char nombreArch[30],resp;
long int numbuscar;
int opc, band=0;
/*printf("Dame el nombre del archivo, no olvide la Ext txt\n");
fflush(stdin);
gets(nombreArch);*/
/*FILE *arch=fopen("ejemplo.txt","ab+"); //abrir un archivo
if(arch==NULL) //comprueba errores en el archivo
{
	printf("Hubo un error en el archivo\n");
}
else{
*/
FILE *arch;
FILE *tmp;
do{
system("cls");
printf("Menu\n");
printf("1. Agregar persona\n");
printf("2. Mostrar persona\n");
printf("3. Mostrar una persona\n");
printf("4. Editar una persona\n");
printf("5. Borrar una persona LOGICA\n");
printf("6. Borrar una persona FISICA\n");
printf("7. Borrar Todo\n");
printf("8. salir\n");
printf("dame la opcion\n");
scanf("%d",&opc);
switch(opc)
{
case 1:
       Agregar(arch, persona);
	break;
case 2:
       MostrarTodos(arch,persona);
	break;
case 3:
    band=MostrarUno(arch,persona);
    if(band==0)
	{
	printf("No se encontro en el archivo\n");
	}
	break;
case 4: //reemplazar
     Editar(arch, persona);
	break;
	
case 5: // Borrado l?gico
     BorrarLogico(arch,persona);
     
	
	break;
case 6:
     BorrarFisico(arch, tmp,persona);
	  break;
case 7:
    printf("Esta seguro de borrar la informacion ....s/n :");
	fflush(stdin);
	scanf("%c",&resp);
	if((resp=='s')||(resp=='S'))
	{
     fclose(arch);
     remove("ejemplo.txt");
     printf("Informaci?n borrada\n");
     }
     break;	  
case 8: printf("BYE\n");
        break;
default: printf("error ... \n");
} system("pause");
}while(opc!=8);
return 0;
}
// funciones
void Agregar(FILE *arch, datos persona)
{ int band=0,dir_fisica;
int num;
arch=fopen("ejemplo.txt","rb+"); //abrir un archivo
if(arch==NULL) //comprueba errores en el archivo
{   arch=fopen("ejemplo.txt","wb"); //abrir un archivo           
	//printf("Hubo un error en el archivo\n");
}
else{
    do{ 
	printf("Dame el numero:\n");
	scanf("%ld", &num);
	if (num<=0)
	   { printf("el num no debe ser negativo o cero\n");
       }
    }while(num<=0);
    //Verifica si existe ese registro en el archivo
    band=0;
	dir_fisica=num*sizeof(persona); // Calculo de la dir. fisica
    fseek(arch,dir_fisica,SEEK_SET); //Posicionar el apuntador del archivo
	fread(&persona,sizeof(datos),1,arch);
	
	if((num==persona.num)&&(persona.num!=0))
	{
	 band=1;
	}
    
	if(band==0) // significa que no existe el reg con esa clave
	{persona.num=num;
    printf("Dame el nombre:\n");
	fflush(stdin);
	gets(persona.nombre);
	dir_fisica=persona.num*sizeof(persona); // Calculo de la dir. fisica
    fseek(arch,dir_fisica,SEEK_SET); //Posicionar el apuntador del archivo
	fwrite(&persona,sizeof(datos),1,arch);
    }
    else
    { printf("Ya existe un registro con ese numero");
    }
    
}
fclose(arch);	
}

void MostrarTodos(FILE * arch, datos persona) // solo secuencial
{
arch=fopen("ejemplo.txt","rb+"); //abrir un archivo
if(arch==NULL) //comprueba errores en el archivo
{
	printf("No existe informacion ...\n");
}
else
{
	rewind(arch);
	fread(&persona,sizeof(datos),1,arch);
	while(!feof(arch))
	{ if(persona.num!=0)
	{
	printf("INFORMACION\n");
	printf("- %ld %s \n",persona.num,persona.nombre);
	}
	fread(&persona,sizeof(datos),1,arch);
	}
	rewind(arch);
}
fclose(arch);
}


int MostrarUno(FILE *arch, datos persona)
{int band=0;
long int numbuscar;
int dir_fisica;
arch=fopen("ejemplo.txt","rb"); //abrir un archivo
if(arch==NULL) //comprueba errores en el archivo
{
	printf("Hubo un error en el archivo\n");
}
else{
    band=0;
	
	printf("Dame el num a buscar:\n");
	scanf("%ld",&numbuscar);
	dir_fisica=numbuscar*sizeof(persona); // Calculo de la dir. fisica
    fseek(arch,dir_fisica,SEEK_SET); //Posicionar el apuntador del archivo
	fread(&persona,sizeof(datos),1,arch);
	if((numbuscar==persona.num)&&(persona.num!=0))
	{
	printf("INFORMACION\n");
	printf("- %ld %s \n",persona.num,persona.nombre);
	band=1;
	}

	
}
fclose(arch);	
return band;
}

void Editar(FILE *arch, datos persona)
{int band=0;
long int numbuscar;
int dir_fisica;
arch=fopen("ejemplo.txt","rb+"); //abrir un archivo
if(arch==NULL) //comprueba errores en el archivo
{
	printf("Hubo un error en el archivo\n");
}
else{
     band=0;
	printf("Dame el num a editar:\n");
	scanf("%ld",&numbuscar);
	dir_fisica=numbuscar*sizeof(persona); // Calculo de la dir. fisica
    fseek(arch,dir_fisica,SEEK_SET); //Posicionar el apuntador del archivo
	fread(&persona,sizeof(datos),1,arch);
	if((numbuscar==persona.num)&&(persona.num!=0))
	{
	printf("INFORMACION\n");
	printf("- %ld %s \n",persona.num,persona.nombre);
	do{
    printf("Dame el numero:\n");
	scanf("%ld", &persona.num);
	if (persona.num<=0)
	   { printf("el num no debe ser negativo o cero\n");
       }
    }while(persona.num<=0);
    
	printf("Dame el nombre:\n");
	fflush(stdin);
	gets(persona.nombre);
	fseek(arch,dir_fisica,SEEK_SET); //Posicionar el apuntador del archivo
	fwrite(&persona,sizeof(datos),1,arch);
	printf("Registro actualizado\n");
	band=1;
	}
	if(band==0)
	{
	printf("No se encontro en el archivo\n");
	}
}
fclose(arch);
}

void BorrarLogico(FILE *arch, datos persona)
{char resp;
int band=0;
long int numbuscar;
int dir_fisica;
arch=fopen("ejemplo.txt","rb+"); //abrir un archivo
if(arch==NULL) //comprueba errores en el archivo
{
	printf("Hubo un error en el archivo\n");
}
else{
    band=0;
	printf("Dame el num a borrar:\n");
	scanf("%ld",&numbuscar);
	dir_fisica=numbuscar*sizeof(persona); // Calculo de la dir. fisica
    fseek(arch,dir_fisica,SEEK_SET); //Posicionar el apuntador del archivo
	fread(&persona,sizeof(datos),1,arch);
	if((numbuscar==persona.num)&&(persona.num!=0))
	{
	printf("INFORMACION\n");
	printf("- %ld %s \n",persona.num,persona.nombre);
    
	printf("Esta seguro de borrar la informacion ....s/n :");
	fflush(stdin);
	scanf("%c",&resp);
	if((resp=='s')||(resp=='S'))
	{
	persona.num=0;
	strcpy(persona.nombre," ");
	fseek(arch,dir_fisica,SEEK_SET);
	fwrite(&persona,sizeof(datos),1,arch);
	printf("Registro borrado \n");
	band=1;
	}
	
    }
	if(band==0)
	{
		printf("No se encontro en el registro\n");
	}
}
fclose(arch);
}
void BorrarFisico(FILE *arch, FILE *tmp,datos persona) // solo secuencial
{ int dir_fisica;
     arch=fopen("ejemplo.txt","rb+"); //abrir un archivo
     tmp=fopen("ejemplo.tmp","wb+"); //abrir un archivo
     if((arch==NULL)||(tmp==NULL)) //comprueba errores en el archivo
     {
     printf("Hubo un error en el archivo\n");
     }
     else
     {
	     rewind(arch);
         fread(&persona,sizeof(datos),1,arch);
	     while(!feof(arch))
	     { if(persona.num!=0)
           {
	       printf("PASANDO INFORMACION\n");
	       printf("- %ld %s \n",persona.num,persona.nombre);
		   dir_fisica=persona.num*sizeof(persona); // Calculo de la dir. fisica
    	   fseek(tmp,dir_fisica,SEEK_SET); //Posicionar el apuntador del archivo
	       fwrite(&persona,sizeof(datos),1,tmp);
           }
	       fread(&persona,sizeof(datos),1,arch);
	       }
	       rewind(arch);
        }
      fclose(arch);
      fclose(tmp);
      remove("ejemplo.txt");
      rename("ejemplo.tmp","ejemplo.txt");
      printf("Archivo compactado\n");
}

