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
#include <string.h>

void print_content(char *content, size_t size)
{
    while (size--)
    {
        printf("%hhu - %c\n", *content, *content);
        ++content;
    }
}

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
            //printf("check_content %p", result);
            if (result == NULL)
                return (NULL);
            result = ft_memcpy(result, content, i);
            result[i] = '\0';
            clear_content(content);
 //           free(*content);
            //content = NULL;
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
    char    *start;

    if (content == NULL)
    {
        content = malloc(sizeof(char) * (BUFFER_SIZE + 1));
        *content = '\0';
    }
    else
        content = ft_realloc(content, (sizeof(char) * (ft_strlen(content) + BUFFER_SIZE + 1)));
    start = content + ft_strlen(content);
    content_read = read(fd, start, BUFFER_SIZE);
    start[content_read] = '\0';
    if (content_read == -1 || content == NULL)
        return (NULL);
    line_break = check_content(content);
    if (content_read == 0)
    {
        if (*content)
        {
            char *temp = content;
            content = NULL;
            return (temp);
        }
        return NULL;
    }
    if (line_break == NULL)
        return get_next_line(fd);
    return (line_break);
}
