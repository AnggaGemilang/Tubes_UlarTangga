#include "header.h"

void leaderboard()
{
    Users user;
	FILE *fptr;
	int tinggi = 14, n = 0, click;

    system("cls");

    gotoxy(trunc(WDT_SCREEN/11/2), 3);
    printf("=============================================\n");
    gotoxy(trunc(WDT_SCREEN/11/2), 4);
    printf("||              LEADERBOARD                ||\n");
    gotoxy(trunc(WDT_SCREEN/11/2), 5);
    printf("||                  ***                    ||\n");
    gotoxy(trunc(WDT_SCREEN/11/2), 6);
    printf("||              Ular Tangga                ||\n");
    gotoxy(trunc(WDT_SCREEN/11/2), 7);
    printf("=============================================\n");

    gotoxy(trunc(WDT_SCREEN/17/2), 10);
    printf("+=========================================================================================+");

	Sort_file();
	if((fptr = fopen("assets/file/users.dat","rb")) == NULL){
       printf("Error! File Tidak Dapat Dibuka...");
       exit(1);
   	} else {
   	    while(fread(&user, sizeof(Users), 1, fptr)==1)
        {
            n++;
            gotoxy(trunc(WDT_SCREEN/12.5/2)+4, tinggi);
            printf("%d", n);
            gotoxy(trunc(WDT_SCREEN/12.5/2)+27, tinggi);
            printf("%s", user.username);
            gotoxy(trunc(WDT_SCREEN/12.5/2)+58, tinggi);
            printf("%d", user.score);
            tinggi++;
        }
	}

	if(n == 0)
    {
        gotoxy(trunc(WDT_SCREEN/9/2),tinggi-1);
        printf("Data Tidak Ditemukan");
        for(int i = 11; i<tinggi+5; i++)
        {
            gotoxy(trunc(WDT_SCREEN/17/2), i); printf("|");
            gotoxy(trunc(WDT_SCREEN/17/2)+90, i); printf("|");
        }

        gotoxy(trunc(WDT_SCREEN/13.5/2),tinggi+2);
        printf("Tekan Enter untuk kembali ke Menu Utama . . .");

        gotoxy(trunc(WDT_SCREEN/17/2), tinggi+4);
        printf("+=========================================================================================+");
    } else
    {
        gotoxy(trunc(WDT_SCREEN/12.5/2), 12);
        printf("Peringkat");
        gotoxy(trunc(WDT_SCREEN/12.5/2)+27, 12);
        printf("Username");
        gotoxy(trunc(WDT_SCREEN/12.5/2)+58,12);
        printf("Score");
        for(int i = 11; i<tinggi+3; i++)
        {
            gotoxy(trunc(WDT_SCREEN/17/2), i); printf("|");
            gotoxy(trunc(WDT_SCREEN/17/2)+90, i); printf("|");
        }

        gotoxy(trunc(WDT_SCREEN/13.5/2),tinggi+1);
        printf("Tekan Enter untuk kembali ke Menu Utama . . .");

        gotoxy(trunc(WDT_SCREEN/17/2), tinggi+3);
        printf("+=========================================================================================+");
    }
	fclose(fptr);
	kembali:
	click = _getch();
    if(click != ENTER_KEY)
        goto kembali;
    Beep(700, 40);
}

void Sort_file(){
	Users dt,temp;
	int i,x;
	int f_struct;
	int f_file;
	FILE *fptr;
	if ((fptr=fopen("assets/file/users.dat", "rb+"))==NULL)
    {
        printf ("File tidak dapat dibuka\n");
    } else
    {
        f_struct = sizeof(Users);
        fseek(fptr, 0, SEEK_END);
        f_file = ftell(fptr);
        rewind(fptr);
        for(i=0;i< f_file; i += f_struct)
        {
            for(x=0;x< f_file - f_struct; x += f_struct)
            {
                fread(&dt, f_struct, 1, fptr);
                fread(&temp, f_struct, 1, fptr);
                if(dt.score<temp.score)
                {
                    fseek(fptr, -(f_struct * 2), SEEK_CUR);
                    fwrite(&temp, f_struct, 1, fptr);
                    fwrite(&dt, f_struct, 1, fptr);
                    fseek(fptr, -f_struct , SEEK_CUR);
                }
                else
                {
                    fseek(fptr, -f_struct , SEEK_CUR);
                }
            }
            rewind(fptr);
        }
        fclose(fptr);
    }
}

void storeNamaFile(Users userBaru)
{
    Users user;
    FILE *fptr;
    boolean status = false;
	if((fptr = fopen("assets/file/users.dat","rb+")) == NULL){
       printf("Error! File Tidak Dapat Dibuka...");
       exit(1);
   	} else {
   	    // perulangan membaca isi file users.dat
   	    while(fread(&user, sizeof(Users), 1, fptr)==1)
        {
            // jika username sudah terdaftar
            if(strcmp(user.username, userBaru.username) == 0)
            {
                status = true;
                user.id = user.id;
                strcpy(user.username, user.username);
                user.score = user.score + userBaru.score;
                fseek(fptr, (long) -sizeof(user), SEEK_CUR);
                fwrite(&user, sizeof(user), 1, fptr);
                break;
            } else
            {
                continue;
            }
        }
        // jika username belum terdaftar
        if(status == false)
        {
            strcpy(user.username, userBaru.username);
            user.score = userBaru.score + 2;
            fwrite(&user, sizeof(user), 1, fptr);
        }
   	}
    fclose(fptr);
}

void inputNama(int jumlahPemain)
{
    system("cls");
    int JumlahAI, x, y, a = 29;
    Users user, user1;

    // mencetak judul permainan
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
    gotoxy(trunc(WDT_SCREEN/11/2+7),27);	    printf(">>>>| Inputkan Nama Player |<<<<");
	gotoxy(trunc(WDT_SCREEN/11/2+3),28);	    printf("______________________________________");

	// membuka file users-baru.dat dalam mode tulis ulang
	FILE *fp, *fp1;
	fp = fopen("assets/file/users-baru.dat","wb");

	// perulangan untuk input nama player 1 s.d 4
	for (int i = 1; i <= jumlahPemain; i++){
        for(int i=40; i > 35; i--)
        {
            gotoxy(61,i); printf("                                              ");
        }
        gotoxy(106,35); printf("\xd9");
        gotoxy(61,35);  printf("\xc0");
        a++;
        ulangiInputNama:
        gotoxy(trunc(WDT_SCREEN/11/2+5),a);
        printf("Player %d: ", i);
        fflush(stdin);
        gets(user.username);
        if(strlen(user.username) == 0)
        {
            Beep(700, 39);
            gotoxy(61,35); printf("\xc0");
            for(int i=61; i < 106; i++)
            {
                gotoxy(i,39); printf("\xc4");
            }
            gotoxy(106,39); printf("\xd9");
            for(int i=38; i > 34; i--)
            {
                gotoxy(106,i); printf("\xb3");
            }
            gotoxy(61,39); printf("\xc0");
            for(int i=38; i > 34; i--)
            {
                gotoxy(61,i); printf("\xb3");
            }
            gotoxy(64,37); printf("                                        ");
            gotoxy(72,37); printf("Nama tidak boleh kosong!");
            goto ulangiInputNama;
        } else if (strlen(user.username) > 12)
        {
            Beep(700, 39);
            gotoxy(61,35); printf("\xc0");
            for(int i=61; i < 106; i++)
            {
                gotoxy(i,39); printf("\xc4");
            }
            gotoxy(106,39); printf("\xd9");
            for(int i=38; i > 34; i--)
            {
                gotoxy(106,i); printf("\xb3");
            }
            gotoxy(61,39); printf("\xc0");
            for(int i=38; i > 34; i--)
            {
                gotoxy(61,i); printf("\xb3");
            }
            gotoxy(64,37); printf("Nama tidak boleh lebih dari 12 karakter!");
            gotoxy(trunc(WDT_SCREEN/11/2+5),a); printf("                                      ");
            goto ulangiInputNama;
        }

        user.id = random_number(11111, 99999);
        user.order = i;

        boolean isAda = false;

        if((fp1 = fopen("assets/file/users.dat","rb+")) == NULL){
            printf("Error! File Tidak Dapat Dibuka...");
            exit(1);
        } else {
            while(fread(&user1, sizeof(Users), 1, fp1)==1)
            {
                if(strcmp(user1.username, user.username))
                {
                    isAda = true;
                    user.score = user1.score;
                    break;
                } else
                {
                    continue;
                }
            }
            if(isAda = false)
            {
                user.score = 0;
            }
        }
        fclose(fp1);

        // menyimpan nama dan id ke dalam file users-baru.id
        fwrite(&user, sizeof(user), 1, fp);
	}
	fclose(fp);
}
