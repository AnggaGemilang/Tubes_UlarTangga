#ifndef permainan_H
#define permainan_H

//data komposit untuk rute pemain dan komputer
struct {
    int Rute;
} Pemain[4],AI[4];

//data komposit untuk koordinat tiap pemain atau komputer pada tiap petak papan
struct {
    struct  {
        int x;
        int y;
    } SiPemain[4], SiAI[4];
} PapanPermainan[100];

//	1. Inti Permainan
void Permainan(int PemainYangBermain, int AIYangBermain, List * map);

//	2. Modul menampilkan pesan jika ada yang menang
void Pemenang(int SiapaMenang, int MenangPemain, int Jml_Pemain,int MenangAI);

//	3. Modul fungsi untuk mengecek petak
int CekAdaUlarTangga(int Petak, int Dadu);

#endif // permainan_H
