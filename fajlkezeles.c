#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "sudoku.h"

void fajlba_iras(FILE *fp, int sudoku[][9]){
    int i,j;
    fp = fopen("sudoku.txt", "wt+");
    if(fp==NULL){
        perror("sudoku.txt megnyitasa");
        return;
    }
    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
            fprintf(fp, "%d ", sudoku[i][j]);
        }
        fprintf(fp, "\n");
    }
    fprintf(fp, "\n\n");
    fclose(fp);
}

void fajlba_iras_sudokuteljes(FILE *fp, int sudoku[][9]){
    int i,j;
    fp = fopen("sudokuteljes.txt", "wt+");
    if(fp==NULL){
        perror("sudokuteljes.txt megnyitasa");
        return;
    }
    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
            fprintf(fp, "%d ", sudoku[i][j]);
        }
        fprintf(fp, "\n");
    }
    fprintf(fp, "\n\n");
    fclose(fp);
}

void fajlbol_kepernyore(FILE *fp, int sudoku[][9]){
    fp = fopen("sudoku.txt", "rt");
    if(fp==NULL){
        perror("sudoku.txt megnyitasa");
        return;
    }
    int i,j;
    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
            fscanf(fp, "%d", &sudoku[i][j]);
        }
    }
    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
            printf("%d ", sudoku[i][j]);
            if((j+1)%3==0 && j<8)printf("|");
        }
        printf("\n");
        if((i+1)%3==0 && i<8)printf("______|______|______\n");
    }


    fclose(fp);
}

void fajlbol_kepernyore_nehezet(FILE *fp, int sudoku[][9]){
    fp = fopen("nehez.txt", "rt");
    if(fp==NULL){
        perror("nehez.txt megnyitasa");
        return;
    }
    int i,j;
    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
            fscanf(fp, "%d", &sudoku[i][j]);
        }
    }
    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
            printf("%d ", sudoku[i][j]);
            if((j+1)%3==0 && j<8)printf("|");
        }
        printf("\n");
        if((i+1)%3==0 && i<8)printf("______|______|______\n");
    }


    fclose(fp);
}

void fajlba_iras_hozzatoldassal(FILE *fp, int sudoku[][9]){
    int i,j;
    fp = fopen("sudoku.txt", "at+");
    if(fp==NULL){
        perror("sudoku.txt megnyitasa");
        return;
    }
    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
            fprintf(fp, "%d ", sudoku[i][j]);
        }
        fprintf(fp, "\n");
    }
    fprintf(fp, "\n\n");
    fclose(fp);
}

void fajlbol_matrixba(FILE *fp, int sudoku[][9]){
    int i,j;
    fp = fopen("sudoku.txt", "rt");
    if(fp==NULL){
        perror("sudoku.txt megnyitasa");
        return;
    }
    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
            fscanf(fp, "%d", &sudoku[i][j]);
        }
    }
    fclose(fp);
}

void fajlbol_matrixba_sudokuteljes(FILE *fp, int sudoku[][9]){
    int i,j;
    fp = fopen("sudokuteljes.txt", "rt");
    if(fp==NULL){
        perror("sudokuteljes.txt megnyitasa");
        return;
    }
    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
            fscanf(fp, "%d", &sudoku[i][j]);
        }
    }
    fclose(fp);
}

void fajlbol_matrixba_nehezteljes(FILE *fp, int sudoku[][9]){
    int i,j;
    fp = fopen("nehezteljes.txt", "rt");
    if(fp==NULL){
        perror("nehezteljes.txt megnyitasa");
        return;
    }
    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
            fscanf(fp, "%d", &sudoku[i][j]);
        }
    }
    fclose(fp);
}

void fajlbol_matrixba_nehezet(FILE *fp, int sudoku[][9]){
    int i,j;
    fp = fopen("nehez.txt", "rt");
    if(fp==NULL){
        perror("nehez.txt megnyitasa");
        return;
    }
    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
            fscanf(fp, "%d", &sudoku[i][j]);
        }
    }
    fclose(fp);
}

