#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main()
{
	const int	fd = open("test", O_RDONLY);
	printf("fd = %d\n", fd);
	
	char *str = get_next_line(fd);
	printf("ligne 1 = %s\n", str);
	free(str);	
	str = get_next_line(fd);
	printf("ligne 2 = %s\n", str);
	free(str);	
	str = get_next_line(fd);
	printf("ligne 3 = %s\n", str);
	free(str);
	close(fd);
	return (0);
}
