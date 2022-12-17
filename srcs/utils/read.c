/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <42.fr>                             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 15:48:49 by marvin            #+#    #+#             */
/*   Updated: 2022/12/17 15:48:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "utils.h"
#include "globals.h"

static void	clear_buffer(char buffer[BUFFER_SIZE + 1])
{
	size_t	i;

	i = 0;
	while (i < BUFFER_SIZE + 1)
	{
		buffer[i] = '\0';
		i++;
	}
}

char	*read_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*output;
	size_t		i;

	if (fd < 0 || fd > FOPEN_MAX || BUFFER_SIZE < 0)
		return (NULL);
	output = NULL;
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n' && buffer[i + 1])
		ft_strreplace(&output, ft_strnjoin(output, buffer + i + 1, BUFFER_SIZE));
	clear_buffer(buffer);
	while (read(fd, buffer, BUFFER_SIZE) > 0)
	{
		i = 0;
		while (buffer[i] && buffer[i] != '\n')
			i++;
		ft_strreplace(&output, ft_strnjoin(output, buffer, i + 1));
		if (buffer[i] == '\n')
			break ;
		clear_buffer(buffer);
	}
	return (output);
}
