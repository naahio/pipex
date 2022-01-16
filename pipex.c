/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabela <mbabela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 13:41:12 by mbabela           #+#    #+#             */
/*   Updated: 2022/01/13 11:52:19 by mbabela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_str(char **as)
{
	if (as && *as)
	{
		free(*as);
		*as = NULL;
	}
}

void	free_arr(char ***arr)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	while ((*arr)[i])
	{
		free_str(*arr + i);
		i++;
	}
	free(*arr);
	*arr = NULL;
}

void	child_proc_2(int *fd, char **argv, char **envp, int file_pos)
{
	int		pos;
	char	**cmd;
	char	*path;

	pos = get_file(argv[file_pos], O_RDWR | O_CREAT | O_TRUNC, 0644);
	wait(0);
	close(fd[1]);
	dup2(fd[0], 0);
	close(fd[0]);
	dup2(pos, 1);
	cmd = ft_split(argv[file_pos - 1], ' ');
	path = get_cmd_path(envp, cmd);
	if (execve(path, cmd, envp) == -1)
	{
		ft_putstr_fd("commande not found : ", 2);
		ft_putendl_fd(cmd[0], 2);
		free_arr(&cmd);
		free_str(&path);
		exit(0);
	}
}

void	child_proc(int *fd, char **argv, char **envp)
{
	int		pos;
	char	**cmd;

	close(fd[0]);
	dup2(fd[1], 1);
	close(fd[1]);
	pos = get_file(argv[1], O_RDONLY, 0);
	dup2(pos, 0);
	cmd = ft_split(argv[2], ' ');
	if (execve(get_cmd_path(envp, cmd), cmd, envp) == -1)
	{
		ft_putstr_fd("commande not found : ", 2);
		ft_putendl_fd(cmd[0], 2);
		free_arr(&cmd);
		exit(0);
	}
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid;
	pid_t	pid2;

	if (!size_cmd(argv, argc) || (check_access(argv[1]) == 0))
		return (0);
	if (pipe(fd) == -1)
		return (-1);
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return (0);
	}
	if (pid == 0)
		child_proc(fd, argv, envp);
	else
	{
		pid2 = fork();
		if (pid2 == 0)
			child_proc_2(fd, argv, envp, argc - 1);
		else
			wait(0);
	}
	return (0);
}
