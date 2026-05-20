#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Definisi struct user untuk menyimpan data pengguna
typedef struct {
    char nama[50];
    char alamat[50];
    char pw[50];
    int hari;
    int poin;
} user;

// Inisialisasi database dan pointer untuk database dinamis
user user_database[24];
user* user_database_ptr = user_database;
int user_size = 4;

//Enum jenis sampah untuk memudahkan penghitungan poin berdasarkan jenis sampah
typedef enum {
    TERBAKAR, TAK_TERBAKAR, PLASTIK, BOTOL_KALENG, KERTAS, B3
} jenisSampah;

//Menghitung poin berdasarkan jenis sampah, berat, dan streak user
int hitungPoin(int jenis, int berat, int hari){
    if (hari < 1) return jenis * berat;
    else if (hari < 7) return (jenis * berat) * 1.25;
    else if (hari < 14) return (jenis * berat) * 1.5;
    else if (hari < 21) return (jenis * berat) * 1.75;
    else return (jenis * berat) * 2;
}

//Compare password input dengan password referensi untuk login
bool login(char ref_pw[50], char input_pw[50]){
    if (strcmp(ref_pw, input_pw) != 0) 
        return false;
    return true;
}

// Membuat user baru dengan mengalokasikan memori dinamis untuk database dan mengisi data user baru ke dalam database
void createUser(){ 
    char nama[50], alamat[50], pw[50];
    printf("Masukkan nama: ");
    scanf("%s", nama);
    printf("Masukkan alamat: ");
    scanf("%s", alamat);
    printf("Masukkan password: ");
    scanf("%s", pw);
    
    // Logika pengisian data user baru ke database dinamis
    user_size++;
    user* tmp = (user*)realloc(user_database_ptr, user_size * sizeof(user));
    if (tmp != NULL) {
        user_database_ptr = tmp;
        strcpy(user_database_ptr[user_size - 1].nama, nama);
        strcpy(user_database_ptr[user_size - 1].alamat, alamat);
        strcpy(strcpy(user_database_ptr[user_size - 1].pw, pw), pw);
        user_database_ptr[user_size - 1].hari = 0;
        user_database_ptr[user_size - 1].poin = 0;
    }
}

//Mencari user index berdasarkan nama yang diinputkan
int findUser(){
    int i, j;
    char input_user[50];
    do
    {    
        printf("Masukkan nama pengguna: ");
        scanf(" %s", input_user);
        for (i = 0; i < user_size; i++) {
            if (strcmp(user_database_ptr[i].nama, input_user) == 0) {
                j = i;
                break;
            }
            else
                j = -1;
        }
        if (j == -1) {
            printf("Pengguna tidak ditemukan. Coba lagi!\n");
        }
    }
    while(j == -1);
    return j;
}

char** users;

int main(){
    // Alokasi memori awal disesuaikan dengan ukuran struct user
    user_database_ptr = (user*)malloc(user_size * sizeof(user));
    
    // Inisialisasi data awal dari database user
    strcpy(user_database_ptr[0].nama, "admin"); strcpy(user_database_ptr[0].alamat, "admin"); strcpy(user_database_ptr[0].pw, "admin"); user_database_ptr[0].hari = 0; user_database_ptr[0].poin = 0;
    strcpy(user_database_ptr[1].nama, "Kenneth"); strcpy(user_database_ptr[1].alamat, "Stasiun UI"); strcpy(user_database_ptr[1].pw, "676942067"); user_database_ptr[1].hari = 2; user_database_ptr[1].poin = 100;
    strcpy(user_database_ptr[2].nama, "Christian"); strcpy(user_database_ptr[2].alamat, "Kostian"); strcpy(user_database_ptr[2].pw, "123456789"); user_database_ptr[2].hari = 5; user_database_ptr[2].poin = 200;
    strcpy(user_database_ptr[3].nama, "Gilchrist"); strcpy(user_database_ptr[3].alamat, "Kosinda"); strcpy(user_database_ptr[3].pw, "CharmonyDove"); user_database_ptr[3].hari = 10; user_database_ptr[3].poin = 350;

    printf("Selamat Datang ke TPA Daur Ulang Abadi!\n\n");
    printf("1. Login\n");
    printf("2. Buat Akun Baru\n");
    printf("Pilih opsi: ");
    int opsi;
    scanf("%d", &opsi);

    if (opsi == 1) 
    {
        char input_pw[50];
        char input_user[50];
        int token;
        do
        {
            int user_index = findUser();
            printf("Masukkan password: ");
            scanf(" %s", input_pw);

            token = login(user_database_ptr[user_index].pw, input_pw);

            if (token) {
                printf("Login berhasil!\n");
            } else {
                printf("Login gagal! Password salah.\n");
            }
            int logged_in_user_index = user_index;
        } while (!token);
    } 
    else if (opsi == 2) 
    {
        createUser();
    } 
    else 
    {
        printf("Opsi tidak valid.\n");
    }

    printf("Terimakasih Telah Mempercacyai Layanani Kami!\n");
    printf("Menu:\n");
    printf("1. Mendaur Ulang\n");
    printf("2. Cek Poin\n");
    printf("3. Tukar Poin\n");
    printf("4. Akun\n");
    printf("5. Keluar\n");
    printf("Pilih opsi: ");
    scanf("%d", &opsi);

    printf("Terima Kasih Telah Menggunakan Layanan Kami!\n");
    free(user_database_ptr);
    return 0;
}