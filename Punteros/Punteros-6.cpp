//
//  Punteros-6.cpp
//  
//
//  Created by Raul Villarreal on 2/8/17.
//
//

#include <stdio.h>
#include <stdlib.h>

int main() {
    int *nums;
    int n, i, contpar = 0;
    
    do {
        printf("Cuantos numeros: ");
        scanf("%d", &n);
        if(n<=0) {
            printf("n no debe ser negativa o cero\n");
        }
    } while(n<=0);
    
    // Reservar memoria
    nums = (int *) malloc(n*sizeof(int));
    
    // Almacenar los numeros
    for (i=0; i<n; i++) {
        printf("Introduzca el numero: ");
        scanf("%d", nums+i);
        
        if((*(nums+i)%2) == 0) {
            contpar++;
        }
    }
    
    printf("***** INFORMACION *****\n");
    
    // Mostrar la informacion
    for (i=0; i<n; i++) {
        printf(" - %d\n", *(nums+i));
    }
    
    printf("Hay %d pares\n", contpar);
    
    free(nums);
    
    return 0;
}
