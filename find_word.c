#include "find_word.h"
#include <stdio.h> 
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
void lower(char *slowo) //Funkcja zmienia podany ciag znakow na male litery
{
	int i;
	for (i = 0; slowo[i]; i++)
		slowo[i] = tolower(slowo[i]);
}

int czy_wystepuje(char *linia, char *slowo) { //Funkcja sprawdza czy podane slowo wystepuje w podanym ciagu znakow
	int i;
	lower(linia);
	lower(slowo);
	char znaki[] = {' ', ',', '.', '\n', ':', ';', '\'', '\"', '(', ')', '?', '!'};
	char buf[BUFFER + 2];
	for (i = 0; i < (sizeof(znaki) / sizeof(znaki[0])); i++) {
		sprintf(buf, " %s%c", slowo, znaki[i]);
		if (strstr(linia, buf) != NULL)
			return 1;
	}
	for (i = 0; i < (sizeof(znaki) / sizeof(znaki[i])); i++)
	{
		sprintf(buf, "%s%c", slowo, znaki[i]);
		if(strstr(linia, buf) == linia)
			return 1;
	}
	return 0;
}

int wyszukaj(char *plik, pointer_slowa slowa) { //Funkcja szuka podanych slow w podanym pliku i zapisuje ilosc wystapien i linie wystapien do struktury danego slowa
	char buf[BUFFER];
	int i, linia = 0;
	FILE *f = fopen(plik, "r");
	pointer_slowo slowo;
	if (f == NULL)
		return 1;
	while (fgets(buf, BUFFER, f) != NULL)
	{
		for (i = 0; i < slowa->n; i++) {
			slowo = (slowa->lista_slow + i);
			if (czy_wystepuje(buf, slowo->slowo) == 1) {
				if (slowo->linie == NULL) {
					slowo->linie = malloc(sizeof(pointer_slowo));
					if (slowo->linie == NULL)
						return 2;
					slowo->linie[0] = linia + 1;
				}
				else {
					slowo->linie = realloc(slowo->linie, sizeof(slowo->linie) * slowo->n);
					if (slowo->linie == NULL)
						return 2;
					slowo->linie[slowo->n] = linia + 1;
				}
				slowo->n++;
			}
		}
		linia++;
	}
	return 0;
}
