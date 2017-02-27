#include <stdio.h>

main() {
	int n, i;
	
	do{
		printf("Cuantos n%cmeros\n", 163);
		scanf("%d", &n);
		
		if((n < 1) || (n > 32767)) {
			printf("El valor debe ser entre 1 y 32767\n");	
		}
	}while((n < 1) || (n > 32767));
	
	int arreglo[n];
	
	for(i = 0; i < n; i++) {
		printf("Introduzca un n%cmero: ", 163);
		scanf("%d", &arreglo[i]);
	}
	
	printf("Los numeros son:");
	
	for(i = 0; i < n; i++) {
		printf("\n%d", arreglo[i]);
	}
	
	return 0;
}
