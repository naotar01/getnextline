/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntaranto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 12:57:06 by ntaranto          #+#    #+#             */
/*   Updated: 2024/11/28 14:08:25 by ntaranto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char *reste;
	char	buffer[BUFFER_SIZE + 1];
	ssize_t bytes_read;
	int	i;
	char	*ligne;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (reste)
	{
		ligne = ft_strdup(reste);
		if (!ligne)
			return (NULL);
		free(reste);
		reste = NULL;
	}
	else
	{
		ligne = ft_strdup("");
		if (!ligne)
			return (NULL);
	}
	bytes_read = 0;
	while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[bytes_read] = '\0';
		ligne = ft_strjoin(ligne, buffer);
		if (!ligne)
			return (NULL);
		i = 0;
		while(ligne[i] != '\0')
		{
			if (ligne[i] == '\n')
			{
				reste = ft_strdup(ligne + i + 1);
				if (reste == NULL)
					return (NULL);
				ligne[i + 1] = '\0';
				return (ligne);
			}
			i++;
		}
	}
	if (bytes_read < 0)
	{
		free(ligne);
		return (NULL);
	}
	if (bytes_read == 0 && ligne[0] != '\0')
		return (ligne);
	return (NULL);
}
