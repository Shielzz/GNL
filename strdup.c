
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

char	*ft_strdup(char *s1)
{
	size_t	i;
	char	*temp;

	i = 0;
	temp = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!temp)
		return(NULL);
	while (s1[i] != '\0')
	{
		temp[i] = s1[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

int main()
{
    char    *line = "1 \n HELLO \n UHUH";
    char    *str = ft_strdup(line);

    printf("TEST: \n %s\n", str);
    return (0);
}