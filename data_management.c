#include "data_management.h"
#include "slowa.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

pointer_slowa init_slowa(int argc) { //Funkcja inicjuje strukture slow
	pointer_slowa slowa = malloc(sizeof(*slowa));
	if (slowa == NULL)
		return NULL;
	slowa->n = 0;
	slowa->lista_slow = malloc(sizeof(struct struct_slowo) * (argc - 2));
	if (slowa->lista_slow == NULL){
		free(slowa);
		return NULL;
	}
	return slowa;
}

pointer_slowa wprowadz(int argc, char **argv) { //Funkcja sluzy do wprowadzania wyszukiwanych slow do struktury slow
	pointer_slowa slowa = init_slowa(argc);
	int i, j, ilosc = 0;
	if (slowa == NULL) {
		printf("Nie udalo sie zaalokowac pamieci");
		return NULL;
	}
	for (i = 2; i < argc; i++)
	{
		for (j = 0; j < ilosc; j++) {
			if (strcmp((slowa->lista_slow[j]).slowo, argv[i]) == 0)
				break;
		}
		if (j != ilosc) 
			continue;
		(slowa->lista_slow[ilosc]).slowo= argv[i];
		(slowa->lista_slow[ilosc]).n = 0;
		ilosc++;
		slowa->n++;
	}
	return slowa;
}

void wypisz(pointer_slowa slowa) { //Funkcja wypisuje wyszukiwane slowa
	int i;
#ifndef BRAK_LINII
	int j;
#endif
	printf("Skorowidz:\n");
	for (i = 0; i < slowa->n; i++)
	{
		printf("Slowo: %s\n", (slowa->lista_slow[i]).slowo);
		printf("Liczba wystapien: %d\n", (slowa->lista_slow[i]).n);
#ifndef BRAK_LINII
		if ((slowa->lista_slow[i]).n > 0)
			printf("Linie w ktorych wystepuje:\n");
		for (j = 0; j < (slowa->lista_slow[i]).n; j++)
			printf("%6d\n", (slowa->lista_slow[i]).linie[j]);
#endif
		printf("\n");
	}
}

void zwolnij_pamiec(pointer_slowa slowa) { //Funkcja zwalnia pamiec zajmowana przez strukture
	int i;
	for (i = 0; i < slowa->n; i++)
	{
		if ((slowa->lista_slow[i]).linie != NULL)
			free((slowa->lista_slow[i]).linie);
	}
	if (slowa->lista_slow != NULL)
		free(slowa->lista_slow);
	free(slowa);
}
