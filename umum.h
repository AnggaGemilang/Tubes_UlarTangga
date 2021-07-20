#ifndef umum_H
#define umum_H

typedef struct {
    int jam, menit, detik;
} Timestamp;

// 1. Modul GoToXY
void gotoxy(int x, int y);

// 2. Modul ganti warna
void setcolor(unsigned short color);

// 3. Modul fugsi untuk menggerakkan cursor
int Cursor(int BanyakPilihan,int x,int y);

int random_number(int batas_awal, int batas_akhir);

#endif // umum_H
