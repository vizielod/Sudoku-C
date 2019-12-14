#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "sudoku.h"

void mezoket_kitolt_listaval(/*FILE *fp,*/ int sudoku[][9], SudokuListaElem **lista, int *pszamlalo){
    SudokuListaElem *plista=*lista;
    int sor,oszlop, szam;
    int szamlalo=0;
    printf("Adja meg, hogy melyik helyre szeretne beirni a szamot!\n");
    printf("Szam: ");
    scanf("%d", &szam);
    if(szam>=10){
        lista_vegerol_torol(plista, sudoku);
        utolso_listaelem_kiirasa(plista, sudoku);
        *pszamlalo = *pszamlalo -1;
        //printf("%d\n", *pszamlalo);
    }
    else{
        printf("Sor: ");
        scanf("%d", &sor);
        printf("Oszlop: ");
        scanf("%d", &oszlop);
        sudoku[sor-1][oszlop-1]=szam;
        printf("\n\n");
        lista_vegere_fuz(plista, sudoku);
        utolso_listaelem_kiirasa(plista, sudoku);
        *pszamlalo = *pszamlalo +1;
        //printf("%d\n", *pszamlalo);
    }
}

void mezoket_kitolt(FILE *fp, int sudoku[][9]){
    int sor,oszlop, szam;
    printf("Adja meg, hogy melyik helyre szeretne beirni a szamot!\n");
    printf("Szam: ");
    scanf("%d", &szam);
    printf("Sor: ");
    scanf("%d", &sor);
    printf("Oszlop: ");
    scanf("%d", &oszlop);
    sudoku[sor-1][oszlop-1]=szam;
    //fajlba_iras_hozzatoldassal(fp, sudoku);
    //fajlbol_kepernyore(fp, sudoku);
    printf("\n\n");
    sudoku_kiir(sudoku);
}
