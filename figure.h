#ifndef FILLIT_FIGURE_H
# define FILLIT_FIGURE_H

#include "field.h"

uint64_t create_tetro(int index);
void	*ft_memset(void *s, int c, size_t n);
int set_and_check_figure(t_fillit_field *figure, int t_figure);
int seek_figure(int figure);


#endif
