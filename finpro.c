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
    TERBAKAR = 1, TAK_TERBAKAR, PLASTIK, BOTOL_KALENG, KERTAS, B3
} jenisSampah;

// Menghitung poin berdasarkan jenis sampah, berat, dan streak user
int hitungPoin(int jenis, int berat, int hari){
    // Mengubah pengali dasar jenis sampah agar TERBAKAR (0) bernilai 1, dst.
    
    if (hari < 1) return jenis * berat;
    else if (hari < 7) return (jenis * berat) * 1.25;
    else if (hari < 14) return (jenis * berat) * 1.5;
    else if (hari < 21) return (jenis * berat) * 1.75;
    else return (jenis * berat) * 2;
}

// Compare password input dengan password referensi untuk login
bool login(char ref_pw[50], char input_pw[50]){
    if (strcmp(ref_pw, input_pw) != 0) 
        return false;
    return true;
}

// Membuat user baru dengan mengalokasikan memori dinamis untuk database dan mengisi data user baru ke dalam database
int createUser(){ 
    char nama[50], alamat[50], pw[50];
    printf("Masukkan nama: ");
    scanf("%s", nama);
    printf("Masukkan alamat: ");
    scanf("%s", alamat);
    printf("Masukkan password: ");
    scanf(" %s", pw);
    
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
    return user_size-1;
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

int pointexchange(int poin) {
    bool loop,loop2;
    int opsi,hitung,opsi2;
    do {
        printf("\n--- Menu Tukar Poin (Poin Anda: %d) ---\n",poin);
        printf("1. Voucher Makanan (10 Poin)\n");
        printf("2. Voucher Pakaian (45 Poin)\n");
        printf("3. Voucher Peralatan (80 Poin)\n");
        printf("4. Merch\n");
        printf("5. Balik Ke Menu Utama\n");
        printf("Pilih: ");
        scanf("%d",&opsi);

        switch (opsi) {
            case 1:
                hitung=poin-10;
                if (hitung<0) {
                    printf("Poin anda kurang\n");
                }
                else {
                    poin=hitung;
                    printf("Selamat Anda Mendapatkan Voucher Makanan\n");
                    printf("Jumlah Poin Anda: %d\n",poin);
                }
                break;
            case 2:
                hitung=poin-45;
                if (hitung<0) {
                    printf("Poin anda kurang\n");
                }
                else {
                    poin=hitung;
                    printf("Selamat Anda Mendapatkan Voucher Pakaian\n");
                    printf("Jumlah Poin Anda: %d\n",poin);
                }
                break;
            case 3:
                hitung=poin-80;
                if (hitung<0) {
                    printf("Poin anda kurang\n");
                }
                else {
                    poin=hitung;
                    printf("Selamat Anda Mendapatkan Voucher Peralatan\n");
                    printf("Jumlah Poin Anda: %d\n",poin);
                }
                break;
            case 4:
                do{
                    printf("\nPilih Merch: \n");
                    printf("1. Tumbler (30 Poin)\n");
                    printf("2. Tote Bag (20 Poin)\n");
                    printf("3. Alat Tulis (15 Poin)\n");
                    printf("4. Balik ke Menu\n");
                    printf("Pilih: ");
                    scanf("%d",&opsi2);

                    switch (opsi2) {
                        case 1:
                            hitung=poin-80;
                            if (hitung<0) {
                                printf("Poin anda kurang\n");
                            }
                            else {
                                poin=hitung;
                                printf("Selamat Anda Mendapatkan Tumbler\n");
                                printf("Jumlah Poin Anda: %d\n",poin);
                            }
                            break;
                        case 2:
                            hitung=poin-80;
                            if (hitung<0) {
                                printf("Poin anda kurang\n");
                            }
                            else {
                                poin=hitung;
                                printf("Selamat Anda Mendapatkan Tote Bag\n");
                                printf("Jumlah Poin Anda: %d\n",poin);
                            }
                            break;
                        case 3:
                            hitung=poin-80;
                            if (hitung<0) {
                                printf("Poin anda kurang\n");
                            }
                            else {
                                poin=hitung;
                                printf("Selamat Anda Mendapatkan Alat Tulis\n");
                                printf("Jumlah Poin Anda: %d\n",poin);
                            }
                            break;
                        case 4:
                            loop2=false;
                            break;
                        default:
                            printf("Pilih Opsi yang Valid\n");
                            break;
                    }

                }while(loop2!=false);
                
                break;
            case 5:
                loop=false;
                break;
            default:
                printf("Pilih Opsi yang Valid!\n");
                break;
        }
    } while (loop!=false);

    return poin;
    
}

int main(){
    jenisSampah jenis = 1;
    int berat = 0, hari = 0, poin = 0, flag = 0, logged_in_user_index = 0;

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
    int opsi;
    
    while (flag == 0){
        printf("Pilih opsi: ");
        scanf("%d", &opsi);

        if (opsi == 1){
            char input_pw[50];
            int token;
            do{
                int user_index = findUser();
                printf("Masukkan password: ");
                scanf(" %s", input_pw);

                token = login(user_database_ptr[user_index].pw, input_pw);

                if (token) {
                    printf("\nLogin berhasil!\n");
                    logged_in_user_index = user_index;
                } else {
                    printf("\nLogin gagal! Password salah.\n");
                }
            } while (!token);
            flag++;
        } else if (opsi == 2) {
            logged_in_user_index = createUser();
            flag++;
        } else printf("Opsi tidak valid.\n");
    }

    printf("Terimakasih Telah Mempercayai Layanan Kami!\n");
    while (flag == 0){
        printf("\nMenu:\n");
        printf("1. Mendaur Ulang\n");
        printf("2. Cek Poin\n");
        printf("3. Tukar Poin\n");
        printf("4. Akun\n");
        printf("5. Keluar\n");
        printf("Pilih opsi: ");
        scanf("%d", &opsi);
        
        switch (opsi){
            case 1:
                printf("\nPilih Jenis Sampah:\n");
                printf("1. Terbakar\n");
                printf("2. Tak Terbakar\n");
                printf("3. Plastik\n");
                printf("4. Botol/Kaleng\n");
                printf("5. Kertas\n");
                printf("6. B3\n");

                while (true){
                    printf("Masukkan pilihan (1-6): ");
                    scanf("%d", &jenis);
                    if (jenis < 1 || jenis > 6){
                        printf("Jenis sampah tidak valid!\n");
                    } else break;
                }

                printf("Masukkan berat sampah (kg): ");
                scanf("%d", &berat);

                int poin_diperoleh = hitungPoin(jenis, berat, user_database_ptr[logged_in_user_index].hari);
                user_database_ptr[logged_in_user_index].poin += poin_diperoleh;
                user_database_ptr[logged_in_user_index].hari += 1;
                
                printf("\n--- Transaksi Berhasil ---\n");
                printf("Poin didapat  : %d poin\n", poin_diperoleh);
                printf("Total poin Anda sekarang: %d poin\n", user_database_ptr[logged_in_user_index].poin);
                break;

            case 2:
                printf("\n--- Informasi Poin Pengguna ---\n");
                printf("Nama Pengguna : %s\n", user_database_ptr[logged_in_user_index].nama);
                printf("Streak Hari   : %d hari\n", user_database_ptr[logged_in_user_index].hari);
                printf("Total Poin    : %d poin\n", user_database_ptr[logged_in_user_index].poin);
                break;

            case 3:
                user_database_ptr[logged_in_user_index].poin=pointexchange(user_database_ptr[logged_in_user_index].poin);
                break;

            case 4:
                printf("\nNama Anda: %s\n", user_database_ptr[logged_in_user_index].nama);
                printf("Alamat Anda: %s\n", user_database_ptr[logged_in_user_index].alamat);
                printf("Jumlah hari Anda telah menyimpan sampah berturut-turut: %d\n", user_database_ptr[logged_in_user_index].hari);
                break;
            case 5:
                flag++;
                printf("Keleuar dari sistem.\n");
                break;
            default:
                printf("\nOpsi invalid!");
                break;
        } 
    }

    printf("Terima Kasih Telah Menggunakan Layanan Kami!\n");
    free(user_database_ptr);
    return 0;
