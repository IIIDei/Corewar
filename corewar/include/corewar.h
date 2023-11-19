/*
** EPITECH PROJECT, 2023
** B-CPE-200-BDX-2-1-corewar-gaetan.dubernat
** File description:
** include corewar
*/


#ifndef PROJECT_H_
    #define PROJECT_H_

    #include "op.h"
    #include "utils.h"
    #include <stdbool.h>

typedef struct argument { //stocker len pour avancement pc
    args_type_t type;
    int value;
} argument_t;

typedef struct instruction {
    int opcode;
    argument_t *args[MAX_ARGS_NUMBER];
} instruction_t;

typedef struct champion {
    //BASE
    char name[PROG_NAME_LENGTH + 1];
    int id;
    size_t file_size;
    char *body;
    size_t body_size;
    //INSTRUCTIONS
    int registers[REG_NUMBER];
    int pc;
    int carry;
    //CHECK ALIVE
    bool is_alive;
    int nb_live;
    bool live_before_die;
    int cycle_to_wait;
} champion_t;

typedef struct corewar {
    char *arena;
    int nb_champs;
    champion_t **champ;
    int cycle_count;
    int dump_cycles;
    int cycle_to_die;
    int nb_alive_champ;
    int last_alive;
} corewar_t;

    //GLOBAL
    int init_core(corewar_t *core);
    int program_loop(corewar_t *core, instruction_t *instru);
    int get_instruction_cycle(int opcode);
    int set_cycle_to_wait(corewar_t *core, champion_t *champ);
    void free_corewar(corewar_t *core);

    //ALGO
    bool game_end(corewar_t *core);
    bool game_end_condition(corewar_t *core);

    //CHECK
    int check_args(corewar_t *core, int const argc, char *argv[]);
    int check_path(char const *path);
    int check_file(char const *arg);
    int set_dump_value(corewar_t *core, char *argv[], int i);

    //ARENA
    int init_arena(corewar_t *core);

    //CHAMPION
    int init_champions(corewar_t *core, char **argv);
    void kill_champ(corewar_t *core, champion_t *champ);
    int read_champion(champion_t *champ, int fd);
    int load_champions(corewar_t *core);
    int set_nb_champ(corewar_t *core, char **argv);
    int get_nb_alive_champ(corewar_t *core);
    int set_cycle_to_wait(corewar_t *core, champion_t *champ);

    //INSTRUCTIONS
    int init_instruction(instruction_t *instru);
    int read_instruction(corewar_t *core, champion_t *champ,
    instruction_t *instru);
    int get_current_opcode(corewar_t *core, champion_t *champ);
    int exec_instruction(corewar_t *core, champion_t *champ,
    instruction_t *instru);
    int exec_live(corewar_t *core, champion_t *champ, int arg);
    bool exec_add(champion_t *champ, int reg1, int reg2, int reg3);
    bool exec_sub(champion_t *champ, int reg1, int reg2, int reg3);

    //PRINT
    int display_champion_body(champion_t *champ);
    int display_arena(char *arena);
    int print_champ_registers(champion_t *champ);
    void display_winner(corewar_t *core);
    void display_winner_last_alive(corewar_t *core);

    //FREE
    void free_instruction(instruction_t *instru);
#endif
