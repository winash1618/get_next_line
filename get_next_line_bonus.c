/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 07:45:39 by mkaruvan          #+#    #+#             */
/*   Updated: 2022/03/09 08:03:54 by mkaruvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	jgetter(char *str)
{
	if (*str == '\n' || *str == '\0')
		return (1);
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
	static char	*str[OPEN_MAX];
	char		*s;
	int			i;

	i = 0;
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	str[fd] = ft_reader(fd, str[fd]);
	if (!str[fd])
		return (NULL);
	s = ft_getcline(str[fd]);
	if (!str[fd])
		return (s);
	while (str[fd][i])
		str[fd][i++] = '\0';
	return (s);
}
