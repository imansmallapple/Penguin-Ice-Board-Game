#include "auto.h"
#include "io.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void process_params(struct Params *Params, char *argv[]){

    if(strcmp("name", argv[1]) == 0)
    {
        Params->mode = 'n';
    }
    else if(strcmp("phase=placement", argv[1]) == 0)
    {
        Params->mode = 'g';
        Params->game_phase = 'p';
    }
    else if(strcmp("phase=movement", argv[1]) == 0)
    {
        Params->mode = 'g';
        Params->game_phase = 'm';
    }
}

void get_penguin_count(struct Params *Params, char *argv[]){

    if(Params->mode = 'g')
    {
        if(Params->game_phase ='p')
        {      
            char *p;
            p=strchr(argv[2], '=');
            p++;
            Params->penguin_count = atoi(p);
        }
    }
}

void get_board(struct Params *Params, char *argv[]){
    if(Params->mode = 'g')
    {   
        if(Params->game_phase = 'p')
        {
            FILE *file;

            file = fopen(argv[3], "r");
            if(file == NULL)
            {
                printf("Error opening file.\n");
                exit(8);
            }

            fscanf(file, "%d", &Params->boardY);
            fscanf(file, "%d", &Params->boardX);

            Params->board = (int**)malloc(Params->boardY * (sizeof(int*)));
            for(int i = 0; i < Params->boardY; i++)
            {
                (Params->board)[i] = (int*)malloc(sizeof(int) * Params->boardX);
            }

            for(int i = 0; i < Params->boardY; i++)
            {
                for(int j = 0; j < Params->boardX; j++)
                {
                    fscanf(file,"%d",&Params->board[i][j]);
                }
            }

            int player_num = 0;

            while(1)
            {
                if(feof(file))
                {   
                    fclose(file);
                    break;
                }
                else
                {
                    fscanf(file, "%d", &Params->ids[player_num]);
                    fscanf(file,"%s",&Params->player_names[player_num]);
                    fscanf(file, "%d",&Params->scores[player_num]);
                    player_num++;
                }
            }
            
        }
        else if(Params->game_phase = 'm')
        {
            FILE *file;

            file = fopen(argv[3], "r");
            if(file == NULL)
            {
                printf("Error opening file.\n");
                exit(8);
            }

            fscanf(file, "%d", &Params->boardY);
            fscanf(file, "%d", &Params->boardX);

            Params->board = (int**)malloc(Params->boardY * (sizeof(int*)));
            for(int i = 0; i < Params->boardY; i++)
            {
                (Params->board)[i] = (int*)malloc(sizeof(int) * Params->boardX);
            }

            for(int i = 0; i < Params->boardY; i++)
            {
                for(int j = 0; j < Params->boardX; j++)
                {
                    fscanf(file,"%d",&Params->board[i][j]);
                }
            }

            int player_num = 0;

            while(1)
            {
                if(feof(file))
                {   
                    fclose(file);
                    break;
                }
                else
                {
                    fscanf(file, "%d", &Params->ids[player_num]);
                    fscanf(file,"%s",&Params->player_names[player_num]);
                    fscanf(file, "%d",&Params->scores[player_num]);
                    player_num++;
                }
            }
        }
    }
}

void write_board(struct Params *Params, char *argv[]){

    if(Params->game_phase = 'g')
    {
        if(Params->game_phase = 'p')
        {
            FILE *file;

            file = fopen(argv[4], "w");
            if(file == NULL)
            {
                printf("Error opening file.\n");
                exit(8);
            }

            /*for(int i = 0 ; i < 2; i++)
            {
                fprintf(file, "%d", Params->board_dims[i]);
                fprintf(file, " ");
            }
            fprintf(file, "\n");

            for(int i = 0; i < Params->board_dims[1]; i++)
            {
                for(int j = 0; j < Params->board_dims[0]; i++)
                {
                    fprintf(file, "%d", Params->board[i][j]);
                    fprintf(file, " ");
                }
                fprintf(file, "\n");
            }*/

            fclose(file);
        }
        else if(Params->game_phase = 'm');
        {
            FILE* file;

            fclose(file);
        }
    }
}

void display_name(struct Params *Params){

    if(Params->mode = 'n')
    {
        printf("GroupF");
    }
}