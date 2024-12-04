/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntaranto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:04:53 by ntaranto          #+#    #+#             */
/*   Updated: 2024/11/28 14:06:31 by ntaranto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int    main(void)
{
    int        fd;
    char    *ligne;

    fd = open("text.txt", O_RDONLY);
    if (fd < 0)
    {
        perror("Error opening file");
        return (1);
    }
    while ((ligne = get_next_line(fd)) != NULL)
    {
        printf("Ligne lue : %s\n", ligne);
        free_ligne(ligne);
    }
    printf("Fin du fichier.\n");
    close(fd);
    return (0);
}
