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
extern void	*ft_realloc(void *ptr, size_t newsize);
extern void	*ft_memmove(void *dest, const void *src, size_t n);
extern void	*ft_memcpy(void *dest, const void *src, size_t n);
int	ft_strlen(char *c);

#endif