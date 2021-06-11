#include "header.h"

int pilihan;

//==============================================================
//             1. Mode Single Player 'Bermain Sendiri'
//==============================================================
void BermainSendiri() {
    int JumlahAI, y;

    //mencetak sisi atas dan bawah kotak
    gotoxy(39,5);       printf("_____________________________________________");
    gotoxy(40,15);      printf("___________________________________________");

    //mencetak sisi kiri dan kanan kotak
    for(y=6;y<=15;y++){
        gotoxy(39,y);		printf("|");
		gotoxy(83,y);		printf("|");
	}

	//mencetak isi tulisan dalam kotak
    gotoxy(53,7);       printf("Pilih Jumlah Lawan");
    gotoxy(43,8);		printf("______________________________________");
    gotoxy(45,10);      printf("1. VS 1 KOMPUTER");
    gotoxy(45,11);      printf("2. VS 2 KOMPUTER");
    gotoxy(45,12);      printf("3. VS 3 KOMPUTER");
    gotoxy(45,13);      printf("4. Kembali");

    pilihan=Cursor(4,42,10); //User memilih menu menggunakan tombol keyboard atas atau bawah

    switch(pilihan) {
    case 1 || 2 || 3:
        //Pemilihan jumlah pemain komputer dilakukan dengan menggunakan tombol atas atau bawah keyboard
        JumlahAI = pilihan;
        system("cls");

        //Jumlah pemain dan jumlah pemain komputer "dilempar" ke modul yang bernama "Permainan"
        Permainan(1, JumlahAI);
    case 4:
        return;
        break;
    }
}

//==============================================================
//         2. Mode Multi Player 'Bermain Bersama Teman'
//==============================================================
void BermainBersamaTeman() {
    int JumlahPemain, y;

    //mencetak sisi atas dan bawah kotak
    gotoxy(39,5);       printf("_____________________________________________");
    gotoxy(40,15);      printf("___________________________________________");

    //mencetak sisi kiri dan kanan kotak
    for(y=6;y<=15;y++){
        gotoxy(39,y);		printf("|");
		gotoxy(83,y);		printf("|");
	}

	//mencetak isi tulisan dalam kotak
    gotoxy(53,7);       printf("Pilih Jumlah Pemain");
    gotoxy(43,8);		printf("______________________________________");
    gotoxy(45,10);      printf("1. 2 Pemain");
    gotoxy(45,11);      printf("2. 3 Pemain");
    gotoxy(45,12);      printf("3. 4 Pemain");
    gotoxy(45,13);      printf("4. Kembali");

    pilihan=Cursor(4,42,10); //User memilih menu menggunakan tombol keyboard atas atau bawah

    switch(pilihan) {
    case 1 || 2 || 3:
        //Pelilihan jumlah pemain yang dilawan dilakukan dengan menggunakan tombol atas atau bawah keyboard
        JumlahPemain = pilihan+1;
        system("cls");

        //Jumlah pemain dan jumlah pemain komputer "dilempar" ke modul yang bernama "Permainan"
        Permainan(JumlahPemain,0);
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

    fclose(fp);
}
