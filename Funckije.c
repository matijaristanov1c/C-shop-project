#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funckije.h"

Roba unesi_robu()
{
    Roba r;

    fflush(stdin);

    printf("Unesite naziv: ");
    gets(r.naziv);

    printf("Unesite proizvodjaca: ");
    gets(r.proizvodjac);

    printf("Unesite cenu: ");
    scanf("%d",&r.cena);

    printf("Unesite stanje na lageru: ");
    scanf("%d",&r.stanje_na_lageru);

    printf("Unesite vrstu: (1-hrana,2-pice,3-higijena,4-tehnika,5-stampa)");
    scanf("%d",&r.vrsta);

    return r;

}
void ispis_robe(const Roba r)
{
    printf("\n-----------\n");
    printf("Naziv: %s\n", r.naziv);
    printf("Prozivodjac: %s\n", r.proizvodjac);
    printf("Cena: %d\n", r.cena);
    printf("Stanje na lageru: %d\n", r.stanje_na_lageru);
    if(r.vrsta == 1)
        printf("Hrana\n");
    else if(r.vrsta == 2)
        printf("Pice\n");
    else if(r.vrsta == 3)
        printf("Higijena\n");
    else if(r.vrsta == 4)
        printf("Tehnika\n");
    else if(r.vrsta == 5)
        printf("Stampa\n");
    else
        printf("Pogresno uneta vrsta!\n");

}
void skini_novi_red_sa_kraja(char tekst[])
{
    int n = strlen(tekst);
    if(tekst[n-1] == '\n')
    {
        tekst[n-1] = '\0';
    }
}
int ucitaj_podatke_iz_fajla(Roba niz[],const char naziv_fajla[])
{

    FILE *f = fopen(naziv_fajla,"r");

    if(f == NULL)
    {
        printf("Ne postoji fajl sa tim imenom!");
        return 0;
    }

    int brojac_pozicije = 0;
    while(!feof(f))
    {
        Roba r;

        fgets(r.naziv,20,f);
        fgets(r.proizvodjac,20,f);
        fscanf(f,"%d\n",&r.cena);
        fscanf(f,"%d\n",&r.stanje_na_lageru);
        fscanf(f,"%d\n",&r.vrsta);

        skini_novi_red_sa_kraja(r.naziv);
        skini_novi_red_sa_kraja(r.proizvodjac);

        niz[brojac_pozicije] = r;
        brojac_pozicije++;
    }

    fclose(f);
    return brojac_pozicije;
}

void ispisi_niz_robe(Roba niz[], int n)
{
    for(int i = 0; i < n; i++)
    {
        ispis_robe(niz[i]);
    }
}

int prikazi_meni()
{
    int opcija;
    printf("1- Dodaj novu robu\n");
    printf("2- Ispisi svu robu\n");
    printf("3- Snimi u fajl i zavrsi\n");
    printf("4- Pretraga po nazivu artikla\n");
    printf("5- Najjeftiniji porizvod zadate vrste\n");
    printf("6- Ispis artikla koje treba nabvaviti\n");
    int n = 6;

    scanf("%d", &opcija);
    while(opcija < 1 || opcija > n)
    {
        printf("Pogresan unos!");
        scanf("%d", &opcija);
    }
    return opcija;
}

void snimi_u_fajl(Roba niz[], int n, const char naziv_fajla[])
{
    FILE *f = fopen(naziv_fajla,"w");

    for(int i = 0; i < n; i++)
    {
        printf("Test");
        fprintf(f,"%s\n",niz[i].naziv);
        fprintf(f,"%s\n",niz[i].proizvodjac);
        fprintf(f,"%d\n",niz[i].cena);
        fprintf(f,"%d\n",niz[i].stanje_na_lageru);
        fprintf(f,"%d\n",niz[i].vrsta);
    }

    fclose(f);

}
void pretraga_po_nazivu_artikla(Roba niz[], int n, char naziv_artikla_pretraga[])
{
    int brojac = 0;

    for(int i = 0;i < n; i++)
    {
        if(strcmp(niz[i].naziv,naziv_artikla_pretraga) == 0)
        {
            brojac++;
        }
        printf("%d",brojac);
        ispis_robe(niz[i]);
    }
}
