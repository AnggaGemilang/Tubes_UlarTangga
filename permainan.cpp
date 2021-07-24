#include "header.h"

// variabel global
Timestamp timestamp;

atomic <bool> atomicStopwatch(false);

atomic <bool> atomicPermainan(false);

int whileStopwatch;

//==============================================================
//                          1. Stopwatch
//==============================================================
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
}

//==============================================================
//                    2. Menampilkan stopwatch
//==============================================================
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
//            3. Multithread stopwatch dan permainan
//==============================================================
void PermainandanStopwatch(int PemainYangBermain, int AIYangBermain)
{
    atomicPermainan = true;
    atomicStopwatch = true;
    whileStopwatch = true;
    displayTime(timestamp);
    thread t1(stopwatch, &timestamp);
    thread t2(Permainan, PemainYangBermain, AIYangBermain);
    t1.join();
    t2.join();
}

//==============================================================
//                      4. Inti Permainan
//==============================================================
void Permainan(int PemainYangBermain, int AIYangBermain)
{
    // Menampilkan map
    List map;
    CreateList(&map);
	buatMap(&map);
    tampilkanMap(map);
    PapanInfo();

    // KAMUS DATA

    // Kamus data address
    address
    P = First(map);

    // Kamus data Users
    Users user, user1, user2, user3, user4;

    user1.player = First(map);//<-- pengisian address tiap bidak di kotak pertama
    user2.player = First(map);
    user3.player = First(map);
    user4.player = First(map);

//    user1.player = Last(map);  //<-- buat langsung finish
//    user1.player = Search(map, 98);  //<-- buat langsung ke kotak 98

    FILE * fptr; //<-- pengisian id (urutan bermain player) dan username
    fptr = fopen("assets/file/users-baru.dat","rb");
    while(fread(&user, sizeof(user), 1, fptr)){
        if(user.id == 1){
            strcpy(user1.username, user.username);//<-- pengisian dilakukan dengan copas dari file
            user1.id = 1;
        }
        if(user.id == 2){
            strcpy(user2.username, user.username);
            user2.id = 2;
        }
        if(user.id == 3){
            strcpy(user3.username, user.username);
            user3.id = 3;
        }
        if(user.id == 4){
            strcpy(user4.username, user.username);
            user4.id = 4;
        }
    }
    fclose(fptr);

    // Kamus data string
    char namaplayer[50];

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
                        if ( player == 1 ){ P = user1.player; strcpy(namaplayer, user1.username);}
                        else if ( player == 2 ){ P = user2.player; strcpy(namaplayer, user2.username);}
                        else if ( player == 3 ){ P = user3.player; strcpy(namaplayer, user3.username);}
                        else if ( player == 4 ){ P = user4.player; strcpy(namaplayer, user4.username);}

                        srand(time(NULL)); // <-- Agar tiap pengulangan dan buka aplikasi dadu dalam keadaan "random"
                        gotoxy(91,10);  printf("                                                 ");
                        gotoxy(91,10);  printf("%s %c Tekan enter untuk mengocok dadu",namaplayer, player+2);

                        // cek apakah perlu menekan enter atau tidak untuk mengocok dadu
                        // jika sebelumnya mendapat dadu 6 dan bermain kembali, maka player tidak perlu menekan enter
                        if(statusUlang == true )
                            input = _getch();

                        if ( input == 13 )
                        {
                            Beep(700, 40);

                            // kocok dadu
                            dapetDadu = KocokDadu();

//                            dapetDadu = 2; // <-- Atur Sendiri angka dadu
//                            gotoxy(91,12);
//                            printf("+---------+\n");
//                            gotoxy(91,13);
//                            printf("|(-)      |\n");
//                            gotoxy(91,14);
//                            printf("|         |\n");
//                            gotoxy(91,15);
//                            printf("|      (-)|\n");
//                            gotoxy(91,16);
//                            printf("+---------+\n");

                            // pergerakan bidak
                            hasilJalan = cekHasilJalan(dapetDadu, Info(P) );

                            P = jalanBidak( P, player, hasilJalan, PemainYangBermain+AIYangBermain, giliran, user1, user2, user3, user4, namaplayer );

                            // print keterangan lokasi Player
                            printLokasiPlayer(giliran, player, P, namaplayer);

                            // menyimpan alamat P kembali ke alamat tiap bidak
                            if ( player == 1 ){ user1.player = P; }
                            else if ( player == 2 ){ user2.player = P; }
                            else if ( player == 3 ){ user3.player = P; }
                            else if ( player == 4 ){ user4.player = P; }

                            // cek apakah bermain kembali
                            cekUlangGiliran( giliran, dapetDadu, &statusUlang, &input, &player, PemainYangBermain, namaplayer, AIYangBermain);

                            //menghentikan giliran player, ganti ke giliran AI
                            if ( player == PemainYangBermain ) { giliranPlayer = false; }
                        }

                        // jika menekan ESC
                        else if ( input == 27 )
                        {
                            Beep(700, 40);
                            atomicStopwatch = false;
                            menuKeluar(PemainYangBermain, AIYangBermain, &timestamp);
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
                    strcpy(user2.username, "KOMPUTER 1");
                    strcpy(user3.username, "KOMPUTER 2");
                    strcpy(user4.username, "KOMPUTER 3");
                    // loop selama AI 2 s.d 4 bermain
                    for( player = 2; player <= AIYangBermain + 1; player++ )
                    {

                        if(atomicPermainan.load())
                        {
                            // merubah berdasar player AI berapa yang sedang bermain
                            // dimulai dari 2 karena jika bermain dg AI, player hanya ada 1
                            if ( player == 2 ){ P = user2.player; strcpy(namaplayer, user2.username);}
                            else if ( player == 3 ){ P = user3.player; strcpy(namaplayer, user3.username);}
                            else if ( player == 4 ){ P = user4.player; strcpy(namaplayer, user4.username);}

                            srand(time(NULL)); // <-- Agar tiap pengulangan dan buka aplikasi dadu dalam keadaan "random"
                            gotoxy(91,10);  printf("                                                 ");
                            gotoxy(91,10);  printf("%s %c sedang bermain", namaplayer, player+2);

                            // kocok dadu
                            dapetDadu = KocokDadu();
                            // dapetDadu = 2; // <-- Custom dadu

                            // pergerakan bidak
                            hasilJalan = cekHasilJalan(dapetDadu, Info(P) );
                            P = jalanBidak( P, player, hasilJalan, PemainYangBermain+AIYangBermain, giliran, user1, user2, user3, user4, namaplayer );

                            // print keterangan lokasi Komputer
                            printLokasiPlayer(giliran, player, P, namaplayer);

                            // menyimpan alamat P kembali ke alamat tiap bidak
                            if ( player == 2 ){ user2.player = P; }
                            else if ( player == 3 ){ user3.player = P; }
                            else if ( player == 4 ){ user4.player = P; }

                            // cek apakah bermain kembali
                            cekUlangGiliran( giliran, dapetDadu, &statusUlang, &input, &player, PemainYangBermain, namaplayer, AIYangBermain );

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
//                5. Print Bidak di Koordinat x,y
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
//                6. Print Hitam di Koordinat x,y
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
//       7. Print Bidak di kotak 1 ketika mulai permainan
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
//             8. Cek Giliran Player atau Komputer
//==============================================================
int cekGiliranPK( boolean giliranPlayer )
{
    if ( giliranPlayer == true )
        return 1;
    else
        return 0;
}

//==============================================================
//                9. Cek Hasil Perpindahan Bidak
//==============================================================
int cekHasilJalan( int hasilDadu, int kotakSebelum )
{
    int hasil;

    hasil = hasilDadu + kotakSebelum;

    return hasil;
}

//==============================================================
//   10. Menggerakkan Bidak jika Hasil Perpindahan Bidak < 100
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
//   11. Menggerakkan Bidak jika Hasil Perpindahan Bidak > 100
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
//   12. Menggerakkan Bidak jika Hasil Perpindahan Bidak = 100
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
//            13. Menggerakkan Bidak sesuai Kondisi
//==============================================================
address jalanBidak( address P, int player, int hasilJalan,
                   int jmlPlayer, int giliran, Users user1,
                   Users user2, Users user3, Users user4, char namaplayer[50])
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
        Pemenang(giliran, player, jmlPlayer, user1, user2, user3, user4, &timestamp, namaplayer);
    }

    return P;
}

//==============================================================
//          14. Cek apakah ada Ular atau Tangga di Kotak
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
            Beep(600, 75);
            Beep(700, 120);
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
//          15. Menampilkan Informasi Lokasi Bidak
//==============================================================
void printLokasiPlayer (int giliran, int player, address P, char namaplayer[50])
{
    gotoxy(104,12+player);
    if ( Info(P) < 10 ) {
        printf("%s %c ada di kotak   %d", namaplayer, player+2, Info(P) );
    }
    else if ( Info(P) < 100 ) {
        printf("%s %c ada di kotak  %d", namaplayer, player+2, Info(P) );
    }
}

//==============================================================
//        16. Mengecek apakah Bermain Kembali atau Tidak
//==============================================================
void cekUlangGiliran ( int giliran, int dapetDadu, boolean *statusUlang,
                      int *input, int *player, int PemainYangBermain,
                      char namaplayer[50], int AIYangBermain )
{
    //ulang giliran jika dapet 6
    if ( dapetDadu == 6 && *statusUlang == true ) //jika mendapat dadu enam dan baru dapet dadu enam
    {
        gotoxy(91,20);  printf("Mendapatkan dadu 6 (1x)");
        if( giliran == 1 )
        {
            gotoxy(91,21);  printf("%s %c bermain kembali", namaplayer, *player+2);
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
                    menuKeluar(PemainYangBermain, AIYangBermain, &timestamp);
                    *input = 1;
                }
            }
        }
        else
        {
            gotoxy(91,21);  printf("%s %c bermain kembali", namaplayer, *player+2);
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
        {
            printf("%s %c tidak bermain kembali", namaplayer, player+2);
            _getch();
        }
        else
        {
            printf("%s %c tidak bermain kembali", namaplayer, player+2);
            Sleep(1500);
        }
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
                menuKeluar(PemainYangBermain, AIYangBermain, &timestamp);
            }
        }
        gotoxy(90,20);  printf("                              ");
        *statusUlang = true;
    }
}

//==============================================================
//                    17. Menghitung skor pemain
//==============================================================
int poinPermainan(int peringkat_ke)
{
    switch(peringkat_ke)
    {
        case 1 :
        {
            return 5000;
            break;
        }
        case 2 :
        {
            return 4000;
            break;
        }
        case 3 :
        {
            return 3000;
            break;
        }
        case 4 :
        {
            return 2000;
            break;
        }
    }
//    return 0;
}

//==============================================================
//          18. Menampilkan pesan jika ada yang menang
//==============================================================
void Pemenang(int playerAtauAI, int lambang, int jmlPemain,
              Users user1, Users user2, Users user3,
              Users user4, Timestamp * timestamp, char namaplayer[50])
{
    int pilihan, i, j, counter;

    Users user;

    FILE *fptr, *tempF;

    Users arrPlayer[4] = {user1, user2, user3, user4},temp;

    atomicStopwatch = false;

    // jika yang menang AI
    if(playerAtauAI == 0)
    {
        gotoxy(104,12+lambang);
        printf("%s %c ada di kotak 100", namaplayer, lambang+2);
        gotoxy(91,17);
        printf("Sayang Sekali");
        gotoxy(91,18);
        printf("Kamu Kalah!!");
        gotoxy(91,19);
        printf("Pemenangnya adalah %s %c", namaplayer, lambang+2);
    }

    // jika yang menang player
    else if(playerAtauAI == 1)
    {
        gotoxy(104,12+lambang);
        printf("%s %c ada di kotak 100", namaplayer, lambang+2);

        // jika bermain bersama teman
        if(jmlPemain > 1)
        {
            gotoxy(91,18);
            printf("Selamat %s %c!!!", namaplayer, lambang+2);
            gotoxy(91,19);
            printf("Kamu lah takdir sang juara!");
        }

        // jika bermain sendiri
        else if(jmlPemain == 1)
        {
            gotoxy(91,18);
            printf("Waaaaaahhhhhhhh");
            gotoxy(91,19);
            printf("Kamu Menang!!");
        }
    }
    gotoxy(91,20);  printf("                                   ");
    gotoxy(91,21);  printf("                                   ");
    gotoxy(91,22);  printf("                                   ");
    gotoxy(91,21);  printf("Permainan Berjalan Selama : %d : %d : %d", timestamp->jam, timestamp->menit, timestamp->detik+1);

    // mengurutkan pemenang berdasar kotak paling jauh
    for(i=0; i<jmlPemain; i++)
    {
        for(j=i+1; j<jmlPemain; j++)
        {
            if(Info(arrPlayer[j].player) > Info(arrPlayer[i].player))
            {
                temp = arrPlayer[i];
                arrPlayer[i] = arrPlayer[j];
                arrPlayer[j] = temp;
            }
        }
    }

    // file untuk menyimpan data user sementara
    tempF = fopen("assets/file/users-kosong.dat","wb+");

    // menampilkan peringkat pemenang
    gotoxy(91,23);  printf("Peringkat Akhir");
    counter = 24;
    int counterBaris = 0;

    for(i=0; i<jmlPemain; i++)
    {
        // menampilkan peringkat pemenang
        gotoxy(91,counter++);
        cout << ++counterBaris << ". " << arrPlayer[i].username << endl;

        // membuka file tempat username baru (users-baru.dat)
        if((fptr = fopen("assets/file/users-baru.dat","rb+")) == NULL){
            printf("Error! File Tidak Dapat Dibuka...");
            exit(1);
        } else {

            // membaca file tempat username baru (users-baru.dat)
            while(fread(&user, sizeof(Users), 1, fptr)==1)
            {

                // memindahkan data user ke file sementara
                if(user.id == arrPlayer[i].id )
                {
                    user.id = user.id;
                    strcpy(user.username, user.username);
                    user.score = user.score + poinPermainan(counterBaris);
                    fseek(fptr, (long) -sizeof(user), SEEK_CUR);
                    fwrite(&user, sizeof(user), 1, tempF);
                    break;
                } else
                {
                    continue;
                }
            }
        }
    }
    fclose(fptr);
    fclose(tempF);

    // memindahkan data user dari file sementara ke file utama (users.dat)
    tempF = fopen("assets/file/users-Kosong.dat","rb");
    while(fread(&user, sizeof(Users), 1, tempF)){
        storeNamaFile(user);
    }
    fclose(tempF);

    // menampilkan pilihan
    gotoxy(91,counter+1);  printf("Apakah anda ingin menutup Program?");
    gotoxy(94,counter+2);  printf("1. Ya");
    gotoxy(94,counter+3);  printf("2. Kembali Ke Menu");

    pilihan = Cursor(2,91,counter+2);

    // untuk menghentikan stopwatch dan menampilkan pesan
    if(pilihan == 2) {
        atomicStopwatch = false;
        whileStopwatch = false;
        timestamp->detik = 0;
        timestamp->menit = 0;
        timestamp->jam = 0;
        menuUtama();
    } else {
        atomicStopwatch = false;
        atomicPermainan = false;
        whileStopwatch = false;
        timestamp->detik = 0;
        timestamp->menit = 0;
        timestamp->jam = 0;
        gotoxy(94, counter+5); printf("Terima Kasih Telah Bermain..^^\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        exit(1);
    }
}

//==============================================================
//          19. Menu untuk Keluar Paksa dari Permainan
//==============================================================
void menuKeluar(int PemainYangBermain, int AIYangBermain, Timestamp * timestamp)
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
        PermainandanStopwatch(PemainYangBermain, AIYangBermain)    ;
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
