#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "sudoku.h"

void sudoku_kitolt(int sudoku[][9]){
    int i,j;
    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
            sudoku[i][j]=rand()%9+1;
        }
    }
}

void sudoku_kiir(int sudoku[][9]){
    int i,j;
    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
            printf("%d ", sudoku[i][j]);
            if((j+1)%3==0 && j<8)printf("|");
        }
        printf("\n");
        if((i+1)%3==0 && i<8)printf("______|______|______\n");
    }
}

void sudoku_kiir_dinamikusan(int **sudoku){
    int i,j;
    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
            printf("%d ", sudoku[i][j]);
            if((j+1)%3==0 && j<8)printf("|");
        }
        printf("\n");
        if((i+1)%3==0 && i<8)printf("______|______|______\n");
    }
}

void elemek_letakarasa_altalanosan(int sudoku[][9]){
    int x,y,k;
    int mar_ures;
    for(k=0;k<64;k++){
        mar_ures=1;
        while(mar_ures){
            y=rand()%9;
            x=rand()%9;
            mar_ures=0;
            if(sudoku[y][x]==0)
                mar_ures=1;
            else
                sudoku[y][x]=0;
        }
    }

}
/*k parameter adja meg, hogy hany elemet kell toroljunk az adott reszmatrixbol*/
void elemek_letakarasa_3x3(int sudoku[][9], int y, int x, int k){//minden 3x3 reszmatrix bal felso negyzete hatarozza meg az adott reszmatrixot
    int l,a,b;
    //int i,j;
    int mar_ures;
    for(l=0;l<(9-k);l++){
        mar_ures=1;
        while(mar_ures){
            a=rand()%3+y;
            b=rand()%3+x;
            mar_ures=0;
            //for(i=y; i<y+3 && !mar_ures ;i++){
                //for(j=x; j<x+3 && !mar_ures ;j++){
                    if(sudoku[a][b]==0)
                        mar_ures=1;
                //}
            //}
            else
                sudoku[a][b]=0;
        }
    }
}
