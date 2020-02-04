#ifndef FILLIT_FIELD_H
# define FILLIT_FIELD_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>


typedef struct	s_fillit_field{
	uint64_t 	sqrt0;
	uint64_t 	sqrt1;
	uint64_t 	sqrt2;
	uint64_t 	sqrt3;

}				t_fillit_field;

void set_figure(t_fillit_field *p, uint32_t tetro);
void insert_figure(t_fillit_field *main_field, t_fillit_field *figure);
void move_right(t_fillit_field *p);
void move_left(t_fillit_field *p);
void move_up(t_fillit_field *p);
void move_down(t_fillit_field *p);
void print_square(t_fillit_field *p);
void create_borders(t_fillit_field *borders_field, t_fillit_field *main_field);
void logical_or(t_fillit_field *p_one, t_fillit_field *p_two);
void logical_xor(t_fillit_field *p_one, t_fillit_field *p_two);
void copy_in_struct(t_fillit_field *p_one, t_fillit_field *p_two);

int check_crossing(t_fillit_field *p_one, t_fillit_field *p_two);
void set_x_max(t_fillit_field *p);
void set_y_max(t_fillit_field *p);
int8_t count_for_max_x(t_fillit_field *borders_field);
int8_t count_for_max_y(t_fillit_field *borders_field);


#endif