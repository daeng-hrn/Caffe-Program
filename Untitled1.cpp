#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct menu{	
	char minuman[20], ukuran[20], penyajian[20];
}menuutama[20];

union {
int pilih;
char kembali, pilihan;
}x;

int data, i, harga;

FILE *datapenjualan;

/*
void banner(){
	system("cls");
	printf("-------------------------------------------------\n");
	printf("|\t\t\t\t\t|\n");
	printf("|\t\tCafe Coffe Kita\t\t\t|\n");
	printf("|\t\tKelompok Lima\t\t\t|\n");
	printf("-------------------------------------------------\n\n");
}
*/

int menu(){
	printf("Menu Utama:\n");
	printf("1. Pesan Minuman\n");
	printf("2. View History\n");
	printf("3. Delete History\n");
	printf("4. Keluar\n\n");
	printf("Silakan masukkan pilihan anda: ");
	scanf("%d", &x.pilih);
	fflush(stdin);
	while(x.pilih < 1 || x.pilih > 4){
		printf("Menu yang anda pilih tidak tersedia!\n");
		printf("Silakan masukkan kembali pilihan anda: ");
		scanf("%d", &x.pilih);
		fflush(stdin);
	}
	return x.pilih;
}

void kembalikemenu(){
	printf("\nKembali ke menu utama? (y/n): ");
	scanf("%s", &x.kembali);
	if(x.kembali == 'y' || x.kembali == 'Y'){
		//banner();
		menu();
	} else exit(0);
}

void pemesanan(){

//Menentukan Jumlah Pemesanan
	printf("Masukkan banyaknya Pesanan : ");
            scanf("%d",&data);
			fflush(stdin);
    for(i=1;i<=data;i++)
			{

//Templete
	inputpesanan:
	printf("\nPesanan Ke -%d:\n", i);
	printf("Silahkan Memasukan Pesananmu:\n\n");
	printf("Minuman\t: Kopi, Teh, Coklat, Soda\n");
	printf("Ukuran\t: Kecil, Sedang, Besar\n");
	printf("Cara Penyajian\t: Dingin, Panas, Hangat\n\n");

//Memasukan Jenis Minuman
	printf("Silahkan masukan nama minuman\t: ");
	scanf("%[^\n]",menuutama[i].minuman);
	fflush(stdin);

//Proses Validasi Inputan jenis Minuman
	if (strcmpi(menuutama[i].minuman, "kopi")==0|| strcmpi(menuutama[i].minuman, "teh")==0 || strcmpi(menuutama[i].minuman, "soda")==0 || strcmpi(menuutama[i].minuman, "coklat")==0)
{

//Ukuran Minuman
ukuranminuman:
	printf("Silahkan masukan ukuran minuman\t: ");
	scanf("%[^\n]",menuutama[i].ukuran);
	fflush(stdin);

//Validasi Ukuran
	if (strcmpi(menuutama[i].ukuran, "kecil")==0 || strcmpi(menuutama[i].ukuran, "sedang")==0 || strcmpi(menuutama[i].ukuran, "besar")==0)
{

//Cara Penyajian
carapenyajian:
	printf("Silahkan masukan cara penyajian\t: ");
	scanf("%[^\n]",menuutama[i].penyajian);
	fflush(stdin);

//Validasi Cara Penyajian
if (strcmpi(menuutama[i].penyajian, "dingin")==0 || strcmpi(menuutama[i].penyajian, "panas")==0 || strcmpi(menuutama[i].penyajian, "hangat")==0) {

//Menentukan Harga
harga = strlen(menuutama[i].ukuran) * strlen(menuutama[i].minuman) * strlen(menuutama[i].penyajian) * 100;
}

//Pengembalian Vallidasi Cara Penyajian
else {
	printf ("Input anda salah !\n\n");
	goto carapenyajian;
}
}

//Pengembalian Validasi Ukuran Minuman
	else { printf ("Input anda salah !\n\n");
	goto ukuranminuman;
}

}

//Else dari Validasi Jenis Minuman Jika salah mengembalikan ke Input jenis minuman
	else { printf ("Input anda salah !\n\n");fflush(stdin);
	goto inputpesanan;
}
}
}


void billing(){

datapenjualan = fopen("dataminuman.txt", "a+");
	if(datapenjualan == NULL){
		printf("data tidak dapat dibuka!");
		exit(1);
	}

for(i=1;i<=data;i++)
			{
printf("\nPesanan Ke -%d:\n", i);
printf ("\nNama Minuman : %s\n", menuutama[i].minuman);
printf ("Size : %s\n", menuutama[i].ukuran);
printf ("Penyajian : %s\n", menuutama[i].penyajian);
printf ("Harga : %d\n\n", harga);
printf ("Apakah Pesanan Sudah Sesuai ? : ");
scanf("%s", &x.pilihan);
if(x.pilihan =='y' || x.pilihan =='Y'){

//Proses Memasukan Data ke FILE
fprintf(datapenjualan,"%d#%s#%s#%s#%d\n", i, menuutama[i].minuman, menuutama[i].ukuran, menuutama[i].penyajian, harga);

}
}
kembalikemenu();
}



int main () {
	//banner();
	menu();
		//if (x.pilih == 1)
	pemesanan();
	billing();
}

