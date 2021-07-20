#include "header.h"

Timestamp timestamp;

atomic <bool> atomicStopwatch(false);

atomic <bool> atomicPermainan(false);

int whileStopwatch;

void stopwatch(Timestamp * timestamp)
{
    while(whileStopwatch) {
        if(atomicStopwatch.load())
        {
            sleep(1);
            timestamp->detik++;
            if(timestamp->detik > 59) {
                timestamp->menit++;
                timestamp->detik = 0;
            }
            if(timestamp->menit > 59) {
                timestamp->jam++;
                timestamp->detik = 0;
                timestamp->menit = 0;
            }
            displayTime(*timestamp);
        }
    }
    printf("asdasdasd");
}

void displayTime(Timestamp timestamp)
{
    gotoxy(26, 1); cout << "                                                                         ";
    gotoxy(26, 1); cout << "Waktu Bermain : ";
    gotoxy(42, 1);
    cout << timestamp.jam << " : "
         << timestamp.menit << " : "
         << timestamp.detik << endl;
}


//==============================================================
//                      1. Inti Permainan
//==============================================================
void PermainandanStopwatch(int PemainYangBermain, int AIYangBermain, List * map)
{
    atomicPermainan = true;
    atomicStopwatch = true;
    whileStopwatch = true;
    displayTime(timestamp);
    thread t1(stopwatch, &timestamp);
    thread t2(Permainan, PemainYangBermain, AIYangBermain, map);
    t1.join();
    t2.join();
}

void Permainan(int PemainYangBermain, int AIYangBermain, List * map)
{
    // Menampilkan map
    CreateList(&(*map));
	buatMap(&(*map));
    tampilkanMap(*map);
    PapanInfo();

    // KAMUS DATA
    // Kamus data address
    address
    P = First(*map),
    // player1 = Last(*map),  //<-- buat langsung finish
    player1 = Search(*map, 98),  //<-- buat langsung ke kotak 97
    // player1 = First(*map),
    player2 = First(*map),
    player3 = First(*map),
    player4 = First(*map);

    // HESE MERE NGARAN ASLII, CEMUNGUDHH QQ *) Stiker teteh korea WKWKWK

    // Kamus data boolean
    boolean
    loopPermainan = true,
    giliranPlayer = true,
    statusUlang = true;

    // Kamus data integer
    int player,
    kotakSesudah,
    playerMenang,
    dapetDadu,
    input,
    giliran,
    hasilJalan;

    // INTI PERMAINAN
    // Print bidak awal player dan AI
    printBidakAwal( PemainYangBermain, AIYangBermain );

    // Perulangan gameplay, akan terus diulang selama belum ada yang berhenti di kotak 100
    while ( loopPermainan == true )
    {
        if(atomicPermainan.load())
        {
            // cek giliran player atau AI
            giliran = cekGiliranPK(giliranPlayer);

            // jika giliran player yang bermain
            if ( giliran == 1 )
            {
                // loop selama player 1 s.d 4 bermain
                for( player = 1; player <= PemainYangBermain; player++ )
                {
                    if(atomicPermainan.load())
                    {
                        //merubah berdasar player berapa yang sedang bermain
                        if ( player == 1 ){ P = player1;}
                        else if ( player == 2 ){ P = player2;}
                        else if ( player == 3 ){ P = player3;}
                        else if ( player == 4 ){ P = player4;}

                        srand(time(NULL)); // <-- Agar tiap pengulangan dan buka aplikasi dadu dalam keadaan "random"
                        gotoxy(91,10);  printf("                                                 ");
                        gotoxy(91,10);  printf("=PLAYER %c= Tekan enter untuk mengocok dadu", player+2);

                        // cek apakah perlu menekan enter atau tidak untuk mengocok dadu
                        // jika sebelumnya mendapat dadu 6 dan bermain kembali, maka player tidak perlu menekan enter
                        if(statusUlang == true )
                            input = _getch();

                        if ( input == 13 )
                        {
                            Beep(700, 40);

                            // kocok dadu
                            dapetDadu = KocokDadu();

                            // dapetDadu = 2; // <-- Atur Sendiri angka dadu

                            // pergerakan bidak
                            hasilJalan = cekHasilJalan(dapetDadu, Info(P) );
                            P = jalanBidak( P, player, hasilJalan, PemainYangBermain+AIYangBermain, giliran );

                            // print keterangan lokasi Player
                            printLokasiPlayer(giliran, player, P);

                            // menyimpan alamat P kembali ke alamat tiap bidak
                            if ( player == 1 ){ player1 = P; }
                            else if ( player == 2 ){ player2 = P; }
                            else if ( player == 3 ){ player3 = P; }
                            else if ( player == 4 ){ player4 = P; }

                            // cek apakah bermain kembali
                            cekUlangGiliran( giliran, dapetDadu, &statusUlang, &input, &player, PemainYangBermain, AIYangBermain, map );

                            //menghentikan giliran player, ganti ke giliran AI
                            if ( player == PemainYangBermain ) { giliranPlayer = false; }
                        }

                        // jika menekan ESC
                        else if ( input == 27 )
                        {
                            Beep(700, 40);
                            atomicStopwatch = false;
                            menuKeluar(PemainYangBermain, AIYangBermain, map, &timestamp);
                        }

                        // jika menekan tombol lain maka akan terjadi loop
                        else
                            player--;

                    }
                }
            }

            // jika giliran AI yang bermain
            else if ( giliran == 0 )
            {
                if ( AIYangBermain == 0 )
                {
                    giliranPlayer = true;
                }
                else
                {
                    // loop selama AI 2 s.d 4 bermain
                    for( player = 2; player <= AIYangBermain + 1; player++ )
                    {

                        if(atomicPermainan.load())
                        {
                            // merubah berdasar player AI berapa yang sedang bermain
                            // dimulai dari 2 karena jika bermain dg AI, player hanya ada 1
                            if ( player == 2 ){ P = player2;}
                            else if ( player == 3 ){ P = player3;}
                            else if ( player == 4 ){ P = player4;}

                            srand(time(NULL)); // <-- Agar tiap pengulangan dan buka aplikasi dadu dalam keadaan "random"
                            gotoxy(91,10);  printf("                                                 ");
                            gotoxy(91,10);  printf("=KOMPUTER %c= sedang bermain",player+2);

                            // kocok dadu
                            dapetDadu = KocokDadu();

                            // pergerakan bidak
                            hasilJalan = cekHasilJalan(dapetDadu, Info(P) );
                            P = jalanBidak( P, player, hasilJalan, PemainYangBermain+AIYangBermain, giliran );

                            // print keterangan lokasi Komputer
                            printLokasiPlayer(giliran, player, P);

                            // menyimpan alamat P kembali ke alamat tiap bidak
                            if ( player == 2 ){ player2 = P; }
                            else if ( player == 3 ){ player3 = P; }
                            else if ( player == 4 ){ player4 = P; }

                            // cek apakah bermain kembali
                            cekUlangGiliran( giliran, dapetDadu, &statusUlang, &input, &player, PemainYangBermain, AIYangBermain, map );

                            //menghentikan giliran AI, ganti ke giliran player
                            if ( player == AIYangBermain + 1) { giliranPlayer = true; }
                        }
                    }
                }
            }
        }
    }
}

//==============================================================
//                2. Print Bidak di Koordinat x,y
//==============================================================
void printBidak(int player, int info)
{
    int temp, x, y, a;

    y = 41-(4*((info-1)/10));

	temp = ((info-1)/10)%2;

	if(temp == 0)
	{
    	x = 27 + ( 6 * ((info-1) % 10)  );
	}
	else if(temp == 1)
	{
		a = info % 10;
		x = 27 + ( 6 * (( (info-(2*a)) % 10)  ));
	}

    if(player == 1){
        gotoxy(x, y);
        printf("%c", player+2);
    }
    if(player == 2){
        gotoxy(x+1, y);
        printf("%c", player+2);
    }
    if(player == 3){
        gotoxy(x, y+1);
        printf("%c", player+2);
    }
    if(player == 4){
        gotoxy(x+1, y+1);
        printf("%c", player+2);
    }

}

//==============================================================
//                3. Print Hitam di Koordinat x,y
//==============================================================
void printBidakKosong(int player, int info)
{
    int temp, x, y, a;

    y = 41-(4*((info-1)/10));

	temp = ((info-1)/10)%2;

	if(temp == 0)
	{
    	x = 27 + ( 6 * ((info-1) % 10)  );
	}
	else if(temp == 1)
	{
		a = info%10;
		x = 27 + ( 6 * (( (info-(2*a) ) % 10)  ));
	}

    if(player == 1){
        gotoxy(x, y);
        printf(" ");
    }
    if(player == 2){
        gotoxy(x+1, y);
        printf(" ");
    }
    if(player == 3){
        gotoxy(x, y+1);
        printf(" ");
    }
    if(player == 4){
        gotoxy(x+1, y+1);
        printf(" ");
    }

}

//==============================================================
//      4. Print Bidak di kotak 1 ketika mulai permainan
//==============================================================
void printBidakAwal( int PemainYangBermain, int AIYangBermain )
{
    int player;

    // Print bidak awal player
    //    printBidak(1, Info(player1));  //<-- buat langsung finish
    for( player = 1; player <= PemainYangBermain; player++ )
    {
        printBidak( player, 1 );
    }

    // Print bidak awal AI
    for( player = 2; player <= AIYangBermain + 1; player++ )
    {
        printBidak( player, 1 );
    }
}

//==============================================================
//          5. Cek Giliran Player atau Komputer
//==============================================================
int cekGiliranPK( boolean giliranPlayer )
{
    if ( giliranPlayer == true )
        return 1;
    else
        return 0;
}

//==============================================================
//                6. Cek Hasil Perpindahan Bidak
//==============================================================
int cekHasilJalan( int hasilDadu, int kotakSebelum )
{
    int hasil;

    hasil = hasilDadu + kotakSebelum;

    return hasil;
}

//==============================================================
//   7. Menggerakkan Bidak jika Hasil Perpindahan Bidak < 100
//==============================================================
address jalanKurang100 ( address P, int player, int kotakSesudah )
{
    // looping untuk animasi pergerakan bidak
    while( Info(P) != kotakSesudah )
    {
        printBidakKosong( player, Info(P) );
        printBidak( player, Info(Next(P)) );
        P = Next(P);
        Sleep(500);
    }
    return P;
}

//==============================================================
//   8. Menggerakkan Bidak jika Hasil Perpindahan Bidak > 100
//==============================================================
address jalanLebih100 ( address P, int player, int kotakSesudah )
{
    // penjumlahan ulang sesudah
    kotakSesudah = 100 - (kotakSesudah - 100);

    // looping untuk animasi pergerakan bidak
    // bergerak sampai 100
    P = jalanSama100(P, player);

    // bergerak sampai sisa dadu yang lebih
    while( Info(P) != kotakSesudah )
    {
        printBidakKosong( player, Info(P) );
        printBidak( player, Info(Prev(P)) );
        P = Prev(P);
        Sleep(500);
    }

    return P;
}

//==============================================================
//   9. Menggerakkan Bidak jika Hasil Perpindahan Bidak = 100
//==============================================================
address jalanSama100 ( address P, int player )
{
    while( Info(P) != 100 )
    {
        printBidakKosong( player, Info(P) );
        printBidak( player, Info(Next(P)) );
        P = Next(P);
        Sleep(500);
    }

    return P;
}

//==============================================================
//          10. Menggerakkan Bidak sesuai Kondisi
//==============================================================
address jalanBidak( address P, int player, int hasilJalan, int jmlPlayer, int giliran )
{
    if( hasilJalan < 100 )
    {
        P = jalanKurang100(P, player, hasilJalan);
        P = cekAdaUlarTangga(P, player);
    }

    if( hasilJalan > 100 )
    {
        P = jalanLebih100(P, player, hasilJalan );
        P = cekAdaUlarTangga(P, player);
    }

    if( hasilJalan == 100 )
    {
        P = jalanSama100(P, player);
        Pemenang(giliran, player, jmlPlayer);
    }

    return P;
}

//==============================================================
//          11. Cek apakah ada Ular atau Tangga di Kotak
//==============================================================
address cekAdaUlarTangga( address P, int player )
{
    if( Jump(P) != Nil )
    {
        Sleep(500);
        printBidakKosong( player, Info(P) );
        printBidak( player, Info(Jump(P)) );
        if(Info(P) < Info(Jump(P)))
        {
            Beep(700, 75);
            Beep(750, 100);
            Beep(800, 400);
        } else
        {
            Beep(800, 300);
            Beep(700, 300);
            Beep(600, 300);
            Beep(400, 700);
        }
        P = Jump(P);
        return P;
    }
    return P;
}

//==============================================================
//          12. Menampilkan Informasi Lokasi Bidak
//==============================================================
void printLokasiPlayer (int giliran, int player, address P)
{
    gotoxy(104,12+player);
    if ( Info(P) < 10 ) {
        if( giliran == 1 )
            printf("PLAYER %c ada di kotak   %d", player+2, Info(P) );
        else
            printf("KOMPUTER %c ada di kotak   %d", player+2, Info(P) );
    }
    else if ( Info(P) < 100 ) {
        if( giliran == 1 )
            printf("PLAYER %c ada di kotak  %d", player+2, Info(P) );
        else
            printf("KOMPUTER %c ada di kotak  %d", player+2, Info(P) );
    }
}

//==============================================================
//        13. Mengecek apakah Bermain Kembali atau Tidak
//==============================================================
void cekUlangGiliran ( int giliran, int dapetDadu, boolean *statusUlang, int *input, int *player, int PemainYangBermain, int AIYangBermain, List * map )
{
    //ulang giliran jika dapet 6
    if ( dapetDadu == 6 && *statusUlang == true ) //jika mendapat dadu enam dan baru dapet dadu enam
    {
        gotoxy(91,20);  printf("Mendapatkan dadu 6 (1x)");
        if( giliran == 1 )
        {
            gotoxy(91,21);  printf("PLAYER %c bermain kembali", *player+2);
            gotoxy(91,22);  printf("Tekan enter untuk mengocok dadu");
            *input = 0;
            while ( *input != 1)
            {
                *input = _getch();
                if ( *input == 13 )
                {
                    *input = 1;
                } else if ( *input == 27 )
                {
                    Beep(700, 40);
                    atomicStopwatch = false;
                    menuKeluar(PemainYangBermain, AIYangBermain, map, &timestamp);
                }
            }
        }
        else
        {
            gotoxy(91,21);  printf("KOMPUTER %c bermain kembali", *player+2);
            Sleep(1500);
            *input = 0;
        }

        gotoxy(90,20);  printf("                              ");
        gotoxy(90,21);  printf("                              ");
        gotoxy(90,22);  printf("                                     ");
        *player -= 1;
        *statusUlang = false;
        *input = 13;
    }
    else if ( dapetDadu == 6 && *statusUlang == false ) //dilakukan jika sudah pernah mendapat dadu 6
    {
        gotoxy(91,20);  printf("Mendapatkan dadu 6 (2x)");
        gotoxy(91,21);
        if( giliran == 1 )
            printf("PLAYER %c tidak bermain kembali", player+2);
        else
            printf("KOMPUTER %c tidak bermain kembali", player+2);
        gotoxy(91,20);  printf("                             ");
        *statusUlang = true;
    }
    else
    {
        gotoxy(91,20);
        printf("Tekan enter untuk melanjutkan");
        *input = 0;
        while ( *input != 1)
        {
            *input = _getch();
            if ( *input == 13 )
            {
                Beep(700, 40);
                *input = 1;

            } else if ( *input == 27 )
            {
                Beep(700, 40);
                *input = 1;
                atomicStopwatch = false;
                menuKeluar(PemainYangBermain, AIYangBermain, map, &timestamp);
            }
        }
        gotoxy(90,20);  printf("                              ");
        *statusUlang = true;
    }
}

//==============================================================
//          14. Menampilkan pesan jika ada yang menang
//==============================================================
void Pemenang(int playerAtauAI,int pemenang,int jmlPemain)
{
    int pilihan;

    atomicStopwatch = false;

    if(playerAtauAI == 0) {
        gotoxy(80,12+pemenang);
        printf("KOMPUTER %c ada di kotak 100", pemenang+2);
        gotoxy(67,17);
        printf("Sayang Sekali");
        gotoxy(67,18);
        printf("Kamu Kalah!!");
        gotoxy(67,19);
        printf("Pemenangnya adalah AI %c",pemenang+2);
    } else if(playerAtauAI == 1) {
        gotoxy(103,12+pemenang);
        printf("PLAYER %c ada di kotak 100", pemenang+2);
        if(jmlPemain > 1) {
            gotoxy(91,18);
            printf("Selamat Player %c!!!",pemenang+2);
            gotoxy(91,19);
            printf("Kamu lah takdir sang juara!");
            gotoxy(91,20);
        } else if(jmlPemain == 1) {
            gotoxy(91,18);
            printf("Waaaaaahhhhhhhh");
            gotoxy(91,19);
            printf("Kamu Menang!!");
        }
    }
    gotoxy(91,20);  printf("                                   ");
    gotoxy(91,21);  printf("                                   ");
    gotoxy(91,22);  printf("                                   ");
    gotoxy(91,20);  printf("Permainan Berjalan Selama : %d : %d : %d", timestamp.jam, timestamp.menit, timestamp.detik+1);
    gotoxy(91,22);  printf("Apakah anda ingin menutup Program?");
    gotoxy(94,23);  printf("1. Ya");
    gotoxy(94,24);  printf("2. Kembali Ke Menu");
    pilihan = Cursor(2,91,23);

    if(pilihan == 2) {
        menuUtama();
    } else {
        gotoxy(94, 25); printf("Terima Kasih Telah Bermain..^^\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        exit(1);
    }

}

//==============================================================
//          15. Menu untuk Keluar Paksa dari Permainan
//==============================================================
void menuKeluar(int PemainYangBermain, int AIYangBermain, List * map, Timestamp * timestamp)
{
    gotoxy(91,19);  printf("                                   ");
    gotoxy(91,20);  printf("                                   ");
    gotoxy(91,21);  printf("                                   ");
    gotoxy(91,22);  printf("                                   ");
    gotoxy(91,23);  printf("                                   ");
    gotoxy(91,19);  printf("Anda telah menekan tombol ESC");
    gotoxy(94,20);  printf("1. Lanjutkan Permainan");
    gotoxy(94,21);  printf("2. Ulangi Permainan");
    gotoxy(94,22);  printf("3. Kembali ke Menu Utama");
    gotoxy(94,23);  printf("4. Keluar Aplikasi");
    int pilihan = Cursor(4,91,20);
    if(pilihan == 1) {
        atomicStopwatch = true;
        gotoxy(91,19);  printf("                               ");
        gotoxy(91,20);  printf("                               ");
        gotoxy(91,21);  printf("                               ");
        gotoxy(91,22);  printf("                               ");
        gotoxy(91,23);  printf("                               ");
        return;
    } else if (pilihan == 2) {
        gotoxy(26, 1); cout << "                                                                         ";
        atomicStopwatch = false;
        atomicPermainan = false;
        whileStopwatch = false;
        timestamp->detik = 0;
        timestamp->menit = 0;
        timestamp->jam = 0;
        PermainandanStopwatch(PemainYangBermain, AIYangBermain, map);
    } else if (pilihan == 3)
    {
        atomicStopwatch = false;
        atomicPermainan = false;
        whileStopwatch = false;
        timestamp->detik = 0;
        timestamp->menit = 0;
        timestamp->jam = 0;
        menuUtama();
    } else
    {
        atomicStopwatch = false;
        gotoxy(94, 25); printf("Terima Kasih Telah Bermain..^^\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        exit(1);
    }
}
