/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntaranto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 12:59:10 by ntaranto          #+#    #+#             */
/*   Updated: 2024/11/27 12:59:12 by ntaranto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

# define BUFFER_SIZE 42

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
void	free_ligne(char *ligne);
char	*ft_strdup(const char *src);
int	main(void);

#endif
