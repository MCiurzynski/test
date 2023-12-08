#include "sort.h"
#include <stdlib.h>
int cmp(const void *a, const void *b) //Funkcja porownuje dwa elementy tablicy slow
{
	pointer_slowo x = (pointer_slowo)a;
	pointer_slowo y = (pointer_slowo)b;
	return x->n < y->n ? -1 : x->n == y->n ? 0 : 1;
}

void sort(pointer_slowa slowa) { //Funkcja sortuje tablice slowprzy uzyciu funkcji qsort
	qsort(slowa->lista_slow, slowa->n, sizeof(slowa->lista_slow[0]), cmp);
}
