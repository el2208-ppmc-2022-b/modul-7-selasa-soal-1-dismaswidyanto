/*EL2208 Praktikum Pemecahan Masalah dengan C 2021/2022
*Modul            : 7 - Stacks and Queues
*Percobaan        : -
*Hari dan Tanggal : Selasa, 5 April 2022
*Nama (NIM)       : -
*Asisten (NIM)    : -
*Nama File        : soal-01.c
*Deskripsi        : -
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct book
{
	char author[25];
	char BookTitle[50];
	int BookCheckout;
};

//isi dengan tipe data stack/queue anda

int main()
{
	//template input
	printf("\nMasukkan Perintah: ");
	scanf("%c", ...);

	printf("Masukkan Nama Buku dan Penulis Buku: ");
	
	//template output
	printf("Berikut adalah daftar buku yang akan dipinjam!");

	printf("\nCheckout Buku:\n");
	printf("Checkout Buku Kosong!\n");
	printf("%s by %s", ...,...);

	printf("\nTerimakasih sudah menggunakan layanan Checkout Buku!");


	return 0;
}

