/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabela <mbabela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 11:03:11 by mbabela           #+#    #+#             */
/*   Updated: 2022/01/13 11:33:24 by mbabela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <errno.h>
# include <stdio.h>

int		get_file(char *file_name, int mode, int permession);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_putendl_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *s, int c);
int		check_access(char *path);
int		find_pwd(char **envp, char *str);
char	*find_path(char	**paths, char *cmd);
char	*get_cmd_path(char **envp, char	**cmd);
void	free_arr(char ***arr);
void	free_str(char **as);
int		size_cmd(char **argv, int argc);

#endif