#ifndef users_H
#define users_H

typedef struct
{
    int id;
    char * username;
    int score;
} Users;

// 1. Untuk menampilkan peringkat ke layar
void leaderboard();

// 2. Untuk mengurutkan file agar yang yang memiliki score tertinggi berada di atas
void Sort_file();

void storeNamaFile(const char * nama);

#endif
