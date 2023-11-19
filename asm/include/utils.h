/*
** EPITECH PROJECT, 2023
** B-CPE-200-BDX-2-1-corewar-gaetan.dubernat
** File description:
** utils
*/

#ifndef UTILS_H_
    #define UTILS_H_
    int my_put_str(char const *str);
    int my_put_strerr(char const *str);
    int my_strcmp(char const *s1, char const *s2);
    char *my_strcat(char *dest, char *src);
    int my_strlen(char const *str);
    char *my_itoa(int nb);
    char **my_line_to_word_array(char const *str);
    char *folder_into_1d_array(char const *filepath);
    long get_file_size(char const *filepath);
    char **my_str_to_word_array(char const *str);
    char *my_strcpy(char *dest, char const *src);
    int my_str_isalphanum(char const *str);
    int len_tab(char *const *const tab);
    int print_tab(char **tab);
    int my_get_nbr(char *valeur);
    int print_tab(char **tab);
    char *my_strncpy(char *dest, char const *src, int n);
    void *my_memset(void *string, int value, int len);
#endif /* !UTILS_H_ */
