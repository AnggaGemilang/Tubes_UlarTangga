#include "header.h"

//==============================================================
//                      1. Modul GoToXY
//==============================================================
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

//    Ascii dari
//    Up key - 224 72
//    Down key - 224 80
//    Left key - 224 75
//    Right key - 224 77

    do {
        cursor=_getch();//diganti jadi _getch(); karena jika menggunakan getch(); ada error drawing operation was attempted when there was no current window error while using getch() in C saat runtime

        if(cursor == 80) {//down key
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

        if(cursor == 72) {//up key
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

    return Pilih;
}
