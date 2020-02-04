#ifndef FILLIT_FILL_PRINT_FINAL_RESULT_H
#define FILLIT_FILL_PRINT_FINAL_RESULT_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>

void fill_bigarray(int square_side_size, char d2garray[][square_side_size]);
void print_bigarray(int square_side_size, char d2garray[][square_side_size]);
void fill_figures_in_letter(int square_side_size, uint16_t *array, char d2garray[][square_side_size]);
void check_array(char *a, uint16_t *for_print, int quantity);
void fill_array(char *temp_inital, char *str, int quantity);

#endif //FILLIT_FILL_PRINT_FINAL_RESULT_H
