#include <limits.h>
#include <malloc.h>
#include <string.h>
#include "SLL.h"

/********** BODY SUB PROGRAM ***********/
/**** Predikat untuk test keadaan LIST  ****/
boolean listEmpty (kota q)
/* Mengirim true jika List Kosong */
{
	 return (q.first == Nil);
}

/**** Konstruktor/Kreator List Kosong ****/
void createList(kota *q)
/* IS : L sembarang */
/* FS : Terbentuk List Kosong */
{
	q->first = Nil;
}

/**** Manajemen Memory ****/
address alokasi (infotype X)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address != Nil, 	   */
/*	dan misalnya menghasilkan P, maka Info(P) = X, Next(P) = Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
	 /* Kamus Lokal */
	 address P;
	 /* Algoritma */
	 P = (address) malloc (sizeof (ElmtList));
	 if (P != Nil)		/* Alokasi berhasil */
	 {
	Info(P) = X;
	Next(P) = Nil;
	 }
	 return (P);
}

void deAlokasi (address P)
/* IS : P terdefinisi */
/* FS : P dikembalikan ke sistem */
/* Melakukan dealokasi / pengembalian address P ke system */
{
	 if (P != Nil)
	 {
	free (P);
	 }
}

/**** Pencarian sebuah elemen List ****/
address search (kota q, infotype X)
/* Mencari apakah ada elemen list dengan Info(P) = X */
/* Jika ada, mengirimkan address elemen tsb. */
/* Jika tidak ada, mengirimkan Nil */
/* Menggunakan variabel bertype boolean */
{
	 /* Kamus Lokal */
	 address P;
	 boolean found =  false;
	 /* algoritma */
	 P = q.first;
	 while ((P != Nil) && (!found))
	 {
	if (Info(P) == X)
	{	found = true; 	}
	else
	{	P = Next(P);	}
	 }	/* P = Nil atau Ketemu */
	 return (P);
}	

boolean fSearch (kota q, address P)
/* Mencari apakah ada elemen list yang beralamat P */
/* Mengirimkan true jika ada, false jika tidak ada */
{
	 /* Kamus Lokal */
	 boolean found=false;
	 address PSearch;
	 /* Algortima */
	 PSearch = q.first;
	 while ((PSearch != Nil) && (!found))
	 {
	if (PSearch == P)
	{	found = true; 	}
	else
	{	PSearch = Next(PSearch);	}
	 }	/* PSearch = Nil atau Ketemu */
	 return (found);
}

address searchPrec (kota q, infotype X)
/* Mengirimkan address elemen sebelum elemen yang nilainya = X */
/* Mencari apakah ada elemen list dengan Info(P) = X */
/* Jika ada, mengirimkan address Prec, dengan Next(Prec) = P dan Info(P) = X */
/* Jika tidak ada, mengirimkan Nil */
/* Jika P adalah elemen pertama, maka Prec = Nil */
/* Search dengan spesifikasi seperti ini menghindari */
/* traversal ulang jika setelah Search akan dilakukan operasi lain */
{
	 /* Kamus Lokal */
	address Prec, P;
	boolean found=false;
	 /* Algoritma */
	Prec = Nil;
	P = q.first;
	while ((P != Nil) && (!found))
	{
		 if (Info(P) == X)
		 {	found = true;	}
		 else
		 {
		Prec = P;
		P = Next(P);
		 }
	}    /* P = Nil atau Ketemu */
	if (found)
	{	return (Prec);		}
	else
	{	return (Nil);		}
}

/**** PRIMITIF BERDASARKAN NILAI ****/
/**** Penambahan Elemen ****/
void insVFirst (kota * q, infotype X)
/* IS : L mungkin Kosong */
/* FS : melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
{
	 /* Kamus Lokal */
	address P;
	 /* Aloritma */
	P = alokasi (X);
	if (P != Nil)
	{	insertFirst (&(*q), P);		}
} 

void insVLast (kota * q, infotype X)
/* IS : L mungkin Kosong */
/* FS : melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir (elemen terakhir adalah yang baru) */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal IS = FS */
{
	 /* Kamus Lokal */
	address P;
	 /* Algoritma */
	P = alokasi (X);
	if (P != Nil)
	{	insertLast (&(*q), P);		}
}

/**** Penghapusan Elemen ****/
void delVFirst (kota * q, infotype * X)
/* IS : L TIDAK Kosong */
/* FS : Elemen pertama List dihapus, nilai info disimpan ke X */
/* 	dan alamat elemen pertama di dealokasi */
{
	 /* Kamus Lokal */
	address P;
	 /* Algoritma */
	P = first(q);
		  *X = Info(P);
	first(q) = first(q)->next;
	deAlokasi (P);
}

void delVLast (kota * q, infotype * X)
/* IS : L TIDAK Kosong */
/* FS : Elemen terakhir list dihapus : nilai info disimpan pada X */
/* 	dan alamat elemen terakhir di dealokasi */
{
	 /* Kamus Lokal */
	address PDel;
	 /* Algoritma */
	PDel = first(q);
	delLast (&(*q), &PDel);
	(*X) = Info(PDel);
	deAlokasi (PDel);
}

/**** PRIMITIF BERDASARKAN ALAMAT ****/
/**** Penambahan elemen berdasarkan alamat ****/
void insertFirst (kota * q, address P)
/* IS : L sembarang, P sudah dialokasi */
/* FS : menambahkan elemen ber-address P sebagai elemen pertama */
{	
	 Next(P) = q->first;
	 q->first = P;
}

void insertAfter (kota * q, address P, address Prec)
/* IS : Prec pastilah elemen List dan bukan elemen terakhir */
/*	P sudah dialokasi */
/* FS : Insert P sebagai elemen sesudah elemen beralamat Prec */
{
	 Next(P) = Next(Prec);
	 Next(Prec) = P;
}

void insertLast (kota * q, address P)
/* IS : L sembarang, P sudah dialokasi */
/* FS : P ditambahkan sebagai elemen terakhir yang baru */
{
	 /* Kamus Lokal */
	address Last;
	 /* Algoritma */
	if (q->first != Nil)
	{
		 Last = q->first;
		 while (Next(Last) != Nil)
		 {	Last = Next(Last); 	}
		 Next(Last) = P;
	}
		else
	{	q->first = P;		}
}

/**** Penghapusan sebuah elemen ****/
void delFirst (kota * q, address * P)
/* IS : L TIDAK kosong */
/* FS : P adalah alamat elemen pertama list sebelum penghapusan */
/*	elemen list berkurang satu (mungkin menjadi kosong) */
/* First elemen yang baru adalah suksessor elemen pertama yang lama */
{
	 *P = first(q);
	 first(q) = first(q)->next;
}


void delP (kota * q, infotype X)
/* IS : L sembarang */
/* FS : Jika ada elemen list beraddress P, dengan Info(P) = X */
/* 	Maka P dihapus dari list dan di dealokasi */
/* Jika tidak ada elemen list dengan Info(P) = X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
{
	 /* Kamus Lokal */
	address P, Prec;
	boolean found=false;
	 /* Algoritma */
		Prec = Nil;
	P = first(q);
	while ((P != Nil) && (!found))
	{
		 if (Info(P) == X)
		 {	found = true;	}
		 else
		 {
		Prec = P;
		P = Next(P);
		 }
	} /* P = Nil Atau Ketemu */

	if (found)
	{
		 if (Prec == Nil && Next(P) == Nil)		/* Hanya 1 elemen */
		 {	first(q) = Nil;	}
		 else if (Prec == Nil)			/* Ketemu di elemen 1*/
		 {	first(q) = Next(P);	}
		 else		/* Ketemu di elemen list yang ditengah/akhir */
		 {	Next(Prec) = Next(P);	}
		 Next(P) = Nil;
		 deAlokasi (P);
	}
}

void delLast (kota * q, address * P)
/* IS : L TIDAK kosong */
/* FS : P adalah alamat elemen terakhir list sebelum penghapusan */
/*	Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last elemen baru adalah predesessor elemen terakhir yang lama, jika ada */
{
	 /* Kamus Lokal */
	address Prec;
	 /* Algoritma */
	*P = first(q);
	Prec = Nil;
	while (Next(*P) != Nil)
	{
		 Prec = *P;
		 *P = Next (*P);
	}

	if (Prec == Nil)	/* Hanya 1 elemen */
	{	first(q) = Nil;	}
	else	/* List Lebih dari 1 elemen */
	{	Next(Prec) = Nil;	}
}	

void delAfter (kota * q, address * Pdel, address Prec)
/* IS : L TIDAK Kosong, Prec adalah anggota List */
/* FS : menghapus Next(Prec): Pdel adalah alamat elemen list yang dihapus */
{
	 *Pdel = Next(Prec);
	 if (Pdel != Nil)
	 {
	Next(Prec) = Next(*Pdel);
	Next(*Pdel) = Nil;
	 }
}

/**** PROSES SEMUA ELEMEN LIST  ****/
void printInfo (kota * q)
/* IS : L mungkin kosong */
/* FS : Jika List tidak kosong, semua info yang disimpan pada elemen list */
/*	diprint. Jika list kosong, hanya menuliskan "List Kosong" */
{
	 /* Kamus Lokal */
	address P;
	printf("Kota %s : ",kt(q));
	P = first(q);
	
	if (P == Nil)
	{
		 printf ("List Kosong .... \a\n");
	}
	else	/* List memiliki elemen */
	{
		 for (;;)
		 {
		if (P == Nil)
		{
			 printf("\n");
			 break;
		}
		else	/* Belum berada di akhir List */
		{
			 printf ("%s ", Info(P));
			 P = Next(P);
		}
		 }
	}
	printf("\n");
}

void delAll (kota * q)
/* Delete semua elemen list dan alamat elemen di dealokasi */
{
	 /* Kamus Lokal */
	address PDel;
	 /* Algoritma */
	PDel = first(q);
	while (PDel != Nil)
	{
		 delFirst (&(*q), &PDel);
		 deAlokasi (PDel);
		 PDel = first(q);
	}
	first(q) = NULL;
}

void delWarga(kota *q, infotype X)
/* IS : L sembarang */
/* FS : Jika ada warga dengan nama X, maka warga tersebut dihapus dari list */
/* Jika tidak ada warga dengan nama X, tidak ada perubahan pada list */
{
    address PDel, Prec;
    boolean found = false;

    Prec = Nil;
    PDel = first(q);

    // Cari warga dengan nama X
    while (PDel != Nil && !found)
    {
        if (strcmp(Info(PDel), X) == 0)
        {
            found = true;
        }
        else
        {
            Prec = PDel;
            PDel = Next(PDel);
        }
    }

    if (found)
    {
        if (Prec == Nil) // Warga yang akan dihapus adalah elemen pertama
        {
            delFirst(q, &PDel);
        }
        else
        {
            delAfter(q, &PDel, Prec);
        }
        deAlokasi(PDel);
    }
}
