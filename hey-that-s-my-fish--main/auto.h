#ifndef _AUTO_H_
#define _AUTO_H_

struct Params{
    char mode;
    char game_phase;
    int **board;
    char player_names[9][20];
    int penguin_count;
    char name[20];
    int board_dims[2];
};

void process_params(struct Params *Params, char *argv[]);
void get_file_names(struct Params *Params, char *argv[]);
void get_penguin_count(struct Params *Params, char *argv[]);
void get_board(struct Params *Params, char *argv[]);
void write_board(struct Params *Params, char *argv[]);
void display_name(struct Params *Params);

#endif