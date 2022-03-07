#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line.h"

int main()
{
	int fd;
	char *str;
	fd = open("foo.txt", O_RDONLY, O_CREAT);
	printf("%d", fd);
	str = get_next_line(fd);
	printf("%s",str);
	str = get_next_line(fd);
	printf("%s",str);
	str = get_next_line(fd);
	printf("%s",str);
}