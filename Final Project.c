#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

struct Sewa {
    int id;
    char nopol[12];
    char tipe[36];
    int tglsewa; // DD (01-31)
    int blnsewa; // MM (01-12)
    int thnsewa; // YYYY (2020)
    int durasi;
    char namapenyewa[36];
    int harga;
} sewa[50], temp;

int jumlahSewa = 0;

bool edit(char nopol[]) {
    int i;
    for(i = 0; i<jumlahSewa; i++) {
        if(!strcmp(nopol, sewa[i].nopol)) {
            printf("Masukkan nama penyewa (saat ini: %s): ", sewa[i].namapenyewa);
            scanf(" %[^\n]s", &sewa[i].namapenyewa);
            printf("Masukkan tipe motor (saat ini: %s): ", sewa[i].tipe);
            scanf(" %[^\n]s", &sewa[i].tipe);
            printf("Masukkan nomor polisi (saat ini: %s): ", sewa[i].nopol);
            scanf(" %[^\n]s", &sewa[i].nopol);
            printf("Masukkan tanggal sewa (DD) (saat ini: %d): ", sewa[i].tglsewa);
            scanf(" %d", &sewa[i].tglsewa);
            printf("Masukkan bulan sewa (MM) (saat ini: %d): ", sewa[i].blnsewa);
            scanf(" %d", &sewa[i].blnsewa);
            printf("Masukkan tahun sewa (YYYY) (saat ini: %d): ", sewa[i].thnsewa);
            scanf(" %d", &sewa[i].thnsewa);
            printf("Masukkan durasi sewa (dalam hari) (saat ini: %d): ", sewa[i].durasi);
            scanf(" %d", &sewa[i].durasi);

            if(!strcmp(sewa[i].tipe, "Beat 125 CC")) sewa[i].harga = 100000*sewa[i].durasi;
            if(!strcmp(sewa[i].tipe, "Vario 150 CC")) sewa[i].harga = 150000*sewa[i].durasi;
            if(!strcmp(sewa[i].tipe, "Aerox")) sewa[i].harga = 200000*sewa[i].durasi;

            printf("Harga sewa: %d\n", sewa[i].harga);
        }
    }
    return false;
}

bool hapus(char nopol[]) {
    int i;
    for(i = 0; i<jumlahSewa; i++) {
        if(!strcmp(nopol, sewa[i].nopol)) {
            strcpy(sewa[i].nopol, " ");
            return true;
        }
    }
    return false;
}

void tampilkan(int mode, int indeks) {
    if(mode == 0) {
        int i;
        int out = 0;
        for(i = 0; i<jumlahSewa; i++) {
            if(!strcmp(" ", sewa[i].nopol)) continue;
            else {
                printf("\n[%d]", sewa[i].id);
                printf("\nNama penyewa\t: %s", sewa[i].namapenyewa);
                printf("\nTipe motor\t: %s", sewa[i].tipe);
                printf("\nNomor polisi\t: %s", sewa[i].nopol);
                printf("\nTanggal sewa\t: %d-%d-%d", sewa[i].tglsewa, sewa[i].blnsewa, sewa[i].thnsewa);
                printf("\nDurasi sewa\t: %d hari", sewa[i].durasi);
                printf("\nHarga sewa\t: Rp%d\n", sewa[i].harga);
                out++;
            }

            if(out == 0) printf("\nTidak ada data persewaan yang ditambahkan!\n");
        }
    } else {
        printf("\n[%d]", sewa[indeks].id);
        printf("\nNama penyewa\t: %s", sewa[indeks].namapenyewa);
        printf("\nTipe motor\t: %s", sewa[indeks].tipe);
        printf("\nNomor polisi\t: %s", sewa[indeks].nopol);
        printf("\nTanggal sewa\t: %d-%d-%d", sewa[indeks].tglsewa, sewa[indeks].blnsewa, sewa[indeks].thnsewa);
        printf("\nDurasi sewa\t: %d hari", sewa[indeks].durasi);
        printf("\nHarga sewa\t: Rp%d\n", sewa[indeks].harga);
    }
}

bool baru() { 
    printf("Masukkan nama penyewa: ");
    scanf(" %[^\n]s", &sewa[jumlahSewa].namapenyewa);
    printf("Masukkan tipe motor: ");
    scanf(" %[^\n]s", &sewa[jumlahSewa].tipe);
    printf("Masukkan nomor polisi: ");
    scanf(" %[^\n]s", &sewa[jumlahSewa].nopol);
    printf("Masukkan tanggal sewa (DD): ");
    scanf(" %d", &sewa[jumlahSewa].tglsewa);
    printf("Masukkan bulan sewa (MM): ");
    scanf(" %d", &sewa[jumlahSewa].blnsewa);
    printf("Masukkan tahun sewa (YYYY): ");
    scanf(" %d", &sewa[jumlahSewa].thnsewa);
    printf("Masukkan durasi sewa (dalam hari): ");
    scanf(" %d", &sewa[jumlahSewa].durasi);

    if(!strcmp(sewa[jumlahSewa].tipe, "Beat 125 CC")) sewa[jumlahSewa].harga = 100000*sewa[jumlahSewa].durasi;
    if(!strcmp(sewa[jumlahSewa].tipe, "Vario 150 CC")) sewa[jumlahSewa].harga = 150000*sewa[jumlahSewa].durasi;
    if(!strcmp(sewa[jumlahSewa].tipe, "Aerox")) sewa[jumlahSewa].harga = 200000*sewa[jumlahSewa].durasi;

    printf("Harga sewa: %d\n", sewa[jumlahSewa].harga);
    sewa[jumlahSewa].id = jumlahSewa+1;

    return true;
}
void sorting(int mode){
	int m, i, j;
	if(mode == 1) { //ascending
        for(m=jumlahSewa/2;m>0;m/=2)
        {
            for(j=m;j<jumlahSewa;j++)
            {
                for(i=j-m;i>=0;i-=m)
                {
                    if(strcmp(sewa[i+m].nopol,sewa[i].nopol)>0)
                    break;
                    else
                    {
                        temp = sewa[i];
                        sewa[i] = sewa[i+m];
                        sewa[i+m] = temp;
                    }
                }
            }
        }
    } else if(mode == 2) { // descending
        for(m=jumlahSewa/2;m>0;m/=2)
        {
            for(j=m;j<jumlahSewa;j++)
            {
                for(i=j-m;i>=0;i-=m)
                {
                    if(strcmp(sewa[i+m].nopol,sewa[i].nopol)<0)
                    break;
                    else
                    {
                        temp = sewa[i];
                        sewa[i] = sewa[i+m];
                        sewa[i+m] = temp;
                    }
                }
            }
        }
    }
    
}


int jumpSrc(char nopol[], int n) { 
    
    sorting(1); //sort secara ascending

    int jump = sqrt(n); 
    int previous = 0; 
    
    while (strcmp(sewa[(int)fmin(jump, n)-1].nopol, nopol) < 0) { 
        previous = jump; 
        jump += sqrt(n); 
        if (previous >= n) return -1; 
    } 
  
    while (strcmp(sewa[previous].nopol, nopol) < 0) { 
        previous++; 
        if (previous == (int)fmin(jump, n)) return -1; 
    } 

    if (!strcmp(sewa[previous].nopol, nopol)) return previous; 
    return -1; 
} 

int main() {
    //Menu
    int pilih;
    int i, sortmode;
    char input[20];
    bool run = true;
    char inputNopol[12];
    while(run == true) {
        printf("\n\nDaftar Persewaan Motor\tHarga Sewa \n");
        printf("Beat 125 CC\t\tRp. 100.000/hari \n");
        printf("Vario 150 CC\t\tRp. 150.000/hari \n");
        printf("Aerox\t\t\tRp. 200.000/hari \n\n");
        printf("\n-----PILIH MENU-----\n");
      	printf("1. Tambah persewaan\n2. Tampilkan semua data persewaan\n3. Edit data persewaan\n4. Hapus data persewaan\n5. Urutkan data\n6. Cari Data\n0. Keluar\nPilih: ");
        scanf("%d", &pilih);
        
        switch(pilih){
            case 1:
                system("cls");
                if(input > 0) {
                    if(baru() == true) {
                        printf("Berhasil ditambahkan.\n\n");
                        jumlahSewa++;
                    } else printf("Gagal menambahkan. \n\n");
                } else printf("Input tidak valid \n\n");
                break;
            case 2:
                system("cls");
                if(jumlahSewa > 0) tampilkan(0, 0);
                break;
            case 3:
                system("cls");
                printf("Masukkan nomor polisi dari motor yang akan diedit:\n");
                scanf(" %[^\n]s", &inputNopol);
                edit(inputNopol);
                break;
            case 4:
                system("cls");
                printf("Masukkan nomor polisi dari motor yang akan dihapus:\n");
                scanf(" %[^\n]s", &inputNopol);
                if(hapus(inputNopol) == true) printf("\nData dengan nomor polisi %s berhasil dihapus! \n\n", inputNopol);
                else printf("Tidak dapat menemukan data dengan nomor polisi %s!", inputNopol);
                break;
            case 5:
            	system("cls");
                printf("Masukkan mode pengurutan:\n1. Ascending\n2. Descending\n> ");
                scanf(" %d", &sortmode);
            	sorting(sortmode);
            	printf("\nBerhasil mengurutkan berdasarkan nomor polisi, Silahkan lihat di menu tampilkan semua data. \n\n");
            	break;
            case 6:
                system("cls");
                printf("Masukkan nomor polisi dari kendaraan yang ingin dicari: ");
                scanf(" %[^\n]s", &inputNopol);
                int cari = jumpSrc(inputNopol, jumlahSewa);
                if(cari != -1) {
                    printf("\nHasil pencarian untuk \"%s\": \n", inputNopol);
                    tampilkan(1, cari);

                } else printf("\nTidak ditemukan data dengan nomor polisi \"%s\"\n", inputNopol);
                break;
            case 0:
                return 0;
            default:
                continue;
        }
    }
}
