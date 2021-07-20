#ifndef users_H
#define users_H

/*typedef struct
{
    char username[50];
    int score;
} Users; */

typedef struct
{
    int id;
    char nama_lengkap[50];
    char username[50];
    char password[50];
    int status;
    int score;
} Users;

// 1. Untuk menampilkan peringkat ke layar
void leaderboard();

// 2. Untuk mengurutkan file agar yang yang memiliki score tertinggi berada di atas
void Sort_file();

#endif
