//
//  Punteros-9.cpp
//  
//
//  Created by Raul Villarreal on 2/13/17.
//
//
/*
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int n, i, j;
    do {
        printf("Introduzca la cantidad de nombres: ");
        scanf("%d", &n);
        
        if(n<=0) {
            printf("La cantidad debe ser mayor a 0");
        }
        
    } while (n<=0);
    char *nombres[n];
    char *aux;
    
    // Reservar memoria para cada nombre
    for (i=0; i<n; i++) {
        nombres[i] = (char *) malloc(20*sizeof(char));
    }
    
    // Almacenar los nombres
    for (i=0; i<n; i++) {
        fflush(stdin);
        printf("Introduzca nombre #%d: ", (i+1));
        scanf("%s", nombres[i]);
        
    }
    
    // Ordenar los nombres
    for (i = 0; i < n - 1 ; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (strcmp(nombres[i], nombres[j]) > 0)
            {
                strcpy(aux, nombres[i]);
                strcpy(nombres[i], nombres[j]);
                strcpy(nombres[j], aux);
            }
        }
    }
    
    // Mostrar los nombres
    printf("**********LOS NOMBRES SON**********\n");
    for (i=0; i<n; i++) {
        printf("-> %s\n", nombres[i]);
    }
    
    // Liberar la memoria
    for (i=0; i<n; i++) {
        free(nombres[i]);
    }
    return 0;
} */

#include <stdio.h>
#include <string.h>
void main()
{
    
    char *a[10],dum[10],s;
    int i,k,j,n;
    clrscr();
    printf("enter the no of std....");
    scanf("%d",&n);
    printf("enter the name of students ");
    for(k=0;k<n;k++)
        scanf("%s",a[k]);
    for(i=1;i<n;i++)
    {
        for(j=1;j<n-i;j++)
        {if(strcmp(a[j-1],a[j])>0)
        {strcpy(*dum,*a[j-1]);
            strcpy(*a[j-1],*a[j]);
            strcpy(*a[j],*dum);
        }
        }  }
    for(i=0;i<n;i++)
        printf("%s",a[i]);
    getch();
}
