#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "sudoku.h"
/* a kikemmentelt reszek a helyesseg ellenorzese erdekeben vannak beakva, ezzel segitve a fejleszto, vagyis az en munkamat */
void sudoku_osszerak_teszt(FILE *fp, int sudoku[][9], int sudoku_teljes[][9], SudokuListaElem **lista){
    SudokuListaElem *plista=*lista;
    int i,j;
    sudoku_kinullaz(sudoku);
    par_elemet_random_beir(sudoku);
    if(sudoku_megold(sudoku,0,0)){
        sudoku_kiir(sudoku);
        /*fajlba_iras(fp, sudoku);*/
        /*fajlbol_kepernyore(fp, sudoku);*/
        //fajlbol_matrixba(fp, sudoku_teljes);
        fajlba_iras_sudokuteljes(fp, sudoku);
        fajlbol_matrixba_sudokuteljes(fp, sudoku_teljes);
        elemek_letakarasa_nehezsegtol_fuggoen(sudoku, 79);
        fajlba_iras(fp, sudoku);
        /*fajlba_iras_hozzatoldassal(fp, sudoku);*/
        //printf("\n\n");
        /*fajlbol_kepernyore(fp, sudoku);*/
        printf("\n\n");
        sudoku_kiir(sudoku);
        /*printf("\n\n");
        sudoku_megold(sudoku,0,0);
        sudoku_kiir(sudoku);*/
    }
    else printf("\n Hiba! Inditsa ujra a jatekot\n");
}

void sudoku_osszerak_extrakonnyu(FILE *fp, int sudoku[][9], int sudoku_teljes[][9], SudokuListaElem **lista){
    SudokuListaElem *plista=*lista;
    sudoku_kinullaz(sudoku);
    par_elemet_random_beir(sudoku);
    if(sudoku_megold(sudoku,0,0)){
        //sudoku_kiir(sudoku);
        fajlba_iras_sudokuteljes(fp, sudoku);
        /*fajlbol_kepernyore(fp, sudoku);*/
        fajlbol_matrixba_sudokuteljes(fp, sudoku_teljes);
        elemek_letakarasa_nehezsegtol_fuggoen(sudoku, 54);
        fajlba_iras(fp, sudoku);
        //printf("\n\n");
        /*fajlbol_kepernyore(fp, sudoku);*/
        sudokulista_letrehoz(fp, plista, sudoku);
        printf("\n\n");
        /*sudoku_kiir(sudoku);
        printf("\n\n");
        sudoku_megold(sudoku,0,0);
        sudoku_kiir(sudoku);*/
    }
    else printf("\n Hiba! Inditsa ujra a jatekot\n");
}

void sudoku_osszerak_konnyu(FILE *fp, int sudoku[][9], int sudoku_teljes[][9], SudokuListaElem **lista){
    SudokuListaElem *plista=*lista;
    sudoku_kinullaz(sudoku);
    par_elemet_random_beir(sudoku);
    if(sudoku_megold(sudoku,0,0)){
        //sudoku_kiir(sudoku);
        fajlba_iras_sudokuteljes(fp, sudoku);
        fajlbol_matrixba_sudokuteljes(fp, sudoku_teljes);
        elemek_letakarasa_nehezsegtol_fuggoen(sudoku, 32);
        fajlba_iras(fp, sudoku);
        sudokulista_letrehoz(fp, plista, sudoku);
        printf("\n\n");
        /*sudoku_kiir(sudoku);
        printf("\n\n");
        sudoku_megold(sudoku,0,0);
        sudoku_kiir(sudoku);*/
    }
    else printf("\n Hiba! Inditsa ujra a jatekot\n");
}

void sudoku_osszerak_kozepes(FILE *fp, int sudoku[][9], int sudoku_teljes[][9], SudokuListaElem **lista){
    SudokuListaElem *plista=*lista;
    sudoku_kinullaz(sudoku);
    par_elemet_random_beir(sudoku);
    if(sudoku_megold(sudoku,0,0)){
        //sudoku_kiir(sudoku);
        fajlba_iras_sudokuteljes(fp, sudoku);
        fajlbol_matrixba_sudokuteljes(fp, sudoku_teljes);
        elemek_letakarasa_nehezsegtol_fuggoen(sudoku, 25);
        fajlba_iras(fp, sudoku);
        sudokulista_letrehoz(fp, plista, sudoku);
        printf("\n\n");
        /*printf("\n\n");
        sudoku_megold(sudoku,0,0);
        sudoku_kiir(sudoku);*/
    }
    else printf("\n Hiba! Inditsa ujra a jatekot\n");
}

void sudoku_osszerak_nehez(FILE *fp, int sudoku[][9], int sudoku_teljes[][9], SudokuListaElem **lista){
    SudokuListaElem *plista=*lista;
    fajlbol_matrixba_nehezet(fp, sudoku);
    fajlbol_matrixba_nehezteljes(fp, sudoku_teljes);
    sudokulista_letrehoz(fp, plista, sudoku);
    printf("\n\n");
}

void sudoku_osszerak_lehetetlen(FILE *fp, int sudoku[][9], int sudoku_teljes[][9], SudokuListaElem **lista){
    SudokuListaElem *plista=*lista;
    sudoku_kinullaz(sudoku);
    par_elemet_random_beir(sudoku);
    if(sudoku_megold(sudoku,0,0)){
        //sudoku_kiir(sudoku);
        fajlba_iras_sudokuteljes(fp, sudoku);
        fajlbol_matrixba_sudokuteljes(fp, sudoku_teljes);
        elemek_letakarasa_nehezsegtol_fuggoen(sudoku, 16);
        fajlba_iras(fp, sudoku);
        sudokulista_letrehoz(fp, plista, sudoku);
        printf("\n\n");
        /*printf("\n\n");
        sudoku_megold(sudoku,0,0);
        sudoku_kiir(sudoku);*/
    }
    else printf("\n Hiba! Inditsa ujra a jatekot\n");
}

/*void sudoku_osszerak_nehez(FILE *fp, int sudoku[][9], int sudoku_teljes[][9], SudokuListaElem **lista){
    SudokuListaElem *plista=*lista;
    sudoku_kinullaz(sudoku);
    par_elemet_random_beir(sudoku);
    if(sudoku_megold(sudoku,0,0)){
        //sudoku_kiir(sudoku);
        //fajlba_iras_sudokuteljes(fp, sudoku);
        fajlbol_matrixba_nehezteljes(fp, sudoku_teljes);
        elemek_letakarasa_nehezsegtol_fuggoen(sudoku, 20);
        fajlba_iras(fp, sudoku);
        sudokulista_letrehoz(fp, plista, sudoku);
        printf("\n\n");
        /*printf("\n\n");
        if(sudoku_megold(sudoku,0,0))
            sudoku_kiir(sudoku);
        else printf("\n Nincs megoldas! \n");
    }
    else printf("\n Hiba! Inditsa ujra a jatekot\n");
}*/

