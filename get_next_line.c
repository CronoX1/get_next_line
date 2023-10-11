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
/*
#include "get_next_line.h"
#include <stdio.h>

int    read_file(int fd, char *content)
{
    if (content == NULL)
        content = malloc(sizeof(char) * BUFFER_SIZE + 1);
    else
        content = ft_realloc(content, (sizeof(char) * (ft_strlen(content) + BUFFER_SIZE)));
    return (read(fd, &content[ft_strlen(content)], BUFFER_SIZE));
}

char    *check_content(char *content, int fd)
{
    static int i = 0;
    char    *result;

    while (content[i])
    {
        if (content[i] == '\n')
        {
            result = malloc(sizeof(char) * (i + 1));
            if (result == NULL)
                return (NULL);
            result = ft_memcpy(result, content, i);
            i++;
            return (result);
        }
        i++;
    }
    return (get_next_line(fd));
}


char    *get_next_line(int fd)
{
    static char *content = NULL;
    int read_result;

    read_result = read_file(fd, content);
    if (read_result == -1)
        return (NULL);
    else if (read_result == 0)
        return (content);
    if (ft_strchr(content, '\n') == 0)
        content = check_content(content, fd);
    return (content);
}
*/
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
    static int i = 0;
    char    *result;

    while (content[i])
    {
        if (content[i] == '\n')
        {
            result = malloc(sizeof(char) * (i + 1));
            if (result == NULL)
                return (NULL);
            result = ft_memcpy(result, content, i);
            i++;
            free(content);
            return (result);
        }
        i++;
    }
    return (content);
}


char    *get_next_line(int fd)
{
    static char *content;
    static int content_read;

    if (content == NULL)
        content = malloc(sizeof(char) * BUFFER_SIZE + 1);
    else
        content = ft_realloc(content, (sizeof(char) * (ft_strlen(content) + BUFFER_SIZE + 1)));
    content_read = read(fd, &content[ft_strlen(content)], BUFFER_SIZE);
    if (content_read == -1)
        return (NULL);
    else if (content_read == 0)
        return (content);
    else
        return (check_content(content));
}