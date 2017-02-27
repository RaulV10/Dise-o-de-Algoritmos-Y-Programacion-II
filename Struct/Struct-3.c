//
//  Struct-3.c
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

void mostrarAlumnos(struct alumnos);

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
    
    mostrarAlumnos(a);
    mostrarAlumnos(b);
    
    return 0;
}

// Funciones
void mostrarAlumnos(struct alumnos alumno) {
    printf("\n\n***** DATOS DE LOS ALUMNOS *****\n\n");
    printf("ALUMNO:\n");
    printf("Matricula: %ld\n", alumno.matricula);
    printf("Nombre: %s\n", alumno.nombre);
    printf("Promedio: %.2f\n", alumno.promedio);
}
