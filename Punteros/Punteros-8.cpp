//
//  Punteros-8.cpp
//  
//
//  Created by Raul Villarreal on 2/13/17.
//
//

#include <stdio.h>
#include <stdlib.h>

void OBurbuja(int *, int);

int main() {
    
    int *nums, n, i;
    do {
        printf("Cuantos numeros: ");
        scanf("%d", &n);
        
        if(n<=0) {
            printf("La cantidad de numeros debe ser mayor a 0");
        }
    } while (n<=0);
    
    // Reservar Memoria
    nums = (int *) malloc(n*sizeof(int));
    
    // Almacenar los nums
    for(i=0; i<n; i++) {
        printf("Introduzca un numero: ");
        scanf("%d", (nums + i));
        // nums++;
    }
    
    // nums = nums - n
    
    // Llamar a la funcion
    OBurbuja(nums, n);
    
    // Librerar la memoria
    free(nums);
    
    return 0;
}

void OBurbuja(int *nums, int n) {
    int i, j;
    int aux;
    
    for(j=0; j<(n-1); j++) {
        for(i=0; i<(n-1); i++) {
            if(*(nums +i)>*(nums + i + 1)) {
                aux = *(nums + i);
                *(nums + i) = *(nums + i + 1);
                *(nums + i + 1) = aux;
            }
        }
    }
    
    printf("\n*********NUMEROS ORDENADOS**********\n");
    
    // Mostrar numeros
    for(i=0; i<n; i++) {
        printf("->%d\n", *(nums+i));
    }
    
}
