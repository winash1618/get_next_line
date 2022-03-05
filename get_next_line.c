/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 13:22:31 by mkaruvan          #+#    #+#             */
/*   Updated: 2022/03/05 08:41:15 by mkaruvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == (char )c)
			return ((char *)(s + i));
		i++;
	}
	if (s[i] == (char )c)
		return ((char *)(s + i));
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new;
	int		x;
	int		xx;

	x = 0;
	xx = 0;
	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		s1[x] = '\0';
	}
	new = (char *)malloc(sizeof (char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!new)
		return (0);
	while (s1[x] != '\0')
	{
		new[x] = s1[x];
		x++;
	}
	while (s2[xx] != '\0')
		new[x++] = s2[xx++];
	new[x] = '\0';
	free (s1);
	return (new);
}
int jgetter(char *str)
{
	int j;

	j = 0;
	if (*str == '\n' || *str == '\0')
		j = 1;
	return (j);
}
char *ft_reader(int fd, char *s, int bf)
{
	char	*str;
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (j == 0 && bf--)
	{
		i = 0;
		str = (char *)malloc(2);
		if (!str)
			return (NULL);
		read(fd, str, 1);
		jgetter(str);
		if (str[i] == '\n')
		{
			str[++i] = '\0';
			s = ft_strjoin(s, str);
		}
		else if (str[i] == '\0')
			s = ft_strjoin(s, str);
		else
			s = ft_strjoin(s, str);
		free(str);
	}
	return (s);
}

char *get_next_line(int fd)
{
	static char *str;

	if (BUFFER_SIZE <= 0 || fd <= 0)
		return (NULL);
	str = ft_reader(fd, str, BUFFER_SIZE);
	return (str);
}

int main()
{
	int fd;
	char *str;
	fd = open("foo.txt", O_RDONLY);
	str = get_next_line(fd);
	printf("%s",str);
}
