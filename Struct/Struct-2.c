//
//  Struct-2.c
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
    
    struct alumnos a, b;
    
    // Introducir la informacion Alumno A
    printf("ALUMNO A\n");
    printf("Introduzca la matricula: ");
    scanf("%ld", &a.matricula);
    printf("Introduzca el nombre: ");
    fflush(stdin);
    // gets(a.nombre);
    scanf("%s", a.nombre);
    printf("Introduzca el promedio: ");
    scanf("%f", &a.promedio);
    
    // Introducir la informacion Alumno B
    printf("ALUMNO B\n");
    printf("Introduzca la matricula: ");
    scanf("%ld", &b.matricula);
    printf("Introduzca el nombre: ");
    fflush(stdin);
    // gets(b.nombre);
    scanf("%s", b.nombre);
    printf("Introduzca el promedio: ");
    scanf("%f", &b.promedio);
    
    
    printf("\n\n***** DATOS DE LOS ALUMNOS *****\n\n");
    printf("ALUMNO A\n");
    printf("Matricula: %ld\n", a.matricula);
    printf("Nombre: %s\n", a.nombre);
    printf("Promedio: %.2f\n", a.promedio);
    printf("ALUMNO B\n");
    printf("Matricula: %ld\n", b.matricula);
    printf("Nombre: %s\n", b.nombre);
    printf("Promedio: %.2f\n", b.promedio);
    
    return 0;
}
