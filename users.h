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

// 3. Untuk mengurutkan file agar yang yang memiliki score tertinggi berada di atas
void storeNamaFile(const char * nama);

// 4. Untuk mengurutkan file agar yang yang memiliki score tertinggi berada di atas
void inputNama(int jumlahPemain);

#endif
