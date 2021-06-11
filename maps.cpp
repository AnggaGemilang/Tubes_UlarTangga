#include "maps.h"
int pilihan;
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
//==============================================================
//             5. Mode Single Player 'Bermain Sendiri'
//==============================================================
void BermainSendiri() {
    int JumlahAI;

    gotoxy(39,5);
    printf("_____________________________________________");
    gotoxy(39,6);
    printf("|");
    gotoxy(39,7);
    printf("|");
    gotoxy(39,8);
    printf("|");
    gotoxy(39,9);
    printf("|");
    gotoxy(39,10);
    printf("|");
    gotoxy(39,11);
    printf("|");
    gotoxy(39,12);
    printf("|");
    gotoxy(39,13);
    printf("|");
    gotoxy(39,14);
    printf("|");
    gotoxy(40,15);
    printf("___________________________________________");
    gotoxy(39,15);
    printf("|");

    gotoxy(83,6);
    printf("|");
    gotoxy(83,7);
    printf("|");
    gotoxy(83,8);
    printf("|");
    gotoxy(83,9);
    printf("|");
    gotoxy(83,10);
    printf("|");
    gotoxy(83,11);
    printf("|");
    gotoxy(83,12);
    printf("|");
    gotoxy(83,13);
    printf("|");
    gotoxy(83,14);
    printf("|");
    gotoxy(83,15);
    printf("|");
    gotoxy(53,7);
    printf("Pilih Jumlah Lawan");
    gotoxy(48,8);
    printf("____________________________");
    gotoxy(45,10);
    printf("1. VS 1 KOMPUTER");
    gotoxy(45,11);
    printf("2. VS 2 KOMPUTER");
    gotoxy(45,12);
    printf("3. VS 3 KOMPUTER");
    gotoxy(45,13);
    printf("4. Kembali");

    pilihan=Cursor(4,42,10); //User memilih menu menggunakan tombol keyboard atas atau bawah

    switch(pilihan) {
    case 4:
//        system("cls");
//				main();
        return;
        break;
    }

    //Pemilihan jumlah pemain komputer dilakukan dengan menggunakan tombol atas atau bawah keyboard
    JumlahAI=Cursor(3,42,10);
    system("cls");

    //Jumlah pemain dan jumlah pemain komputer "dilempar" ke modul yang bernama "Permainan"
    Permainan(1,JumlahAI);
}

//==============================================================
//         6. Mode Multi Player 'Bermain Bersama Teman'
//==============================================================
void BermainBersamaTeman() {
    int JumlahPemain;

    gotoxy(39,5);
    printf("_____________________________________________");
    gotoxy(39,6);
    printf("|");
    gotoxy(39,7);
    printf("|");
    gotoxy(39,8);
    printf("|");
    gotoxy(39,9);
    printf("|");
    gotoxy(39,10);
    printf("|");
    gotoxy(39,11);
    printf("|");
    gotoxy(39,12);
    printf("|");
    gotoxy(39,13);
    printf("|");
    gotoxy(39,14);
    printf("|");
    gotoxy(40,15);
    printf("___________________________________________");
    gotoxy(39,15);
    printf("|");

    gotoxy(83,6);
    printf("|");
    gotoxy(83,7);
    printf("|");
    gotoxy(83,8);
    printf("|");
    gotoxy(83,9);
    printf("|");
    gotoxy(83,10);
    printf("|");
    gotoxy(83,11);
    printf("|");
    gotoxy(83,12);
    printf("|");
    gotoxy(83,13);
    printf("|");
    gotoxy(83,14);
    printf("|");
    gotoxy(83,15);
    printf("|");
    gotoxy(53,8);
    printf("Pilih Jumlah Pemain:");
    gotoxy(47,9);
    printf("_______________________________");
    gotoxy(45,11);
    printf("1. 2 Pemain");
    gotoxy(45,12);
    printf("2. 3 Pemain");
    gotoxy(45,13);
    printf("3. 4 Pemain");
    gotoxy(45,14);
    printf("4. Kembali");

    pilihan=Cursor(4,42,11); //User memilih menu menggunakan tombol keyboard atas atau bawah

    switch(pilihan) {
    case 4:
//        system("cls");
//				main();
        return;
        break;
    }


    //Pelilihan jumlah pemain yang dilawan dilakukan dengan menggunakan tombol atas atau bawah keyboard
    JumlahPemain=Cursor(3,42,11)+1;
    system("cls");

    //Jumlah pemain dan jumlah pemain komputer "dilempar" ke modul yang bernama "Permainan"
    Permainan(JumlahPemain,0);
}

//==============================================================
//          7. Menampilkan Tatacara bermain permainan
//==============================================================
void CaraMain() {
    FILE *MembukaFile;
    char Kalimat;

    if((MembukaFile=fopen("assets\\file\\HowTo.txt","r")) != NULL) {
        while((Kalimat=getc(MembukaFile)) != EOF) {
            putch(Kalimat);
        }
    } else {
        printf("Tidak Muncul");
    }

    fclose(MembukaFile);
}

//==============================================================
//                      8. Inti Permainan
//==============================================================
void Permainan(int PemainYangBermain,int AIYangBermain) {
    PapanGame();
    int i,j,k,l,m,n,o,p,q,

        DapetDadu,
        GiliranPemain=PemainYangBermain,
        GiliranAI=AIYangBermain,

        Status=1,
        StatusSelesai=0,
        StatusUlang=0,
        AngkaPetak,
        Sebelum,
        Sesudah,
        SebelumAI=0,
        SesudahAI=0;

    //data komposit untuk rute pemain dan komputer
    struct	{
        int Rute;
    }	Pemain[4],AI[4];

    //data komposit untuk koordinat tiap pemain atau komputer pada tiap petak papan
    struct  {
        struct  {
            int x;
            int y;
        } SiPemain[4],SiAI[4];
    } PapanPermainan[100];

    //mengisi tiap petak papan dengan koordinat tiap pemain atau komputer
    for (n=0; n<4; n++) {
        for (l=0; l<10; l++) {
            for (m=0; m<10; m++) {
                //((l+1)/2)*20+((l+1)%2)+(pow(-1,((l+1)-1))*((m+1)-1))
                //rumus ini ditemukan ketika tugas "ANGKA MENGULAR" dari dosen Kognitif Komputasi
                //Thanks to Pak Dosen Dewa Gede Parta
                AngkaPetak=((l+1)/2)*20+((l+1)%2)+(pow(-1,((l+1)-1))*((m+1)-1));
                PapanPermainan[AngkaPetak-1].SiPemain[n].x=(5+(n%2))+(6*m);
                PapanPermainan[AngkaPetak-1].SiPemain[n].y=(42+(floor(n/2)))-(4*l);
                PapanPermainan[AngkaPetak-1].SiAI[n].x=(5+(n%2))+(6*m);
                PapanPermainan[AngkaPetak-1].SiAI[n].y=(42+(floor(n/2)))-(4*l);
            }
        }
    }

    //inisialisasi awal icon tiap pemain, dari mulai hati,wajik,keriting, dan sekop
    //namun penginisialisasian ini tergantung banyaknya pemain yang memainkan permainan
    //berurut dari pemain pertama sampai pemain ke-4: hati, diamond, keriting, sekop.
    for (o=0; o<GiliranPemain; o++) {
        gotoxy(PapanPermainan[0].SiPemain[o].x,PapanPermainan[0].SiPemain[o].y);
        printf("%c",o+3);
    }

    //inisialisasi awal icon untuk komputer
    //komputer tidak akan mendapatkan icon hati, karena secara default icon hati hanya untuk pemain pertama
    //jadi komputer pertama sampai dengan komputer terakhir hanya mendapatkan icon wajik, keriting, dan sekop
    for (p=0; p<GiliranAI; p++) {
        gotoxy(PapanPermainan[0].SiAI[p+1].x,PapanPermainan[0].SiAI[p+1].y);
        printf("%c",p+4);
    }

    //Inisialisasi rute tiap pemain dan komputer
    for (k=0; k<=3; k++) {
        Pemain[k].Rute=0;
        AI[k].Rute=0;
    }

    //JRENG! JRENG! disinilah "inti" dari permainan yang kami buat
    //Karena pengulangan "do...while" ini dilakukan hingga ada pemain atau komputer yang berhasi mengubah
    //variabel "StatusFinish" menjadi 1 (TRUE, dalam artian mencapai kotak terakhir)
    do {
        //Variabel "Status" ini dijadikan "switch" agar pemain manusian dan pemain komputer bisa
        //bergantian untuk "bermain"

        if(Status==1) { //Status diisi 1 menandakan giliran pemain
            for(i=0; i<GiliranPemain; i++) {
                srand(time(NULL)); // <-- Agar tiap pengulangan dan buka aplikasi dadu dalam keadaan "random"
                gotoxy(67,11);
                printf("                                                  ");
                gotoxy(67,11);
                printf("=PEMAIN %c=,tekan enter untuk mengocok dadu",i+3);
                _getch();
                Sebelum=Pemain[i].Rute;
                DapetDadu=KocokDadu();
                Pemain[i].Rute= Pemain[i].Rute + DapetDadu;
                if (Pemain[i].Rute==99) {
                    Sesudah=Pemain[i].Rute;
                    gotoxy(PapanPermainan[Sebelum].SiPemain[i].x,PapanPermainan[Sebelum].SiPemain[i].y);
                    printf(" ");
                    gotoxy(PapanPermainan[Sesudah].SiPemain[i].x,PapanPermainan[Sesudah].SiPemain[i].y);
                    printf("%c",i+3);
                    gotoxy(80,12+i);
                    printf("PEMAIN %c ada di kotak %d",i+3,Sesudah+1);
                    StatusSelesai=1; //<--FINISH!!
                    Pemenang(Status,i+1,PemainYangBermain+AIYangBermain,j);
                    break;
                } else if (Pemain[i].Rute>99) {
                    //dikurang dulu, misal dapat angka dadu 6 ketika di kotak 99, maka pemain/komputer
                    //akan ada di kotak  94
                    //dibawah ini dimulai dari 99, dikarenakan array di C dimulai dari angka nol.
                    Pemain[i].Rute=99-((Pemain[i].Rute)-99);
                    Sesudah=Pemain[i].Rute;

                    //masih terdapat "bugs" disini.
                    for (q=Sebelum; q<Sesudah; q++) {
                        gotoxy(PapanPermainan[q].SiPemain[i].x,PapanPermainan[q].SiPemain[i].y);
                        printf(" ");
                        gotoxy(PapanPermainan[q+1].SiPemain[i].x,PapanPermainan[q+1].SiPemain[i].y);
                        printf("%c",i+3);
                        Sleep(500);
                    }
                    Pemain[i].Rute= CekAdaUlarTangga(Pemain[i].Rute,DapetDadu);
                    gotoxy(PapanPermainan[Sesudah].SiPemain[i].x,PapanPermainan[Sesudah].SiPemain[i].y);
                    printf(" ");
                    gotoxy(PapanPermainan[Pemain[i].Rute].SiPemain[i].x,PapanPermainan[Pemain[i].Rute].SiPemain[i].y);
                    printf("%c",i+3);
                } else if (Pemain[i].Rute<99) {
                    Sesudah=Pemain[i].Rute;
                    //variabel bernama "sebelum" dan "sesudah" berguna untuk animasi gerak tiap bidak pemain/komputer
                    //yang digunakan oleh pengulangan dibawah ini
                    for (q=Sebelum; q<Sesudah; q++) {
                        gotoxy(PapanPermainan[q].SiPemain[i].x,PapanPermainan[q].SiPemain[i].y);
                        printf(" ");
                        gotoxy(PapanPermainan[q+1].SiPemain[i].x,PapanPermainan[q+1].SiPemain[i].y);
                        printf("%c",i+3);
                        Sleep(500);
                    }
                    //cek apakah menginjak ular atau tangga
                    Pemain[i].Rute= CekAdaUlarTangga(Pemain[i].Rute,DapetDadu);
                    gotoxy(PapanPermainan[Sesudah].SiPemain[i].x,PapanPermainan[Sesudah].SiPemain[i].y);
                    printf(" ");
                    gotoxy(PapanPermainan[Pemain[i].Rute].SiPemain[i].x,PapanPermainan[Pemain[i].Rute].SiPemain[i].y);
                    printf("%c",i+3);
                }
                gotoxy(80,12+i);
                if (Pemain[i].Rute <= 9) {
                    printf("PEMAIN %c ada di kotak  %d",i+3,Pemain[i].Rute+1);
                } else if (Pemain[i].Rute==10) {
                    printf("PEMAIN %c ada di kotak %d",i+3,Pemain[i].Rute+1);
                } else {
                    printf("PEMAIN %c ada di kotak %d",i+3,Pemain[i].Rute+1);
                }
                gotoxy(80,16);
                printf("                              ");
                gotoxy(67,20);
                printf("tekan enter untuk melanjutkan");
                _getch();
                gotoxy(67,20);
                printf("                              ");
                Sebelum=0;
                Sesudah=0;

                //ulang giliran jika dapet 6
                if (DapetDadu==6 && StatusUlang==0) { //jika mendapat dadu enam dan baru dapet dadu enam
                    i--;
                    StatusUlang=1;

                } else if (StatusUlang==1) { //dilakukan jika statement if diatas false (dapet dadu gak 6 atau status ulang udah satu)
                    StatusUlang=0;
                }
            }
            if ((i=GiliranPemain) && (AIYangBermain !=0 )) {
                Status=0;
            }
        } else if(Status==0) { //Giliran komputer
            //srand(time(0000));
            for(j=0; j<GiliranAI; j++) {
                srand(time(NULL));
                gotoxy(67,11);
                printf("                                                  ");
                gotoxy(67,11);
                printf("=KOMPUTER %c= sedang bermain",j+4);
                SebelumAI=AI[j].Rute;
                DapetDadu=KocokDadu();
                AI[j].Rute = AI[j].Rute + DapetDadu;
                //AI[j].Rute = cekulartangga(AI[j].Rute);
                if (AI[j].Rute==99) {
                    SesudahAI=AI[j].Rute;
                    gotoxy(PapanPermainan[SebelumAI].SiAI[j+1].x,PapanPermainan[SebelumAI].SiAI[j+1].y);
                    printf(" ");
                    gotoxy(PapanPermainan[SesudahAI].SiAI[j+1].x,PapanPermainan[SebelumAI].SiAI[j+1].y);
                    printf("%c",j+4);
                    gotoxy(80,13+j);
                    printf("KOMPUTER %c ada di posisi %d",j+4,SesudahAI+1);
                    StatusSelesai=1;
                    Pemenang(Status,i+1,PemainYangBermain+AIYangBermain,j);
                    break;
                } else if (AI[j].Rute>99) {
                    AI[j].Rute=99-((AI[j].Rute)-99);
                    SesudahAI=AI[j].Rute;
                    for (q=SebelumAI; q<SesudahAI; q++) {
                        gotoxy(PapanPermainan[q].SiAI[j+1].x,PapanPermainan[q].SiAI[j+1].y);
                        printf(" ");
                        gotoxy(PapanPermainan[q+1].SiAI[j+1].x,PapanPermainan[q+1].SiAI[j+1].y);
                        printf("%c",j+4);
                        Sleep(500);
                    }
                    AI[j].Rute = CekAdaUlarTangga(AI[j].Rute,DapetDadu);
                    gotoxy(PapanPermainan[SesudahAI].SiAI[j+1].x,PapanPermainan[q].SiAI[j+1].y);
                    printf(" ");
                    gotoxy(PapanPermainan[AI[j].Rute].SiAI[j+1].x,PapanPermainan[AI[j].Rute].SiAI[j+1].y);
                    printf("%c",j+4);
                } else if (AI[j].Rute<99) {
                    SesudahAI=AI[j].Rute;
                    for (q=SebelumAI; q<SesudahAI; q++) {
                        gotoxy(PapanPermainan[q].SiAI[j+1].x,PapanPermainan[q].SiAI[j+1].y);
                        printf(" ");
                        gotoxy(PapanPermainan[q+1].SiAI[j+1].x,PapanPermainan[q+1].SiAI[j+1].y);
                        printf("%c",j+4);
                        Sleep(500);
                    }
                    AI[j].Rute = CekAdaUlarTangga(AI[j].Rute,DapetDadu);
                    gotoxy(PapanPermainan[SesudahAI].SiAI[j+1].x,PapanPermainan[q].SiAI[j+1].y);
                    printf(" ");
                    gotoxy(PapanPermainan[AI[j].Rute].SiAI[j+1].x,PapanPermainan[AI[j].Rute].SiAI[j+1].y);
                    printf("%c",j+4);
                }
                gotoxy(80,13+j);
                if (AI[j].Rute <= 9) {
                    printf("KOMPUTER %c ada di posisi  %d",j+4,AI[j].Rute+1);
                } else if (AI[j].Rute==10) {
                    printf("KOMPUTER %c ada di posisi %d",j+4,AI[j].Rute+1);
                } else {
                    printf("KOMPUTER %c ada di posisi %d",j+4,AI[j].Rute+1);
                }
                Sleep(1500);
                SebelumAI=0;
                SesudahAI=0;
                //ulang giliran jika dapet 6
                if (DapetDadu==6 && StatusUlang==0) { //jika mendapat dadu enam dan baru dapet dadu enam
                    j--;
                    StatusUlang=1;
                } else if (StatusUlang==1) { //dilakukan jika statement if diatas false (dapet dadu gak 6 atau status ulang udah satu)
                    StatusUlang=0;
                }
            }
            if ((j=GiliranAI)) {
                Status=1;
            }
        }
    } while(StatusSelesai != 1);
}

//==============================================================
//     9. Modul menampilkan box header untuk judul permainan
//==============================================================
void PapanInfo() {

    int x,y,i,j;

    //Box Pertama
    gotoxy(x=66,y=4);
    printf("ษออออออออออออออออออออออออออออออออออออออออออออออออออป");
    for (i=0; i<3; i++) {
        gotoxy(x=66,y=5+i);
        printf("บ                                                  บ");
    }
    gotoxy(x=66,y=5+i);
    printf("ศออออออออออออออออออออออออออออออออออออออออออออออออออผ");
    gotoxy(x=70,y=(1+i));
    printf("บUlar Tanggaบ");
    gotoxy(x=83,y=(3+i));
    printf("Menuju 100!");

    //Box kedua
    gotoxy(x=66,y=7+i);
    printf("ษออออออออออออออออออออออออออออออออออออออออออออออออออป");
    for (j=0; j<(43-(7+i)); j++) {
        gotoxy(x=66,y=(8+i)+j);
        printf("บ                                                  บ");
    }
    gotoxy(x=66,y=((8+i)+j));
    printf("ศออออออออออออออออออออออออออออออออออออออออออออออออออผ");
    gotoxy(x=68,y=(8  + i + (j-7)));
    printf("Legend:");
    gotoxy(x=68,y=(9  + i + (j-6)));
    printf("ฎ : Kepala Ular");
    gotoxy(x=68,y=(10 + i + (j-5)));
    printf("ฏ : Ekor Ular");
    gotoxy(x=68,y=(11 + i + (j-4)));
    printf("Û : Tangga");
}

//==============================================================
//	10. Modul membuat papan permainan buta (tanpa simbol ular
//                          ataupun tangga)
//==============================================================
void PapanButa() {
    int x,y,i,j,nomor;
//    board vertikal
    for (i=0; i<=10; i++) {
        for (j=0; j<39; j++) {
            gotoxy(x=4+(6*i),y=5+j);
            printf("บ");
        }
    }

//    board horizontal
	for (i=0; i<11; i++) {
		for (j=0; j<10; j++) {	gotoxy(x=4+(6*j),y=4+(4*i));	printf("ฮอออออฮ");	}
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
//      11. Modul untuk meletakkan simbol ular dan tangga
//==============================================================
void SimbolUlarDanTangga() {
    int x,y;
    //Posisi Ular (Ekor)
    gotoxy(x=45,y=41);
    setcolor(8);
    printf("ฏ");
    setcolor(7);
    gotoxy(x=15,y=37);
    setcolor(9);
    printf("ฏ");
    setcolor(7);
    gotoxy(x=27,y=33);
    setcolor(10);
    printf("ฏ");
    setcolor(7);
    gotoxy(x=45,y=29);
    setcolor(11);
    printf("ฏ");
    setcolor(7);
    gotoxy(x=9,y=21);
    setcolor(12);
    printf("ฏ");
    setcolor(7);
    gotoxy(x=51,y=13);
    setcolor(13);
    printf("ฏ");
    setcolor(7);
    gotoxy(x=39,y=13);
    setcolor(14);
    printf("ฏ");
    setcolor(7);
    gotoxy(x=21,y=13);
    setcolor(15);
    printf("ฏ");
    setcolor(7);


    //Posisi Ular ( Kepala)
    gotoxy(x=27,y=37);
    setcolor(8);
    printf("ฎ");
    setcolor(7);
    gotoxy(x=15,y=17);
    setcolor(9);
    printf("ฎ");
    setcolor(7);
    gotoxy(x=45,y=9);
    setcolor(10);
    printf("ฎ");
    setcolor(7);
    gotoxy(x=45,y=21);
    setcolor(11);
    printf("ฎ");
    setcolor(7);
    gotoxy(x=27,y=17);
    setcolor(12);
    printf("ฎ");
    setcolor(7);
    gotoxy(x=51,y=5);
    setcolor(13);
    printf("ฎ");
    setcolor(7);
    gotoxy(x=39,y=5);
    setcolor(14);
    printf("ฎ");
    setcolor(7);
    gotoxy(x=15,y=5);
    setcolor(15);
    printf("ฎ");
    setcolor(7);

    //Posisi Tangga (Awal Naik)
    gotoxy(x=27,y=41);
    setcolor(8);
    printf("Û");
    setcolor(7);
    gotoxy(x=57,y=41);
    setcolor(9);
    printf("Û");
    setcolor(7);
    gotoxy(x=9,y=37);
    setcolor(10);
    printf("Û");
    setcolor(7);
    gotoxy(x=51,y=33);
    setcolor(11);
    printf("Û");
    setcolor(7);
    gotoxy(x=9,y=29);
    setcolor(12);
    printf("Û");
    setcolor(7);
    gotoxy(x=63,y=21);
    setcolor(13);
    printf("Û");
    setcolor(7);
    gotoxy(x=21,y=17);
    setcolor(14);
    printf("Û");
    setcolor(7);
    gotoxy(x=63,y=13);
    setcolor(15);
    printf("Û");
    setcolor(7);

    //Posisi Tangga (Akhir Naik)
    gotoxy(x=45,y=37);
    setcolor(8);
    printf("Û");
    setcolor(7);
    gotoxy(x=63,y=29);
    setcolor(9);
    printf("Û");
    setcolor(7);
    gotoxy(x=21,y=29);
    setcolor(10);
    printf("Û");
    setcolor(7);
    gotoxy(x=27,y=9);
    setcolor(11);
    printf("Û");
    setcolor(7);
    gotoxy(x=15,y=21);
    setcolor(12);
    printf("Û");
    setcolor(7);
    gotoxy(x=45,y=17);
    setcolor(13);
    printf("Û");
    setcolor(7);
    gotoxy(x=9,y=9);
    setcolor(14);
    printf("Û");
    setcolor(7);
    gotoxy(x=63,y=5);
    setcolor(15);
    printf("Û");
    setcolor(7);

}

//==============================================================
//  12. Modul untuk menampilkan papan ermainan secara utuh (Ada
// hiasan Header judul permainan, dan ada simbol ular dan tangga)
//==============================================================
void PapanGame() {
    PapanInfo();
    PapanButa();
    SimbolUlarDanTangga();
}

//==============================================================
//             13. Modul fungsi untuk mengocok dadu
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
//       14. Modul menampilkan pesan jika ada yang menang
//==============================================================
void Pemenang(int SiapaMenang,int MenangPemain,int Jml_Pemain,int MenangAI) {
    int kembali;

    if(SiapaMenang == 0) {
        gotoxy(67,17);
        printf("Sayang Sekali~");
        gotoxy(67,18);
        printf("Kamu Kalah!!");
        gotoxy(67,19);
        printf("Pemenangnya adalah CPU %d",MenangAI);

    } else if(SiapaMenang == 1) {
        if(Jml_Pemain > 1) {
            gotoxy(67,17);
            printf("Selamat Pemain %d!!!",MenangPemain);
            gotoxy(67,18);
            printf("Kamu lah takdir sang juara!");

        } else if(Jml_Pemain == 1) {
            gotoxy(67,17);
            printf("Waaaaaahhhhhhhh");
            gotoxy(67,18);
            printf("Kamu Menang!! Sugoi!");
        }
    }
    gotoxy(67,20);
    printf("Kembali ke menu utama?");
    gotoxy(67,21);
    printf("1. Ya | 2. Exit : ");
    gotoxy(67,22);
    scanf("%d",&kembali);

    if(kembali == 1) {
//			main();
        return;
    } else {
        system("exit");
    }

}

//==============================================================
//            15. Modul fungsi untuk mengecek petak
//==============================================================
int CekAdaUlarTangga(int Petak, int Dadu) {
    int StatusNaik,StatusTurun;


    //nginjek tangga
    if (Petak==3,8,19,27,39,50,62,70) {
        //Pengecekan apakah yang main Pemain manusia atau Pemain komputer
        StatusNaik=1;
        //yang main adalah Pemain Manusia
//		if (status==1) {
//			srand(time(NULL));
//
//		//yang main adalah Pemain komputer
//		} else if (status==0) {
//			srand(time(NULL));
//		}

        if (StatusNaik==1) {
//			StatusNaik=1;
            switch(Petak) {
            case 3:
                Petak=13;
                break;
            case 8:
                Petak=30;
                break;
            case 19:
                Petak=37;
                break;
            case 27:
                Petak=83;
                break;
            case 39:
                Petak=58;
                break;
            case 50:
                Petak=66;
                break;
            case 62:
                Petak=80;
                break;
            case 70:
                Petak=90;
                break;
            }
        }
    }

    //nginjek ular
    if (Petak==98,94,92,86,63,61,53,16) {
        StatusTurun=1;

        if (StatusTurun==1) {
            switch(Petak) {
            case 98:
                Petak=77;
                break;
            case 94:
                Petak=74;
                break;
            case 92:
                Petak=72;
                break;
            case 86:
                Petak=23;
                break;
            case 63:
                Petak=59;
                break;
            case 61:
                Petak=18;
                break;
            case 53:
                Petak=33;
                break;
            case 16:
                Petak=6;
                break;
            }
        }
    }


    if(Dadu==6) {
        gotoxy(67,18);
        printf("Berhasil mendapat dadu nomor 6");
        gotoxy(67,19);
        printf("pemain bermain bermain kembali");
        Sleep(1000);
        gotoxy(67,18);
        printf("                                                  ");
        gotoxy(67,19);
        printf("                                                  ");
    } else if(Dadu!=6) {
        gotoxy(67,18);
        printf("Mendapat dadu nomor %d", Dadu);
        Sleep(1000);
        gotoxy(67,18);
        printf("                                                  ");
    }

    gotoxy(67,20);
    printf("Pindah ke kotak %d",Petak+1);
    Sleep(1000);
    gotoxy(67,19);
    printf("                                                  ");
    gotoxy(67,20);
    printf("                                                  ");
    return Petak;
}



