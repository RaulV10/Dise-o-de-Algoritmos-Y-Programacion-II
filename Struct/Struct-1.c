//
//  Struct-1.c
//  
//
//  Created by Raul Villarreal on 2/27/17.
//
//

#include <stdio.h>
#include <stdlib.h>

struct alumnos {
    long int matricula;
    char nombre[30];
    float promedio;
};

int main() {
    
    struct alumnos a;
    
    // Introducir la informacion
    printf("Introduzca la matricula: ");
    scanf("%ld", &a.matricula);
    printf("Introduzca el nombre: ");
    fflush(stdin);
    // gets(a.nombre);
    scanf("%s", a.nombre);
    printf("Introduzca el promedio: ");
    scanf("%f", &a.promedio);
    
    printf("\n\n***** DATOS DEL ALUMNO *****\n\n");
    printf("Matricula: %ld\n", a.matricula);
    printf("Nombre: %s\n", a.nombre);
    printf("Promedio: %.2f\n", a.promedio);
    
    return 0;
}
