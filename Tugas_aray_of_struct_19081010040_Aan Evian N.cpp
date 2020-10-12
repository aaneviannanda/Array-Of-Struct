#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
//program menambahkan, menampilkan, mengedit, dan menghapus data menggunakan array of struct
void menu();
void tambah_mhs();
void tampil_mhs();
void edit_mhs();
void hapus_mhs();
void close();
// inisialisasi menu-menu di dalam program
struct DATA {
	char nama[30];
	int angkatan,nomer;
	char jenis_kelamin[30];
	float nilai[5];
	int total;
	
}tambah,cek,hapus,sort[100],temp;

char index[2];
int main()
{
	system("cls");
	menu();
	return 0;
}
void menu(){
	int pilih;
	menu:
		system("cls");
		printf("\t\tMENU UTAMA\n\n");
		printf("\n1). Tambah Data Mahasiswa Dan Nilai Mahasiswa");
		printf("\n2). Tampil Data Mahasiswa");
		printf("\n3). Hapus Data Mahasiswa");
		printf("\n4). Edit Data Mahasiswa");	
		printf("\n5). Keluar");
		printf("\n\nInput Pilihan Nomor Menu : ");
		scanf("%d", &pilih);
		switch(pilih){
			case 1:tambah_mhs();
				break;
			case 2:tampil_mhs();
				break;	
			case 3:hapus_mhs();
				break;
			case 4:edit_mhs();
				break;
			case 5:close();
				break;
			default:printf("\nMohon Maaf Pilihan Anda Salah !");
				getche();
				goto menu;
		}
}
void tambah_mhs(){
	// menu untuk menambahkan data mahasiswa
	FILE *ptr,*ptr1;
	int count=0;
	
	ptr =fopen("mahasiswa.txt","a");
		system("cls");
		ptr1 =fopen("mahasiswa.txt","r");
		while (fscanf (ptr1,"%d;%[^;];%[^;];%d;%f;%f;%f;%f;%f\n",&tambah.nomer,tambah.nama,tambah.jenis_kelamin,&tambah.angkatan,&tambah.nilai[0],&tambah.nilai[1],&tambah.nilai[2],&tambah.nilai[3],&tambah.nilai[4])!=EOF)
		{
			tambah.nomer++;	
		}
		cek.nomer = tambah.nomer;
		fclose(ptr1);
		printf ("Masukan nama mahasiswa : ");fflush(stdin);
		scanf ("%[^\n]",tambah.nama);
		printf ("Masukan jenis kelamin mahasiswa : ");fflush(stdin);
		scanf ("%[^\n]",tambah.jenis_kelamin);
		printf ("Masukan tahun angkatan : ");fflush(stdin);
		scanf ("%d",&tambah.angkatan); 
		printf("Nilai UTS\t: ");
		scanf("%f",&tambah.nilai[0]);
		printf("Nilai Tugas\t: ");
		scanf("%f",&tambah.nilai[1]);
		printf("Nilai Kuis\t: ");
		scanf("%f",&tambah.nilai[2]);
		printf("Nilai UAS\t: ");
		scanf("%f",&tambah.nilai[3]);
		tambah.nilai[4]=(tambah.nilai[0]+tambah.nilai[1]+tambah.nilai[2]+tambah.nilai[3])/4;
		tambah.total = tambah.nilai[4];
		fprintf(ptr,"%d;%s;%s;%d;%f;%f;%f;%f;%f\n",tambah.nomer,tambah.nama,tambah.jenis_kelamin,tambah.angkatan,tambah.nilai[0],tambah.nilai[1],tambah.nilai[2],tambah.nilai[3],tambah.nilai[4]);
		fclose(ptr);
	
		printf("\n\nData Mahasiswa Sudah Disimpan !");
		add_invalid:
		printf("\n\n\tEnter 1 untuk menu utama dan 0 untuk keluar : ");
		switch(getch()){
    		case '1': menu();
        		break;
        	case '0': close();
        		break;
        	default:printf("\nMaaf Kesalahan Input !");
        		getche();
        		goto add_invalid;
 		}
}
void close(){
}
void tampil_mhs()
// menu untuk menampilkan data mahasiswa
{
	FILE *view;
	view = fopen("mahasiswa.txt","r");
	int test=0;
	system ("cls");
	printf ("NOMER\tNAMA\tJENIS KELAMIN\tANGKATAN\tUTS\tTUGAS\tKUIS\tUAS\n");
	while (fscanf (view,"%d;%[^;];%[^;];%d;%f;%f;%f;%f;%f\n",&tambah.nomer,tambah.nama,tambah.jenis_kelamin,&tambah.angkatan,&tambah.nilai[0],&tambah.nilai[1],&tambah.nilai[2],&tambah.nilai[3],&tambah.nilai[4])!=EOF)
	{
		printf("%d\t%s\t%s\t%d\t\t%.2f\t%.2f\t%.2f\t%.2f\n",tambah.nomer,tambah.nama,tambah.jenis_kelamin,tambah.angkatan,tambah.nilai[0],tambah.nilai[1],tambah.nilai[2],tambah.nilai[3],&tambah.nilai[4]);
		test++;
	}
	printf ("\nJumlah Data Mahasiswa : %d",test);
	fclose(view);
	
	if(test==0)
	{
		system("cls");
		printf ("\nData Kosong ! \n");
	}
	list_invalid:
    printf("\n\nEnter 1 untuk menu utama dan 0 untuk keluar : ");
    switch(getch()){
    	case '1': menu();
        	break;
        case '0': close();
        	break;
        default:printf("\nMaaf Kesalahan Input !");
        	getche();
        	goto list_invalid;
 	}
}
void hapus_mhs()
// Menu untuk menghapus data mahasiswa
{
	FILE *lama, *baru;
	int test=0;
	lama = fopen("mahasiswa.txt","r");
	baru = fopen("baru.txt","w");
	system("cls");
	printf("Input Nomer Mahasiswa yang akan di hapus : ");
	scanf("%d", &hapus.nomer);
	while(fscanf (lama,"%d;%[^;];%[^;];%d;%f;%f;%f;%f;%f\n",&tambah.nomer,tambah.nama,tambah.jenis_kelamin,&tambah.angkatan,&tambah.nilai[0],&tambah.nilai[1],&tambah.nilai[2],&tambah.nilai[3],&tambah.nilai[4])!=EOF)
	{
		if(tambah.nomer != hapus.nomer)
		{
			fprintf(baru,"%d;%s;%s;%d;%f;%f;%f;%f;%f\n",tambah.nomer,tambah.nama,tambah.jenis_kelamin,tambah.angkatan,tambah.nilai[0],tambah.nilai[1],tambah.nilai[2],tambah.nilai[3],&tambah.nilai[4]);	
		}
		else{
			test++;
			printf("\nData Mahasiswa Nomer : %d Dengan Nama : %s\n",tambah.nomer,tambah.nama);
			printf("\nBerhasil dihapus dari Daftar !");
		}
	}
	fclose(lama);
	fclose(baru);
	remove("mahasiswa.txt");
	rename("baru.txt","mahasiswa.txt");
		if(test==0){
            printf("\nData tidak ditemukan !\a\a\a");
            erase_invalid:
            printf("\nInput 0 untuk mencoba lagi, 1 untuk ke menu utama and 2 untuk keluar :");
			switch(getch()){
            	case '0': hapus_mhs();
            		break;
            	case '1': menu();
            		break;
            	case '2': close();
            		break;
            	default:printf("\nMaaf Kesalahan Input !");
            		getche();
            		goto erase_invalid;
			}
    }
    else{
    	erase_valid:
		printf("\nInput 1 untuk ke menu utama and 0 untuk keluar :");
        switch(getch()){
       		case '1': menu();
       			break;
       		case '0': close();
       			break;
       		default:printf("\nMaaf Kesalahan Input !");
        		getche();
        		goto erase_valid;
        }
    }
	
}
void edit_mhs()
// Menu untuk mengedit data mahasiswa
{
	int pilih,test=0;
	FILE *lama,*baru;
	lama = fopen("mahasiswa.txt","r");
	baru = fopen ("baru.txt","w");
	system("cls");
	
	printf ("Masukan Nomer Mahasiswa : ");
	scanf ("%d",&cek.nomer);
	while(fscanf (lama,"%d;%[^;];%[^;];%d;%f;%f;%f;%f;%f\n",&tambah.nomer,tambah.nama,tambah.jenis_kelamin,&tambah.angkatan,&tambah.nilai[0],&tambah.nilai[1],&tambah.nilai[2],&tambah.nilai[3],&tambah.nilai[4])!=EOF)
	{
		if(tambah.nomer == cek.nomer)
		{
			test=1;
			ganti:
				printf("\nNomer : %d dimiliki Mahasiswa dengan Nama : %s",tambah.nomer,tambah.nama);
				printf("\n\nData yang akan diganti : ");
				printf("\n[1]. Nama");
				printf("\n[2]. Jenis Kelamin");
				printf("\n[3]. Angkatan");
				printf("\nInput Pilihan : ");
				scanf("%d",&pilih);
				
				if(pilih == 1)
				{
					printf ("\nMasukan Data Nama Baru : ");fflush(stdin);
					scanf ("%[^\n]",cek.nama);
					strcpy(tambah.nama,cek.nama);
						fprintf(baru,"%d;%s;%s;%d;%f;%f;%f;%f;%f\n",tambah.nomer,tambah.nama,tambah.jenis_kelamin,tambah.angkatan,tambah.nilai[0],tambah.nilai[1],tambah.nilai[2],tambah.nilai[3],&tambah.nilai[4]);
					printf ("\nPerubahan Sudah Disimpan !");
				}
				else if (pilih == 2)
				{
					printf("\nMasukan Data Jenis Kelamin L/P : ");fflush(stdin);
					scanf ("%[^\n]",cek.jenis_kelamin);
					strcpy(tambah.jenis_kelamin,cek.jenis_kelamin);
						fprintf(baru,"%d;%s;%s;%d;%f;%f;%f;%f;%f\n",tambah.nomer,tambah.nama,tambah.jenis_kelamin,tambah.angkatan,tambah.nilai[0],tambah.nilai[1],tambah.nilai[2],tambah.nilai[3],&tambah.nilai[4]);
					printf ("\nPerubahan Sudah Disimpan !");
				}
				else if (pilih == 3)
				{
					printf ("\nMasukan Data Angkatan Baru : ");
					scanf ("%d",&cek.angkatan);
					tambah.angkatan = cek.angkatan;
					fprintf(baru,"%d;%s;%s;%d;%f;%f;%f;%f;%f\n",tambah.nomer,tambah.nama,tambah.jenis_kelamin,tambah.angkatan,tambah.nilai[0],tambah.nilai[1],tambah.nilai[2],tambah.nilai[3],&tambah.nilai[4]);
					printf ("\nPerubahan Sudah Disimpan !");
				}
				else{
					printf("\n\nInput Anda Salah !");
					getche();
					goto ganti;
				}
		}
		else
		{
			fprintf(baru,"%d;%s;%s;%d;%f;%f;%f;%f;%f\n",tambah.nomer,tambah.nama,tambah.jenis_kelamin,tambah.angkatan,tambah.nilai[0],tambah.nilai[1],tambah.nilai[2],tambah.nilai[3],&tambah.nilai[4]);
		}
	}

	fclose(lama);
	fclose(baru);
	remove("mahasiswa.txt");
	rename("baru.txt","mahasiswa.txt");
	if(test!=1){   
		system("cls");
        printf("\nData tidak ditemukan !\a\a\a");
        edit_invalid:
        printf("\nInput 0 untuk mencoba lagi, 1 untuk ke menu utama dan 2 untuk keluar :");
        switch(getch()){
            case '0': edit_mhs();
            	break;
            case '1': menu();
            	break;
            case '2': close();
            	break;
            default:printf("\nMaaf Kesalahan Input !");
            	getche();
            	goto edit_invalid;
        }
    }
    else{
    	edit_valid:
		printf("\n\n\nInput 1 untuk ke menu utama dan 0 untuk keluar :");
        switch(getch()){
        	case '1': menu();
        		break;
        	case '0': close();
        		break;
        	default:printf("\nMaaf Kesalahan Input !");
        		getche();
        		goto edit_valid;
        }
    }
//Sumber Code : https://github.com/igstbagusdharmaputra/crud-bahasa-c/blob/master/file.c
//editor : Aan Evian N
}


