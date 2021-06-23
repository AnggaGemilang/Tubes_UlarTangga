#include "header.h"

//==============================================================
//     1. Modul menampilkan box header untuk judul permainan
//==============================================================
void PapanInfo() {
    int x,y,i,j;
    //Box Pertama
    gotoxy(x=66,y=4);
    printf("��������������������������������������������������ͻ");
    for (i=0; i<3; i++) {
        gotoxy(x=66,y=5+i);
        printf("�                                                  �");
    }
    gotoxy(x=66,y=5+i);
    printf("��������������������������������������������������ͼ");
    gotoxy(x=70,y=(1+i));
    printf("�Ular Tangga�");
    gotoxy(x=83,y=(3+i));
    printf("Menuju 100!");

    //Box kedua
    gotoxy(x=66,y=7+i);
    printf("��������������������������������������������������ͻ");
    for (j=0; j<(43-(7+i)); j++) {
        gotoxy(x=66,y=(8+i)+j);
        printf("�                                                  �");
    }
    gotoxy(x=66,y=((8+i)+j));
    printf("��������������������������������������������������ͼ");
    gotoxy(x=68,y=(8  + i + (j-7)));
    printf("Legend:");
    gotoxy(x=68,y=(9  + i + (j-6)));
    printf("� : Kepala Ular");
    gotoxy(x=68,y=(10 + i + (j-5)));
    printf("� : Ekor Ular");
    gotoxy(x=68,y=(11 + i + (j-4)));
    printf("� : Tangga");
}

//==============================================================
//             2. Modul fungsi untuk mengocok dadu
//==============================================================
int KocokDadu() {
    srand(time(NULL));
    int dadu=rand()%6+1;
    switch(dadu) {
    case 1:
        gotoxy(67,12);
        printf("+---------+\n");
        gotoxy(67,13);
        printf("|         |\n");
        gotoxy(67,14);
        printf("|   (-)   |\n");
        gotoxy(67,15);
        printf("|         |\n");
        gotoxy(67,16);
        printf("+---------+\n");
        break;
    case 2:
        gotoxy(67,12);
        printf("+---------+\n");
        gotoxy(67,13);
        printf("|(-)      |\n");
        gotoxy(67,14);
        printf("|         |\n");
        gotoxy(67,15);
        printf("|      (-)|\n");
        gotoxy(67,16);
        printf("+---------+\n");
        break;
    case 3:
        gotoxy(67,12);
        printf("+---------+\n");
        gotoxy(67,13);
        printf("|      (-)|\n");
        gotoxy(67,14);
        printf("|   (-)   |\n");
        gotoxy(67,15);
        printf("|(-)      |\n");
        gotoxy(67,16);
        printf("+---------+\n");
        break;
    case 4:
        gotoxy(67,12);
        printf("+---------+\n");
        gotoxy(67,13);
        printf("|(-)   (-)|\n");
        gotoxy(67,14);
        printf("|         |\n");
        gotoxy(67,15);
        printf("|(-)   (-)|\n");
        gotoxy(67,16);
        printf("+---------+\n");
        break;
    case 5:
        gotoxy(67,12);
        printf("+---------+\n");
        gotoxy(67,13);
        printf("|(-)   (-)|\n");
        gotoxy(67,14);
        printf("|   (-)   |\n");
        gotoxy(67,15);
        printf("|(-)   (-)|\n");
        gotoxy(67,16);
        printf("+---------+\n");
        break;
    case 6:
        gotoxy(67,12);
        printf("+---------+\n");
        gotoxy(67,13);
        printf("|(-)   (-)|\n");
        gotoxy(67,14);
        printf("|(-)   (-)|\n");
        gotoxy(67,15);
        printf("|(-)   (-)|\n");
        gotoxy(67,16);
        printf("+---------+\n");
        break;
    }

    return dadu;
}

//==============================================================
//             3. Modul prosedur untuk membuat map
//==============================================================
void buatMap(List * L) {
    address P, Jump;
    for(int i = 1; i <= 100; i++)
    {
        InsVLast(&(*L), i, generateSimbol(i));
    }
    P = First(*L);
    while(P != Nil)
    {
        if(generateAddress(*L, Info(P)) != Nil)
        {
            Jump(P) = generateAddress(*L, Info(P));
        }
        P = Next(P);
    }
}


//==============================================================
//             4. Modul prosedur untuk menampilkan map
//==============================================================
void tampilkanMap(List L) {
    address P;
    int x, y, columnCounter, baris, simbolCounter;
    y = 5;
    x = 4;
    baris = 1;
    columnCounter = 1;
    simbolCounter = 1;
    if(First(L) == Nil) {
        printf("matriks kosong.\n\n");
    } else {
        P = Last(L);
        printf("\n\n\n\n    �������������������������������������������������������������\n");
        while(P != Nil){
            gotoxy(x, y);
            printf("�");
            cout << Info(P);
            if(Simbol(P) != ' ') {
                tampilkanSimbol(simbolCounter, Simbol(P));
                simbolCounter++;
            }
            if(columnCounter == 10)
            {
                if(baris % 2 == 1){
                    gotoxy(x+6, y);
                    printf("�");
                } else {
                    gotoxy(x+60, y);
                    printf("�");
                }
                baris++;
                if(baris % 2 == 1){
                    x = -2;
                } else {
                    x = 64;
                }
                y += 4;
                columnCounter = 0;
                printf("\n    �     �     �     �     �     �     �     �     �     �     �");
                printf("\n    �     �     �     �     �     �     �     �     �     �     �");
                printf("\n    �������������������������������������������������������������\n");
            }
            columnCounter++;
            P = Prev(P);
            ((baris % 2 == 1) ? x += 6 : x -= 6);
        }
    }
}

//==============================================================
//             5. Modul fungsi untuk mengenerate simbol
//==============================================================
simboltype generateSimbol(infotype info) {
    if(info == 99) {
        return '�';
    } else if(info == 95) {
        return '�';
    } else if(info == 93) {
        return '�';
    } else if(info == 91) {
        return '�';
    } else if(info == 81) {
        return '�';
    } else if(info == 84) {
        return '�';
    } else if(info == 87) {
        return '�';
    } else if(info == 78) {
        return '�';
    } else if(info == 75) {
        return '�';
    } else if(info == 73) {
        return '�';
    } else if(info == 71) {
        return '�';
    } else if(info == 62) {
        return '�';
    } else if(info == 63) {
        return '�';
    } else if(info == 64) {
        return '�';
    } else if(info == 67) {
        return '�';
    } else if(info == 60) {
        return '�';
    } else if(info == 59) {
        return '�';
    } else if(info == 54) {
        return '�';
    } else if(info == 51) {
        return '�';
    } else if(info == 40) {
        return '�';
    } else if(info == 38) {
        return '�';
    } else if(info == 34) {
        return '�';
    } else if(info == 31) {
        return '�';
    } else if(info == 24) {
        return '�';
    } else if(info == 28) {
        return '�';
    } else if(info == 20) {
        return '�';
    } else if(info == 19) {
        return '�';
    } else if(info == 17) {
        return '�';
    } else if(info == 14) {
        return '�';
    } else if(info == 4) {
        return '�';
    } else if(info == 7) {
        return '�';
    } else if(info == 9) {
        return '�';
    } else {
        return ' ';
    }
}

//==============================================================
//             6. Modul prosedur untuk menampilkan simbol
//==============================================================
void tampilkanSimbol(infotype counter, simboltype Simbol) {
    if(counter == 1) {
        setcolor(15);
    } else if (counter == 2) {
        setcolor(14);
    } else if (counter == 3) {
        setcolor(13);
    } else if (counter == 4) {
        setcolor(15);
    } else if (counter == 5) {
        setcolor(10);
    } else if (counter == 6) {
        setcolor(11);
    } else if (counter == 7) {
        setcolor(14);
    } else if (counter == 8) {
        setcolor(15);
    } else if (counter == 9) {
        setcolor(14);
    } else if (counter == 10) {
        setcolor(13);
    } else if (counter == 11) {
        setcolor(15);
    } else if (counter == 12) {
        setcolor(13);
    } else if (counter == 13) {
        setcolor(12);
    } else if (counter == 14) {
        setcolor(14);
    } else if (counter == 15) {
        setcolor(9);
    } else if (counter == 16) {
        setcolor(12);
    } else if (counter == 17) {
        setcolor(12);
    } else if (counter == 18) {
        setcolor(11);
    } else if (counter == 19) {
        setcolor(13);
    } else if (counter == 20) {
        setcolor(12);
    } else if (counter == 21) {
        setcolor(10);
    } else if (counter == 22) {
        setcolor(11);
    } else if (counter == 23) {
        setcolor(9);
    } else if (counter == 24) {
        setcolor(11);
    } else if (counter == 25) {
        setcolor(10);
    } else if (counter == 26) {
        setcolor(10);
    } else if (counter == 27) {
        setcolor(9);
    } else if (counter == 28) {
        setcolor(8);
    } else if (counter == 29) {
        setcolor(8);
    } else if (counter == 30) {
        setcolor(9);
    } else if (counter == 31) {
        setcolor(8);
    } else if (counter == 32) {
        setcolor(8);
    }
    if(counter >= 30 && counter <= 32) {
        cout << "   " << Simbol;
    } else {
        cout << "  " << Simbol;
    }
    setcolor(11);
}

//==============================================================
//             7. Modul fungsi untuk mengenerate address jump
//==============================================================
address generateAddress(List L, infotype info) {
    if(info == 99) {
        return Search(L, 78);
    } else if(info == 95) {
        return Search(L, 75);
    } else if(info == 93) {
        return Search(L, 73);
    } else if(info == 87) {
        return Search(L, 24);
    } else if(info == 71) {
        return Search(L, 91);
    } else if(info == 62) {
        return Search(L, 19);
    } else if(info == 63) {
        return Search(L, 81);
    } else if(info == 64) {
        return Search(L, 60);
    } else if(info == 54) {
        return Search(L, 34);
    } else if(info == 51) {
        return Search(L, 67);
    } else if(info == 40) {
        return Search(L, 59);
    } else if(info == 28) {
        return Search(L, 84);
    } else if(info == 20) {
        return Search(L, 38);
    } else if(info == 17) {
        return Search(L, 7);
    } else if(info == 4) {
        return Search(L, 14);
    } else if(info == 9) {
        return Search(L, 31);
    } else {
        return Nil;
    }
}
