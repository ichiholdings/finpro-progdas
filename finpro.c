#include <stdio.h>


int user_database[24];
int *user_database_ptr = &user_database;
int user_size = 4;

user_database[0] = (user){"admin", "admin", "admin", 0, 0};
user_database[1] = (user){"Kenneth", "Stasiun UI", "676942067", 2, 100};
user_database[2] = (user){"Christian", "Kostian", "123456789", 5, 200};
user_database[3] = (user){"Gilchrist", "Kosinda", "CharmonyDove", 10, 350};

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

void addUserPoints()

bool login(char ref_pw[50], char input_pw[50]){
    if (input_pw != ref_pw) 
        return false;
    return true;
}

void createUser(char nama[50], char pw[50]){
    char nama[50], alamat[50], pw[50];
    printf("Masukkan nama: ");
    scanf("%s", nama);
    printf("Masukkan alamat: ");
    scanf("%s", alamat);
    printf("Masukkan password: ");
    scanf("%s", pw);
    createUser(nama, pw);
}

void addUserDatabase(char user[50], char pw[50]){
    user_size++;
    int tmp*;
    tmp = (user*)realloc(user_database_ptr, user_size);
    if (tmp == NULL) {
        printf("Reallocation failed\n");
        return;
    }
    user_database_ptr = tmp;
}

char findUser(char user[50]){
    for (int i = 0; i < user_size; i++) {
        if (strcmp(user_database_ptr[i].nama, user) == 0) {
            return i;
        }
    }
    return -1; // User tidak ditemukan
}

char** users;

int main(){
    user_database_ptr = (user*)malloc(user_size* sizeof(user));
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
        printf("Masukkan nama pengguna: ");
        scanf(" %s", input_user);
        int user_index = findUser(input_user);
        if (user_index == -1) {
            printf("User tidak ditemukan.\n");
            return 1;
        }
        printf("Masukkan password: ");
        scanf(" %s", input_pw);
        if (login(user_database_ptr[user_index].pw, input_pw)) {
            printf("Login berhasil!\n");
        } else {
            printf("Login gagal! Password salah.\n");
        }
        int logged_in_user_index = user_index;
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
}
