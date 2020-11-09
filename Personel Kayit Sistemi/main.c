#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define U 50

typedef struct {
    char ad[U];
    char gorev[U];
    char sehir[U];
    int maas;
}Personel;

void menuYazdir();
void kayitEkle();
void kayitSil();
void kayitGuncelle();
void kayitSorgu();
void kayitOku(Personel p);

int main(int argc, char** argv) {
    printf("-------------------------------------\n");
    printf("[ISCI KAYIT SISTEMI]\n");
    printf("-------------------------------------\n");
    
    int secim;
    
    while(1) {
    menuYazdir();
    scanf("%d",&secim);
    
    switch(secim) {
        case 1:
            kayitEkle();
            break;
        case 2:
            kayitSil();
            break;
        case 3:
            kayitGuncelle();
            break;
        case 4:
            kayitSorgu();
            break;
        case 0:
            printf("Cikis Yapiliyor...");
            return 0;
        default:
            printf("Lutfen Gecerli Bir Islem Seciniz.\n");
            break;
    }
   } 
    
    return (EXIT_SUCCESS);
}
void menuYazdir() {
    printf("\n-------[ANA MENU]-------\n");
    printf("1. Personel Kaydi Olustur\n");
    printf("2. Kayit Sil\n");
    printf("3. Personel Bilgisi Guncelle\n");
    printf("4. Kayit Sorgula\n");
    printf("0. CIKIS\n");
    printf("-------------------------\n");
    printf("Yapmak istediginiz islemi seciniz :");
    
}
void kayitEkle() {
    printf("\n-------[PERSONEL KAYIT EKRANI]-------\n");
    Personel p;
    kayitOku(p);
    char uzantı[5] = ".bin";
    char dosyaAdi[U];
    strcpy(dosyaAdi,(p.ad));
    strcat(dosyaAdi,uzantı);
    
    FILE* filePtr = NULL;
    filePtr = fopen(dosyaAdi,"w");
    
    fwrite(&p, sizeof(Personel),1,filePtr);
    fclose(filePtr);
    printf("\nKayit Basariyla Olusturuldu.\n");
    printf("---------------------------------\n");    
}

void kayitSil() {
    printf("\n-------[KAYIT SILME EKRANI-------]\n");
    
    Personel p;
    printf("Kaydi Silinecek Personelin Adini Giriniz :");
    gets(p.ad);
    fflush(stdin);
    
    char uzantı[5] = ".bin";
    char dosyaAdi[U];
    strcpy(dosyaAdi,(p.ad));
    strcat(dosyaAdi,uzantı);
    FILE* filePtr = NULL;
    filePtr = fopen(dosyaAdi,"r");
        if(filePtr == NULL) {
        printf("%s Dosyasi Bulunamadi.",dosyaAdi);
        return;
        }
    
    fclose(filePtr);
    if(remove(dosyaAdi)==0) {
        printf("\nKayit basariyla silindi.\n");
    }
    printf("-------------------------------------\n");
}

void kayitGuncelle() {
    printf("\n-------[KAYIT GUNCELLEME EKRANI-------]\n");
    Personel p;
    printf("Kaydi Guncellenecek Personelin Adini Giriniz :");
    gets(p.ad);
    fflush(stdin);
    
    char uzantı[5] = ".bin";
    char dosyaAdi[U];
    strcpy(dosyaAdi,(p.ad));
    strcat(dosyaAdi,uzantı);
    
    FILE* filePtr = NULL;
    filePtr = fopen(dosyaAdi,"rb+");
    kayitOku(p);
    
    fwrite(&p,sizeof(Personel),1,filePtr);
    fclose(filePtr);
    printf("Kayit Basariyla Guncellenmistir.\n");
    printf("-------------------------------------\n");
}

void kayitSorgu() {
    printf("-------[KAYIT SORGULAMA EKRANI]-------\n");
    Personel p;
    printf("Kaydi Sorgulanacak Personelin Adini Giriniz :");
    gets(p.ad);
    fflush(stdin);
    
    char uzantı[5] = ".bin";
    char dosyaAdi[U];
    strcpy(dosyaAdi,(p.ad));
    
    strcat(dosyaAdi,uzantı);
    
    FILE* filePtr = NULL;
    filePtr = fopen(dosyaAdi,"r");
    Personel p2;
    fread(&p2,sizeof(Personel),1,filePtr);
    
    printf("-------------------------------------\n");
    puts(p2.ad);
    puts(p2.gorev);
    printf("%d",p2.maas);
    puts(p2.sehir);
    printf("-------------------------------------\n");
}

void kayitOku(Personel p) {
    printf("Personelin adini ve soyadini giriniz : ");
    gets(p.ad);
    fflush(stdin);
    
    printf("Personelin gorevini giriniz : ");
    gets(p.gorev);
    fflush(stdin);
            
    printf("Personelin maasini giriniz : ");
    scanf("%d",&p.maas);
    
    printf("Personelin sehrini giriniz : ");
    scanf("%s",p.sehir);
}