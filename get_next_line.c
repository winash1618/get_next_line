/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 13:22:31 by mkaruvan          #+#    #+#             */
/*   Updated: 2022/03/06 09:15:01 by mkaruvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*freeme(char *s, char *str)
{
	free (s);
	free (str);
	return (NULL);
}

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
	if (*str == '\n' || *str == EOF)
		j = 1;
	return (j);
}

char *ft_reader(int fd, char *s)
{
	char	*str;
	int		i;
	int		j;
	int		k;

	j = 0;
	i = 0;
	while (j == 0)
	{
		k = 0;
		str = (char *)malloc(2);
		if (!str)
			return (NULL);
		str[1] = '\0';
		k = read(fd, str, 1);
		i += k;
		if (k == -1)
		{
			free (s);
			return (NULL);
		}
		j = jgetter(str);
		s = ft_strjoin(s, str);
		free(str);
	}
	return (s);
}
char	*ft_strdup(const char *s1)
{
	char	*ptr;
	int		count;

	count = 0;
	ptr = (char *) malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	while (*s1)
	{
		*ptr++ = *s1++;
		count++;
	}
	*ptr = '\0';
	ptr = ptr - count;
	s1 = s1 - count;
	return (ptr);
}
char	*ft_getcline(char *str)
{
	int		i;
	char	*s;

	i = 0;
	if (!str)
		return (NULL);
	i = ft_strlen(str);
	s = ft_strdup(str);
	return (s);
}

char *get_next_line(int fd)
{
	static char *str;
	char *s;
	int i;

	i = 0;
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	str = ft_reader(fd, str);
	s = ft_getcline(str);
	if (!str)
		return (s);
	while(str[i])
		str[i++] = '\0';
	return (s);
}


