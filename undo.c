#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "sudoku.h"


void sudokulista_letrehoz(FILE *fp, SudokuListaElem **lista, int sudoku[][9]){
    fajlbol_matrixba(fp, sudoku);
    SudokuListaElem *uj= (SudokuListaElem*) malloc (sizeof(SudokuListaElem));
    uj->kov=*lista;
    int i,j;
    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
            uj->sudokutomb[i][j] = sudoku[i][j];
        }
    }

    *lista=uj;

    sudoku_kiir((*lista)->sudokutomb);
}

void lista_vegere_fuz(SudokuListaElem **lista, int sudoku[][9]){
    SudokuListaElem* uj;
    uj=(SudokuListaElem*) malloc (sizeof(SudokuListaElem));
    /* uj listaelem kitoltese adattal */
    int i,j;
    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
            uj->sudokutomb[i][j] = sudoku[i][j];
        }
    }
    uj->kov=NULL;
    if(*lista==NULL)
        *lista=uj;
    else{
        SudokuListaElem* mozgo;
        for(mozgo= *lista; mozgo->kov!=NULL; mozgo=mozgo->kov);
        mozgo->kov=uj;
    }
}


void lista_vegerol_torol(SudokuListaElem **lista, int sudoku[][9]){
    SudokuListaElem* mozgo, *elozo;
    SudokuListaElem* torlendo;
    mozgo=*lista;
    if(mozgo->kov==NULL){
        printf("Nincs ahova visszalepni!\n");

    }
    else{
        while(mozgo->kov!=NULL){
        elozo=mozgo;
        mozgo=mozgo->kov;
        }
        torlendo=mozgo;
        free(torlendo);
        elozo->kov=NULL;
    }
}

void utolso_listaelem_kiirasa(SudokuListaElem **lista, int sudoku[][9]){
    if(*lista==NULL){
        printf("Hello");
    }
    else{
        SudokuListaElem* mozgo;
        for(mozgo=*lista; mozgo->kov!=NULL; mozgo=mozgo->kov);
        sudoku_kiir(mozgo->sudokutomb);
    }
}

void felszabadit(SudokuListaElem **lista){
    SudokuListaElem* mozgo = *lista;
    while(mozgo!=NULL){
        SudokuListaElem *temp = mozgo->kov;
        free(mozgo);
        mozgo=temp;
    }
    *lista=NULL;
}

