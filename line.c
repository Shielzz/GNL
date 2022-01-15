#include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_endofline(char* line)
{
	int		i;

	while (line[i])
	{
		if (line[i] == '\n')
			return (i);
		i++;
	}
	return (i);
}

char	*ft_line(char *line)
{
	char	*temp;
	int		i;

	i = 0;
	temp = malloc(sizeof(char) * (ft_endofline(line) + 1));
	if (!temp)
		return (NULL);
	while (line[i] && i < ft_endofline(line))
	{
		temp[i] = line[i];
		i++;
	}
	temp[i] = '\0';
	//free(line);
	return (temp);
}

int main()
{
    char    *line = "1 \n 2 \n 3\n";

    printf("TEST: \n %s\n", ft_line(line));
    return (0);
}