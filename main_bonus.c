#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line.h"

int main()
{
	int fd1, fd2, fd3;
	char *str;
	fd1 = open("foo.txt", O_RDONLY);
	fd2 = open("foo2.txt", O_RDONLY);
	fd3 = open("foo3.txt", O_RDONLY);
	printf("%d", fd1);
	str = get_next_line(fd1);
	printf("%s",str);
	str = get_next_line(fd2);
	printf("%s",str);
	str = get_next_line(fd3);
	printf("%s",str);
}