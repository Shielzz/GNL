/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Louisa <Louisa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 00:13:47 by lhafsi            #+#    #+#             */
/*   Updated: 2022/01/15 01:48:31 by lhafsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// on garde la 1è partie avec \n
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
// on garde la 2è partie avec \n
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

char	*get_next_line(int fd)
{
	char 		*buffer;
	static char	*txt = NULL;
	char		*line;
	int			ret;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return(NULL);
	//line = ft_strdup(txt);
	ret = 4;
	while (ret != 0 && ft_strchr(txt, '\n') == 0)
	{
		ret = read(fd, buffer, BUFFER_SIZE);
		if (ret == - 1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[ret] = '\0';
		txt = ft_strjoin(txt, buffer);
	}
	//	txt = ft_save(txt);
		line = ft_line(txt);
		txt = ft_save(txt);
		//line = ft_line(line);
		return (line);
}
