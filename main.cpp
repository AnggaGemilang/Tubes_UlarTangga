#include "header.h"

int PilihanUser;
bool ulangi=true;

int main() {
	int x, y, loop;
	int width;

	ShowWindow(GetConsoleWindow(),SW_MAXIMIZE); // mengatur display agar fullscreen

	List map;

	do {
		system("color b"); // mengatur warna font
		system("MODE 120,50"); // mengatur ukuran windows

		//  mencetak sisi atas dan bawah kotak
		gotoxy(trunc(WDT_SCREEN/11/2),5);		printf("____________________________________________");
		gotoxy(trunc(WDT_SCREEN/11/2),15);		printf("____________________________________________");

		//  mencetak sisi kiri dan kanan kotak
		for(y=6;y<=15;y++){
			gotoxy(trunc(WDT_SCREEN/11/2-1),y);		    printf("|");
			gotoxy(trunc(WDT_SCREEN/11/2+44),y);		printf("|");
		}

		//  mencetak isi tulisan dalam kotak
		gotoxy(trunc(WDT_SCREEN/11/2+7),7);		    printf(">>>>>| Game Ular Tangga |<<<<<");
		gotoxy(trunc(WDT_SCREEN/11/2+3),8);		    printf("______________________________________");
		gotoxy(trunc(WDT_SCREEN/11/2+5),10);		printf("1. Bermain Sendiri");
		gotoxy(trunc(WDT_SCREEN/11/2+5),11);		printf("2. Bermain Dengan Teman");
		gotoxy(trunc(WDT_SCREEN/11/2+5),12);		printf("3. Cara Bermain");
		gotoxy(trunc(WDT_SCREEN/11/2+5),13);		printf("4. Keluar Permainan");

		PilihanUser = Cursor(4,64,10); //User memilih menu menggunakan tombol keyboard atas atau bawah

		switch(PilihanUser) {
			case 1:
				system("cls");
				BermainSendiri(&map);
				break;
			case 2:
				system("cls");
				BermainBersamaTeman(&map);
				break;
			case 3:
				system("cls");
				CaraMain();
				break;
			case 4:
				system("cls");
				exit(1);
				break;
        //  tidak ada default karena bisa dijamin pilihan user tidak akan keluar dari pilihan yang disediakan
		}
	} while(true);

	return 0;

}


