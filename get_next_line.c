/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-al <aruiz-al@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:14:22 by aruiz-al          #+#    #+#             */
/*   Updated: 2023/09/20 15:14:31 by aruiz-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char    *check_content(char *content)
{
    int i;
    char    *result;

    i = 0;
    while (content[i])
    {
        if (content[i] == '\n')
        {
            result = malloc(sizeof(char) * (i + 1));
            if (result == NULL)
                return (NULL);
            result = ft_memmove(result, content, i);
            printf("Result vale: %s\n", result);
            return (result);
        }
        i++;
    }
    return (NULL);
}


char    *get_next_line(int fd)
{
    static char *content;
    int content_read;

    printf("Content vale: %s\n", content);
    if (content == NULL)
        content = malloc(sizeof(char) * BUFFER_SIZE + 1);
    else
    {
        printf("content mide: %d\n", ft_strlen(content));
        content = ft_realloc(content, (sizeof(char) * (ft_strlen(content) + BUFFER_SIZE + 1)));
    }
    printf("Content2 vale: %s\n", content);
    content_read = read(fd, &content[ft_strlen(content)], BUFFER_SIZE);
    if (content_read == -1)
        return (NULL);
    else if (content_read == 0)
        return (content);
    else
        return (check_content(content));
}