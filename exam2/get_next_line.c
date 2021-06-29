#include "get_next_line.h"

static char	*add_char(char *data, char buf)
{
	int		cnt;
	char	*ret;

	cnt = 0;
	while (*(data + cnt))
		cnt++;
	ret = malloc(cnt + 2);
	if (!ret)
	{
		free(data);
		return (0);
	}
	ret[cnt + 1] = 0;
	ret[cnt] = buf;
	cnt = 0;
	while (*(data + cnt))
	{
		*(ret + cnt) = *(data + cnt);
		cnt++;
	}
	free(data);
	return (ret);
}

int get_next_line(char **line)
{
	char	buf;
	char	*data;
	int		ret;

	if (!line || !(data = malloc(2)))
		return (-1);
	data[0] = 0;
	data[1] = 0;
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
