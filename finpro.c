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

// Enum jenis sampah untuk memudahkan penghitungan poin berdasarkan jenis sampah
typedef enum {
    TERBAKAR, TAK_TERBAKAR, PLASTIK, BOTOL_KALENG, KERTAS, B3
} jenisSampah;

// Menghitung poin berdasarkan jenis sampah, berat, dan streak user
int hitungPoin(int jenis, int berat, int hari){
    // Mengubah pengali dasar jenis sampah agar TERBAKAR (0) bernilai 1, dst.
    int pengali_jenis = jenis + 1; 
    
    if (hari < 1) return pengali_jenis * berat;
    else if (hari < 7) return (pengali_jenis * berat) * 1.25;
    else if (hari < 14) return (pengali_jenis * berat) * 1.5;
    else if (hari < 21) return (pengali_jenis * berat) * 1.75;
    else return (pengali_jenis * berat) * 2;
}

// Compare password input dengan password referensi untuk login
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
        strcpy(user_database_ptr[user_size - 1].pw, pw);
        user_database_ptr[user_size - 1].hari = 0;
        user_database_ptr[user_size - 1].poin = 0;
    }
}

// Mencari user index berdasarkan nama yang diinputkan
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

    int logged_in_user_index = -1; 

    if (opsi == 1) 
    {
        char input_pw[50];
        int token;
        do
        {
            int user_index = findUser();
            printf("Masukkan password: ");
            scanf(" %s", input_pw);

            token = login(user_database_ptr[user_index].pw, input_pw);

            if (token) {
                printf("Login berhasil!\n");
                logged_in_user_index = user_index;
            } else {
                printf("Login gagal! Password salah.\n");
            }
        } while (!token);
    } 
    else if (opsi == 2) 
    {
        createUser();
        logged_in_user_index = user_size - 1;
    } 
    else 
    {
        printf("Opsi tidak valid.\n");
        free(user_database_ptr);
        return 0;
    }

    printf("\nTerimakasih Telah Mempercayai Layanan Kami!\n");
    printf("Menu:\n");
    printf("1. Mendaur Ulang\n");
    printf("2. Cek Poin\n");
    printf("3. Tukar Poin\n");
    printf("4. Akun\n");
    printf("5. Keluar\n");
    printf("Pilih opsi: ");
    scanf("%d", &opsi);

    if (opsi == 1) {
        int pilihan_user, jenis, berat;
        printf("\nPilih Jenis Sampah:\n");
        printf("1. Terbakar\n");
        printf("2. Tak Terbakar\n");
        printf("3. Plastik\n");
        printf("4. Botol/Kaleng\n");
        printf("5. Kertas\n");
        printf("6. B3\n");
        printf("Masukkan pilihan (1-6): ");
        scanf("%d", &pilihan_user);


    printf("\nTerimakasih Telah Mempercayai Layanan Kami!\n");
    printf("Menu:\n");
    printf("1. Mendaur Ulang\n");
    printf("2. Cek Poin\n");
    printf("3. Tukar Poin (Belum Tersedia)\n");
    printf("4. Akun (Belum Tersedia)\n");
    printf("5. Keluar\n");
    printf("Pilih opsi: ");
    scanf("%d", &opsi);

    switch (opsi) {
        case 1: {
            int pilihan_user, jenis, berat;
            printf("\nPilih Jenis Sampah:\n");
            printf("1. Terbakar\n");
            printf("2. Tak Terbakar\n");
            printf("3. Plastik\n");
            printf("4. Botol/Kaleng\n");
            printf("5. Kertas\n");
            printf("6. B3\n");
            printf("Masukkan pilihan (1-6): ");
            scanf("%d", &pilihan_user);

            if (pilihan_user >= 1 && pilihan_user <= 6) {
                jenis = pilihan_user - 1;

                printf("Masukkan berat sampah (kg): ");
                scanf("%d", &berat);

                int poin_diperoleh = hitungPoin(jenis, berat, user_database_ptr[logged_in_user_index].hari);
                
                user_database_ptr[logged_in_user_index].poin += poin_diperoleh;
                user_database_ptr[logged_in_user_index].hari += 1; 

                printf("\n--- Transaksi Berhasil ---\n");
                printf("Poin didapat  : %d poin\n", poin_diperoleh);
                printf("Total poin Anda sekarang: %d poin\n", user_database_ptr[logged_in_user_index].poin);
            } else {
                printf("Jenis sampah tidak valid!\n");
            }
            break;
        }

        case 2: {
            printf("\n--- Informasi Poin Pengguna ---\n");
            printf("Nama Pengguna : %s\n", user_database_ptr[logged_in_user_index].nama);
            printf("Streak Hari   : %d hari\n", user_database_ptr[logged_in_user_index].hari);
            printf("Total Poin    : %d poin\n", user_database_ptr[logged_in_user_index].poin);
            break;
        }

        case 3:

            break;

        case 4:

            break;

        case 5:
            printf("Keluar dari sistem.\n");
            break;

        default:
            printf("Opsi tidak valid!\n");
            break;
    }