#include <stdio.h>
#include "datamanip.h"

void gen_board(int a, int b, int c){

    srand(time(NULL));
    
    FILE *boardfile;
    
    boardfile = fopen("board.txt", "w+");

    for(int i = 0; i < b; i++)
    {
        for(int j = 0; j < a; j++)
        {
            fprintf(boardfile, "00 ");
        }
        fprintf(boardfile, "\n");
    }

    
    fclose(boardfile);
}

void write_placement(int a, int b){

}

void process_move(int a, int b){

}

void add_score(int a, int b){
    
}