//
//  Struct-8.cpp
//
//
//  Created by Raul Villarreal on 3/07/17.
//
//

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    long int *matricula;
    char *nombre;
    float promedio;
}alumnos;

void mostrarAlumnos(alumnos [20], int);

int main() {
    int n, i;
    
    do {
        printf("Introduzca el numero de alumnos a registrar: ");
        scanf("%d", &n);
        
        if(n<=0) {
            printf("\nIntroduzca un numero positivo\n");
        }
    }while(n <= 0);
    
    alumnos a[n];
    
    // Reservar Memoria
    for (i = 0; i<n; i++) {
        a[i].matricula = (long int *) malloc(sizeof(long int));
        a[i].nombre = (char *) malloc(20*sizeof(char));
        
    }
    
    
    // Almacenar informacion de alumnos
    for (i=0; i<n; i++) {
        // Introducir la informacion Alumno A
        printf("ALUMNO #%d\n", i+1);
        printf("Introduzca la matricula: ");
        scanf("%ld", a[i].matricula);
        printf("Introduzca el nombre: ");
        fflush(stdin);
        // gets(a.nombre);
        scanf("%s", a[i].nombre);
        printf("Introduzca el promedio: ");
        scanf("%f", &a[i].promedio);
        
    }

    // Llamar a la funcion para mostrar datos de alumno
    mostrarAlumnos(a, n);

    
    // Liberar Memoria
    for (i = 0; i < n; i++) {
        free(a[i].matricula);
        free(a[i].nombre);
    }
    
    
    return 0;
}

// Funciones
void mostrarAlumnos(alumnos alumno[], int n) {
    int i;
    
    for (i = 0; i < n; i++) {
        printf("\n\n***** DATOS DE LOS ALUMNOS *****\n\n");
        printf("ALUMNO #%d:\n", i+1);
        printf("Matricula: %ld\n", *alumno[i].matricula);
        printf("Nombre: %s\n", alumno[i].nombre);
        printf("Promedio: %.2f\n", alumno[i].promedio);
    }
    
}
