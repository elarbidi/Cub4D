# include "../cub3d.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int	i;
	int	j;

	if (*needle == '\0')
		return ((char *) haystack);
	i = 0;
	while (haystack[i])
	{
		j = 0;
		while (needle[j] == haystack[i + j])
		{
			if (needle[j + 1] == '\0')
				return ((char *) &haystack[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}

char	*skip_spaces(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] <= 32)
			i++;
		else
			break;
	}
	return (ft_substr(str, i, ft_strlen(str)));
}

int	check_spaces(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] <= 32)
			return (ERROR);
		i++;
	}
	return (SUCCES);
}

char	*ft_strcpy(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s2[i])
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*_s1;
	unsigned char	*_s2;
	size_t			i;

	_s1 = (unsigned char *) s1;
	_s2 = (unsigned char *) s2;
	i = 0;
	while (_s1[i])
	{
		if (!(_s1[i] == _s2[i] && _s1[i] != '\0' && _s2[i] != '\0'))
			return (_s1[i] - _s2[i]);
		i++;
	}
	return (SUCCES);
}
