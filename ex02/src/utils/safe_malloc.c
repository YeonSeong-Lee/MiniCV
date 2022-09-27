#include <stdlib.h>
#include <stdio.h>

static void	ft_bzero(void *s, size_t n)
{
	unsigned char	*str;
	size_t			i;

	str = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		str[i++] = 0;
	}
}

void	*safe_malloc(size_t size)
{
	void	*allocated_ptr;

	allocated_ptr = malloc(size);
	if (!allocated_ptr)
	{
		printf("malloc failed");
		exit(1);
	}
	ft_bzero(allocated_ptr, size);
	return (allocated_ptr);
}