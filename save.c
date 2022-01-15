#include <stdio.h>
# include <stdlib.h>
# include <unistd.h>


size_t	ft_strlen(char const *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

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

char	*ft_save(char *line)
{
	char	*temp;
	int		i;
	int		j;

	i = ft_endofline(line) + 1;
	j = 0;
	temp = malloc(sizeof(char) * (ft_strlen(line) - i));
	if (!temp)
		return (NULL);
	while (line[i])
	{
		temp[j] = line[i];
		i++;
		j++;
	}
	temp[i] = '\0';
	return (temp);
}

int main()
{
    char    *line = "1 \n HELLO \n UHUH";

    printf("TEST: \n %s\n", ft_save(line));
    return (0);
}