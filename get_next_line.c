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

void    clear_content(char *content)
{
    int i;

    i = 0;
    while (content[i])
    {
        content[i] = '\0';
        i++;
    }
}

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
            result = ft_memcpy(result, content, i);
            clear_content(content);
            free(content);
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
    char    *line_break;

    if (content == NULL)
    {
        content = malloc(sizeof(char) * BUFFER_SIZE + 1);
        content[BUFFER_SIZE] = '\0';
    }
    else
    {
        content = ft_realloc(content, (sizeof(char) * (ft_strlen(content) + BUFFER_SIZE + 1)));
        content[ft_strlen(content) + BUFFER_SIZE] = '\0';
    }
    content_read = read(fd, &content[ft_strlen(content)], BUFFER_SIZE);
    if (content_read == -1)
        return (NULL);
    else if (content_read == 0 || content == NULL)
        return (content);
    line_break = check_content(content);
    if (line_break == NULL)
        return (get_next_line(fd));
    else
    {
        return (line_break);
    }
    return (NULL);
}
