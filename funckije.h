#ifndef FUNCKIJE_H_INCLUDED
#define FUNCKIJE_H_INCLUDED

typedef struct Roba
{
    char naziv[20],proizvodjac[20];
    int cena,stanje_na_lageru;
    int vrsta;


}Roba;

Roba unesi_robu();
void ispis_robe(const Roba r);
void skini_novi_red_sa_kraja(char tekst[]);
int ucitaj_podatke_iz_fajla(Roba niz[],const char naziv_fajla[]);
void ispisi_niz_robe(Roba niz[], int n);
int prikazi_meni();
void snimi_u_fajl(Roba niz[], int n, const char naziv_fajla[]);
void pretraga_po_nazivu_artikla(Roba niz[], int n, char naziv_artikla_pretraga[]);


#endif // FUNCKIJE_H_INCLUDED
