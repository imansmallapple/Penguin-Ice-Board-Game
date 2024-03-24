#include "autonomous.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define name "FishyBusiness"

void process_params(struct Params *Params,int argc, char *argv[]){

    if(argc == 1)
    {
        printf("Error, no parameters provided.\n");
        exit(8);
    }
    if(strcmp("name", argv[1]) == 0)
    {
        Params->mode = 'n';
    }
    else if(strcmp("phase=placement", argv[1]) == 0)
    {   
        if(argc < 5)
        {
            printf("Not enough parameters.\n");
            exit(8);
        }
        Params->mode = 'g';
        Params->game_phase = 'p';
    }
    else if(strcmp("phase=movement", argv[1]) == 0)
    {   
        if(argc < 4)
        {
            printf("Not enough parameters.\n");
            exit(8);
        }
        Params->mode = 'g';
        Params->game_phase = 'm';
    }
    else 
    {
        printf("Invalid paramater, please input:\n");
        printf("- name - for displaying team name,\n");
        printf("- phase=placement - for placement phase of the game,\n");
        printf("- phase=movement - for movement phase of the game.\n");
        exit(8);
    }
}

void get_penguin_count(struct Params *Params, char *argv[]){

    if(Params->mode == 'g')
    {
        if(Params->game_phase =='p')
        {      
            char *p;
            p=strchr(argv[2], '=');
            p++;
            Params->penguin_count = atoi(p);
        }
    }
}

int get_board(struct Params *Params, char *argv[]){
    if(Params->mode == 'g')
    {   
        if(Params->game_phase == 'p')
        {
            FILE *file;

            file = fopen(argv[3], "r");
            if(file == NULL)
            {
                printf("Error opening file.\n");
                return 2;
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

            Params->no_of_players = 0;
            for(int i = 0; i < 9; i++)
            {
                Params->names[i] = (char *)malloc(20 + 1);
            }
            while(1)
            {      
                if(feof(file) != 0)
                {
                    break;
                }
                fscanf(file, "%d", &Params->ids[Params->no_of_players]);
                fscanf(file, "%s", Params->names[Params->no_of_players]);
                fscanf(file, "%d", &Params->scores[Params->no_of_players]);
                Params->no_of_players++; 
            }

            if(Params->ids[Params->no_of_players - 1] > 9)
            {
                Params->no_of_players--;
            }
            fclose(file);
            return 0;
        }
        else if(Params->game_phase == 'm')
        {
            FILE *file;

            file = fopen(argv[2], "r");
            if(file == NULL)
            {
                printf("Error opening file.\n");
                return 2;
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

            Params->no_of_players = 0;
            for(int i = 0; i < 9; i++)
            {
                Params->names[i] = (char *)malloc(20 + 1);
            }
            while(1)
            {      
                if(feof(file) != 0)
                {
                    break;
                }
                fscanf(file, "%d", &Params->ids[Params->no_of_players]);
                fscanf(file, "%s", Params->names[Params->no_of_players]);
                fscanf(file, "%d", &Params->scores[Params->no_of_players]);
                Params->no_of_players++; 
            }

            if(Params->ids[Params->no_of_players - 1] > 9)
            {
                Params->no_of_players--;
            }
            fclose(file);
            return 0;
        }
    }
}

void is_name_in_file(struct Params *Params, char* argv[]){
    if(Params->mode == 'g')
    {
        if(Params->game_phase == 'p' || Params->game_phase == 'm')
        {   
            int is_name_in_file = 0;
            for(int i = 0; i < Params->no_of_players; i++)
            {   
                if(strcmp(name, Params->names[i]) == 0)
                {
                    is_name_in_file = 1;
                    Params->my_id = Params->ids[i];
                    break;
                }
            }

            if(is_name_in_file == 0)
            {   

                Params->ids[Params->no_of_players] = Params->no_of_players + 1;
                Params->my_id = Params->ids[Params->no_of_players];
                Params->names[Params->no_of_players] = name;
                Params->scores[Params->no_of_players] = 0;

                Params->no_of_players += 1;
            }
        }
    }
}

int isSafe2(struct Params *Params, int x, int y){
    if(x > 0 && x <= Params->boardX && y > 0 && y <= Params->boardY)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int is_move_available2(struct Params *Params){

    int is_move_available = 0;

    for(int i = 0; i < Params->boardY; i++)
    {
        for(int j = 0; j < Params->boardX; j++)
        {
            if(Params->board[i][j] == Params->my_id)
            {
                if(isSafe2(Params, i, j - 1) == 1)
                {
                    if(Params->board[i][j - 1] == 10 || 
                       Params->board[i][j - 1] == 20 ||
                       Params->board[i][j - 1] == 30)
                    {
                        is_move_available = 1;
                        return is_move_available;
                    }
                }
                if(isSafe2(Params, i, j + 1) == 1)
                {
                    if(Params->board[i][j + 1] == 10 || 
                       Params->board[i][j + 1] == 20 ||
                       Params->board[i][j + 1] == 30)
                    {
                        is_move_available = 1;
                        return is_move_available;
                    }
                }
                if(isSafe2(Params, i, j + 1) == 1)
                {
                    if(Params->board[i + 1][j] == 10 || 
                       Params->board[i + 1][j] == 20 ||
                       Params->board[i + 1][j] == 30)
                    {
                        is_move_available = 1;
                        return is_move_available;
                    }
                }
                if(isSafe2(Params, i - 1, j) == 1)
                {
                    if(Params->board[i - 1][j] == 10 || 
                       Params->board[i - 1][j] == 20 ||
                       Params->board[i - 1][j] == 30)
                    {
                        is_move_available = 1;
                        return is_move_available;
                    }
                }
            }
        }
    }

    if(is_move_available == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int is_move_available_chosen_pen2(struct Params *Params){

    int is_move_available = 0;

    for(int i = 0; i < Params->boardY; i++)
    {
        for(int j = 0; j < Params->boardX; j++)
        {
            if(Params->board[i][j] == Params->my_id)
            {
                if(isSafe2(Params, i, j - 1) == 1)
                {
                    if(Params->board[i][j - 1] == 10 || 
                       Params->board[i][j - 1] == 20 ||
                       Params->board[i][j - 1] == 30)
                    {
                        return 1;
                    }
                }
                if(isSafe2(Params, i, j + 1) == 1)
                {
                    if(Params->board[i][j + 1] == 10 || 
                       Params->board[i][j + 1] == 20 ||
                       Params->board[i][j + 1] == 30)
                    {
                        return 2;
                    }
                }
                if(isSafe2(Params, i, j + 1) == 1)
                {
                    if(Params->board[i + 1][j] == 10 || 
                       Params->board[i + 1][j] == 20 ||
                       Params->board[i + 1][j] == 30)
                    {
                        return 3;
                    }
                }
                if(isSafe2(Params, i - 1, j) == 1)
                {
                    if(Params->board[i - 1][j] == 10 || 
                       Params->board[i - 1][j] == 20 ||
                       Params->board[i - 1][j] == 30)
                    {
                        return 4;
                    }
                }
            }
        }
    }

    if(is_move_available == 0)
    {
        return 0;
    }
}

int place_penguin(struct Params *Params){

    if(Params->mode == 'g')
    {
        if(Params->game_phase == 'p')
        {
            if(Params->penguin_count > 0)
            {   
                int pen_placed = 0;
                for(int i = 0; i < Params->boardY; i++)                
                {
                    if(pen_placed == 0)
                    {
                        for(int j = 0; j < Params->boardX; j++)
                        {
                            if(Params->board[i][j] == 10 ||
                               Params->board[i][j] == 20 ||
                               Params->board[i][j] == 30)
                            {
                                Params->scores[Params->my_id - 1] += (Params->board[i][j] / 10);
                                Params->board[i][j] = Params->my_id;
                                pen_placed = 1;
                                break;
                            }
                        }
                    }
                    else
                    {
                        return 0;
                    }
                }
            }
            else
            {
                return 1;
            }
        }
    }
}

int make_movement(struct Params *Params){

    if(Params->mode == 'g')
    {
        if(Params->game_phase == 'm')
        {
            if(is_move_available2(Params) == 1)
            {   
                int move_made = 0;

                for(int i = 0; i < Params->boardY; i++)
                {
                    for(int j = 0; j < Params->boardX; j++)
                    {
                        if(Params->board[i][j] == Params->my_id)
                        {
                            if(is_move_available_chosen_pen2(Params) == 0)
                            {
                                return 0;
                            }
                            else if(is_move_available_chosen_pen2(Params) == 1)
                            {
                                Params->scores[Params->my_id - 1] += (Params->board[i][j - 1] / 10);
                                Params->board[i][j - 1] = Params->my_id; 
                                Params->board[i][j] = 0;
                                return 1;
                            }
                            else if(is_move_available_chosen_pen2(Params) == 2)
                            {
                                Params->scores[Params->my_id - 1] += (Params->board[i][j + 1] / 10);
                                Params->board[i][j + 1] = Params->my_id; 
                                Params->board[i][j] = 0;
                                return 1;
                            }
                            else if(is_move_available_chosen_pen2(Params) == 3)
                            {
                                Params->scores[Params->my_id - 1] += (Params->board[i + 1][j] / 10);
                                Params->board[i + 1][j] = Params->my_id; 
                                Params->board[i][j] = 0;
                                return 1;
                            }
                            else
                            {
                                Params->scores[Params->my_id - 1] += (Params->board[i - 1][j] / 10);
                                Params->board[i - 1][j] = Params->my_id; 
                                Params->board[i][j] = 0;
                                return 1;
                            }
                        }
                    }
                }

                if(move_made == 0)
                {
                    return 0;
                }
            }
            else
            {
                return 0;
            }
        }
    }
}

void write_board(struct Params *Params, char *argv[]){

    if(Params->mode == 'g')
    {
        if(Params->game_phase == 'p')
        {
            FILE *file;

            file = fopen(argv[4], "w");
            if(file == NULL)
            {
                printf("Error opening file.(writing)\n");
                exit(8);
            }

            fprintf(file,"%d",Params->boardY);
            fprintf(file," ");
            fprintf(file,"%d",Params->boardX);
            fprintf(file, "\n");

            for(int i = 0; i < Params->boardY; i++)
            {    
                for(int j = 0; j < Params->boardX; j++)
                {
                    if(j < Params->boardX - 1)
                    {   
                        if(Params->board[i][j] < 10)
                        {
                            fprintf(file, "0%d ", Params->board[i][j]); 
                        }
                        else
                        {
                            fprintf(file,"%d ", Params->board[i][j]);
                        }
                    }
                    else
                    {   
                        if(Params->board[i][j] < 10)
                        {
                            fprintf(file, "0%d\n", Params->board[i][j]);
                        }
                        else
                        {
                            fprintf(file,"%d\n", Params->board[i][j]);
                        }
                    }
                }
            }
            for(int i = 0; i < Params->no_of_players; i++)
            {   
                fprintf(file,"%d",Params->ids[i]);
                fprintf(file," ");
                fprintf(file,"%s",Params->names[i]);
                fprintf(file," ");
                fprintf(file,"%d\n",Params->scores[i]);
            }
            fclose(file);
        }
        else if(Params->game_phase == 'm')
        {
            FILE *file;

            file = fopen(argv[3], "w");
            if(file == NULL)
            {
                printf("Error opening file.(writing)\n");
                exit(8);
            }

            fprintf(file,"%d",Params->boardY);
            fprintf(file," ");
            fprintf(file,"%d",Params->boardX);
            fprintf(file, "\n");

            for(int i = 0; i < Params->boardY; i++)
            {    
                for(int j = 0; j < Params->boardX; j++)
                {
                    if(j < Params->boardX - 1)
                    {   
                        if(Params->board[i][j] < 10)
                        {
                            fprintf(file, "0%d ", Params->board[i][j]); 
                        }
                        else
                        {
                            fprintf(file,"%d ", Params->board[i][j]);
                        }
                    }
                    else
                    {   
                        if(Params->board[i][j] < 10)
                        {
                            fprintf(file, "0%d\n", Params->board[i][j]);
                        }
                        else
                        {
                            fprintf(file,"%d\n", Params->board[i][j]);
                        }
                    }
                }
            }
            for(int i = 0; i < Params->no_of_players; i++)
            {   
                fprintf(file,"%d",Params->ids[i]);
                fprintf(file," ");
                fprintf(file,"%s",Params->names[i]);
                fprintf(file," ");
                fprintf(file,"%d\n",Params->scores[i]);
            }
            fclose(file);
        }
    }
}

void display_name(struct Params *Params){

    if(Params->mode == 'n')
    {
        printf("%s", name);
    }
}