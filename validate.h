#ifndef FILLIT_VALIDATE_H
#define FILLIT_VALIDATE_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>


int get_figure_numbers(char *a);
int get_figures(char *a, int fd);
int check_figure(char *buf);

#endif
