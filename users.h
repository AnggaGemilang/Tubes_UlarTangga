#ifndef users_H
#define users_H
#include "linkedlist.h"
typedef struct
{
    int id;
    char username[50];
    int score;
    address player;
} Users;

// 1. Untuk menampilkan peringkat ke layar
void leaderboard();

// 2. Untuk mengurutkan file agar yang yang memiliki score tertinggi berada di atas
void Sort_file();

// 3. Untuk mengurutkan file agar yang yang memiliki score tertinggi berada di atas
void storeNamaFile(Users userBaru);

// 4. Untuk mengurutkan file agar yang yang memiliki score tertinggi berada di atas
void inputNama(int jumlahPemain);

#endif
