#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "sudoku.h"

int main()
{
    FILE *fp;
    srand(time(0));
    int sudoku[9][9];
    SudokuListaElem *lista=NULL;
    /* tesztmatrix a megoldo fuggveny helyes futasanak vizsgalatara */
    /*int sudoku2[9][9]={{0, 0, 9, 7, 0, 0, 4, 0, 0},
                       {7, 0, 8, 0, 6, 4, 0, 0, 0},
                       {6, 0, 0, 0, 0, 8, 0, 0, 7},
                       {1, 0, 5, 0, 2, 0, 0, 8, 0},
                       {0, 0, 6, 0, 0, 0, 5, 0, 0},
                       {0, 7, 0, 0, 4, 0, 6, 0, 2},
                       {9, 0, 0, 1, 0, 0, 0, 0, 5},
                       {0, 0, 0, 4, 8, 0, 3, 0, 1},
                       {0, 0, 1, 0, 0, 7, 2, 0, 0}};*/

    jatekmenu(fp, sudoku, &lista);
    felszabadit(&lista);
    return 0;
}
