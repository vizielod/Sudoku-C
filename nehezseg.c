#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "sudoku.h"
void elemek_letakarasa_nehezsegtol_fuggoen(int sudoku[][9], int n){

    FILE *fp;
    int masolat[9][9];
    int masolat2[9][9];
    int i,j,y,x;
    int nehezseg=n;
    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
            masolat[i][j]=sudoku[i][j];
        }
    }
    int mar_ures;
    int mentes;
    int db,k=0;
    while(k!=(81-nehezseg)){
        mar_ures=1;
        while(mar_ures){
            y=rand()%9;
            x=rand()%9;
            mar_ures=0;
            if(sudoku[y][x]==0)
                mar_ures=1;
            else{
                for(i=0;i<9;i++){
                    for(j=0;j<9;j++){
                        masolat2[i][j]=sudoku[i][j];
                    }
                }
                mentes=sudoku[y][x];
                masolat2[y][x]=0;
                if(sudoku_megold(masolat2,0,0)){
                    db=0;
                    for(i=0;i<9;i++){
                        for(j=0;j<9;j++){
                            if(masolat[i][j]==masolat2[i][j])
                                db++;//megvizsgalja, hogy a letakaras utani megoldas megegyezike az eredeti matrixxal, mert ha nem, akkor nem lehet letakarni azt az elemet
                        }
                    }
                    if(db==81){
                        k++;
                        sudoku[y][x]=0;
                    }
                    else
                        sudoku[y][x]=mentes;
                }

            }
        }
    }
}

/*void elemek_letakarasa_kozepes(int sudoku[][9]){
    elemek_letakarasa_3x3(sudoku,0,0,3);//sor, oszlop, mennyiseg
    elemek_letakarasa_3x3(sudoku,0,3,3);
    elemek_letakarasa_3x3(sudoku,0,6,3);
    elemek_letakarasa_3x3(sudoku,3,0,3);
    elemek_letakarasa_3x3(sudoku,3,3,3);
    elemek_letakarasa_3x3(sudoku,3,6,3);
    elemek_letakarasa_3x3(sudoku,6,0,3);
    elemek_letakarasa_3x3(sudoku,6,3,3);
    elemek_letakarasa_3x3(sudoku,6,6,3);

}

void elemek_letakarasa_nehez(int sudoku[][9]){
    elemek_letakarasa_3x3(sudoku,0,0,2);//sor, oszlop, mennyiseg
    elemek_letakarasa_3x3(sudoku,0,3,2);
    elemek_letakarasa_3x3(sudoku,0,6,2);
    elemek_letakarasa_3x3(sudoku,3,0,2);
    elemek_letakarasa_3x3(sudoku,3,3,2);printf("\n\n");
        sudoku_megold(sudoku,0,0);
        sudoku_kiir(sudoku);
    elemek_letakarasa_3x3(sudoku,3,6,2);
    elemek_letakarasa_3x3(sudoku,6,0,2);
    elemek_letakarasa_3x3(sudoku,6,3,2);
    elemek_letakarasa_3x3(sudoku,6,6,2);

}

void elemek_letakarasa_extrakonnyu(int sudoku[][9]){
    elemek_letakarasa_3x3(sudoku,0,0,6);//sor, oszlop, mennyiseg
    elemek_letakarasa_3x3(sudoku,0,3,6);
    elemek_letakarasa_3x3(sudoku,0,6,6);
    elemek_letakarasa_3x3(sudoku,3,0,6);
    elemek_letakarasa_3x3(sudoku,3,3,6);
    elemek_letakarasa_3x3(sudoku,3,6,6);
    elemek_letakarasa_3x3(sudoku,6,0,6);
    elemek_letakarasa_3x3(sudoku,6,3,6);
    elemek_letakarasa_3x3(sudoku,6,6,6);

}*/
