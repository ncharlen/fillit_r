#include "figure.h"
#include "field.h"
#include "main_algorithm.h"

const uint32_t tetro[4][8] =
		{
				{0x0, 0x00000303, 0x0000000F, 0x00000603, 0x00000306, 0x00000407, 0x00000107, 0x00000207},
				{0x0, 0x00000303, 0x01010101, 0x00010302, 0x00020301, 0x00030202, 0x00020203, 0x00020302},
				{0x0, 0x00000303, 0x0000000F, 0x00000603, 0x00000306, 0x00000701, 0x00000704, 0x00000702},
				{0x0, 0x00000303, 0x01010101, 0x00010302, 0x00020301, 0x00010103, 0x00030101, 0x00010301}
		};

void	*ft_memset(void *s, int c, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = (unsigned char)c;
		i++;
	}
	return (s);
}

uint64_t create_tetro(int index)
{
	return (tetro[index >> 3][index & 7]);
}

int set_and_check_figure(t_fillit_field *figure, int t_figure)
{
	t_fillit_field max_x;
	t_fillit_field max_y;

	set_x_max(&max_x);
	set_y_max(&max_y);
	set_figure(figure, t_figure);
	while (!check_crossing(&max_y, figure))
		move_up(figure);
	while (!check_crossing(&max_x, figure))
		move_left(figure);
	if ((t_figure = seek_figure(figure->sqrt0)) == -1)
		return (-1);
	return (t_figure);
}

int seek_figure(int figure)
{
	for (int i = 0; i < 4; ++i)
	{
		for (int k = 0; k < 8; ++k)
		{
			if (tetro[i][k] == figure)
				return ((i << 3) + k);
		}
	}
	return (-1);
}
/*
 *  1 - ##
 *  	##
 *
 *  2 - ####  10 - #
 *  			   #
 *  			   #
 *  			   #
 *
 *  3 - ##	  11 -  #
 *  	 ##		   ##
 *				   #
 *
 *  4 -  ##   12 - #
 *  	##		   ##
 *  	            #
 *
 *  5 - ###   13 -  #	21 - #    29 - ##
 *		  #			#		 ###	   #
 *		  		   ##				   #
 *
 *	6 - ###   14 - ##	22 -   #  30 - #
 *		#			#		 ###       #
 *					#				   ##
 *
 *	7 - ###   15 -  #	23 -  #   31 - #
 *		 #		   ##		 ###       ##
 *		 			#				   #
 */



/*
int8_t q_rotate(int index)
{
	const int8_t quantity[] = {0, 1, 2, 2, 2, 4, 4, 4};

	return (quantity[index]);
}
*/

/*
 * const uint32_t tetro[4][8] =
			{
					{0x0, 0x00000303, 0x0000000F, 0x00000603, 0x00000306, 0x00000407, 0x00000107, 0x00000207},
					{0x0, 0x00000303, 0x01010101, 0x00010302, 0x00020301, 0x00030202, 0x00020203, 0x00020302},
					{0x0, 0x00000303, 0x0000000F, 0x00000603, 0x00000306, 0x00000701, 0x00000704, 0x00000702},
					{0x0, 0x00000303, 0x01010101, 0x00010302, 0x00020301, 0x00010103, 0x00030101, 0x00010301}
			};

 */