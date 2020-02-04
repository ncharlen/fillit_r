#include "field.h"
#include "figure.h"
#include "main_algorithm.h"
#include "validate.h"

#include <time.h>
#include <math.h>
#define MAX_FIG 26

int main()
{
	clock_t t;

	t = clock();

	t_fillit_field test;
	t_fillit_field test_borders;
	char *a;
	int fd;
	int n;
	const int f[] = {1,2,3,4,5,6,7,10,11,12,13,14,15,21,22,23,29,30,31};
	const int d[] = {1,2,10,3,11,4,12,7};
	const int e[] = {12,23,10};


	/*
	 *  if (argc == 2)
		fd = open(argv[1], O_RDONLY);

	 if (argc != 2)
	{
		printf("usage: fillit input_file\n");
		return (1);
	}
	if ((list = read_tetri(open(argv[1], O_RDONLY))) == NULL)
	{
		ft_putstr("error\n");
		return (1);
	}

	 while ((count = read(fd, buf, 21)) >= 20)
	 */

	fd = open("/Users/dark/CLionProjects/fillit/ex_3", O_RDONLY);
	//

	//check_file(fd);
	a = malloc(sizeof(char) * (MAX_FIG + 1));
	ft_memset(a, '\0', 27);

	if (get_figures(a, fd) == -1)
	{
		printf("error\n");
		return (1);
	}
	n = get_figure_numbers(a);
	/*for (int i = 0; i < n; ++i)
	{

		printf("%d \n", a[i]);

	}*/

	generate_start(a, n);
/*
	for (int i = 0; i < n; ++i)
	{
		a[i] = f[i];
		printf("%d \n", a[i]);

	}
	printf("\n Figures number, %d  \n", n);
*/



	//set_figure(&test, create_tetro(31));
	//set_y_max(&test);
	//print_square(&test);
	//set_right_border_8(&test);
	//set_max_y_border(&test);

	t = clock() - t;

	printf ("It took me %d clicks (%f seconds).\n",
			(int)t, ((double)t)/CLOCKS_PER_SEC);
	free(a);
	close(fd);
	return 0;
}