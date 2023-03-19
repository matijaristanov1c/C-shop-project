#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funckije.h"

int main()
{
    Roba niz[100];

    int n = ucitaj_podatke_iz_fajla(niz,"ulaz.txt");
    ///ispisi_niz_robe(niz,n);


    while(1)
    {
        int odabir = prikazi_meni();
        if(odabir == 1) /// dodaj novi
        {
            niz[n] = unesi_robu();
            n++;
        }
        else if(odabir == 2) /// ispisi sve
        {
            ispisi_niz_robe(niz,n);
        }
        else if(odabir == 3) /// sacuvaj u fajl
        {
            snimi_u_fajl(niz,n,"ulaz.txt");
            break;
        }
        else if(odabir == 4) /// Pretraga po nazivu
        {
            char trazeni_naziv[50];
            fflush(stdin);

            printf("Unesite naziv koji zelite: ");
            gets(trazeni_naziv);

            pretraga_po_nazivu_artikla(niz,n,trazeni_naziv);
        }
        else if(odabir == 5) /// Trazenje najjeftinijeg
        {

        }
        else if(odabir == 6) /// Ispis artikla koje treba nabaviti
        {

        }
    }
}
