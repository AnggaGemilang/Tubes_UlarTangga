#ifndef maps_H
#define maps_H

#include <stdio.h>
#include <windows.h>
#include <math.h>
#include <conio.h>
//#include "maps.h"
#include <stdbool.h>
#include <time.h>

/*PROTOTIPE FUNGSI*/

/*VARIABEL GLOBAL*/
//COORD coord= {0,0}; //Variabel global GoToXY


//	1. Modul GoToXY
void gotoxy(int x,int y);

//	2. Modul ganti warna
void setcolor (unsigned short color);

//	3. Modul fugsi untuk menggerakkan cursor
int Cursor(int BanyakPilihan,int x,int y);

//	4. Menampilkan menu utama permainan
void MenuUtama();

//	5. Mode Single Player 'Bermain Sendiri'
void BermainSendiri();

//	6. Mode Multi Player 'Bermain Bersama Teman'
void BermainBersamaTeman();

//	7. Menampilkan Tatacara bermain permainan
void CaraMain();

//	8. Inti Permainan
void Permainan(int PemainYangBermain,int AIYangBermain);

//	9. Modul menampilkan box header untuk judul permainan
void PapanInfo();

//	10. Modul membuat papan permainan buta (tanpa simbol ular ataupun tangga)
void PapanButa();

//	11. Modul untuk meletakkan simbol ular dan tangga
void SimbolUlarDanTangga();

//	12. Modul untuk menampilkan papan ermainan secara utuh (Ada hiasan Header
//		judul permainan, dan ada simbol ular dan tangga)
void PapanGame();

//	13. Modul fungsi untuk mengocok dadu
int KocokDadu();

//	14. Modul menampilkan pesan jika ada yang menang
void Pemenang(int SiapaMenang,int MenangPemain,int Jml_Pemain,int MenangAI);

//	15. Modul fungsi untuk mengecek petak
int CekAdaUlarTangga(int Petak, int Dadu);


#endif
