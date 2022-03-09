#include "get_next_line_bonus.h"

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
	static char	*str[OPEN_MAX];
	char *s;
	int i;

	i = 0;
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	str[fd] = ft_reader(fd, str[fd]);
	if (!str[fd])
		return (NULL);
	s = ft_getcline(str[fd]);
	if (!str[fd])
		return (s);
	while(str[fd][i])
		str[fd][i++] = '\0';
	return (s);
}
