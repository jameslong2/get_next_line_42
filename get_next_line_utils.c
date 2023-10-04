
#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	size_t	l;

	l = 0;
	if (!s)
		return (l);
	while (s[l])
		l++;
	l++;
	return (l);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	h[3];

	h[0] = ft_strlen(src);
	h[1] = ft_strlen(dst);
	i = 0;
	if (dstsize == 0)
		return (h[0]);
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (h[0]);
}

void	initjoin(char const *s1, char const *s2, size_t *i)
{
	i[0] = 0;
	i[1] = 0;
	i[2] = ft_strlen(s1) -2;
	i[3] = ft_strlen(s1) + ft_strlen(s2) - 1;
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*tmp;
	size_t		i[4];
	char	*og;

	initjoin(s1, s2, i);
	og = s1;
	tmp = (char *)malloc(i[3] * sizeof(char));
	if (tmp == 0)
		return (0);
	else if (ft_strlen(s1) <= 1 && ft_strlen(s2) > 1)
		ft_strlcpy(tmp, (const char *)s2, (size_t)ft_strlen(s2));
	else if (ft_strlen(s2) <= 1 && ft_strlen(s1) > 1)
		ft_strlcpy(tmp, (const char *)s1, (size_t)ft_strlen(s1));
	else if (ft_strlen(s1) > 1 && ft_strlen(s2) > 1)
	{
		while (i[0] < i[3] - 2)
		{
			if (*s1)
				tmp[i[1]++] = *((char *)s1++);
			if (*s2)
				tmp[i[2]++] = *((char *)s2++);
			i[0]++;
		}
		tmp[i[0]] = '\0';
	}
	else
	{
		free(tmp);
		return (0);
	}
	if (og)
		free(og);
	return (tmp);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (*(s + i))
	{
		if (*(s + i) == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)(s + i));
	else
		return (0);
}
