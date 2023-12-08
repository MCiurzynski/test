#include "slowa.h"
#ifndef DATA_MANAGMENT_H
#define DATA_MANAGMENT_H

pointer_slowa init_slowa(int argc);

pointer_slowa wprowadz(int argc, char **argv);

void wypisz(pointer_slowa slowa);

void zwolnij_pamiec(pointer_slowa slowa);

#endif
