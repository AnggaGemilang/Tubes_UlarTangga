#ifndef users_H
#define users_H
#include "linkedlist.h"
typedef struct
{
    int id;
    int order;
    char username[50];
    int score;
    address player;
} Users;

// 1. Untuk menampilkan peringkat ke layar
void leaderboard();

// 2. Untuk mengurutkan file agar yang yang memiliki score tertinggi berada di atas
void Sort_file();

// 3. Untuk memasukkan data pemain ke dalam file
void storeNamaFile(Users userBaru);

// 4. Untuk menginput nama yang nantinya dikirim ke modul permainan
void inputNama(int jumlahPemain);

#endif
