#include "header.h"

void leaderboard()
{
    Users user;
	FILE *fptr;
	int tinggi = 14, n = 0;

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
        gotoxy(trunc(WDT_SCREEN/12.5/2), 12);
        printf("Peringkat");
        gotoxy(trunc(WDT_SCREEN/12.5/2)+27, 12);
        printf("Username");
        gotoxy(trunc(WDT_SCREEN/12.5/2)+58,12);
        printf("Score");
   	    while(fread(&user, sizeof(Users), 1, fptr)==1)
        {
            n++;
            gotoxy(trunc(WDT_SCREEN/12.5/2)+4, tinggi);
            printf("%d", n);
            gotoxy(trunc(WDT_SCREEN/12.5/2)+27, tinggi);
            printf("%s", user.nama_lengkap);
            gotoxy(trunc(WDT_SCREEN/12.5/2)+58, tinggi);
            printf("%d", user.score);
            tinggi++;
        }
	}

	for(int i = 11; i<tinggi+3; i++)
    {
        gotoxy(trunc(WDT_SCREEN/17/2), i); printf("|");
        gotoxy(trunc(WDT_SCREEN/17/2)+90, i); printf("|");
    }

    gotoxy(trunc(WDT_SCREEN/13.5/2),tinggi+1);
    printf("Tekan Enter untuk kembali ke Menu Utama . . .");

    gotoxy(trunc(WDT_SCREEN/17/2), tinggi+3);
    printf("+=========================================================================================+");
	fclose(fptr);
	_getch();
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
    }
	f_struct = sizeof(Users);
	fseek(fptr, 0, SEEK_END);
	f_file = ftell(fptr);
	rewind(fptr);
	for(i=0;i< f_file; i += f_struct){
		for(x=0;x< f_file - f_struct; x += f_struct){
			fread(&dt, f_struct, 1, fptr);
			fread(&temp, f_struct, 1, fptr);
			if(dt.score<temp.score){
				fseek(fptr, -(f_struct * 2), SEEK_CUR);
				fwrite(&temp, f_struct, 1, fptr);
				fwrite(&dt, f_struct, 1, fptr);
				fseek(fptr, -f_struct , SEEK_CUR);
			}
			else{
				fseek(fptr, -f_struct , SEEK_CUR);
			}
		}
		rewind(fptr);
	}
	fclose(fptr);
}
