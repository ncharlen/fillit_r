#include "validate.h"
#include "figure.h"
#include "field.h"
#include "main_algorithm.h"
#include "fill_print_final_result.h"
#define BUF_SIZE 21

t_fillit_field figure;

int get_figure_numbers(char *a)
{
	int counter = 0;

	while (*a)
	{
		++a;
		++counter;
	}
	return (counter);
}

int get_figures(char *a, int fd)
{
	int count;
	char *buf;
	int i = 0;

	buf = malloc(sizeof(char) * (BUF_SIZE + 1));
	buf[BUF_SIZE] = '\0';
	count = read(fd, buf, BUF_SIZE);
	while (count >= 20)
	{
		if ((a[i] = check_figure(buf)) != -1)
		{
			++i;
			count = read(fd, buf, BUF_SIZE);
		}
		else
			{
			free(buf);
			return (-1);
			}
	}
	if (count != 0)
	{
		free(buf);
		return (-1);
	}
	free(buf);
	return (1);
}

int check_figure(char *buf)
{
	int symbols = 0;
	int new_string = 0;
	int i = 0;
	uint32_t t_figure = 0;


	while (*buf)
	{
		if (*buf == '.')
			++symbols;
		else if (*buf == '#')
		{
			t_figure |= (1 << i);
			++symbols;
		}
		else if (*buf == '\n')
		{
			if (symbols != 4)
				return (-1);
			i += 3;
			symbols = 0;
			if (++new_string == 4)
			{
				++buf;
				break;
			}
		}
		else
			return (-1);
		++i;
		++buf;
	}

	if (buf[0] != '\n' || buf[1] != '\0')
		return (-1);

	if ((t_figure = set_and_check_figure(&figure, t_figure)) == -1)
		return (-1);
	//print_square(&figure);
	//printf("\n");
	return (t_figure);
}