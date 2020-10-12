#include <stdio.h>
#include <string.h>
//program menambahkan, menampilkan, mengedit, dan menghapus data menggunakan array of struct
int a=0,b,d,menu=0;
char c[16];
// inisialisasi menu-menu di dalam program
struct data{
	char nama['0'][64];
	char npm['0'][64];
	char prodi['0'][64];
	char angkatan['0'][64];
	char umur['0'][64];
	char jenis_kelamin['0'][64];
	char ipk['0'][64];
}data;
 
void input();
void view();
void update();
void del();

int main(){
	//Menu Utama
	system("cls");
    while(menu!=5){
        printf("\tMAIN MENU\t\n");
		printf("\n[1]. Tambah Mahasiswa ");
		printf("\n[2]. Tampil Data Mahasiswa");
		printf("\n[3]. Update Data Mahasiswa");
		printf("\n[4]. Hapus Data Mahasiswa");
		printf("\n\nInput Pilihan Nomor Menu : ");
        scanf("%d",&menu);
       
        puts("");
        if(menu==1){
            input();
        }else if(menu==2){
            view();
        }else if(menu==3){
            update();
        }else if(menu==4){
            del();
        }else{
            printf("PLIH MENU YANG TERSEDIA");
        }puts("");
    }
    return 0;
}

void input(){
	// menu untuk menambahkan data mahasiswa
	system("cls");
    a=a+1;
    printf("Masukkan Nama		   : ");
    scanf(" %[^\n]s",data.nama[a]);
    printf("Masukkan Npm		   : ");
    scanf("%s",data.npm[a]);
    printf("Masukkan Prodi		   : ");
    scanf("%s",data.prodi[a]);
    printf("Masukkan Tahun Angkatan    : ");
    scanf(" %[^\n]s",data.angkatan[a]);
    printf("Masukkan Umur 		   : ");
    scanf(" %[^\n]s",data.umur[a]);
    printf("Masukkan Jenis Kelamin     : ");
    scanf(" %[^\n]s",data.jenis_kelamin[a]);
    printf("Masukkan Nilai IPK	   : ");
    scanf(" %[^\n]s",data.ipk[a]);
}
 
void view(){
	// menu untuk menampilkan data mahasiswa
	system("cls");
    if(a<1){
        printf("ANDA BELUM INPUT DATA");
    }else{
        b=1;
        while(b<=a){
            printf("%d.Nama             : %s\n",b,data.nama[b]);
            printf("  Npm              : %s\n",data.npm[b]);
            printf("  Prodi            : %s\n",data.prodi[b]);
            printf("  Tahun angkatan   : %s\n",data.angkatan[b]);
            printf("  Umur	           : %s\n",data.umur[b]);
            printf("  Jenis Kelamin    : %s\n",data.jenis_kelamin[b]);
            printf("  Nilai IPK        : %s\n",data.ipk[b]);
            printf("----------\n");
            b++;
        }
    }
}
 
void update(){
	// menu untuk mengubah data mahasiswa
	system("cls");
    printf("Masukkan NPM yang Ingin di Update : ");
    scanf("%s",c);
    b=1;
    d=0;
    while(b<=a && d==0){
        if(strcmp(c,data.npm[b])==0){
            d++;
        }
        b++;
    }
    if(d<1){
        printf("DATA YANG AKAN ANDA UPDATE MUNGKIN TIDAK ADA");
    }else{
        b--;
        printf("%d.Nama             : %s\n",b,data.nama[b]);
        printf("  Npm              : %s\n",data.npm[b]);
        printf("  Prodi            : %s\n",data.prodi[b]);
        printf("  Tahun angkatan   : %s\n",data.angkatan[b]);
        printf("  Umur	           : %s\n",data.umur[b]);
        printf("  Jenis Kelamin    : %s\n",data.jenis_kelamin[b]);
        printf("  Nilai IPK        : %s\n",data.ipk[b]);
        printf("----------\n");
        printf("Masukkan Nama Baru : ");
        scanf(" %[^\n]s",data.nama[b]);
        printf("Masukkan Npm Baru  : ");
        scanf(" %[^\n]s",data.nama[a]);
   		printf("Masukkan Npm      : ");
    	scanf("%s",data.npm[a]);
    	printf("Masukkan Prodi    : ");
   		scanf("%s",data.prodi[a]);
    	printf("Masukkan Tahun Angkatan : ");
    	scanf(" %[^\n]s",data.angkatan[a]);
    	printf("Masukkan Umur : ");
    	scanf(" %[^\n]s",data.umur[a]);
   		printf("Masukkan Jenis Kelamin : ");
    	scanf(" %[^\n]s",data.jenis_kelamin[a]);
    	printf("Masukkan Nilai IPK  : ");
    	scanf(" %[^\n]s",data.ipk[a]);
    }
}
 
void del(){
	// menu untuk menghapus data mahasiswa
	system("cls");
    printf("Masukkan NPM yang Ingin di Delete : ");
    scanf("%s",c);
    b=1;
    d=0;
    while(b<=a && d==0){
        if(strcmp(c,data.npm[b])==0){
            d++;
        }
        b++;
    }
    if(d<1){
        printf("DATA YANG AKAN ANDA DELETE MUNGKIN TIDAK ADA");
    }else{
        b--;
        printf("data %s BERHASIL DI DELETE",data.nama[b]);
        while(b<=a){
            strcpy(data.nama[b],data.nama[b+1]);
            strcpy(data.npm[b],data.npm[b+1]);
            strcpy(data.prodi[b],data.prodi[b+1]);
            strcpy(data.angkatan[b],data.angkatan[b+1]);
            strcpy(data.umur[b],data.umur[b+1]);
            strcpy(data.jenis_kelamin[b],data.jenis_kelamin[b+1]);
            strcpy(data.ipk[b],data.ipk[b+1]);
            b++;
        }
        b--;
        strcpy(data.npm[b],"");
        a--;
    }
}
