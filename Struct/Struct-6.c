//
//  Struct-6.c
//
//
//  Created by Raul Villarreal on 2/27/17.
//
//

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    long int *matricula;
    char *nombre;
    float promedio;
}alumnos;

void mostrarAlumnos(alumnos *);

int main() {
    
    alumnos *a;
    
    // Reservar memoria para "a"
    a = (alumnos *) malloc(sizeof(alumnos));
    
    // Reservar Memoria
    a->matricula = (long int *) malloc(sizeof(long int));
    a->nombre = (char *) malloc(20*sizeof(char));
    
    // Introducir la informacion Alumno A
    printf("ALUMNO A\n");
    printf("Introduzca la matricula: ");
    scanf("%ld", a->matricula);
    printf("Introduzca el nombre: ");
    fflush(stdin);
    // gets(a.nombre);
    scanf("%s", a->nombre);
    printf("Introduzca el promedio: ");
    scanf("%f", &a->promedio);
    
    // Llamar a la funcion para mostrar datos de alumno
    mostrarAlumnos(a);
    
    // Liberar Memoria
    free(a->matricula);
    free(a->nombre);
    
    return 0;
}

// Funciones
void mostrarAlumnos(alumnos *alumno) {
    printf("\n\n***** DATOS DE LOS ALUMNOS *****\n\n");
    printf("ALUMNO:\n");
    printf("Matricula: %ld\n", *alumno->matricula);
    printf("Nombre: %s\n", alumno->nombre);
    printf("Promedio: %.2f\n", alumno->promedio);
}
