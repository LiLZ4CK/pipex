/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwalad <zwalad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 16:51:08 by zwalad            #+#    #+#             */
/*   Updated: 2022/02/22 14:57:32 by zwalad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "pipex.h"

char	*sub_main(char *cmd, char **env)
{
	int		i;
	char	**paths;
	char	*str;
	char	*sstr;

	i = 0;
	if (!access(cmd, F_OK))
		return (cmd);
	while (ft_strncmp(env[i], "PATH", 4))
		i++;
	paths = ft_split(env[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		str = ft_strjoin("/", cmd);
		sstr = ft_strjoin(paths[i], str);
		if (!access(sstr, F_OK))
			return (one_line(paths, str, sstr));
		free(sstr);
		free(str);
		i++;
	}
	return (cmd);
}

t_zero	the_z(char **argv, char **env)
{
	t_zero	z;

	z.cmd1 = ft_split(argv[2], ' ');
	z.cmd2 = ft_split(argv[3], ' ');
	z.path1 = sub_main(z.cmd1[0], env);
	z.path2 = sub_main(z.cmd2[0], env);
	z.fd2 = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (z.fd2 == -1)
		herror("file 2");
	z.fd1 = open(argv[1], O_RDWR);
	if (z.fd1 == -1)
		herror("file 1");
	return (z);
}

void	exec1(int fd0, int fd1, t_zero z)
{
	close(fd0);
	dup2(fd1, 1);
	execve(z.path1, z.cmd1, NULL);
}

void	exec2(int fd0, int fd1, t_zero z)
{
	close(fd1);
	dup2(z.fd2, 1);
	dup2(fd0, 0);
	execve(z.path2, z.cmd2, NULL);
}

int	main(int argc, char **argv, char **env)
{
	t_zero	z;
	int		pid[2];
	int		fd[2];

	if (argc != 5)
		herror("number of argument");
	z = the_z(argv, env);
	if (pipe(fd) == -1)
		herror("error");
	pid[0] = fork();
	if (pid[0] == -1)
		herror("1st fork error");
	dup2(z.fd1, 0);
	if (pid[0] == 0)
		exec1(fd[0], fd[1], z);
	pid[1] = fork();
	if (pid[1] == -1)
		herror("2ed fork error");
	if (pid[1] == 0)
		exec2(fd[0], fd[1], z);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid[0], 0, 0);
	waitpid(pid[1], 0, 0);
	return (0);
}
