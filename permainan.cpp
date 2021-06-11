#include "header.h"

//==============================================================
//                      1. Inti Permainan
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
//            2. Modul fungsi untuk mengecek petak
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

//==============================================================
//       3. Modul menampilkan pesan jika ada yang menang
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
