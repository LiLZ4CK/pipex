/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwalad <zwalad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 16:50:12 by zwalad            #+#    #+#             */
/*   Updated: 2022/02/22 14:52:58 by zwalad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include	<unistd.h>
# include	<stdlib.h>
# include	<stdio.h>
# include	<fcntl.h>

typedef struct t_zero
{
	char	*path1;
	char	*path2;
	char	**cmd1;
	char	**cmd2;
	int		fd1;
	int		fd2;
}	t_zero;

char	*sub_main(char *argv, char **env);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strcat(char *dest, const char *src);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
void	exec1(int fd0, int fd1, t_zero z);
void	exec2(int fd0, int fd1, t_zero z);
void	the_free(char **str);
int		herror(char *str);
char	*ft_access(char **str);
char	*one_line(char	**paths, char *str, char *sstr);

#endif