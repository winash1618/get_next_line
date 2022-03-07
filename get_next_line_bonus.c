#include "get_next_line_bonus.h"

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

char *ft_free(char *str, char *s)
{
	free (s);
	free (str);
	return (NULL);
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
			return (ft_free(str, s));
		j = jgetter(str);
		if(k != 0)
			s = ft_strjoin(s, str);
		if (k == 0 && i == 0)
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
	// s[BUFFER_SIZE] = '\0';
	while(str[i])
		str[i++] = '\0';
	return (s);
}
