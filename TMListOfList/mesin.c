#include "header.h"

void createList(list *L){
	(*L).first = NULL;
}

int countElementB(list L){
	int hasil = 0;
	if (L.first != NULL)
	{
		eBaris* bantu;
		bantu = L.first;

		while(bantu != NULL) {
		    hasil++;
		    bantu = bantu->next;
		}
	}

	return hasil;
}

int countElementK(eBaris L){
	int hasil = 0;
	if (L.col != NULL)
	{
		eKolom* bantu;
		bantu = L.col;

		while(bantu != NULL) {
		    hasil++;
		    bantu = bantu->next_kol;
		}
	}

	return hasil;
}

void addFirstB(tim dataTim, list *L){
	eBaris* baru;
	baru = (eBaris*) malloc(sizeof(eBaris));
	//copy data inputan kedalam list
	strcpy(baru->kontainer.nama, dataTim.nama);
	baru->kontainer.tahun = dataTim.tahun;
	baru->col = NULL;
	//jika list masih kosong, isi pointer next dengan NULL
	if ((*L).first == NULL) baru->next = NULL;
	//jika tidak, isi pointer next dengan elemen yang sebelumnya ada dipaling depan
	else baru->next = (*L).first;
	//pindahkan isi pointer baru kedepan
	(*L).first = baru;
	//kosongkan pointer baru agar tidak menjadi jombai
	baru = NULL;
}

void addFirstK(pemain dataPemain, eBaris *L){
	eKolom* baru;
	baru = (eKolom*) malloc(sizeof(eKolom));
	//copy data inputan kedalam list
	strcpy(baru->kontainer_kol.nama_pemain, dataPemain.nama_pemain);
	//jika list masih kosong, isi pointer next dengan NULL
	if ((*L).col == NULL) baru->next_kol = NULL;
	//jika tidak, isi pointer next dengan elemen yang sebelumnya ada dipaling depan
	else baru->next_kol = (*L).col;
	//pindahkan isi pointer baru kedepan
	(*L).col = baru;
	//kosongkan pointer baru agar tidak menjadi jombai
	baru = NULL;
}

void addAfterB(eBaris* prev, tim dataTim){
	eBaris* baru;
	baru = (eBaris*) malloc(sizeof(eBaris));
	//copy data inputan kedalam list
	strcpy(baru->kontainer.nama, dataTim.nama);
	baru->kontainer.tahun = dataTim.tahun;
	baru->col = NULL;
	//jika data berikutnya di list masih kosong, isi pointer baru dengan NULL
	if (prev->next == NULL) baru->next = NULL;
	//jika tidak, isi pointer baru dengan pointer sebelum pointer akhir
	else baru->next = prev->next;
	//isi data di posisi sebelum pointer akhir dengan data yang baru
	prev->next = baru;
	baru = NULL;
}

void addAfterK(eKolom* prev, pemain dataPemain){
	eKolom* baru;
	baru = (eKolom*) malloc(sizeof(eKolom));
	//copy data inputan kedalam list
	strcpy(baru->kontainer_kol.nama_pemain, dataPemain.nama_pemain);
	//jika data berikutnya di list masih kosong, isi pointer baru dengan NULL
	if (prev->next_kol == NULL) baru->next_kol = NULL;
	//jika tidak, isi pointer baru dengan pointer sebelum pointer akhir
	else baru->next_kol = prev->next_kol;
	//isi data di posisi sebelum pointer akhir dengan data yang baru
	prev->next_kol = baru;
	baru = NULL;
}

void addPriorityB(tim dataTim, list *L){
	if (((*L).first == NULL) || (dataTim.tahun < L->first->kontainer.tahun))
	{
		//jika list masih kosong
		addFirstB(dataTim, L);
	}
	else{
		//jika sudah terisi
		/*deklarasikan pointer preview dengan nilai elemen pertama*/
		eBaris* last = (*L).first;
		//cari hingga pointer terakhir
		while((last->next != NULL) && (last->next->kontainer.tahun < dataTim.tahun)) {
		    last = last->next;
		}
		addAfterB(last, dataTim);
	}
}

void addLastK(pemain dataPemain, eBaris *L){
	if ((*L).col == NULL)
	{
		//jika list masih kosong
		addFirstK(dataPemain, L);
	}
	else{
		//jika sudah terisi
		/*deklarasikan pointer preview dengan nilai elemen pertama*/
		eKolom* last = (*L).col;
		//cari hingga pointer terakhir
		while(last->next_kol != NULL) {
		    last = last->next_kol;
		}
		addAfterK(last, dataPemain);
	}
}

void delFirstK(eBaris *L){
	if ((*L).col != NULL)
	{
		/*deklarasikan pointer hapus dengan nilai elemen pertama*/
		eKolom* hapus = (*L).col;
		//jika hanya ada 1 data, kosongkan nilai pointer
		if (countElementK(*L) == 1) (*L).col = NULL;
		//jika lebih, pindahkan nilai elemen pertama ke pointer didepannya dan hapus nilai pointer pertama
		else {
			(*L).col = (*L).col->next_kol;
			hapus->next_kol = NULL;
		}

		// elemen awal sebelumnya dikosongkan
		free(hapus);
	}
}

void delAfterK(eKolom* prev){
	/*deklarasikan pointer hapus dengan nilai elemen setelah posisi yang ditunjuk*/
	eKolom* hapus = prev->next_kol;
	//jika pointer yang ditunjuk tidak kosong
	if (hapus != NULL)
	{
		//jika pointer berikutnya setelah pointer yang ditunjuk kosong, maka hapus pointer tersebut
		if (hapus->next_kol == NULL) prev->next_kol = NULL;
		/*jika tidak, hubungkan posisi pointer yang ditunjuk dengan pointer terakhir di list dan 
		kosongkan pointer diantara kedua pointer tersebut*/
		else{
			prev->next_kol = hapus->next_kol;
			hapus->next_kol = NULL;
		}

		free(hapus);
	}
}

void delLastK(eBaris *L){
	if ((*L).col != NULL)
	{
		//jika isi list hanya 1, lakukan delfirst
		if(countElementK(*L) == 1) delFirstK(L);
		//jika tidak
		else{
			/*deklarasikan pointer terakhir dengan nilai elemen pertama*/
			eKolom* last = (*L).col;
			//deklarasi pointer previews
			eKolom* before_last;
			//cek semua pointer selama pointer belum habis
			while(last->next_kol != NULL) {
				//pindahkan posisi pointer terakhir ke pointer prev
			    before_last = last;
			    //iterasi pointer
			    last = last->next_kol;
			}
			//lakukan delAfter
			delAfterK(before_last);
		}
	}
}

void delAllK(eBaris *L){
	//jika list tidak kosong
	if (countElementK(*L) != 0)
	{
		int i;
		for (i = countElementK(*L); i >= 1; --i)
		{
			//proses penghapusan elemen list
			delLastK(L);
		}
	}
}

void delFirstB(list *L){
	/*jika array terisi*/
	if ((*L).first != NULL)
	{
		/*deklarasikan pointer hapus dengan nilai elemen pertama*/
		eBaris* hapus = (*L).first;

		if (hapus->col != NULL) delAllK(hapus);
		//jika hanya ada 1 data, kosongkan nilai pointer
		if (countElementB(*L) == 1) (*L).first = NULL;
		//jika lebih, pindahkan nilai elemen pertama ke pointer didepannya dan hapus nilai pointer pertama
		else {
			(*L).first = (*L).first->next;
			hapus->next = NULL;
		}

		// elemen awal sebelumnya dikosongkan
		free(hapus);
	}
}

void delAfterB(eBaris* prev){
	/*deklarasikan pointer hapus dengan nilai elemen setelah posisi yang ditunjuk*/
	eBaris* hapus = prev->next;
	//jika pointer yang ditunjuk tidak kosong
	if (hapus != NULL)
	{
		if (hapus->col != NULL) delAllK(hapus);
		//jika pointer berikutnya setelah pointer yang ditunjuk kosong, maka hapus pointer tersebut
		if (hapus->next == NULL) prev->next = NULL;
		/*jika tidak, hubungkan posisi pointer yang ditunjuk dengan pointer terakhir di list dan 
		kosongkan pointer diantara kedua pointer tersebut*/
		else prev->next = hapus->next;
		hapus->next = NULL;

		free(hapus);
	}
}
void delLastB(list *L){
	//jika list tidak kosong
	if ((*L).first != NULL)
	{
		//jika isi list hanya 1, lakukan delfirst
		if(countElementB(*L) == 1) delFirstB(L);
		//jika tidak
		else{
			/*deklarasikan pointer terakhir dengan nilai elemen pertama*/
			eBaris* last = (*L).first;
			//deklarasi pointer previews
			eBaris* before_last;
			//cek semua pointer selama pointer belum habis
			while(last->next != NULL) {
				//pindahkan posisi pointer terakhir ke pointer prev
			    before_last = last;
			    //iterasi pointer
			    last = last->next;
			}
			//lakukan delAfter
			delAfterB(before_last);
		}
	}
}

void delAllB(list *L){
	//jika list tidak kosong
	if (countElementB(*L) != 0)
	{
		int i;
		for (i = countElementB(*L); i >= 1; --i)
		{
			//proses penghapusan elemen list
			delLastB(L);
		}
	}
}
/*gunakan fungsi ini untuk mendapatkan elemen baris yang terakhir diinputkan*/
eBaris* getLatestBaris(list L, char nama[]){
	/*inisialisasi dan cek jika listnya tidak kosong, nilai tunjuk jadi elemen baris pertama*/
	eBaris* tunjuk = NULL;
	if (L.first != NULL)
	{
		tunjuk = L.first;
		/*perulangan selama bukan null dan bukan nama yang dicari*/
		while((tunjuk != NULL) && (strcmp(tunjuk->kontainer.nama, nama) != 0)) {
		    tunjuk = tunjuk->next;
		}
	}

	return tunjuk;
}

void printElement(list L){
	if (L.first != NULL)
	{
		eBaris* bantu = L.first;

		while(bantu != NULL) {
		    printf("%s %d\n", bantu->kontainer.nama, bantu->kontainer.tahun);
		    
		    eKolom* eCol = bantu->col;

		    while(eCol != NULL) {
		        printf("- %s\n", eCol->kontainer_kol.nama_pemain);

		        eCol = eCol->next_kol;
		    }
		    printf("==================\n");

		    bantu = bantu->next;
		}
	}
	else printf("list kosong\n");
}