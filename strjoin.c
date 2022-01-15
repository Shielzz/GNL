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

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	if (!s2 || !s1 )
		return (s2);
	str = malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2)) + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	//free(s1);  leak car on perd l'adresse, donc on free nous meme pour vider & supprimer l'adresse
	return (str);
}

int main()
{
    char    *s1 = "OKOK";
    char    *s2 = NULL;

    printf("JOIN:\n%s\n",ft_strjoin(s1, s2));
    return(0);
}