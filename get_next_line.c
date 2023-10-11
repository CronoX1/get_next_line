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

char    *get_next_line(int fd)
{
    char    *content;
    char    *final_content;
    int i;

    i = 0;
    content = (char *)malloc(sizeof(char) * BUFFER_SIZE);
    final_content = (char *)malloc(sizeof(char) * 100);
    if (!content || !final_content)
        return (NULL);
    read(fd, content, BUFFER_SIZE);
    while (ft_strchr(final_content, '\n') == 0)
    {
        read(fd, content, BUFFER_SIZE);
        final_content = ft_strjoin(final_content, content);
        free(content);
        content = (char *)malloc(sizeof(char) * BUFFER_SIZE);
    }
    free(content);
    while (final_content[i] && final_content[i] != '\n')
        i++;
    final_content[i] = '\0';
    if (!final_content)
        return (NULL);
    return (final_content);
}

/*char    *get_next_line(int fd)
{
    char    *content;
    char    *final_content;
    int final_i;
    static int  i = 0;

    final_i = 0;
    content = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
    final_content = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
    if (!content || !final_content)
        return (NULL);
    content[BUFFER_SIZE] = '\0';
    final_content[BUFFER_SIZE] = '\0';
    read(fd, content, BUFFER_SIZE);
    while (content[i] && content[i] != '\n')
    {
        final_content[final_i] = content[i];
        i++;
        final_i++;
    }
    i++;
    free(content);
    if (!final_content)
        return (NULL);
    return (final_content);
}*/