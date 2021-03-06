#include "header.h"

//========================================================================
//  1. Modul untuk mengatur posisi output berdasarkan koordinat tertentu
//========================================================================
void gotoxy(int x, int y) { //goes to x,y console
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

//==============================================================
//                    2. Modul ganti warna
//==============================================================
void setcolor (unsigned short color) {
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hCon,color);
}

//==============================================================
//          3. Modul fugsi untuk menggerakkan cursor
//==============================================================
int Cursor(int BanyakPilihan,int x,int y) {
    int Pilih=1,ysel=(BanyakPilihan+y-1)-y;
    char cursor;
    gotoxy(x,y);
    printf("%c",62);

    do {
        cursor =_getch();//diganti jadi _getch(); karena jika menggunakan getch(); ada error drawing operation was attempted when there was no current window error while using getch() in C saat runtime
        if(cursor == DOWN_KEY) {//down key
            Beep(500, 40);
            if(Pilih+1 > BanyakPilihan) {
                gotoxy(x,y);
                printf(" ");
                y=y-ysel;//posisi y kembali lagi ke pilihan 1 jika sudah di pilihan terakhir
                Pilih=1;
                gotoxy(x,y);
                printf("%c",62);
            } else {
                gotoxy(x,y);
                printf(" ");
                Pilih ++;
                y++;
                gotoxy(x,y);
                printf("%c",62);
            }
        }

        else if(cursor == UP_KEY) {//up key
            Beep(500, 40);
            if(Pilih-1 == 0) {
                gotoxy(x,y);
                printf(" ");
                y=y+ysel;//posisi y kembali lagi ke pilihan terakhir jika sudah di pilihan pertama
                Pilih=BanyakPilihan;
                gotoxy(x,y);
                printf("%c",62);
            } else {
                gotoxy(x,y);
                printf(" ");
                Pilih --;
                y --;
                gotoxy(x,y);
                printf("%c",62);
            }
        }
    } while(cursor != 13);

	Beep(700, 40);

    return Pilih;
}

//==============================================================
//          4. Modul untuk mengambil nomor secara acak
//==============================================================
int random_number(int batas_awal, int batas_akhir)
{
    srand(time(NULL));
    int random_number = (rand() % (batas_akhir - batas_awal + 1)) + batas_awal;
    return random_number;
}
