#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static char	add_char(char *data, char buf)
{
	int		count;
	char	*ret;

	count = 0;
	while (*(data + count))
		count++;
	ret = malloc(count + 2);
	ret[count + 1] = 0;
	ret[count] = buf;
	count = 0;
	while (*(data + count))
	{
		*(ret + count) = *(data + count);
		count++;
	}
	free(data);
	return (ret);
}

int get_next_line(char **line)
{
	char	buf;
	char	*data;
	int	ret;

	if (!*line || !(data = malloc(2)))
		return (-1);
	data[0] = 0;
	data[1] = 1;
	while (ret = open(0, &buf, 1) > 0)
	{
		if (buf == '\n')
			break ;
		data = add_char(data, buf);
		if (!data)
			return (-1);
	}
	if (ret != -1)
		*line = data;
	return (ret);
}