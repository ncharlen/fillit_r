#include "figure.h"
#include "field.h"
#include "main_algorithm.h"

#define MASK_MOVE_LEFT 			0x0101010101010101
#define MASK_MOVE_RIGHT 		0x8080808080808080
#define MASK_MOVE_DOWN 			0xFF00000000000000
#define MASK_MOVE_UP 			0x00000000000000FF
#define MASK_MOVE_L 			0x7F7F7F7F7F7F7F7F
#define MASK_MOVE_R 			0xFEFEFEFEFEFEFEFE

void set_x_max(t_fillit_field *p)
{
	p->sqrt0 = 0x0101010101010101;
	p->sqrt1 = 0;
	p->sqrt2 = 0x0101010101010101;
	p->sqrt3 = 0;
}

void set_y_max(t_fillit_field *p)
{
	p->sqrt0 = 0x00000000000000FF;
	p->sqrt1 = 0x00000000000000FF;
	p->sqrt2 = 0;
	p->sqrt3 = 0;
}


void set_figure(t_fillit_field *p, uint32_t tetro)
{
	p->sqrt0 = tetro;
	p->sqrt1 = 0;
	p->sqrt2 = 0;
	p->sqrt3 = 0;
}

void move_right(t_fillit_field *p)
{
	uint64_t mask_for_copy_1, mask_for_copy_2, mask_border;
	mask_for_copy_1 = p->sqrt0 & MASK_MOVE_RIGHT;
	mask_for_copy_2 = p->sqrt2 & MASK_MOVE_RIGHT;
	mask_border = MASK_MOVE_R;


	p->sqrt0 = (p->sqrt0 ^ mask_for_copy_1) << 1;
	p->sqrt1 = ((p->sqrt1 << 1) & mask_border) | (mask_for_copy_1 >> 7);

	p->sqrt2 = (p->sqrt2 ^ mask_for_copy_2) << 1;
	p->sqrt3 = ((p->sqrt3 << 1) & mask_border) | (mask_for_copy_2 >> 7);
}

void move_left(t_fillit_field *p)
{
	uint64_t mask_for_copy_1, mask_for_copy_2, mask_border;
	mask_for_copy_1 = p->sqrt1 & MASK_MOVE_LEFT;
	mask_for_copy_2 = p->sqrt3 & MASK_MOVE_LEFT;
	mask_border = MASK_MOVE_L;

	p->sqrt1 = (p->sqrt1 ^ mask_for_copy_1) >> 1;
	p->sqrt0 = ((p->sqrt0 >> 1) & mask_border) | (mask_for_copy_1 << 7);


	p->sqrt3 = (p->sqrt3 ^ mask_for_copy_2) >> 1;
	p->sqrt2 = ((p->sqrt2 >> 1) & mask_border) | (mask_for_copy_2 << 7);
}

void move_up(t_fillit_field *p)
{
	uint64_t mask_for_copy_1, mask_for_copy_2;
	mask_for_copy_1 = p->sqrt2 & MASK_MOVE_UP;
	mask_for_copy_2 = p->sqrt3 & MASK_MOVE_UP;

	p->sqrt2 = (p->sqrt2 ^ mask_for_copy_1) >> 8;
	p->sqrt0 = (p->sqrt0 >> 8) | (mask_for_copy_1 << 56);

	p->sqrt3 = (p->sqrt3 ^ mask_for_copy_2) >> 8;
	p->sqrt1 = (p->sqrt1 >> 8) | (mask_for_copy_2 << 56);
}

void move_down(t_fillit_field *p)
{
	uint64_t mask_for_copy_1, mask_for_copy_2;
	mask_for_copy_1 = p->sqrt0 & MASK_MOVE_DOWN;
	mask_for_copy_2 = p->sqrt1 & MASK_MOVE_DOWN;

	p->sqrt0 = (p->sqrt0 ^ mask_for_copy_1) << 8;
	p->sqrt2 = (p->sqrt2 << 8) | (mask_for_copy_1 >> 56);

	p->sqrt1 = (p->sqrt1 ^ mask_for_copy_2) << 8;
	p->sqrt3 = (p->sqrt3 << 8) | (mask_for_copy_2 >> 56);
}
/*
void print_square(t_fillit_field *p)
{
	uint64_t sqrt0 = p->sqrt0;
	uint64_t sqrt1 = p->sqrt1;
	uint64_t sqrt2 = p->sqrt2;
	uint64_t sqrt3 = p->sqrt3;

	for (int32_t i = 0; i < 8; ++i)
	{
		for (int32_t j = 0; j < 8; ++j)
		{
			printf("%c  ", (sqrt0 & 1) ? '#' : '.');
			sqrt0 >>= 1;
		}
		for (int32_t j = 0; j < 8; ++j)
		{
			printf("%c  ", (sqrt1 & 1) ? '#' : '.');
			sqrt1 >>= 1;
		}
		printf("\n");
	}
	for (int32_t i = 0; i < 8; ++i)
	{
		for (int32_t j = 0; j < 8; ++j)
		{
			printf("%c  ", (sqrt2 & 1) ? '#' : '.');
			sqrt2 >>= 1;
		}
		for (int32_t j = 0; j < 8; ++j)
		{
			printf("%c  ", (sqrt3 & 1) ? '#' : '.');
			sqrt3 >>= 1;
		}
		printf("\n");
	}
}
*/
void logical_or(t_fillit_field *p_one, t_fillit_field *p_two)
{
	p_one->sqrt0 |= p_two->sqrt0;
	p_one->sqrt1 |= p_two->sqrt1;
	p_one->sqrt2 |= p_two->sqrt2;
	p_one->sqrt3 |= p_two->sqrt3;
}

void copy_in_struct(t_fillit_field *p_one, t_fillit_field *p_two)
{
	p_one->sqrt0 = p_two->sqrt0;
	p_one->sqrt1 = p_two->sqrt1;
	p_one->sqrt2 = p_two->sqrt2;
	p_one->sqrt3 = p_two->sqrt3;
}

void logical_xor(t_fillit_field *p_one, t_fillit_field *p_two)
{
	p_one->sqrt0 ^= p_two->sqrt0;
	p_one->sqrt1 ^= p_two->sqrt1;
	p_one->sqrt2 ^= p_two->sqrt2;
	p_one->sqrt3 ^= p_two->sqrt3;
}

void create_borders(t_fillit_field *borders_field, t_fillit_field *main_field)
{
	t_fillit_field mask_field;


	copy_in_struct(&mask_field, main_field); logical_or(borders_field, &mask_field);
	move_up(&mask_field); move_right(&mask_field);
	logical_or(borders_field, &mask_field); copy_in_struct(&mask_field, main_field);
	move_down(&mask_field); move_left(&mask_field);
	logical_or(borders_field, &mask_field); copy_in_struct(&mask_field, main_field);
	move_up(&mask_field);
	logical_or(borders_field, &mask_field); copy_in_struct(&mask_field, main_field);
	move_up(&mask_field); move_left(&mask_field);
	logical_or(borders_field, &mask_field); copy_in_struct(&mask_field, main_field);
	move_left(&mask_field);
	logical_or(borders_field, &mask_field); copy_in_struct(&mask_field, main_field);
	move_right(&mask_field);
	logical_or(borders_field, &mask_field); copy_in_struct(&mask_field, main_field);
	move_down(&mask_field);
	logical_or(borders_field, &mask_field); copy_in_struct(&mask_field, main_field);
	move_right(&mask_field); move_down(&mask_field);
	logical_or(borders_field, &mask_field); logical_xor(borders_field, main_field);
}



int check_crossing(t_fillit_field *p_one, t_fillit_field *p_two)
{
	return  ((p_one->sqrt0 & p_two->sqrt0) || (p_one->sqrt1 & p_two->sqrt1) ||
			(p_one->sqrt2 & p_two->sqrt2) || (p_one->sqrt3 & p_two->sqrt3));

}

void insert_figure(t_fillit_field *main_field, t_fillit_field *figure)
{
	logical_or(main_field, figure);
}


int8_t count_for_max_x(t_fillit_field *borders_field)
{
	t_fillit_field border_copy;
	t_fillit_field x_max_check;

	set_x_max(&x_max_check);

	int8_t count_x = 0;

	copy_in_struct(&border_copy, borders_field);
	for (int i = 0; i < 8; ++i, move_left(&border_copy))
	{
		if (check_crossing(&border_copy, &x_max_check))
			++count_x;
	}
	return (count_x);
}

int8_t count_for_max_y(t_fillit_field *borders_field)
{
	t_fillit_field border_copy;
	t_fillit_field y_max_check;

	set_y_max(&y_max_check);

	int8_t count_y = 0;

	copy_in_struct(&border_copy, borders_field);
	for (int i = 0; i < 8; ++i, move_up(&border_copy))
	{
		if (check_crossing(&border_copy, &y_max_check))
			++count_y;
	}
	return (count_y);
}
