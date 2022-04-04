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

typedef struct node_stack
{
	struct node_stack *nextNode;
	struct book bookData;

} node;

typedef struct stack_Checkout
{
	struct node_stack *top;

} stack;

int isEmptyCheckout(stack *Checkout)
{
	return (Checkout->top == NULL ? 1 : 0);
}
void push(stack *Checkout, struct book _bookData)
{
	node *newNode;
	newNode = malloc(sizeof(struct node_stack));
	newNode->bookData = _bookData;
	newNode->nextNode = Checkout->top;
	Checkout->top = newNode;
}
void showCheckout(stack *Checkout)
{

	node *tmp;
	int i = 0;
	tmp = Checkout->top;

	printf("\nCheckout Buku:\n");
	if (isEmptyCheckout(Checkout))
	{
		printf("Checkout Buku Kosong!\n");
		return;
	}
	//Reverse Stack
	stack *reversed_display;
	reversed_display = malloc(sizeof(stack));
	reversed_display->top = NULL;
	while (tmp != NULL)
	{
		push(reversed_display, tmp->bookData);
		tmp = tmp->nextNode;
	}

	//Tampilkan Stack
	tmp = reversed_display->top;
	while (tmp != NULL)
	{
		printf("%s by %s", tmp->bookData.author,tmp->bookData.BookTitle);
		tmp = tmp->nextNode;
		i++;
	}
}

void pop(stack *Checkout)
{
	node *tmp;
	tmp = Checkout->top;
	Checkout->top = tmp->nextNode;

	free(tmp);
}

int main()
{
	stack *currCheckout;
	char *token;
	struct book bookBuf;
	char str[75];
	currCheckout = (stack *)malloc(sizeof(stack));

	// PENTING!!! INISIALISASI
	currCheckout->top = NULL;

	char cmd = 'X';
	int bookId = 0;
	int nowIndex = -1;
	int numOfbook = 0;

	while (cmd != 'E')
	{
		printf("\nMasukkan Perintah: ");
		scanf("%c", &cmd);

		// ADD BUKU
		if (cmd == 'A')
		{
			printf("Masukkan Nama Buku dan Penulis Buku: ");
			scanf("%s[^\n]",str);
		//	char ch = '\n';
		//	strncat(str,&ch,1);
			printf("%s\n",str);
			token = strtok(str, ",");
			strcpy(bookBuf.author, token);
			token = strtok(NULL, ",");
			strcpy(bookBuf.BookTitle, token);
			bookBuf.BookCheckout = bookId;
			bookId++;
			push(currCheckout, bookBuf);
		}

		// Delete Top of the Checkout
		if (cmd == 'D')
		{
			pop(currCheckout);
			bookId--;
		}
		if (cmd == 'S')
		{
			showCheckout(currCheckout);
		}
		
		if (cmd == 'C')
		{
			printf("Berikut adalah daftar buku yang akan dipinjam!");
			showCheckout(currCheckout);
			
			cmd = 'E';
		}
		
		// Clear buffer
        	getchar();
        	getchar();
	}
	printf("\nTerimakasih sudah menggunakan layanan Checkout Buku!");
	return 0;
}


