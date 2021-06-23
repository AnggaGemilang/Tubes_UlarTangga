#include "header.h"

int pilihan;

//==============================================================
//                  1. Menu utama program
//==============================================================
void menuUtama()
{

    int PilihanUser;
    bool ulangi=true;
	int x, y, loop;
	int width;

    List map;

        do {
            system("color b"); // mengatur warna font
            system("MODE 120,50"); // mengatur ukuran windows

            //  mencetak sisi atas dan bawah kotak
            gotoxy(trunc(WDT_SCREEN/11/2),5);		printf("____________________________________________");
            gotoxy(trunc(WDT_SCREEN/11/2),15);		printf("____________________________________________");

            //  mencetak sisi kiri dan kanan kotak
            for(y=6;y<=15;y++){
                gotoxy(trunc(WDT_SCREEN/11/2-1),y);		    printf("|");
                gotoxy(trunc(WDT_SCREEN/11/2+44),y);		printf("|");
            }

            //  mencetak isi tulisan dalam kotak
            gotoxy(trunc(WDT_SCREEN/11/2+7),7);		    printf(">>>>>| Game Ular Tangga |<<<<<");
            gotoxy(trunc(WDT_SCREEN/11/2+3),8);		    printf("______________________________________");
            gotoxy(trunc(WDT_SCREEN/11/2+5),10);		printf("1. Bermain Sendiri");
            gotoxy(trunc(WDT_SCREEN/11/2+5),11);		printf("2. Bermain Dengan Teman");
            gotoxy(trunc(WDT_SCREEN/11/2+5),12);		printf("3. Cara Bermain");
            gotoxy(trunc(WDT_SCREEN/11/2+5),13);		printf("4. Keluar Permainan");

            PilihanUser = Cursor(4,64,10); //User memilih menu menggunakan tombol keyboard atas atau bawah

            switch(PilihanUser) {
                case 1:
                    system("cls");
                    BermainSendiri(&map);
                    break;
                case 2:
                    system("cls");
                    BermainBersamaTeman(&map);
                    break;
                case 3:
                    system("cls");
                    CaraMain();
                    break;
                case 4:
                    system("cls");
                    exit(1);
                    break;
            //  tidak ada default karena bisa dijamin pilihan user tidak akan keluar dari pilihan yang disediakan
            }
        } while(true);
    }

//==============================================================
//             2. Mode Single Player 'Bermain Sendiri'
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
    gotoxy(trunc(WDT_SCREEN/11/2+7),7);		    printf(">>>>| Pilih Jumlah Lawan |<<<<");
	gotoxy(trunc(WDT_SCREEN/11/2+3),8);		    printf("______________________________________");
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
//         3. Mode Multi Player 'Bermain Bersama Teman'
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
//          4. Menampilkan Tatacara bermain permainan
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
