#include "header.h"

//==============================================================
//     1. Modul menampilkan box header untuk judul permainan
//==============================================================
void PapanInfo() {

    int x,y,i,j;

    //Box Pertama
    gotoxy(x=66,y=4);
    printf("浜様様様様様様様様様様様様様様様様様様様様様様様様融");
    for (i=0; i<3; i++) {
        gotoxy(x=66,y=5+i);
        printf("�                                                  �");
    }
    gotoxy(x=66,y=5+i);
    printf("藩様様様様様様様様様様様様様様様様様様様様様様様様夕");
    gotoxy(x=70,y=(1+i));
    printf("�Ular Tangga�");
    gotoxy(x=83,y=(3+i));
    printf("Menuju 100!");

    //Box kedua
    gotoxy(x=66,y=7+i);
    printf("浜様様様様様様様様様様様様様様様様様様様様様様様様融");
    for (j=0; j<(43-(7+i)); j++) {
        gotoxy(x=66,y=(8+i)+j);
        printf("�                                                  �");
    }
    gotoxy(x=66,y=((8+i)+j));
    printf("藩様様様様様様様様様様様様様様様様様様様様様様様様夕");
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
//	2. Modul membuat papan permainan buta (tanpa simbol ular
//                          ataupun tangga)
//==============================================================
void PapanButa() {
    int x,y,i,j,nomor;
//    board vertikal
    for (i=0; i<=10; i++) {
        for (j=0; j<39; j++) {
            gotoxy(x=4+(6*i),y=5+j);
            printf("�");
        }
    }

//    board horizontal
	for (i=0; i<11; i++) {
		for (j=0; j<10; j++) {	gotoxy(x=4+(6*j),y=4+(4*i));	printf("陵様様�");	}
	}

//    NOMOR
    for (i=0; i<10; i++) {
        for (j=0; j<10; j++) {
            gotoxy(x=5+(6*j),y=41-(4*i));
            nomor=((i+1)/2)*20+((i+1)%2)+(pow(-1,((i+1)-1))*((j+1)-1));
            printf("%d",nomor);
        }
    }
}

//==============================================================
//      3. Modul untuk meletakkan simbol ular dan tangga
//==============================================================
void SimbolUlarDanTangga() {
    int x,y;
    //Posisi Ular (Ekor)
    gotoxy(x=45,y=41);
    setcolor(8);
    printf("�");
    setcolor(7);
    gotoxy(x=15,y=37);
    setcolor(9);
    printf("�");
    setcolor(7);
    gotoxy(x=27,y=33);
    setcolor(10);
    printf("�");
    setcolor(7);
    gotoxy(x=45,y=29);
    setcolor(11);
    printf("�");
    setcolor(7);
    gotoxy(x=9,y=21);
    setcolor(12);
    printf("�");
    setcolor(7);
    gotoxy(x=51,y=13);
    setcolor(13);
    printf("�");
    setcolor(7);
    gotoxy(x=39,y=13);
    setcolor(14);
    printf("�");
    setcolor(7);
    gotoxy(x=21,y=13);
    setcolor(15);
    printf("�");
    setcolor(7);


    //Posisi Ular ( Kepala)
    gotoxy(x=27,y=37);
    setcolor(8);
    printf("�");
    setcolor(7);
    gotoxy(x=15,y=17);
    setcolor(9);
    printf("�");
    setcolor(7);
    gotoxy(x=45,y=9);
    setcolor(10);
    printf("�");
    setcolor(7);
    gotoxy(x=45,y=21);
    setcolor(11);
    printf("�");
    setcolor(7);
    gotoxy(x=27,y=17);
    setcolor(12);
    printf("�");
    setcolor(7);
    gotoxy(x=51,y=5);
    setcolor(13);
    printf("�");
    setcolor(7);
    gotoxy(x=39,y=5);
    setcolor(14);
    printf("�");
    setcolor(7);
    gotoxy(x=15,y=5);
    setcolor(15);
    printf("�");
    setcolor(7);

    //Posisi Tangga (Awal Naik)
    gotoxy(x=27,y=41);
    setcolor(8);
    printf("�");
    setcolor(7);
    gotoxy(x=57,y=41);
    setcolor(9);
    printf("�");
    setcolor(7);
    gotoxy(x=9,y=37);
    setcolor(10);
    printf("�");
    setcolor(7);
    gotoxy(x=51,y=33);
    setcolor(11);
    printf("�");
    setcolor(7);
    gotoxy(x=9,y=29);
    setcolor(12);
    printf("�");
    setcolor(7);
    gotoxy(x=63,y=21);
    setcolor(13);
    printf("�");
    setcolor(7);
    gotoxy(x=21,y=17);
    setcolor(14);
    printf("�");
    setcolor(7);
    gotoxy(x=63,y=13);
    setcolor(15);
    printf("�");
    setcolor(7);

    //Posisi Tangga (Akhir Naik)
    gotoxy(x=45,y=37);
    setcolor(8);
    printf("�");
    setcolor(7);
    gotoxy(x=63,y=29);
    setcolor(9);
    printf("�");
    setcolor(7);
    gotoxy(x=21,y=29);
    setcolor(10);
    printf("�");
    setcolor(7);
    gotoxy(x=27,y=9);
    setcolor(11);
    printf("�");
    setcolor(7);
    gotoxy(x=15,y=21);
    setcolor(12);
    printf("�");
    setcolor(7);
    gotoxy(x=45,y=17);
    setcolor(13);
    printf("�");
    setcolor(7);
    gotoxy(x=9,y=9);
    setcolor(14);
    printf("�");
    setcolor(7);
    gotoxy(x=63,y=5);
    setcolor(15);
    printf("�");
    setcolor(7);

}

//==============================================================
//  4. Modul untuk menampilkan papan ermainan secara utuh (Ada
// hiasan Header judul permainan, dan ada simbol ular dan tangga)
//==============================================================
void PapanGame() {
    PapanInfo();
    PapanButa();
    SimbolUlarDanTangga();
}

//==============================================================
//             5. Modul fungsi untuk mengocok dadu
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
//             6. Modul prosedur untuk membuat map
//==============================================================
void buatMap(List * L1)
{
	List L2;
	int i, j, isGanjil = true, ganjilGenap = 0;
	infotype nilai = 101;
	address P1, P2, down;

	for(i=1; i<=10; i++)
	{
	    ganjilGenap += 1;
		CreateList(&L2);
        if(ganjilGenap % 2 == 1)
        {
            isGanjil = false;
            if(ganjilGenap != 1)
            {
                nilai -= 9;
            }
        } else
        {
            isGanjil = true;
            nilai -= 11;
        }
		for(j=1; j<=10; j++)
		{
		    if(isGanjil)
            {
                nilai += 1;
            } else
            {
                nilai -= 1;
            }
			P1 = Alokasi(nilai, generateSimbol(i, j));
			if(i==1)
			{
				InsertLast(&(*L1), P1);
				P2 = First(*L1);
			}
			else
			{
				InsertLast(&L2, P1);
				baris(down) = P1;
				down = Next(down);
			}
		}
		if(i > 1)
		{
			P2 = baris(P2);
		}
		down = P2;
	}
}


//==============================================================
//             7. Modul prosedur untuk menampilkan map
//==============================================================
void tampilkanMap(List L)
{
	address P1,P2;
    infotype counter = 0;

	if(First(L) == Nil)
	{
		printf("matriks kosong.\n\n");
	}
	else
	{
		P1 = First(L);
		while(P1 != Nil)
		{
            printf("陵様様陵様様陵様様陵様様陵様様陵様様陵様様陵様様陵様様陵様様�\n");
			P2=P1;
			while (P2 != Nil)
			{
                printf("�");
				printf ("%d", Info(P2));
                if(Simbol(P2) != ' ')
                {
                    counter++;
                    tampilkanSimbol(counter, Simbol(P2));
                } else {
                    if(Info(P2) == 100)
                    {
                        cout << "  ";
                    } else if(Info(P2) >= 1 && Info(P2) <= 9) {
                        cout << "    ";
                    } else {
                        cout << "   ";
                    }
                }
				P2 = Next(P2);
			}
            printf("�");
			printf("\n�     �     �     �     �     �     �     �     �     �     �");
			printf("\n�     �     �     �     �     �     �     �     �     �     �\n");
			P1 = baris(P1);
		}
        printf("陵様様陵様様陵様様陵様様陵様様陵様様陵様様陵様様陵様様陵様様�\n");
	}
}

//==============================================================
//             8. Modul fungsi untuk mengenerate simbol
//==============================================================
simboltype generateSimbol(infotype baris, infotype kolom)
{
    if(baris == 1)
    {
        if(kolom == 2)
        {
            return '�';
        } else if(kolom == 6)
        {
            return '�';
        } else if(kolom == 8)
        {
            return '�';
        } else if(kolom == 10)
        {
            return '�';
        }
    } else if (baris == 2)
    {
        if(kolom == 1)
        {
            return '�';
        } else if(kolom == 4)
        {
            return '�';
        } else if(kolom == 7)
        {
            return '�';
        }
    } else if (baris == 3)
    {
        if(kolom == 3)
        {
            return '�';
        } else if(kolom == 6)
        {
            return '�';
        } else if(kolom == 8)
        {
            return '�';
        } else if(kolom == 10)
        {
            return '�';
        }
    } else if (baris == 4)
    {
        if(kolom == 2)
        {
            return '�';
        } else if(kolom == 3)
        {
            return '�';
        } else if(kolom == 4)
        {
            return '�';
        } else if(kolom == 7)
        {
            return '�';
        }
    } else if (baris == 5)
    {
        if(kolom == 1)
        {
            return '�';
        } else if(kolom == 2)
        {
            return '�';
        } else if(kolom == 7)
        {
            return '�';
        } else if(kolom == 10)
        {
            return '�';
        }
    } else if (baris == 7)
    {
        if(kolom == 1)
        {
            return '�';
        } else if(kolom == 3)
        {
            return '�';
        } else if(kolom == 7)
        {
            return '�';
        } else if(kolom == 10)
        {
            return '�';
        }
    } else if (baris == 8)
    {
        if(kolom == 4)
        {
            return '�';
        } else if(kolom == 8)
        {
            return '�';
        }
    } else if (baris == 9)
    {
        if(kolom == 1)
        {
            return '�';
        } else if(kolom == 2)
        {
            return '�';
        } else if(kolom == 4)
        {
            return '�';
        } else if(kolom == 7)
        {
            return '�';
        }
    } else if (baris == 10)
    {
        if(kolom == 4)
        {
            return '�';
        } else if(kolom == 7)
        {
            return '�';
        } else if(kolom == 9)
        {
            return '�';
        }
    }
    return ' ';
}

void tampilkanSimbol(infotype counter, simboltype Simbol)
{
    if(counter == 1)
    {
        setcolor(15);
    } else if (counter == 2)
    {
        setcolor(14);
    } else if (counter == 3)
    {
        setcolor(13);
    } else if (counter == 4)
    {
        setcolor(15);
    } else if (counter == 5)
    {
        setcolor(14);
    } else if (counter == 6)
    {
        setcolor(11);
    } else if (counter == 7)
    {
        setcolor(10);
    } else if (counter == 8)
    {
        setcolor(15);
    } else if (counter == 9)
    {
        setcolor(14);
    } else if (counter == 10)
    {
        setcolor(13);
    } else if (counter == 11)
    {
        setcolor(15);
    } else if (counter == 12)
    {
        setcolor(9);
    } else if (counter == 13)
    {
        setcolor(14);
    } else if (counter == 14)
    {
        setcolor(12);
    } else if (counter == 15)
    {
        setcolor(13);
    } else if (counter == 16)
    {
        setcolor(12);
    } else if (counter == 17)
    {
        setcolor(12);
    } else if (counter == 18)
    {
        setcolor(11);
    } else if (counter == 19)
    {
        setcolor(13);
    } else if (counter == 20)
    {
        setcolor(12);
    } else if (counter == 21)
    {
        setcolor(10);
    } else if (counter == 22)
    {
        setcolor(11);
    } else if (counter == 23)
    {
        setcolor(9);
    } else if (counter == 24)
    {
        setcolor(10);
    } else if (counter == 25)
    {
        setcolor(11);
    } else if (counter == 26)
    {
        setcolor(10);
    } else if (counter == 27)
    {
        setcolor(9);
    } else if (counter == 28)
    {
        setcolor(8);
    } else if (counter == 29)
    {
        setcolor(8);
    } else if (counter == 30)
    {
        setcolor(8);
    } else if (counter == 31)
    {
        setcolor(8);
    } else if (counter == 32)
    {
        setcolor(9);
    }
    if(counter >= 30 && counter <= 32)
    {
        cout << "   " << Simbol;
    } else
    {
        cout << "  " << Simbol;
    }
    setcolor(7);
}
