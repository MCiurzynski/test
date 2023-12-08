#include "slowa.h"
#ifndef FIND_WORD_H
#define FIND_WORD_H

#define BUFFER 1024

void lower(char *slowo);

int czy_wystepuje(char *linia, char *slowo);

int wyszukaj(char *plik, pointer_slowa slowa);

#endif
