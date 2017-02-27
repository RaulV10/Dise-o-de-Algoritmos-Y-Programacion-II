//
//  Struct-7.c
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

void mostrarAlumnos(alumnos *, int);

int main() {
    int n, i;
    alumnos *a;
    
    do {
        printf("Introduzca el numero de alumnos a registrar: ");
        scanf("%d", &n);
        
        if(n<=0) {
            printf("\nIntroduzca un numero positivo\n");
        }
    }while(n <= 0);
    
    
    // Reservar memoria para la cantidad de alumnos
    a = (alumnos *) malloc(n*sizeof(alumnos));
    
    // Reservar Memoria
    for (i = 0; i<n; i++) {
        a->matricula = (long int *) malloc(sizeof(long int));
        a->nombre = (char *) malloc(20*sizeof(char));
        
        // Cambiar al siguiente alumno para reservar memoria
        a++;
    }
    
    // Regresar al alumno inicial
    a = a - n;
    
    // Almacenar informacion de alumnos
    for (i=0; i<n; i++) {
        // Introducir la informacion Alumno A
        printf("ALUMNO #%d\n", i+1);
        printf("Introduzca la matricula: ");
        scanf("%ld", a->matricula);
        printf("Introduzca el nombre: ");
        fflush(stdin);
        // gets(a.nombre);
        scanf("%s", a->nombre);
        printf("Introduzca el promedio: ");
        scanf("%f", &a->promedio);
        
        a++;
    }
    
    // Regresar al alumno inicial
    a = a - n;
    
    // Llamar a la funcion para mostrar datos de alumno
    mostrarAlumnos(a, n);

    
    // Liberar Memoria
    for (i = 0; i < n; i++) {
        free(a->matricula);
        free(a->nombre);
        
        a++;
    }
    
    // Regresar al alumno inicial
    a = a - n;
    
    return 0;
}

// Funciones
void mostrarAlumnos(alumnos *alumno, int n) {
    int i;
    
    for (i = 0; i < n; i++) {
        printf("\n\n***** DATOS DE LOS ALUMNOS *****\n\n");
        printf("ALUMNO #%d:\n", i+1);
        printf("Matricula: %ld\n", *alumno->matricula);
        printf("Nombre: %s\n", alumno->nombre);
        printf("Promedio: %.2f\n", alumno->promedio);
        
        alumno++;
    }
    
    alumno = alumno - n;
    
}
