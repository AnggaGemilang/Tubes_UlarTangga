#ifndef permainan_H
#define permainan_H

// 1. Inti Permainan
void Permainan(int PemainYangBermain, int AIYangBermain, List * map);

// 2. Print Bidak di Koordinat x,y
void printBidak(int player, int info);

// 3. Print Hitam di Koordinat x,y
void printBidakKosong(int player, int info);

// 4. Cek apakah ada Ular atau Tangga di Kotak
void Pemenang(boolean SiapaMenang,int MenangPemain,int Jml_Pemain,int MenangAI);

// 5. Menampilkan pesan jika ada yang menang
address cekAdaUlarTangga( address P, int player );

void tekanESC();

#endif // permainan_H
