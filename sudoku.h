#ifndef SUDOKU_H_INCLUDED
#define SUDOKU_H_INCLUDED
/*A listahoz tartozo strukturak*/

typedef struct SudokuListaElem{
    int sudokutomb[9][9];
    struct SudokuListaElem *kov;
}SudokuListaElem;

typedef struct SudokuLista{
    SudokuListaElem *eleje;
    SudokuListaElem *vege;
}SudokuLista;
/* nehezsegi szintekhez tartozo fv-k */

void elemek_letakarasa_konnyu(int sudoku[][9]);
void elemek_letakarasa_kozepes(int sudoku[][9]);
void elemek_letakarasa_nehez(int sudoku[][9]);
void elemek_letakarasa_extrakonnyu(int sudoku[][9]);

void sudoku_kitolt(int sudoku[][9]);
void sudoku_kiir(int sudoku[][9]);
void sudoku_kiir_dinamikusan(int **sudoku);
void elemek_letakarasa_altalanosan(int sudoku[][9]);
void elemek_letakarasa_3x3(int sudoku[][9], int y, int x, int k);

/* a generalashoz szukseges fuggvenyek */

void sudoku_kinullaz(int sudoku[][9]);
void sudoku_generalas_rekurzivan(int sudoku[][9],int y,int x);
int megoldase(int sudoku[][9], int y, int x, int szam);
int sudoku_megold(int sudoku[][9], int y, int x);
void par_elemet_random_beir(int sudoku[][9]);

/* fajlkezeles */

void fajlba_iras(FILE *fp, int sudoku[][9]);
void fajlbol_kepernyore(FILE *fp, int sudoku[][9]);
void fajlba_iras_hozzatoldassal(FILE *fp, int sudoku[][9]);
void fajlba_iras_sudokuteljes(FILE *fp, int sudoku[][9]);
void fajlbol_matrixba(FILE *fp, int sudoku[][9]);
void fajlbol_matrixba_sudokuteljes(FILE *fp, int sudoku[][9]);
void fajlbol_matrixba_nehezet(FILE *fp, int sudoku[][9]);
void fajlbol_matrixba_nehezteljes(FILE *fp, int sudoku[][9]);


/* osszerak fuggvenyek */

void sudoku_osszerak_teszt(FILE *fp, int sudoku[][9], int sudoku_teljes[][9], SudokuListaElem **lista);
void sudoku_osszerak_extrakonnyu(FILE *fp, int sudoku[][9], int sudoku_teljes[][9], SudokuListaElem **lista);
void sudoku_osszerak_konnyu(FILE *fp, int sudoku[][9], int sudoku_teljes[][9], SudokuListaElem **lista);
void sudoku_osszerak_kozepes(FILE *fp, int sudoku[][9], int sudoku_teljes[][9], SudokuListaElem **lista);
void sudoku_osszerak_nehez(FILE *fp, int sudoku[][9], int sudoku_teljes[][9], SudokuListaElem **lista);

/* menu */

void jatekmenu(FILE *fp, int sudoku[][9], SudokuListaElem **lista);

/* jatek */

void mezoket_kitolt_listaval(/*FILE *fp,*/ int sudoku[][9], SudokuListaElem **lista, int *pszamlalo);
void mezoket_kitolt(FILE *fp, int sudoku[][9]);

/* undo */
void sudokulista_letrehoz(FILE *fp, SudokuListaElem **lista, int sudoku[][9]);
void lista_vegere_fuz(SudokuListaElem **lista, int sudoku[][9]);
void lista_vegerol_torol(SudokuListaElem **lista, int sudoku[][9]);
void utolso_listaelem_kiirasa(SudokuListaElem **lista, int sudoku[][9]);
void felszabadit(SudokuListaElem **lista);

#endif // SUDOKU_H_INCLUDED
