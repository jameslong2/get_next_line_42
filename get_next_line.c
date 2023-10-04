#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*tmp;

	if (len > (size_t)ft_strlen(s) && start < (unsigned int)ft_strlen(s))
	{
		len = (size_t)ft_strlen(s) + 1;
		len = len - start;
	}
	else if (start >= (unsigned int)ft_strlen(s) || len == 0)
	{
		len = 1;
		start = (unsigned int)ft_strlen(s);
	}
	else if (start < (unsigned int)ft_strlen(s) && len <= (size_t)ft_strlen(s)
		&& (size_t)start + len <= (size_t)ft_strlen(s))
		len++;
	tmp = (char *)malloc(len);
	if (tmp == 0)
		return (0);
	ft_strlcpy(tmp, s + start, len);
	return (tmp);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*tmp;
	size_t	i;

	i = 0;
	tmp = malloc(size * count);
	if (tmp == 0)
		return (0);
	while (i < count * size)
		((unsigned char *)tmp)[i++] = (unsigned char)0;
	return (tmp);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
		((unsigned char *)s)[i++] = 0;
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*tmp;
	int		res;

	res = 1;
	if (fd < 0 || read(fd,0,0) < 0)
	{
		return (0);
	}
	buffer = (char *)ft_calloc((BUFFER_SIZE + 1),sizeof(char));
	tmp = 0;
	if (!buffer)
		return (0);
	while (res > 0)
	{
		res = read(fd, buffer, BUFFER_SIZE);
		/*if (res == -1)
		{
			if (buffer)
				free(buffer);
			return (0);
		}*/
		//tmp[res] = 0;
		tmp = ft_strjoin(tmp, buffer);
		if (res == -1 || (res == 0 && !tmp))
			break;
		/*if (res == 0 && ft_strlen(buffer) == 2)
		{
			tmp = (char *)ft_calloc(ft_strlen(buffer) + 1,sizeof(char));
			ft_strlcpy(tmp,buffer,ft_strlen(buffer));
			break;
			return (buffer);
		}*/
		//tmp = ft_strjoin(tmp, buffer);
		if (!tmp)
			break;
		if (ft_strchr(tmp, '\n', BUFFER_SIZE) || res == 0)
			break;
	}
	if (buffer)
		free(buffer);
	return (tmp);
}
