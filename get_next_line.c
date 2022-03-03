/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 13:22:31 by mkaruvan          #+#    #+#             */
/*   Updated: 2022/03/03 11:02:59 by mkaruvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char *ft_reader(int fd, char *s)
{
	char	*str;
	int		i;

	str = (char *) * malloc(BUFFER_SIZE + 1);
	if (!str)
		return (NULL);
	while (!strchr(s, '\n'))
	{
		str = 
	}
}

char *get_next_line(int fd)
{
	static char *str;

	if (BUFFER_SIZE <= 0 || fd <= 0)
		return (NULL);
	str = ft_reader(str, fd);
	while ()
}
