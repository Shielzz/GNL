
#include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

char	*ft_strchr(char *s, int c)
{
	char	*str;

	str = s;
	while (*str)
	{
		if (*str == (char)c)
			return (str);
		str++;
	}
	if (*str == c)
		return (str);
	return (NULL);
}

int main()
{
    char    *line = "123 NEXT\nHELLO \n UHUH";

    printf("TEST: \n %s\n", ft_strchr(line, '\n'));
    return (0);
}