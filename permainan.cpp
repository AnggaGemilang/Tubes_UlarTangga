#include "header.h"

//==============================================================
//                      1. Inti Permainan
//==============================================================
void Permainan(int PemainYangBermain, int AIYangBermain, List * map)
{
    // Menampilkan map
    CreateList(&(*map));
	buatMap(&(*map));
    tampilkanMap(*map);
    PapanInfo();

    // Kamus data address
    address
    P = First(*map),
//    player1 = Last(*map),  //<-- buat langsung finish
//    player1 = Search(*map, 97),  //<-- buat langsung ke kotak 97
    player1 = First(*map),
    player2 = First(*map),
    player3 = First(*map),
    player4 = First(*map);

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
    input;

    // Print bidak awal player
//    printBidak(1, Info(player1));  //<-- buat langsung finish
    for( player = 1; player <= PemainYangBermain; player++ )
    {
        printBidak( player, Info(P) );
    }

    // Print bidak awal AI
    for( player = 2; player <= AIYangBermain + 1; player++ )
    {
        printBidak( player, Info(P) );
    }

    // Perulangan gameplay, akan terus diulang selama belum ada yang berhenti di kotak 100
    while ( loopPermainan == true )
    {
        // jika giliran player yang bermain
        if ( giliranPlayer == true )
        {
            // loop selama player 1 s.d 4 bermain
            for( player = 1; player <= PemainYangBermain; player++ )
            {
                //merubah berdasar player berapa yang sedang bermain
                if ( player == 1 ){ P = player1;}
                if ( player == 2 ){ P = player2;}
                if ( player == 3 ){ P = player3;}
                if ( player == 4 ){ P = player4;}

                srand(time(NULL)); // <-- Agar tiap pengulangan dan buka aplikasi dadu dalam keadaan "random"
                gotoxy(68,43);  printf("Tekan ESC untuk keluar dari permainan");
                gotoxy(67,11);  printf("                                                  ");
                gotoxy(67,11);  printf("=PLAYER %c= Tekan enter untuk mengocok dadu",player+2);
                if ( statusUlang == true ) { input = _getch(); }

                if ( input == 13 )
                {
                    statusUlang = true;
                    dapetDadu = KocokDadu();
                    kotakSesudah = Info(P) + dapetDadu;
    //                kotakSesudah = 100;  //<-- buat langsung finish
                    Sleep(800);

                    // jika bidak belum mencapai kotak 100
                    if( kotakSesudah < 100 )
                    {
                        // looping untuk animasi pergerakan bidak
                        while( Info(P) != kotakSesudah )
                        {
                            printBidakKosong( player, Info(P) );
                            printBidak( player, Info(Next(P)) );
                            P = Next(P);
                            Sleep(500);
                        }
                    }

                    // jika bidak melebihi kotak 100
                    if( kotakSesudah > 100 )
                    {
                        // penjumlahan ulang sesudah
                        kotakSesudah = 100 - (kotakSesudah - 100);

                        // looping untuk animasi pergerakan bidak
                        // bergerak sampai 100
                        while( Info(P) != 100 )
                        {
                            printBidakKosong( player, Info(P) );
                            printBidak( player, Info(Next(P)) );
                            P = Next(P);
                            Sleep(500);
                        }

                        // bergerak sampai sisa dadu yang lebih
                        while( Info(P) != kotakSesudah )
                        {
                            printBidakKosong( player, Info(P) );
                            printBidak( player, Info(Prev(P)) );
                            P = Prev(P);
                            Sleep(500);
                        }
                    }

                    // jika bidak mencapai kotak 100
                    if ( kotakSesudah == 100 )
                    {
                        // looping untuk animasi pergerakan bidak
                        while( Info(P) != 100 )
                        {
                            printBidakKosong( player, Info(P) );
                            printBidak( player, Info(Next(P)) );
                            P = Next(P);
                            Sleep(500);
                        }

                        gotoxy(80,12+player);
                        printf("PLAYER %c ada di kotak %d", player+2, Info(P) );
                        playerMenang = player;
                        player = 5;
                        giliranPlayer = 2;
                        loopPermainan = false; //<--FINISH!!
                        Pemenang(1, playerMenang, PemainYangBermain+AIYangBermain, playerMenang);
                        break;
                    }

                    // cek apakah menginjak ular atau tangga
                    P = cekAdaUlarTangga(P, player);

                    // print lokasi Player
                    gotoxy(80,12+player);
                    if ( Info(P) < 10 ) {
                        printf("PLAYER %c ada di kotak   %d", player+2, Info(P) );
                    }
                    else if ( Info(P) < 100 ) {
                        printf("PLAYER %c ada di kotak  %d", player+2, Info(P) );
                    }

                    // menyimpan alamat P kembali ke alamat tiap bidak
                    if ( player == 1 ){ player1 = P; }
                    if ( player == 2 ){ player2 = P; }
                    if ( player == 3 ){ player3 = P; }
                    if ( player == 4 ){ player4 = P; }

                    //ulang giliran jika dapet 6
                    if ( dapetDadu == 6 && statusUlang == true ) //jika mendapat dadu enam dan baru dapet dadu enam
                    {
                        gotoxy(67,20);  printf("Mendapatkan dadu 6");
                        gotoxy(67,21);  printf("PLAYER %c bermain kembali", player+2);
                        gotoxy(67,22);  printf("Tekan enter untuk mengocok dadu");
                        input = 0;
                        while ( input != 1)
                        {
                            input = _getch();
                            if ( input == 13 ) { input = 1; }
                            if ( input == 27 ) { input = 1; tekanESC();}
                        }
                        gotoxy(67,20);  printf("                              ");
                        gotoxy(67,21);  printf("                              ");
                        gotoxy(67,22);  printf("                                     ");
                        player--;
                        statusUlang = false;
                    }
                    else if ( statusUlang == false ) //dilakukan jika sudah pernah mendapat dadu 6
                    {
                        statusUlang = true;
                        gotoxy(67,20);  printf("Tekan enter untuk melanjutkan");
                        input = 0;
                        while ( input != 1)
                        {
                            input = _getch();
                            if ( input == 13 ) { input = 1; }
                            if ( input == 27 ) { input = 1; tekanESC();}
                        }
                        gotoxy(67,20);  printf("                              ");
                    }
                    else
                    {
                        gotoxy(67,20);  printf("Tekan enter untuk melanjutkan");
                        input = 0;
                        while ( input != 1)
                        {
                            input = _getch();
                            if ( input == 13 ) { input = 1; }
                            if ( input == 27 ) { input = 1; tekanESC();}
                        }
                        gotoxy(67,20);  printf("                              ");
                    }

                    //menghentikan giliran player, ganti ke giliran AI
                    if ( player == PemainYangBermain ) { giliranPlayer = false; }
                }
                else if ( input == 27 )
                {
                    tekanESC();
                }
            }
        }

        // jika giliran AI yang bermain
        if ( giliranPlayer == false )
        {
            if ( AIYangBermain == 0 ) { giliranPlayer = true; }
            else
            {
                // loop selama AI 1 s.d 4 bermain
                for( player = 2; player <= AIYangBermain + 1; player++ )
                {
                    // merubah berdasar player AI berapa yang sedang bermain
                    // dimulai dari 2 karena jika bermain dg AI, player hanya ada 1
                    if ( player == 2 ){ P = player2;}
                    if ( player == 3 ){ P = player3;}
                    if ( player == 4 ){ P = player4;}

                    srand(time(NULL)); // <-- Agar tiap pengulangan dan buka aplikasi dadu dalam keadaan "random"
                    gotoxy(67,11);  printf("                                                  ");
                    gotoxy(67,11);  printf("=KOMPUTER %c= sedang bermain",player+2);
                    dapetDadu = KocokDadu();
                    kotakSesudah = Info(P) + dapetDadu;
                    Sleep(800);

                    // jika bidak belum mencapai kotak 100
                    if( kotakSesudah < 100 )
                    {
                        // looping untuk animasi pergerakan bidak
                        while( Info(P) != kotakSesudah )
                        {
                            printBidakKosong( player, Info(P) );
                            printBidak( player, Info(Next(P)) );
                            P = Next(P);
                            Sleep(500);
                        }
                    }

                    // jika bidak melebihi kotak 100
                    if( kotakSesudah > 100 )
                    {
                        // penjumlahan ulang sesudah
                        kotakSesudah = 100 - (kotakSesudah - 100);

                        // looping untuk animasi pergerakan bidak
                        // bergerak sampai 100
                        while( Info(P) != 100 )
                        {
                            printBidakKosong( player, Info(P) );
                            printBidak( player, Info(Next(P)) );
                            P = Next(P);
                            Sleep(500);
                        }

                        // bergerak sampai sisa dadu yang lebih
                        while( Info(P) != kotakSesudah )
                        {
                            printBidakKosong( player, Info(P) );
                            printBidak( player, Info(Prev(P)) );
                            P = Prev(P);
                            Sleep(500);
                        }
                    }

                    // jika bidak mencapai kotak 100
                    if ( kotakSesudah == 100 )
                    {
                        // looping untuk animasi pergerakan bidak
                        while( Info(P) != 100 )
                        {
                            printBidakKosong( player, Info(P) );
                            printBidak( player, Info(Next(P)) );
                            P = Next(P);
                            Sleep(500);
                        }

                        gotoxy(80,12+player);
                        printf("KOMPUTER %c ada di kotak %d", player+2, Info(P) );
                        playerMenang = player;
                        player = 5;
                        giliranPlayer = 2;
                        loopPermainan = false; //<--FINISH!!
                        Pemenang(0, playerMenang, PemainYangBermain+AIYangBermain, playerMenang);
                        break;
                    }

                    // cek apakah menginjak ular atau tangga
                    P = cekAdaUlarTangga(P, player);

                    // print lokasi Komputer
                    gotoxy(80,12+player);
                    if ( Info(P) < 10) {
                        printf("KOMPUTER %c ada di kotak   %d", player+2, Info(P) );
                    }
                    else if ( Info(P) <100 ) {
                        printf("KOMPUTER %c ada di kotak  %d", player+2, Info(P) );
                    }

                    // menyimpan alamat P kembali ke alamat tiap bidak
                    if ( player == 2 ){ player2 = P; }
                    if ( player == 3 ){ player3 = P; }
                    if ( player == 4 ){ player4 = P; }

                    //ulang giliran jika dapet 6
                    if ( dapetDadu == 6 && statusUlang == true ) //jika mendapat dadu enam dan baru dapet dadu enam
                    {
                        gotoxy(67,20);  printf("Mendapatkan dadu 6");
                        gotoxy(67,21);  printf("KOMPUTER %c bermain kembali", player+2);
                        Sleep(1500);
                        gotoxy(67,20);  printf("                              ");
                        gotoxy(67,21);  printf("                              ");
                        player--;
                        statusUlang = false;
                    }
                    else if ( statusUlang == false ) //dilakukan jika sudah pernah mendapat dadu 6
                    {
                        statusUlang = true;
                    }

                    //menghentikan giliran AI, ganti ke giliran player
                    if ( player == AIYangBermain + 1) { giliranPlayer = true; }
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

    y = 42-(4*((info-1)/10));

	temp = ((info-1)/10)%2;

	if(temp == 0)
	{
    	x = 5 + ( 6 * ((info-1) % 10)  );
	}
	else if(temp == 1)
	{
		a = info%10;
		x = 5 + ( 6 * (( (info-(2*a)) % 10)  ));
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

    y = 42-(4*((info-1)/10));

	temp = ((info-1)/10)%2;

	if(temp == 0)
	{
    	x = 5 + ( 6 * ((info-1) % 10)  );
	}
	else if(temp == 1)
	{
		a = info%10;
		x = 5 + ( 6 * (( (info-(2*a) ) % 10)  ));
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
//          4. Cek apakah ada Ular atau Tangga di Kotak
//==============================================================
address cekAdaUlarTangga( address P, int player )
{
    if( Jump(P) != Nil )
    {
        Sleep(500);
        printBidakKosong( player, Info(P) );
        printBidak( player, Info(Jump(P)) );
        P = Jump(P);
        return P;
    }
    else if ( Jump(P) == Nil )
    {
        return P;
    }
}

//==============================================================
//          5. Menampilkan pesan jika ada yang menang
//==============================================================
void Pemenang(boolean SiapaMenang,int MenangPemain,int Jml_Pemain,int MenangAI)
{
    int pilihan;

    if(SiapaMenang == 0) {
        gotoxy(67,17);
        printf("Sayang Sekali");
        gotoxy(67,18);
        printf("Kamu Kalah!!");
        gotoxy(67,19);
        printf("Pemenangnya adalah AI %d",MenangAI);

    } else if(SiapaMenang == 1) {
        if(Jml_Pemain > 1) {
            gotoxy(67,17);
            printf("Selamat Player %d!!!",MenangPemain);
            gotoxy(67,18);
            printf("Kamu lah takdir sang juara!");

        } else if(Jml_Pemain == 1) {
            gotoxy(67,17);
            printf("Waaaaaahhhhhhhh");
            gotoxy(67,18);
            printf("Kamu Menang!!");
        }
    }
    gotoxy(67,20);  printf("Apakah anda ingin menutup program?");
    gotoxy(69,21);  printf("1. Ya");
    gotoxy(69,22);  printf("2. Kembali ke menu utama");
    pilihan = Cursor(2,67,21);

    if(pilihan == 2) {
        return;
    } else {
        system("cls");
        exit(1);
    }

}

void tekanESC()
{
    gotoxy(67,19);  printf("Anda telah menekan tombol ESC");
    gotoxy(67,20);  printf("Apakah anda ingin menutup program?");
    gotoxy(69,21);  printf("1. Ya");
    gotoxy(69,22);  printf("2. Kembali ke menu utama");
    int pilihan = Cursor(2,67,21);

    if(pilihan == 2) {
        menuUtama();
    } else {
        system("cls");
        exit(1);
    }
}
