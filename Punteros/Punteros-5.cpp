//
//  Punteros-5.cpp
//  
//
//  Created by Raul Villarreal on 2/7/17.
//
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    
    /* 2 */
    // Declarar puntero
    // Tipo de dato *nombrePuntero;
    
    /* 3 */
    // Reserva de memoria
    // nombrePuntero = (tipo_dato *)malloc(tamano_que_se_requiere_reservar);
    
    /* 4 */
    // Utilizacion de puntero en el programa
    // Liberar la memoria free(nombrePuntero);
    
    /* MAS REFERENCIAS */
    // http://stackoverflow.com/questions/20109984/c-c-sizeofshort-sizeofint-sizeoflong-sizeoflong-long-etc-on-a
    
    /*
    printf("El tamano del int es %lu\n", sizeof(int)); // 4
    printf("El tamano del char es %lu\n", sizeof(char)); // 1
    printf("El tamano del long int es %lu\n", sizeof(long int)); // 8
    */
    
    long int *matricula;
    char *nombre;
    int contv = 0, i, tam;
    matricula = (long int *) malloc(sizeof(long int));
    nombre = (char *) malloc(30*sizeof(char)); // char nombre[30]
    
    // Almacenar
    printf("Introducir una matricula: ");
    scanf("%ld", matricula);
    printf("Introduzca un nombre: ");
    fflush(stdin);
    scanf("%s", nombre);
    
    tam = strlen(nombre);
    for(i=0; i<tam; i++) {
        switch (*(nombre+i)) {
            case 'a': case 'e': case 'i': case 'o': case 'u':
            case 'A': case 'E': case 'I': case 'O': case 'U':
                contv++;
                break;
                
            default:
                break;
        }
    }
    
    // Mostrar informacion
    printf("La matricula: %ld\n", *matricula); // Si no requiere asterisco imprime la direccion de memoria
    printf("Nombre: %s\n", nombre);
    printf("Tiene %d vocales\n", contv);
    /* Se utiliza asterisco cuando queremos imprimir un numero o manejar las letras por separado */
    free(matricula);
    free(nombre);
    
    return 0;
}
