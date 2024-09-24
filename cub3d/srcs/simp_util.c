#include "../includes/cub3d.h"

void	*safe_malloc(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (ptr == NULL)
		exit(1);
	ft_memset(ptr, 0, size);
	return (ptr);
}

void	safe_free(void **ptr)
{
	if (ptr != NULL && *ptr != NULL)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

void	free_2d_array(void **array, int height)
{
	int	i;

	i = -1;
	while (++i < height)
		free(array[i]);
	free(array);
}

void	fill_int_array(int *arr, int size, int val)
{
	int	i;

	i = 0;
	while (i < size)
	{
		arr[i] = val;
		i++;
	}
}

void	error_exit(char *msg)
{
	ft_putendl_fd(msg, STDERR_FILENO);
	exit(1);
}
