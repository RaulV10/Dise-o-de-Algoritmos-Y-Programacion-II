#include <stdio.h>
main() {
	 int i=100, *p1, *p2;
	 p1 = &i;
	 p2 = p1;
	 if (p1==p2) /* estamos comparando dos punteros */
	 	printf("p1 apunta a la misma dirección de memoria que p2");
	 *p1 = *p1 + 2; /* El * tiene más prioridad que el + */
	 printf ("\nEl valor de *p2 es %d\n", *p2);
	 (*p2)++; /* ante la duda de prioridades usamos parentesis */
	 printf("El valor de *p1 es %d\n", *p1);
	 i--;
	 printf("El valor de i es %d\n", i);
	 printf("La direccion de memoria de p1 es %p\n", p1);
	 printf("La direccion de memoria de p2 es %p\n", p2);
}
