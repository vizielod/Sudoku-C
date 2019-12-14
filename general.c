#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "sudoku.h"

void sudoku_kinullaz(int sudoku[][9]){
    int i,j;
    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
            sudoku[i][j]=0;
        }
    }
}

void par_elemet_random_beir(int sudoku[][9]){
    /* eloszor kitoltom az elso sort random 1-9 ig, ugy hogy ne ismetlodjenek a szamok */
    int i,j;
    int mar_van;
    for(i=0;i<9;i++){
        mar_van=1;
        while(mar_van){
            sudoku[0][i]=rand()%9+1;
            mar_van=0;
            for(j=0;j<i;j++){
                if(sudoku[0][i]==sudoku[0][j])
                    mar_van=1;
            }
        }
    }
}

int megoldase(int sudoku[][9], int y, int x, int szam){
    int sor=(y/3)*3;
    int oszlop=(x/3)*3;
    int i;
    for(i=0;i<9;i++){
        if(sudoku[y][i]==szam)return 0;//az adott sort vizsgalja
        if(sudoku[i][x]==szam)return 0;//az adott oszlopot vizsgalja
        if(sudoku[sor+(i%3)][oszlop+(i/3)]==szam)return 0;//azt a 3x3 mas retmatrixot amelyikbe epp bennevan
    }
    return 1;
}

int sudoku_megold(int sudoku[][9], int y, int x){
    int i;
    if(y<9 && x<9){
        /* ha ki van toltve a mezo, akkor tovabblep a kovetkezore */
        if(sudoku[y][x]!=0){
            if((x+1)<9) return sudoku_megold(sudoku, y, x+1);
            else if((y+1)<9) return sudoku_megold(sudoku, y+1, 0);
            else return 1;
        }
        else{
            /* vegigprobalja 1-9 ig a szamokat, hogy melyik talalna oda */
            for(i=0;i<9;i++){
                if(megoldase(sudoku, y, x, i+1)){
                    sudoku[y][x]=i+1;
                    if(sudoku_megold(sudoku, y, x))
                        return 1;
                    else sudoku[y][x]=0;
                }
            }
        }
        return 0;
    }
    else return 1;
}


