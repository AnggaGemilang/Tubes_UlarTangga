#ifndef permainan_H
#define permainan_H

//	1. Inti Permainan
void Permainan(int PemainYangBermain,int AIYangBermain);

//	2. Modul menampilkan pesan jika ada yang menang
void Pemenang(int SiapaMenang,int MenangPemain,int Jml_Pemain,int MenangAI);

//	3. Modul fungsi untuk mengecek petak
int CekAdaUlarTangga(int Petak, int Dadu);

#endif // permainan_H
