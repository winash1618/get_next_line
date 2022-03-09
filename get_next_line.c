/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 13:22:31 by mkaruvan          #+#    #+#             */
/*   Updated: 2022/03/09 08:10:43 by mkaruvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	jgetter(char *str)
{
	if (*str == '\n' || *str == '\0')
		return (1);
	return (0);
}

char	*ft_free(char *str, char *s)
{
	free (s);
	free (str);
	return (NULL);
}

char	*ft_reader(int fd, char *s)
{
	char	*str;
	int		i[3];

	i[0] = 0;
	i[1] = 0;
	while (i[1] == 0)
	{
		i[2] = 0;
		str = (char *)malloc(2);
		if (!str)
			return (NULL);
		str[1] = '\0';
		i[2] = read(fd, str, 1);
		i[0] += i[2];
		if (i[2] == -1)
			return (ft_free(str, s));
		i[1] = jgetter(str);
		if (i[2] != 0)
			s = ft_strjoin(s, str);
		if (i[2] == 0 && i[0] == 0)
			return (ft_free(str, s));
		free(str);
	}
	return (s);
}

char	*ft_getcline(char *str)
{
	int		i;
	char	*s;

	i = 0;
	s = NULL;
	if (!str)
		return (NULL);
	i = ft_strlen(str);
	s = ft_strjoin(s, str);
	return (s);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*s;
	int			i;

	i = 0;
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	str = ft_reader(fd, str);
	s = ft_getcline(str);
	if (!str)
		return (s);
	while (str[i])
		str[i++] = '\0';
	return (s);
}
