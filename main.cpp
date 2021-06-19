#include "header.h"

int PilihanUser;
bool ulangi=true;

int main() {
	int x, y, loop;
	int width;

	ShowWindow(GetConsoleWindow(),SW_MAXIMIZE); // mengatur display agar fullscreen

	List map;

	do {
		system("color b");//mengatur warna font
		system("MODE 120,50");//mengatur ukuran windows

        cout << GetSystemMetrics(width);

		//mencetak sisi atas dan bawah kotak
		gotoxy(62,5);		printf("____________________________________________");
		gotoxy(62,15);		printf("____________________________________________");

		//mencetak sisi kiri dan kanan kotak
		for(y=6;y<=15;y++){
			gotoxy(61,y);		printf("|");
			gotoxy(106,y);		printf("|");
		}

		//mencetak isi tulisan dalam kotak
		gotoxy(69,7);		printf(">>>>>| Game Ular Tangga |<<<<<");
		gotoxy(65,8);		printf("______________________________________");
		gotoxy(67,10);		printf("1. Bermain Sendiri");
		gotoxy(67,11);		printf("2. Bermain Dengan Teman");
		gotoxy(67,12);		printf("3. Cara Bermain");
		gotoxy(67,13);		printf("4. Keluar Permainan");

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
			//tidak ada default karena bisa dijamin pilihan user tidak akan keluar dari pilihan yang disediakan
		}
	} while(true);

	return 0;

}


