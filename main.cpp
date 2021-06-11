#include "maps.h"

int PilihanUser;
bool ulangi=true;

int main() {
	int x, y, loop;

	do {
		system("color b");//mengatur warna font
		system("MODE 120,50");//mengatur ukuran windows

		gotoxy(39,5);		printf("_____________________________________________");
		gotoxy(40,15);		printf("____________________________________________");

		for(y=6;y<=15;y++){
			gotoxy(39,y);		printf("|");
			gotoxy(83,y);		printf("|");
		}

		gotoxy(47,7);		printf(">>>>>| Game Ular Tangga |<<<<<<");
		gotoxy(43,8);		printf("______________________________________");
		gotoxy(45,10);		printf("1. Bermain Sendiri");
		gotoxy(45,11);		printf("2. Bermain Dengan Teman");
		gotoxy(45,12);		printf("3. Cara Bermain");
		gotoxy(45,13);		printf("4. Keluar Permainan");

		PilihanUser=Cursor(4,42,10); //User memilih menu menggunakan tombol keyboard atas atau bawah

		switch(PilihanUser) {
			case 1:
				system("cls");
				BermainSendiri();
				break;
			case 2:
				system("cls");
				BermainBersamaTeman();
				break;
			case 3:
				system("cls");
				CaraMain();
				break;
			case 4:
				system("cls");
				exit(1);
				break;
			//tidak ada default karena bisa dijamin pilihan user tidak akan keluar dari pilihan yang disediakan
		}
		_getch();

	} while(1);

	return 0;

}


