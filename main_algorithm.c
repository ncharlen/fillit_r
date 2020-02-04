#include "figure.h"
#include "field.h"
#include "main_algorithm.h"
#include "fill_print_final_result.h"

t_fillit_field main_field;
t_fillit_field borders_field;
t_fillit_field optimal_variation;
t_fillit_field check_variation;

int square_side_size = 0;
int min_square_side = 3;
int counter;
uint16_t *for_print_in_alphabet;

void put_figure_in_array(char index, u_int8_t x, u_int8_t y)
{
	for_print_in_alphabet[counter] = index + (x << 5) + (y << 9);
	++counter;
}



bool search_position_start(t_fillit_field *figure, t_fillit_field *main_field, t_fillit_field *borders, char *str)
{
	t_fillit_field figure_copy;
	copy_in_struct(&figure_copy,figure);

	int max_x_figure = count_for_max_x(figure);
	int max_y_figure = count_for_max_y(figure);

	int max_x = square_side_size - max_x_figure + 1;
	int max_y = square_side_size - max_y_figure + 1;

	if (str[1])
	{
		for (int y = 0; y < max_y; ++y, move_down(figure), copy_in_struct(&figure_copy, figure))
		{
			for (int x = 0; x < max_x; ++x, move_right(&figure_copy))
			{
				insert_figure(main_field, &figure_copy);
				create_borders(borders, main_field);

				put_figure_in_array(*str, x, y);
				if (generate(str + 1))
					return true;
				--counter;
				logical_xor(borders, borders);
				logical_xor(main_field, &figure_copy);
				create_borders(borders, main_field);

			}
		}
	}
	return false;
}


bool search_position(t_fillit_field *figure, t_fillit_field *main_field, t_fillit_field *borders, char *str)
{
	t_fillit_field figure_copy;
	copy_in_struct(&figure_copy,figure);

	int max_x_figure = count_for_max_x(figure);
	int max_y_figure = count_for_max_y(figure);
	int max_x = square_side_size - max_x_figure + 1;
	int max_y = square_side_size - max_y_figure + 1;

	if (str[1])
	{
		for (int y = 0; y < max_y; ++y, move_down(figure), copy_in_struct(&figure_copy, figure))
		{
			for (int x = 0; x < max_x; ++x, move_right(&figure_copy))
			{
				if (check_crossing(&figure_copy, borders) && !check_crossing(&figure_copy, main_field))
				{
					insert_figure(main_field, &figure_copy);
					create_borders(borders, main_field);

					put_figure_in_array(*str, x, y);
					if(generate(str + 1))
						return true;
					--counter;
					logical_xor(borders, borders);
					logical_xor(main_field, &figure_copy);
					create_borders(borders, main_field);
				}
			}
		}
	}
	return false;
}

bool search_position_end(t_fillit_field *figure, t_fillit_field *main_field, t_fillit_field *borders, char *str)
{
	t_fillit_field figure_copy;
	copy_in_struct(&figure_copy,figure);
	int max_x_figure = count_for_max_x(figure);
	int max_y_figure = count_for_max_y(figure);
	int max_x_border = count_for_max_x(borders);
	int max_y_border = count_for_max_y(borders);
	int max_x = ((max_x_border + max_x_figure - 1) <= square_side_size) ? max_x_border : (square_side_size - max_x_figure + 1);
	int max_y = ((max_y_border + max_y_figure - 1) <= square_side_size) ? max_y_border : (square_side_size - max_y_figure + 1);

	for (int y = 0; y < max_y; ++y, move_down(figure), copy_in_struct(&figure_copy, figure))
	{
		for (int x = 0; x < max_x; ++x, move_right(&figure_copy))
		{
			if (check_crossing(&figure_copy, borders) && !check_crossing(&figure_copy, main_field))
			{

				insert_figure(main_field, &figure_copy);
				create_borders(borders, main_field);

				put_figure_in_array(*str, x, y);
				copy_in_struct(&optimal_variation, main_field);

				printf("\n Optimal Variation with %d square size \n\n", square_side_size);
				//print_square(&optimal_variation);

				logical_xor(borders, borders);
				logical_xor(main_field, &figure_copy);
				create_borders(borders, main_field);
				return true;

			}
		}
	}
	return false;
}


bool generate_start(char *str, int quantity)
{
	t_fillit_field function_figure;
	int8_t check_mask = 0;
	char *p;
	char temp;
	char *temp_inital;

	temp_inital = malloc(sizeof(char) * (quantity + 1));
	temp_inital[quantity] = '\0';

	for (int i = 0; i < quantity; ++i)
	{
		temp_inital[i] = str[i];
	}


	//fill_array(temp_inital, str, quantity);
	int arg = 0;
	for_print_in_alphabet = malloc(sizeof(uint16_t) * (quantity + 1));
	for_print_in_alphabet[quantity] = '\0';

	counter = 0;
	square_side_size = sqrt(min_square_side * quantity) + 1;
	char d2garray[square_side_size][square_side_size];
	if (str[1])
	{
		p = str;
		while (*p && arg != 1)
		{
			if ((check_mask & (1 << (*p))) == 0) {
				check_mask |= 1 << (*p);
				temp = *p;
				*p = *str;
				*str = temp;

				set_figure(&function_figure, create_tetro(*str));
				arg = search_position_start(&function_figure, &main_field, &borders_field, str);

				temp = *p;
				*p = *str;
				*str = temp;
			}
			++p;
		}
		if (arg == 1)
		{
			{
				/*for (int i = 0; i < quantity; ++i)
				{
					printf("%d \n", (for_print_in_alphabet[i] & 31));
				}*/
				printf("\n Finish \n");
				//print_square(&optimal_variation);
				check_array(temp_inital, for_print_in_alphabet, quantity);

				fill_bigarray(square_side_size, d2garray);
				fill_figures_in_letter(square_side_size, for_print_in_alphabet, d2garray);
				print_bigarray(square_side_size, d2garray);
				free(for_print_in_alphabet);
				free(temp_inital);
				return true;
			}
		}
		else
		{
			printf("\n With %d square size no optimal variation\n", square_side_size);
			printf("\n Increasing square size \n");
			min_square_side += 1;
			free(for_print_in_alphabet);
			generate_start(str, quantity);
		}
	}
	else
	{
		printf("\n Error \n");
	}
	return false;
}

bool generate(char *str)
{
	t_fillit_field function_figure;

	int8_t check_mask = 0;
	char *p;
	char temp;

	if (str[1])
	{
		p = str;
		while (*p)
		{
			if ((check_mask & (1 << (*p))) == 0)
			{
				check_mask |= 1 << (*p);
				temp = *p;
				*p = *str;
				*str = temp;

				set_figure(&function_figure, create_tetro(*str));
				if (search_position(&function_figure, &main_field, &borders_field, str))
					return true;
				temp = *p;
				*p = *str;
				*str = temp;
			}
			++p;
		}
	}
	else
		{
		set_figure(&function_figure, create_tetro(*str));
		if (search_position_end(&function_figure, &main_field, &borders_field, str))
			return true;
	}
	return false;
}
