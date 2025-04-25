#ifndef SLL_H
#define SLL_H
#include "boolean.h"
#include <stdio.h>
#define Nil NULL

#define Info(P) (P)->info
#define Next(P) (P)->next
#define First(L) (L).First
#define kt(q) (q)->kt
#define first(q) q->first

typedef char* infotype;
typedef struct tElmtList *address;
typedef struct tElmtList {
	 infotype info;
	 address  next;
	 } ElmtList;


typedef struct city{
	infotype kt;
	address first;
} kota;

/* Definisi list : */
/* List kosong ===> First(L) = Nil */
/* Setiap elemen dengan address P dapat diacu info(P) dan Next(P);  */
/* Elemen terakhir list ===> Jika addressnya Last maka Next(Last) = Nil */
typedef struct {
	  address First;
} List;

/*********** PROTOTYPE ****************/
/**** Predikat untuk test keadaan LIST  ****/
boolean listEmpty (kota q);
/* Mengirim true jika List Kosong */

/**** Konstruktor/Kreator List Kosong ****/
void createList(kota *q);
/* IS : L sembarang */
/* FS : Terbentuk List Kosong */

/**** Manajemen Memory ****/
address alokasi (infotype X);
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address != Nil, 	   */
/*	dan misalnya menghasilkan P, maka Info(P) = X, Next(P) = Nil */
/* Jika alokasi gagal, mengirimkan Nil */

void deAlokasi (address P);
/* IS : P terdefinisi */
/* FS : P dikembalikan ke sistem */
/* Melakukan dealokasi / pengembalian address P ke system */

/**** Pencarian sebuah elemen List ****/
address search (kota q, infotype X);
/* Mencari apakah ada elemen list dengan Info(P) = X */
/* Jika ada, mengirimkan address elemen tsb. */
/* Jika tidak ada, mengirimkan Nil */

boolean fSearch (kota q, address P);
/* Mencari apakah ada elemen list yang beralamat P */
/* Mengirimkan true jika ada, false jika tidak ada */

address searchPrec (kota q, infotype X);
/* Mengirimkan address elemen sebelum elemen yang nilainya = X */
/* Mencari apakah ada elemen list dengan Info(P) = X */
/* Jika ada, mengirimkan address Prec, dengan Next(Prec) = P dan Info(P) = X */
/* Jika tidak ada, mengirimkan Nil */
/* Jika P adalah elemen pertama, maka Prec = Nil */
/* Search dengan spesifikasi seperti ini menghindari */
/* traversal ulang jika setelah Search akan dilakukan operasi lain */

/**** PRIMITIF BERDASARKAN NILAI ****/
/**** Penambahan Elemen ****/
void insVFirst (kota * q, infotype X);
/* IS : L mungkin Kosong */
/* FS : melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */

void insVLast (kota * q, infotype X);
/* IS : L mungkin Kosong */
/* FS : melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir (elemen terakhir adalah yang baru) */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal IS = FS */

/**** Penghapusan Elemen ****/
void delVFirst (kota * q, infotype * X);
/* IS : L TIDAK Kosong */
/* FS : Elemen pertama List dihapus, nilai info disimpan ke X */
/* 	dan alamat elemen pertama di dealokasi */

void delVLast (kota * q, infotype * X);
/* IS : L TIDAK Kosong */
/* FS : Elemen terakhir list dihapus : nilai info disimpan pada X */
/* 	dan alamat elemen terakhir di dealokasi */

/**** PRIMITIF BERDASARKAN ALAMAT ****/
/**** Penambahan elemen berdasarkan alamat ****/
void insertFirst (kota * q, address P);
/* IS : L sembarang, P sudah dialokasi */
/* FS : menambahkan elemen ber-address P sebagai elemen pertama */

void insertAfter (kota * q, address P, address Prec);
/* IS : Prec pastilah elemen List dan bukan elemen terakhir */
/*	P sudah dialokasi */
/* FS : Insert P sebagai elemen sesudah elemen beralamat Prec */

void insertLast (kota * q, address P);
/* IS : L sembarang, P sudah dialokasi */
/* FS : P ditambahkan sebagai elemen terakhir yang baru */

/**** Penghapusan sebuah elemen ****/
void delFirst (kota * q, address * P);
/* IS : L TIDAK kosong */
/* FS : P adalah alamat elemen pertama list sebelum penghapusan */
/*	elemen list berkurang satu (mungkin menjadi kosong) */
/* First elemen yang baru adalah suksessor elemen pertama yang lama */

void delP (kota * q, infotype X);
/* IS : L sembarang */
/* FS : Jika ada elemen list beraddress P, dengan Info(P) = X */
/* 	Maka P dihapus dari list dan di dealokasi */
/* Jika tidak ada elemen list dengan Info(P) = X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */

void delLast (kota * q, address * P);
/* IS : L TIDAK kosong */
/* FS : P adalah alamat elemen terakhir list sebelum penghapusan */
/*	Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last elemen baru adalah predesessor elemen terakhir yang lama, jika ada */

void delAfter (kota * q, address * Pdel, address Prec);
/* IS : L TIDAK Kosong, Prec adalah anggota List */
/* FS : menghapus Next(Prec): Pdel adalah alamat elemen list yang dihapus */

/**** PROSES SEMUA ELEMEN LIST  ****/
void printInfo (kota * q);
/* IS : L mungkin kosong */
/* FS : Jika List tidak kosong, semua info yang disimpan pada elemen list */
/*	diprint. Jika list kosong, hanya menuliskan "List Kosong" */

void delWarga(kota *q, infotype X);

/***************************************/
/*******  PROSES TERHADAP LIST  ********/
/***************************************/

void delAll (kota * q);
/* Delete semua elemen list dan alamat elemen di dealokasi */

#endif
