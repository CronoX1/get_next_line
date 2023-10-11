/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-al <aruiz-al@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:13:51 by aruiz-al          #+#    #+#             */
/*   Updated: 2023/09/20 15:14:06 by aruiz-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
#include <stdlib.h>
#include <unistd.h>

extern char *get_next_line(int fd);
extern char	**ft_split(char const *s, char c);
extern size_t	ft_strlen(const char *s);
extern size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize);
extern int ft_strchr(const char *s, int c);
extern char *ft_read(int fd, char *content, int amount);
extern char	*ft_strjoin(char const *s1, char const *s2);
extern void	*ft_memcpy(void *dest, const void *src, size_t n);

#endif