#ifndef maps_H
#define maps_H

#include "header.h"

//	1. Modul menampilkan box header untuk judul permainan
void PapanInfo();

//	2. Modul fungsi untuk mengocok dadu
int KocokDadu();

//	3. Modul prosedur untuk membuat map
void buatMap(List * L1);

//	4. Modul prosedur untuk menampilkan map
void tampilkanMap(List L);

//	5. Modul prosedur untuk mengenerate simbol
simboltype generateSimbol(infotype baris, infotype kolom);

//	6. Modul prosedur untuk menampilkan simbol
void tampilkanSimbol(infotype counter, simboltype Simbol);

void buatMapEasy(List * L1);
#endif
