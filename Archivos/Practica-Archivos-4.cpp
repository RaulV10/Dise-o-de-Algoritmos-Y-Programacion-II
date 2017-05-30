#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

typedef struct Cliente{
	long int num;
	char *nombre;
	struct Cliente *sig;
}NODO;

NODO *primero=NULL, *ultimo=NULL;
long int cont=0;
void Agregar();
void MostrarTodo();
void BuscarSeq(int num);
void Pila();

int main(){ 
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
				break;
			case 4:
				
				break;
			case 5:
				MostrarTodo();
				break;	
			case 6: Pila();
				break;	
			case 7:
				break;	
			case 8:
				break;	
			case 9:
				break;	
			default:
				break;
		} system("pause");
		
	}while(opc!=9);
	return 0;
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


void Pila() {
	NODO *aux;
    aux=primero;
    int n = cont;
    char *nombres[n];
    int num[n];
    int i = 0;
        
    
	// Reservar memoria para cada nombre
    for (i=0; i<n; i++) {
        nombres[i] = (char *) malloc(20*sizeof(char));
    }
    
//    // Almacenar los nombres
//    for (i=0; i<cont; i++) {
//        nombres[i] = aux->nombre;
//        aux= aux->sig;
//    }
    
    if(aux==NULL)
    {
        printf("Lista vacia");
        
        return;
    }
    
    while(aux!=NULL)
    {
        printf("Ordenados: %d -> %s\n", aux->num, aux->nombre);
        nombres[i] = aux->nombre;
        num[i] = aux->num;
        printf("%d -> %s\n", num[i], nombres[i]);
        aux=aux->sig;
        i++;
    }
    
    printf("%s", nombres[0]);
    
    //i = 0;
    // nombres[0] = aux->nombre;
    for(i=0; i < n; i++){
		printf("%s\n", nombres[i]);
	}
    printf("fin");
    return;
}
