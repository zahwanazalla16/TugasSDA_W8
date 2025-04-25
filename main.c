#include <stdio.h>
#include <stdlib.h> 
#include "SLL.h"
#include <string.h>

// Untuk fungsi system("pause") di Windows

int main()
{
    /* Kamus Lokal */
    int choice;
    char input[100], input2[100]; // Variabel untuk menyimpan input pengguna
    infotype isi;
    address P;

    /* Inisialisasi kota */
    int jmlKota = 5;
    kota namaKota[jmlKota];

    // Menyiapkan jumlah kota
    for (int i = 0; i < jmlKota; i++)
    {
        createList(&namaKota[i]);
    }

    // Menambah Nama kota
    namaKota[0].kt = (char *)"Bandung";
    namaKota[1].kt = (char *)"Jakarta";
    namaKota[2].kt = (char *)"Malang";
    namaKota[3].kt = (char *)"Cimahi";
    namaKota[4].kt = (char *)"Padalarang";
    
    
    // Menambah List di awal 
	insVFirst (&namaKota[0], (char *) "zahwa");
	insVFirst (&namaKota[1], (char *) "faridha");
	insVFirst (&namaKota[2], (char *) "suci");
	insVFirst (&namaKota[3], (char *) "hilmi");
	insVFirst (&namaKota[4], (char *) "maul");


    do
    {
        system("cls");
		int i;
        printf("\n=================================\n");
        printf("        DATA KOTA & WARGA        \n");
        printf("=================================\n");
        for (i = 0; i < jmlKota; i++)
        {
            printInfo(&namaKota[i]);
        }     
        printf("=================================\n");
        printf("             M E N U            \n");
        printf("=================================\n");
        printf("1. Delete Kota\n");
        printf("2. Entry Kota\n");
        printf("3. Delete Warga\n");
        printf("4. Entry Warga\n");
        printf("0. Exit\n");
        printf("Pilih menu: ");
        scanf("%d", &choice);
        printf("=================================\n");

        switch (choice)
        {
        	
        case 0:
            printf("Terima kasih telah menggunakan program ini.\n");
            break;
            
		case 1:
		{
		    int j;
			char cityName[50];
		    printf("Masukkan nama kota yang ingin dihapus: ");
		    scanf("%s", cityName);
		    for (i = 0; i < jmlKota; i++)
		    {
		        if (strcmp(namaKota[i].kt, cityName) == 0)
		        {
		            delAll(&namaKota[i]);
		            printf("Kota %s berhasil dihapus.\n", cityName);
		            // Menggeser array untuk menutupi kota yang dihapus
		            for (j = i; j < jmlKota - 1; j++) {
		                namaKota[j] = namaKota[j+1];
		            }
		            jmlKota--; // Mengurangi jumlah kota karena ada satu kota yang dihapus
		            break;
		        }
		    }
		    break;
		}
		
        case 2:
            printf("Masukkan nama kota yang ingin ditambahkan: ");
            scanf("%s", input);
            jmlKota++;
            namaKota[jmlKota - 1].kt = (char *)malloc(strlen(input) + 1);
            strcpy(namaKota[jmlKota - 1].kt, input);
            createList(&namaKota[jmlKota - 1]);
            printf("Kota %s berhasil ditambahkan.\n", input);
            break;
            
        case 3:
			{
			    char warga[50];
			    char kotaWarga[50];
			    printf("Masukkan nama warga yang ingin dihapus: ");
			    scanf("%s", warga);
			    printf("Masukkan nama kota tempat tinggal warga: ");
			    scanf("%s", kotaWarga);
			    for (int i = 0; i < jmlKota; i++)
			    {
			        if (strcmp(namaKota[i].kt, kotaWarga) == 0)
			        {
			            delWarga(&namaKota[i], warga);
			            printf("Warga %s berhasil dihapus dari Kota %s.\n", warga, kotaWarga);
			            break;
			        }
			    }
			    break;
			}
            break;
            
		case 4:
		    char targetCity[50];
		    printf("Masukkan nama kota tempat tinggal warga yang ingin ditambahkan: ");
		    scanf("%s", targetCity);
		    for (int i = 0; i < jmlKota; i++) {
		        if (strcmp(namaKota[i].kt, targetCity) == 0) {
		            char* newCitizen = (char*)malloc(50 * sizeof(char)); // Alokasikan memori dinamis untuk nama warga baru
		            if (newCitizen == NULL) {
		                printf("Gagal mengalokasikan memori.\n");
		                break;
		            }
		            printf("Masukkan nama warga yang ingin ditambahkan ke Kota %s: ", targetCity);
		            scanf("%s", newCitizen); // Simpan nama warga ke dalam memori yang dialokasikan
		            insVFirst(&namaKota[i], newCitizen);
		            printf("Warga %s berhasil ditambahkan ke Kota %s.\n", newCitizen, targetCity);
		            break;
		        }
		        // Jika kota tidak ditemukan
		        if (i == jmlKota - 1) {
		            printf("Kota %s tidak ditemukan.\n", targetCity);
		        }
		    }
		    break;
		    
        default:
            printf("Menu tidak valid.\n");
            break;
        }

    } while (choice != 0);

    return 0;
}


