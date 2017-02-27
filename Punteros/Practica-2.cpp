//
//  Practica-2.cpp
//  
//
//  Created by Raul Villarreal on 2/7/17.
//
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *palabra;
    int cons, i, tam;
    
    palabra = (char *) malloc(30*sizeof(char));
    
    // Almacenar
    printf("Introduzca una palabra: ");
    fflush(stdin);
    scanf("%s", palabra);
    
    tam = strlen(palabra);
    
    
    for(i=0; i<tam; i++) {
        switch (*(palabra+i)) {
            case 'b': case 'c': case 'd': case 'f': case 'g': case 'h': case 'j': case 'k': case 'l': case 'm': case 'n': case 'p': case 'q': case 'r': case 's': case 't': case 'v': case 'w': case 'x': case 'y': case 'z':
            case 'B': case 'C': case 'D': case 'F': case 'G': case 'H': case 'J': case 'K': case 'L': case 'M': case 'N': case 'P': case 'Q': case 'R': case 'S': case 'T': case 'V': case 'W': case 'X': case 'Y': case 'Z':
                cons++;
                break;
                
            default:
                break;
        }
    }
    
    printf("Tiene %d consonantes\n", cons);
}
