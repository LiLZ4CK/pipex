/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pip_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwalad <zwalad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 15:23:58 by zwalad            #+#    #+#             */
/*   Updated: 2022/02/21 00:50:51 by zwalad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "pipex.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strcat(char *dest, const char *src)
{
	int	j;

	j = 0;
	while (src[j])
	{
		dest[j] = src[j];
		j++;
	}
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		len;
	int		i;
	int		j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = 0;
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	len = i + j + 1;
	j = 0;
	str = (char *)malloc(len);
	if (!str)
		return (NULL);
	ft_strcat(str, s1);
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	size_t			i;
	unsigned int	t;

	i = 0;
	if (!s)
		return (NULL);
	t = ft_strlen(s);
	if (len > t + 1)
		len = t + 1;
	str = malloc(len + 1);
	if (str == NULL)
		return (NULL);
	while (len > 0 && start + i <= t && s[start + i])
	{
		str[i] = s[start + i];
		i++;
		len --;
	}
	str[i] = '\0';
	return (str);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	if (n == 0)
		return (0);
	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (i < (n - 1) && str1[i] == str2[i] && str1[i] && str2[i])
		i++;
	return (str1[i] - str2[i]);
}
