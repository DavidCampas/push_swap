#include "../../inc/get_next_line.h"

char    *ft_strncpy(char *dest, const char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (!dest || !src)
		return (NULL);
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

char    *ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	size_t	len_s1;
	size_t	len_s2;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	len_s1 = strlen(s1);
	len_s2 = strlen(s2);
	s3 = (char *) malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (!s3)
		return (NULL);
	ft_memcpy(s3, s1, len_s1);
	ft_memcpy(s3 + len_s1, s2, len_s2);
	s3[len_s1 + len_s2] = '\0';
	return (s3);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (!dest || !src)
		return (NULL);
	i = 0;
	while (i < n)
	{
		*((unsigned char *)dest + i) = *((unsigned char *)src + i);
		i++;
	}
	return (dest);
}

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*cpy;

	if (!s)
		return (NULL);
	len = strlen(s);
	cpy = (char *)malloc((len + 1) * sizeof(char));
	if (!cpy)
		return (NULL);
	ft_memcpy(cpy, s, len);
	cpy[len] = '\0';
	return (cpy);
}