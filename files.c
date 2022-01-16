/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabela <mbabela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 08:15:46 by mbabela           #+#    #+#             */
/*   Updated: 2022/01/13 11:35:05 by mbabela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_access(char *path)
{
	if (access(path, F_OK) == -1)
		ft_putstr_fd("file doesn't exist!\n", 2);
	else if (access(path, R_OK) == -1)
		ft_putstr_fd("No Permission!\n", 2);
	else if (access(path, W_OK) == -1)
		ft_putstr_fd("No Permission!\n", 2);
	else
		return (1);
	return (0);
}

int	find_pwd(char **envp, char *str)
{
	int	i;
	int	j;

	i = 0;
	while (envp[i])
	{
		j = 0;
		while (str[j] == envp[i][j])
			j++;
		if (str[j] == '\0')
			return (i);
		i++;
	}
	return (-1);
}

char	*find_path(char	**paths, char *cmd)
{
	int		i;
	char	*path;
	char	*part;

	i = 0;
	while (paths[i] && cmd[0] != '/')
	{
		part = ft_strjoin(paths[i], "/");
		path = ft_strjoin(part, cmd);
		free_str(&part);
		if (access(path, F_OK) == 0)
			return (path);
		free_str(&path);
		i++;
	}
	if (cmd[0] == '/')
		return ("");
	if (access(cmd, F_OK) == 0)
		return (cmd);
	return (NULL);
}

char	*get_cmd_path(char **envp, char	**cmd)
{
	char	**paths;
	char	*path;
	int		i;

	if (*cmd[0] == '/')
		return (*cmd);
	i = find_pwd(envp, "PATH=");
	paths = ft_split(envp[i] + 5, ':');
	path = find_path(paths, *cmd);
	free_arr(&paths);
	return (path);
}

int	get_file(char *file_name, int mode, int permession)
{
	int	pos;

	if ((mode == (O_RDWR | O_CREAT | O_TRUNC)) || (check_access(file_name)))
	{
		if (permession)
			pos = open(file_name, mode, permession);
		else
			pos = open(file_name, mode);
		return (pos);
	}
	return (-1);
}
