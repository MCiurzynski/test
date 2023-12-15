#include "data_management.h"
#include "find_word.h"
#include "sort.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	if (argc == 1) {
		printf("Nie podano nazwy pliku\n");
		return 1;
	}
	if (argc == 2) {
		printf("Nie podano slow do wyszukania\n");
		return 2;
	}
	pointer_slowa slowa = wprowadz(argc, argv);
	if (wyszukaj(argv[1], slowa) == 1) {
		printf("Nie udalo sie otworzyc pliku\n");
		zwolnij_pamiec(slowa);
		return 3;
	}
	sort(slowa);
	wypisz(slowa);
	zwolnij_pamiec(slowa);
	return 0;
}
