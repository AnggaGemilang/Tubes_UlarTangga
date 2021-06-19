#include "header.h"

int pilihan;

//==============================================================
//             1. Mode Single Player 'Bermain Sendiri'
//==============================================================
void BermainSendiri(List * map) {
    int JumlahAI, y;

    //  mencetak sisi atas dan bawah kotak
    gotoxy(trunc(WDT_SCREEN/11/2),5);		printf("____________________________________________");
    gotoxy(trunc(WDT_SCREEN/11/2),15);		printf("____________________________________________");

    //  mencetak sisi kiri dan kanan kotak
    for(y=6;y<=15;y++){
        gotoxy(trunc(WDT_SCREEN/11/2-1),y);		    printf("|");
        gotoxy(trunc(WDT_SCREEN/11/2+44),y);		printf("|");
    }

	//mencetak isi tulisan dalam kotak
    gotoxy(trunc(WDT_SCREEN/11/2+7),7);		printf(">>>>| Pilih Jumlah Lawan |<<<<");
	gotoxy(trunc(WDT_SCREEN/11/2+3),8);		printf("______________________________________");
	gotoxy(trunc(WDT_SCREEN/11/2+5),10);		printf("1. VS 1 KOMPUTER");
	gotoxy(trunc(WDT_SCREEN/11/2+5),11);		printf("2. VS 2 KOMPUTER");
	gotoxy(trunc(WDT_SCREEN/11/2+5),12);		printf("3. VS 3 KOMPUTER");
	gotoxy(trunc(WDT_SCREEN/11/2+5),13);		printf("4. Kembali");

    pilihan = Cursor(4,64,10); //User memilih menu menggunakan tombol keyboard atas atau bawah

    switch(pilihan) {
    case 1 :
    case 2 :
    case 3 :

        //Pemilihan jumlah pemain komputer dilakukan dengan menggunakan tombol atas atau bawah keyboard
        JumlahAI = pilihan;

        system("cls");

        //Jumlah pemain dan jumlah pemain komputer "dilempar" ke modul yang bernama "Permainan"
        Permainan(1, JumlahAI, &(*map));
        break;
    case 4:
        return;
        break;
    }
}

//==============================================================
//         2. Mode Multi Player 'Bermain Bersama Teman'
//==============================================================
void BermainBersamaTeman(List * map) {
    int JumlahPemain, y;

    //  mencetak sisi atas dan bawah kotak
    gotoxy(trunc(WDT_SCREEN/11/2),5);		printf("____________________________________________");
    gotoxy(trunc(WDT_SCREEN/11/2),15);		printf("____________________________________________");

    //  mencetak sisi kiri dan kanan kotak
    for(y=6;y<=15;y++){
        gotoxy(trunc(WDT_SCREEN/11/2-1),y);		    printf("|");
        gotoxy(trunc(WDT_SCREEN/11/2+44),y);		printf("|");
    }

	//mencetak isi tulisan dalam kotak
    gotoxy(trunc(WDT_SCREEN/11/2+7),7);		printf(">>>>| Pilih Jumlah Pemain |<<<<");
	gotoxy(trunc(WDT_SCREEN/11/2+3),8);		printf("______________________________________");
	gotoxy(trunc(WDT_SCREEN/11/2+5),10);		printf("1. 2 Pemain");
	gotoxy(trunc(WDT_SCREEN/11/2+5),11);		printf("2. 3 Pemain");
	gotoxy(trunc(WDT_SCREEN/11/2+5),12);		printf("3. 4 Pemain");
	gotoxy(trunc(WDT_SCREEN/11/2+5),13);		printf("4. Kembali");

    pilihan = Cursor(4,64,10); //User memilih menu menggunakan tombol keyboard atas atau bawah

    switch(pilihan) {
        case 1:
        case 2:
        case 3:

            //Pelilihan jumlah pemain yang dilawan dilakukan dengan menggunakan tombol atas atau bawah keyboard
            JumlahPemain = pilihan+1;

            system("cls");

            //Jumlah pemain dan jumlah pemain komputer "dilempar" ke modul yang bernama "Permainan"
            Permainan(JumlahPemain,0, &(*map));
            break;
        case 4:
            return;
            break;
    }
}

//==============================================================
//          3. Menampilkan Tatacara bermain permainan
//==============================================================
void CaraMain() {
    FILE *fp;
    char Kalimat;

    if((fp=fopen("assets\\file\\HowTo.txt","r")) != NULL) {
        while((Kalimat=getc(fp)) != EOF) {
            putch(Kalimat);
        }
    } else {
        gotoxy(43,10);       printf("File Tata Cara Bermain Tidak Ditemukan!");
    }

    _getch();

    fclose(fp);
}
