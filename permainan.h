#ifndef permainan_H
#define permainan_H

// 1. Stopwatch
void stopwatch(Timestamp * timestamp);

// 2. Menampilkan stopwatch
void displayTime(Timestamp timestamp);

// 3. Multithread stopwatch dan permainan
void PermainandanStopwatch(int PemainYangBermain, int AIYangBermain);

// 4. Inti Permainan
void Permainan(int PemainYangBermain, int AIYangBermain);

// 5. Print Bidak di Koordinat x,y
void printBidak(int player, int info);

// 6. Print Hitam di Koordinat x,y
void printBidakKosong(int player, int info);

// 7. Print Bidak di kotak 1 ketika mulai permainan
void printBidakAwal( int PemainYangBermain, int AIYangBermain );

// 8. Cek Giliran Player atau Komputer
int cekGiliranPK( boolean giliranPlayer );

// 9. Cek Hasil Perpindahan Bidak
int cekHasilJalan( int hasilDadu, int kotakSebelum );

// 10. Menggerakkan Bidak jika Hasil Perpindahan Bidak < 100
address jalanKurang100 ( address P, int player, int kotakSesudah );

// 11. Menggerakkan Bidak jika Hasil Perpindahan Bidak > 100
address jalanLebih100 ( address P, int player, int kotakSesudah );

// 12. Menggerakkan Bidak jika Hasil Perpindahan Bidak = 100
address jalanSama100 ( address P, int player );

// 13. Menggerakkan Bidak sesuai Kondisi
address jalanBidak( address P, int player, int hasilJalan,
                   int jmlPlayer, int giliran, Users user1,
                   Users user2, Users user3, Users user4, char namaplayer[50]);

// 14. Cek apakah ada Ular atau Tangga di Kotak
address cekAdaUlarTangga( address P, int player );

// 15. Menampilkan Informasi Lokasi Bidak
void printLokasiPlayer (int giliran, int player, address P, char namaplayer[50]);

// 16. Mengecek apakah Bermain Kembali atau Tidak
void cekUlangGiliran ( int giliran, int dapetDadu, boolean *statusUlang,
                      int *input, int *player, int PemainYangBermain,
                      char namapemain[50], int AIYangBermain );

// 17. Menghitung skor pemain
int poinPermainan(int peringkat_ke);

// 18. Menampilkan pesan jika ada yang menang
void Pemenang(int playerAtauAI, int lambang, int jmlPemain,
              Users user1, Users user2, Users user3,
              Users user4, Timestamp * timestamp, char namaplayer[50]);

// 19. Menu untuk Keluar Paksa dari Permainan
void menuKeluar(int PemainYangBermain, int AIYangBermain, Timestamp * timestamp);




#endif // permainan_H
