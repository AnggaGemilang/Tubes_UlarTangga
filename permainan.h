#ifndef permainan_H
#define permainan_H

// 1. Inti Permainan
void PermainandanStopwatch(int PemainYangBermain, int AIYangBermain);

// 1. Inti Permainan
void Permainan(int PemainYangBermain, int AIYangBermain);

// 2. Print Bidak di Koordinat x,y
void printBidak(int player, int info);

// 3. Print Hitam di Koordinat x,y
void printBidakKosong(int player, int info);

// 4. Print Bidak di kotak 1 ketika mulai permainan
void printBidakAwal( int PemainYangBermain, int AIYangBermain );

// 5. Cek Giliran Player atau Komputer
int cekGiliranPK( boolean giliranPlayer );

// 6. Cek Hasil Perpindahan Bidak
int cekHasilJalan( int hasilDadu, int kotakSebelum );

// 7. Menggerakkan Bidak jika Hasil Perpindahan Bidak < 100
address jalanKurang100 ( address P, int player, int kotakSesudah );

// 8. Menggerakkan Bidak jika Hasil Perpindahan Bidak > 100
address jalanLebih100 ( address P, int player, int kotakSesudah );

// 9. Menggerakkan Bidak jika Hasil Perpindahan Bidak = 100
address jalanSama100 ( address P, int player );

// 10. Menggerakkan Bidak sesuai Kondisi
address jalanBidak( address P, int player, int hasilJalan, int jmlPlayer, int giliran );

// 11. Cek apakah ada Ular atau Tangga di Kotak
address cekAdaUlarTangga( address P, int player );

// 12. Menampilkan Informasi Lokasi Bidak
void printLokasiPlayer (int giliran, int player, address P);

// 13. Mengecek apakah Bermain Kembali atau Tidak
void cekUlangGiliran ( int giliran, int dapetDadu, boolean *statusUlang, int *input, int *player, int PemainYangBermain, int AIYangBermain);

// 14. Menampilkan pesan jika ada yang menang
void Pemenang(int playerAtauAI,int pemenang,int jmlPemain);

// 15. Menu untuk Keluar Paksa dari Permainan
void menuKeluar(int PemainYangBermain, int AIYangBermain, Timestamp * timestamp);

void stopwatch(Timestamp * timestamp);

void displayTime(Timestamp timestamp);

#endif // permainan_H
