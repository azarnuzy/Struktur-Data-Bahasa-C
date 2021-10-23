#include "header.h"
/*Saya Muhammad Azar Nuzy 2004191 mengerjakan soal Kompetisi UTS 2021 C1 dalam 
mata kuliah Struktur Data untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin*/
int main()
{
    /* 
    **L sebagai variabel untuk tipe data list
    **masukanNama = sebagai variabel dari tipe data restoran sebagai masukan dari baris
    **masukanDari = sebagai variabel dari tipedata restoran sebagai masukan dari restoran yang menunya akan dipindah
    **masukanKe = sebagai variabel dari tipedata restoran yang akan menerima menu baru
    **masukaMenu = sebagai variabel dari menuRestoran yang akan 
    **sstart = sebagai variabel untuk menjadi awal dari masukan kolom atau menu dari restoran
    **n: masukan untuk menentukan banyaknya baris yang ada
     */
    list L;
    //menginsialisasi list
    createList(&L);
    int n;
    scanf("%d", &n);
    int i;
    
    restoran masukanNama, masukanDari, masukanKe;
    menuRestoran masukanMenu;

    char sstart[20];
    for(i=0; i<n; i++) {
        scanf("%s %s", sstart, masukanNama.nama);
        //memasukan nama restoran ke dalam baris
        addLastB(masukanNama, &L);
        //mendapatkan nilai dari baris terakhir pada list
        eBaris* row = getLatestBaris(L, masukanNama.nama);
        int cek = 0;
        do {
            scanf("%s", masukanMenu.namaMenu);
            //kondisi jika masukan berupa end maka perulangan akan pindah pada baris selanjutnya
            if(strcmp(masukanMenu.namaMenu, "end") != 0) {
                scanf("%d", &masukanMenu.harga);
                addLastK(masukanMenu, row);
            }else {
                cek = 1;
            }
        }while(cek == 0);
    }
    
    int cek = 0;
    scanf("%s", sstart);
    do {
        scanf("%s", masukanDari.nama);
            //kondisi jika masukan berupa end maka perualngan akan pindah pada baris berikutnya
            if(strcmp(masukanDari.nama, "end") != 0) {
                scanf("%s %s", masukanDari.menuSwitch, masukanKe.nama);
                switchMenu(masukanDari, masukanKe, &L);
            }else {
                cek = 1;
            }
    }while(cek == 0);
    //menampilkan hasil keluaran
    printElement(L);
    return 0;
}