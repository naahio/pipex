/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabela <mbabela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 14:11:30 by mbabela           #+#    #+#             */
/*   Updated: 2022/01/16 13:20:37 by mbabela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	size_cmd(char **argv, int argc)
{
	int	i;

	if (argc != 5)
	{
		write (2, "Error no args!\n", 16);
		return (0);
	}
	i = 1;
	while (argv[i])
	{
		if (!ft_strlen(argv[i]))
		{
			write (2, "cmd/file does not exist! \n", 26);
			return (0);
		}
		i++;
	}
	return (1);
}
