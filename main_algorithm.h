#ifndef FILLIT_MAIN_ALGORITHM_H
# define FILLIT_MAIN_ALGORITHM_H
#include <math.h>
#include <stdbool.h>

int square_side_size;

bool search_position_start(t_fillit_field *figure, t_fillit_field *main_field, t_fillit_field *borders, char *str);
bool search_position(t_fillit_field *figure, t_fillit_field *main_field, t_fillit_field *borders, char *str);
bool search_position_end(t_fillit_field *figure, t_fillit_field *main_field, t_fillit_field *borders, char *str);
bool generate(char *str);
bool generate_start(char *str, int quantity);
void put_figure_in_array(char index, u_int8_t x, u_int8_t y);




#endif //FILLIT_MAIN_ALGORITHM_H
