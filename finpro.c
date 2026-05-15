#include <stdio.h>

typedef struct {
    char nama[50];
    char alamat[50];
    char pw[50];
    int hari;
    int poin;
} user;

typedef enum {
    TERBAKAR, TAK_TERBAKAR, PLASTIK, BOTOL_KALENG, KERTAS, B3
} jenisSampah;

int hitungPoin(int jenis, int berat, int hari){
    if (hari < 1) return jenis * berat;
    else if (hari < 7) return (jenis * berat) * 1.25;
    else if (hari < 14) return (jenis * berat) * 1.5;
    else if (hari < 21) return (jenis * berat) * 1.75;
    else return (jenis * berat) * 2;
}

bool login(char ref_pw[50], char input_pw[50]){
    if (input_pw != ref_pw) return false;
    return true;
}

void createUser(char user[50], char pw[50]){
    /// bla bla bla
}

char** users;

int main(){
    // bla bla bla
}
