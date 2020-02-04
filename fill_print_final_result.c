#include "fill_print_final_result.h"
#include "figure.h"
#include "field.h"
#include "main_algorithm.h"


t_fillit_field for_fill;

void fill_array(char *temp_inital, char *str, int quantity)
{
	temp_inital = malloc(sizeof(char) * (quantity + 1));
	temp_inital[quantity] = '\0';

	for (int i = 0; i < quantity; ++i)
	{
		temp_inital[i] = str[i];
	}

}

void fill_bigarray(int square_side_size, char d2garray[][square_side_size])
{
	for (int i = 0; i < square_side_size; ++i)
	{
		for (int j = 0; j < square_side_size; ++j)
		{
			d2garray[i][j] = '.';
		}
		d2garray[i][square_side_size] = '\n';
	}
	d2garray[square_side_size][square_side_size] = '\n';

}

void fill_figures_in_letter(int square_side_size, uint16_t *array, char d2garray[][square_side_size])
{
	int k = 0;

	while(*array) {
		set_figure(&for_fill, create_tetro(*array & 31));
		for (int32_t i = 0; i < 8; ++i) {
			for (int32_t j = 0; j < 8; ++j) {
				if (for_fill.sqrt0 & 1)
				d2garray[i + ((*array >> 9) & 15)][j + ((*array >> 5) & 15)] = 'A' + k;
				for_fill.sqrt0 >>= 1;
			}
		}
		++array;
		++k;
	}
}

void print_bigarray(int square_side_size, char d2garray[][square_side_size])
{
	for (int i = 0; i < square_side_size; ++i)
	{
		for (int j = 0; j < square_side_size; ++j)
		{
			printf("%c", d2garray[i][j]);
		}
		printf("\n");
	}
}

void check_array(char *a, uint16_t *for_print, int quantity)
{
	uint16_t *temp;

	temp = malloc(sizeof(uint16_t) * (quantity + 1));
	temp[quantity] = '\0';
	for (int i = 0; i < quantity; ++i)
	{
		temp[i] = for_print[i];
	}
	for (int i = 0; i < quantity; ++i)
	{
		for (int k = 0; k < quantity; ++k)
		{
			if (a[i] == (temp[k] & 0x1F))
			{
				for_print[i] = temp[k];
				temp[k] = 0;
				break;
			}
		}
	}
	free(temp);
}