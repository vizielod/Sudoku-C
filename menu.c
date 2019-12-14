#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "sudoku.h"

void jatekmenu(FILE *fp, int sudoku[][9], SudokuListaElem **lista){
    SudokuListaElem *plista=*lista;
    int sor,oszlop, szam;
    printf("Udvozollek a jatekomban!\n"
           "A jatek elkezdesehez valassz nehezseget!\n"
           "1. Extrakonnyu\n"
           "2. Konnyu\n"
           "3. Kozepes\n"
           "4. Nehez\n"
           "5. Lehetetlen. Ezt ki ne probald!\n"
           "7. Tesztelesre\n");
    printf("Nehezseget a megfelelo szam lenyomasaval valaszthatod ki.\n"
           "A valasztas utan kezdodik is a jatek!\n"
           "Ha 9-nel nagyobb szamot ad meg, akkor torolheti az utolso beirt elemet, vagyis  Undozik egyet a program");
    int sudoku_teljes[9][9];
    char valasz;
    int k,i,j;
    int szamlalo=0;
    int db=0;
    printf("Nehezsegi szint: ");
    scanf(" %c", &valasz);
    switch(valasz){
        case '1':
            sudoku_osszerak_extrakonnyu(fp, sudoku, sudoku_teljes, &lista);
            while(szamlalo<27){
                mezoket_kitolt_listaval(/*fp,*/ sudoku, &lista, &szamlalo);
            }
            for(i=0;i<9;i++){
                for(j=0;j<9;j++){
                    if(sudoku[i][j]==sudoku_teljes[i][j])
                        db++;
                }
            }
            if(db==81)
                printf("Helyes a megoldas!\n");
            else
                printf("A megoldas rossz!\n");
            break;
        case '2':
            sudoku_osszerak_konnyu(fp, sudoku, sudoku_teljes, &lista);
            while(szamlalo<49){
                mezoket_kitolt_listaval(/*fp,*/ sudoku, &lista, &szamlalo);
            }
            for(i=0;i<9;i++){
                for(j=0;j<9;j++){
                    if(sudoku[i][j]==sudoku_teljes[i][j])
                        db++;
                }
            }
            if(db==81)
                printf("Helyes a megoldas!\n");
            else
                printf("A megoldas rossz!\n");
            break;
        case '3':
            sudoku_osszerak_kozepes(fp, sudoku, sudoku_teljes, &lista);
            while(szamlalo<56){
                mezoket_kitolt_listaval(/*fp,*/ sudoku, &lista, &szamlalo);
            }
            for(i=0;i<9;i++){
                for(j=0;j<9;j++){
                    if(sudoku[i][j]==sudoku_teljes[i][j])
                        db++;
                }
            }
            if(db==81)
                printf("Helyes a megoldas!\n");
            else
                printf("A megoldas rossz!\n");
            break;
        case '4':
            sudoku_osszerak_nehez(fp, sudoku, sudoku_teljes, &lista);
            while(szamlalo<61){
                mezoket_kitolt_listaval(/*fp,*/ sudoku, &lista, &szamlalo);
            }
            for(i=0;i<9;i++){
                for(j=0;j<9;j++){
                    if(sudoku[i][j]==sudoku_teljes[i][j])
                        db++;
                }
            }
            if(db==81)
                printf("Helyes a megoldas!\n");
            else
                printf("A megoldas rossz!\n");
            break;
        case '5':
            /*sudoku_osszerak_lehetetlen(fp, sudoku, sudoku_teljes, &lista);
            while(szamlalo<65){
                mezoket_kitolt_listaval(fp, sudoku, &lista, &szamlalo);
            }
            for(i=0;i<9;i++){
                for(j=0;j<9;j++){
                    if(sudoku[i][j]==sudoku_teljes[i][j])
                        db++;
                }
            }
            if(db==81)
                printf("Helyes a megoldas!\n");
            else
                printf("A megoldas rossz!\n");
            break;*/
            printf("Mondtam, hogy ne problad ki!\nInditsd ujra a jatekot es probalj ki mas nehezseget, hidd el meg a nehez sem    menne!\n");
            break;
        case '6':
            fajlbol_kepernyore(fp,sudoku);
            for(k=0;k<4;k++){
                mezoket_kitolt(fp, sudoku);
            }
            break;
        case '7':
            sudoku_osszerak_teszt(fp, sudoku, sudoku_teljes, &lista);
            printf("\n\n");
            sudoku_kiir(sudoku);
            printf("\n\n");
            sudoku_kiir(sudoku_teljes);
            while(szamlalo<2){
                mezoket_kitolt_listaval(/*fp,*/ sudoku, &lista, &szamlalo);
            }
            for(i=0;i<9;i++){
                for(j=0;j<9;j++){
                    if(sudoku[i][j]==sudoku_teljes[i][j])
                        db++;
                }
            }
            if(db==81)
                printf("Helyes a megoldas!\n");
            else
                printf("A megoldas rossz!\n");
            break;
        default:
            printf("Ervenytelen valasz!\n");
            break;
    }
}
