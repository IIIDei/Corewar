/*
** EPITECH PROJECT, 2023
** B-CPE-200-BDX-2-1-corewar-gaetan.dubernat
** File description:
** asm
*/

#ifndef ASM_H_
    #define ASM_H_
    #include <stdint.h>
    #include <stdbool.h>

    typedef struct line_s {
        char** tokens;
        int token_count;
    } line_t;

    typedef struct parameter_s {
            int *type;
            int *value;
            char *mnemonic;
            uint8_t opcode;
        } parameter_t;

    typedef struct label_entry_s {
        char *label;
        int address;
    } label_entry_t;

    typedef struct mnemonic_opcode_s {
        const char *mnemonic;
        uint8_t opcode;
    } mnemonic_opcode_t;

    int check_arg(int const argc, char *argv[]);
    char *folder_into_1d_array(char const *filepath);
    int is_label(const char *token);
    bool is_mnemonic(char *token);
    char *is_comment(char* parsed_file_lines);
    char *concatenate_tokens(char **tokens, int start_index);
    char **remove_comments(char **parsed_file_lines);
    void change_extension_to_cor(char* filename);
    line_t* line_to_word_split(char *const filepath);
    int find_len_optab(char *const mnemonic);
    char *my_full_fill_strncpy(char *dest, char const *src, int n);
    bool len_handling(char *mnemonic, int tab_len, char *first_str);
    bool label_char_checker(char *const potential_label);
    char **my_str_to_word_array_comma(char const *str);
    bool good_param_type(char *mnemonic, char **params);
    int mnemonic_and_params_checker(line_t *line, int nb_line);
    char **parse_wether_its_header(char *old_parse);
    bool is_first_word_header(char *parsed_file);
    int prog_size_calculator(parameter_t *param, int i);
    int which_param(char *const param);
    uint8_t find_opcode(const char *mnemonic);
    int len_and_type_checker(line_t *line, int i);
    int get_value(char *value_str);
    header_t header_filler(line_t *line, header_t header, char *filepath, \
int size);
    int len_and_type_checker_2(line_t *line, int i, int j);
    void write_header(const char *output_file, header_t header);
    bool label_char_checker_2(char c);
    void param_filler(line_t *line, parameter_t *param);
    extern mnemonic_opcode_t    mnemonic_opcode_map[];

#endif /* !ASM_H_ */
