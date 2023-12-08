#ifndef SLOWA_H
#define SLOWA_H

typedef struct struct_slowo { //Struktura przechowujaca jedno slowo, ilosc jego wystapien i linie wystapien
	char *slowo;
	int n;
	int *linie;
} *pointer_slowo;

typedef struct { //Struktura przechowujaca tablice struktur poszczegolnych slow i ich ilosc
	int n;
	pointer_slowo lista_slow;
} *pointer_slowa;

#endif
