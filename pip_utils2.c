/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pip_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwalad <zwalad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 15:25:34 by zwalad            #+#    #+#             */
/*   Updated: 2022/02/20 23:34:17 by zwalad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "pipex.h"

static int	ft_wnb(const char *str, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if ((str[0] != c && i == 0) || (str[i] != c && str[i - 1] == c))
		{
			i++;
			j++;
		}
		if (str[i])
			i++;
	}
	return (j);
}

static void	ft_free(char **str, int wnbr)
{
	int	i;

	i = 0;
	while (i < wnbr)
	{
		free(str[i]);
		i++;
	}
}

static void	alloc(char **sp, const char *s, char c, int wnbr)
{
	int	i;
	int	j;
	int	index;

	i = 0;
	j = 0;
	while (j < wnbr - 1)
	{
		while (s[i] == c && s[i] != '\0')
			i++;
			index = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		sp [j] = ft_substr(s, index, i - index);
		if (!sp[j])
		{
			ft_free(sp, j);
			break ;
		}
		j++;
	}
	sp[j] = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		wnbr;

	if (s == NULL)
		return (NULL);
	wnbr = ft_wnb(s, c) + 1;
	str = malloc(sizeof(char *) * wnbr);
	if (str == NULL)
		return (NULL);
	alloc(str, s, c, wnbr);
	return (str);
}
