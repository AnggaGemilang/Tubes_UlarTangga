#include "header.h"

int pilihan;

//==============================================================
//                  1. Menu utama program
//==============================================================
void menuUtama()
{
    int PilihanUser;
    bool ulangi=true;
    char pilihanUser;
	int x, y, loop;
	int width;

//    List map;

    mainMenu:

  	setcolor(WHITE);

    do {

        system("cls");

        title('n');

        //  mencetak sisi atas dan bawah kotak
        for(x=trunc(WDT_SCREEN/11/2);x<=106;x++){
            gotoxy(x,25);   printf("\xc4");
            gotoxy(x,36);   printf("\xc4");
        }

		gotoxy(106,36); printf("\xd9");
        gotoxy(106,25);  printf("\xbf");
        gotoxy(61,25);   printf("\xda");
        gotoxy(61,36);  printf("\xc0");

        //  mencetak sisi kiri dan kanan kotak
        for(y=26;y<=35;y++){
            gotoxy(trunc(WDT_SCREEN/11/2-1),y);	    printf("\xb3");
            gotoxy(trunc(WDT_SCREEN/11/2+44),y);	printf("\xb3");
        }

        //  mencetak isi tulisan dalam kotak
        gotoxy(trunc(WDT_SCREEN/11/2+7),27);		printf(">>>>>| Game Ular Tangga |<<<<<");
        gotoxy(trunc(WDT_SCREEN/11/2+3),28);		printf("______________________________________");
        gotoxy(trunc(WDT_SCREEN/11/2+5),30);		printf("1. Bermain Sendiri");
        gotoxy(trunc(WDT_SCREEN/11/2+5),31);		printf("2. Bermain Dengan Teman");
        gotoxy(trunc(WDT_SCREEN/11/2+5),32);		printf("3. Leaderboard");
        gotoxy(trunc(WDT_SCREEN/11/2+5),33);		printf("4. Cara Bermain");
        gotoxy(trunc(WDT_SCREEN/11/2+5),34);		printf("5. Keluar Permainan");

        PilihanUser = Cursor(5,64,30); //User memilih menu menggunakan tombol keyboard atas atau bawah

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
                Sort_file();
                leaderboard();
                break;
            case 4:
                system("cls");
                CaraMain();
                break;
            case 5:
                gotoxy(61,36); printf("\xc0");
                for(int i=61; i < 106; i++)
                {
                    gotoxy(i,40); printf("\xc4");
                }
                gotoxy(106,40); printf("\xd9");
                for(int i=39; i > 35; i--)
                {
                    gotoxy(106,i); printf("\xb3");
                }
                gotoxy(61,40); printf("\xc0");
                for(int i=39; i > 35; i--)
                {
                    gotoxy(61,i); printf("\xb3");
                }
                gotoxy(70,38); printf("Apakah Anda Yakin [Y/N]? "); pilihanUser = _getch();
                if(pilihanUser=='y' || pilihanUser=='Y')
                {
                    Beep(700, 40);
                    printf("\n\n\n");
                    exit(0);
                } else if(pilihanUser=='n' || pilihanUser=='N'){
                    Beep(700, 40);
                    system("cls");
                    goto mainMenu;
                }
                break;
            //  tidak ada default karena bisa dijamin pilihan user tidak akan keluar dari pilihan yang disediakan
        }
    } while(true);
}

//==============================================================
//             2. Mode Single Player 'Bermain Sendiri'
//==============================================================
void BermainSendiri() {
    int JumlahAI, x, y;

    title('n');

    //  mencetak sisi atas dan bawah kotak
    for(x=trunc(WDT_SCREEN/11/2);x<=106;x++){
        gotoxy(x,25);   printf("\xc4");
        gotoxy(x,35);   printf("\xc4");
    }

    gotoxy(106,35); printf("\xd9");
    gotoxy(61,35);  printf("\xc0");
    gotoxy(106,25);  printf("\xbf");
    gotoxy(61,25);   printf("\xda");

    //  mencetak sisi kiri dan kanan kotak
    for(y=26;y<=34;y++){
        gotoxy(trunc(WDT_SCREEN/11/2-1),y);	    printf("\xb3");
        gotoxy(trunc(WDT_SCREEN/11/2+44),y);	printf("\xb3");
    }

	//mencetak isi tulisan dalam kotak
    gotoxy(trunc(WDT_SCREEN/11/2+7),27);	    printf(">>>>| Pilih Jumlah Lawan |<<<<");
	gotoxy(trunc(WDT_SCREEN/11/2+3),28);	    printf("______________________________________");
	gotoxy(trunc(WDT_SCREEN/11/2+5),30);		printf("1. VS 1 KOMPUTER");
	gotoxy(trunc(WDT_SCREEN/11/2+5),31);		printf("2. VS 2 KOMPUTER");
	gotoxy(trunc(WDT_SCREEN/11/2+5),32);		printf("3. VS 3 KOMPUTER");
	gotoxy(trunc(WDT_SCREEN/11/2+5),33);		printf("4. Kembali");

    pilihan = Cursor(4,64,30); //User memilih menu menggunakan tombol keyboard atas atau bawah

    switch(pilihan) {
    case 1 :
    case 2 :
    case 3 :

        //Pemilihan jumlah pemain komputer dilakukan dengan menggunakan tombol atas atau bawah keyboard
        JumlahAI = pilihan;
        inputNama(1);
        system("cls");

        //Jumlah pemain dan jumlah pemain komputer "dilempar" ke modul yang bernama "Permainan"
        PermainandanStopwatch(1, JumlahAI);
        break;
    case 4:
        return;
        break;
    }
}

//==============================================================
//         3. Mode Multi Player 'Bermain Bersama Teman'
//==============================================================
void BermainBersamaTeman() {
    int JumlahPemain, x, y;

    title('n');

    //  mencetak sisi atas dan bawah kotak
    for(x=trunc(WDT_SCREEN/11/2);x<=106;x++){
        gotoxy(x,25);   printf("\xc4");
        gotoxy(x,35);   printf("\xc4");
    }

    gotoxy(106,35); printf("\xd9");
    gotoxy(61,35);  printf("\xc0");
    gotoxy(106,25);  printf("\xbf");
    gotoxy(61,25);   printf("\xda");

    //  mencetak sisi kiri dan kanan kotak
    for(y=26;y<=34;y++){
        gotoxy(trunc(WDT_SCREEN/11/2-1),y);	    printf("\xb3");
        gotoxy(trunc(WDT_SCREEN/11/2+44),y);	printf("\xb3");
    }

	//mencetak isi tulisan dalam kotak
    gotoxy(trunc(WDT_SCREEN/11/2+7),27);		printf(">>>>| Pilih Jumlah Pemain |<<<<");
	gotoxy(trunc(WDT_SCREEN/11/2+3),28);		printf("______________________________________");
	gotoxy(trunc(WDT_SCREEN/11/2+5),30);		printf("1. 2 Pemain");
	gotoxy(trunc(WDT_SCREEN/11/2+5),31);		printf("2. 3 Pemain");
	gotoxy(trunc(WDT_SCREEN/11/2+5),32);		printf("3. 4 Pemain");
	gotoxy(trunc(WDT_SCREEN/11/2+5),33);		printf("4. Kembali");

    pilihan = Cursor(4,64,30); //User memilih menu menggunakan tombol keyboard atas atau bawah

    switch(pilihan) {
        case 1:
        case 2:
        case 3:

            //Pelilihan jumlah pemain yang dilawan dilakukan dengan menggunakan tombol atas atau bawah keyboard
            JumlahPemain = pilihan+1;
            inputNama(JumlahPemain);
            system("cls");

            //Jumlah pemain dan jumlah pemain komputer "dilempar" ke modul yang bernama "Permainan"
            PermainandanStopwatch(JumlahPemain,0);
            break;
        case 4:
            return;
            break;
    }
}

//==============================================================
//          4. Menampilkan Tatacara bermain permainan
//==============================================================
void CaraMain() {
    FILE *fp;
    char Kalimat;
    int i = 2, click;

    if((fp=fopen("assets\\file\\HowTo.txt","r")) != NULL) {
        gotoxy(trunc(WDT_SCREEN/11/2), 2);
        while((Kalimat=getc(fp)) != EOF) {
            putch(Kalimat);
        }
    } else {
        gotoxy(43,10); printf("File Tata Cara Bermain Tidak Ditemukan!");
    }

    kembali:
  	click = _getch();
    if(click != ENTER_KEY)
        goto kembali;
    Beep(700, 40);


    fclose(fp);
}

//==============================================================
//          4. Menampilkan Tatacara bermain permainan
//==============================================================
void title(char mode){
	int i;
	for(i = 20; i < 147; i++)
	{
		gotoxy(i,23); printf("\xc4");
		if(mode=='y')
		{
			Sleep(1);
		}
	}
	gotoxy(147,23); printf("\xd9");
	for(i = 22; i > 2; i--)
	{
		gotoxy(147,i); printf("\xb3");
		if(mode=='y')
		{
			Sleep(1);
		}
	}
	gotoxy(147,2); printf("\xbf");
	for(i = 146; i > 20; i--)
	{
		gotoxy(i,2); printf("\xc4");
		if(mode=='y')
		{
			Sleep(1);
		}
	}
	gotoxy(20,2); printf("\xda");
	for(i = 3; i < 23; i++)
	{
		gotoxy(20,i); printf("\xb3");
		if(mode=='y')
		{
			Sleep(1);
		}
	}
	gotoxy(20,23); printf("\xc0");
	setcolor(LIGHT_GREEN);
	gotoxy(30,5); printf("лл     лл\n");
	gotoxy(30,6); printf("лл     лл\n");
	gotoxy(30,7); printf("лл     лл\n");
	gotoxy(30,8); printf("лл     лл\n");
	gotoxy(30,9); printf("  ллллл\n");
	setcolor(LIGHT_BLUE);
	gotoxy(65,5); printf("лллллллл\n");
	gotoxy(65,6); printf("лл     лл\n");
	gotoxy(65,7); printf("лллллллл\n");
	gotoxy(65,8); printf("лл     лл\n");
	gotoxy(65,9); printf("лл     лл\n");

	if(mode=='y')
	{
		Sleep(400);
	}

	setcolor(YELLOW);
	gotoxy(42,5); printf("лл\n");
	gotoxy(42,6); printf("лл\n");
	gotoxy(42,7); printf("лл\n");
	gotoxy(42,8); printf("лл\n");
	gotoxy(42,9); printf("лллллллл\n");
	setcolor(RED);
	gotoxy(53,5); printf("  ллллл\n");
	gotoxy(53,6); printf(" лл   лл\n");
	gotoxy(53,7); printf("ллллллллл\n");
	gotoxy(53,8); printf("лл     лл\n");
	gotoxy(53,9); printf("лл     лл\n");

	setcolor(LIGHT_GREEN);
	gotoxy(30,12); printf("лллллллллллллл\n");
	gotoxy(30,13); printf("      лл\n");
	gotoxy(30,14); printf("      лл\n");
	gotoxy(30,15); printf("      лл\n");
	gotoxy(30,16); printf("      лл\n");
	gotoxy(30,17); printf("      лл\n");
	gotoxy(30,18); printf("      лл\n");
	gotoxy(30,19); printf("      лл\n");
	gotoxy(30,20);printf("      лл \n");
	setcolor(LIGHT_GRAY);
	gotoxy(127,12); printf("    ллллл\n");
	gotoxy(127,13); printf("  лл     лл\n");
	gotoxy(127,14); printf(" лл       лл\n");
	gotoxy(127,15); printf("лл         лл\n");
	gotoxy(127,16); printf("ллллллллллллл\n");
	gotoxy(127,17); printf("лл         лл\n");
	gotoxy(127,18); printf("лл         лл\n");
	gotoxy(127,19); printf("лл         лл\n");
	gotoxy(127,20);printf("лл         лл\n");
	if(mode=='y')
	{
		Sleep(400);
	}
	setcolor(YELLOW);
	gotoxy(50,12); printf("    ллллл\n");
	gotoxy(50,13); printf("  лл     лл\n");
	gotoxy(50,14); printf(" лл       лл\n");
	gotoxy(50,15); printf("лл         лл\n");
	gotoxy(50,16); printf("ллллллллллллл\n");
	gotoxy(50,17); printf("лл         лл\n");
	gotoxy(50,18); printf("лл         лл\n");
	gotoxy(50,19); printf("лл         лл\n");
	gotoxy(50,20);printf("лл         лл\n");
	setcolor(LIGHT_BLUE);
	gotoxy(107,12); printf("  лллллллл\n");
	gotoxy(107,13); printf("лл        лл\n");
	gotoxy(107,14); printf("лл        лл\n");
	gotoxy(107,15); printf("лл        \n");
	gotoxy(107,16); printf("лллллллллл\n");
	gotoxy(107,17); printf("лл        лл\n");
	gotoxy(107,18); printf("лл        лл\n");
	gotoxy(107,19); printf("лл        лл\n");
	gotoxy(107,20);printf("  лллллллл   \n");
	if(mode=='y')
	{
		Sleep(400);
	}
	setcolor(RED);
	gotoxy(69,12); printf("лллл       лл\n");
	gotoxy(69,13); printf("лл лл      лл\n");
	gotoxy(69,14); printf("лл  лл     лл\n");
	gotoxy(69,15); printf("лл   лл    лл\n");
	gotoxy(69,16); printf("лл    лл   лл\n");
	gotoxy(69,17); printf("лл     лл  лл\n");
	gotoxy(69,18); printf("лл      лл лл\n");
	gotoxy(69,19); printf("лл       лллл\n");
	gotoxy(69,20);printf("лл        ллл\n");
	setcolor(PURPLE);
	gotoxy(88,12); printf("  лллллллл\n");
	gotoxy(88,13); printf("лл        лл\n");
	gotoxy(88,14); printf("лл        лл\n");
	gotoxy(88,15); printf("лл        \n");
	gotoxy(88,16); printf("лллллллллл\n");
	gotoxy(88,17); printf("лл        лл\n");
	gotoxy(88,18); printf("лл        лл\n");
	gotoxy(88,19); printf("лл        лл\n");
	gotoxy(88,20);printf("  лллллллл   \n");
	setcolor(WHITE);
}
