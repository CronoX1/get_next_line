/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-al <aruiz-al@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:14:38 by aruiz-al          #+#    #+#             */
/*   Updated: 2023/09/20 15:14:47 by aruiz-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	number_of_words(char const *s, char c)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (s[i])
	{
		if ((s[i] != c) && (s[i + 1] == c || s[i + 1] == '\0'))
			n++;
		i++;
	}
	return (n);
}

static char	*get_next_word(char const *s, char c, int *i)
{
	char	*word;
	int		start;
	int		len;

	while (s[*i] && s[*i] == c)
		(*i)++;
	start = *i;
	while (s[*i] && s[*i] != c)
		(*i)++;
	len = *i - start;
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	ft_strlcpy(word, s + start, len + 1);
	return (word);
}

static char	**free_all(char **strings)
{
	int	i;

	i = 0;
	while (strings[i])
	{
		free(strings[i]);
		++i;
	}
	free(strings);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		words_number;
	char	**strings;
	int		i_final_array;
	int		i;

	if (!s)
		return (NULL);
	words_number = number_of_words(s, c);
	strings = malloc((words_number + 1) * sizeof(char *));
	if (strings == NULL)
		return (NULL);
	i_final_array = 0;
	i = 0;
	while (i_final_array < words_number)
	{
		strings[i_final_array] = get_next_word(s, c, &i);
		if (!strings[i_final_array])
			return (free_all(strings));
		++i_final_array;
	}
	strings[i_final_array] = NULL;
	return (strings);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	while ((dstsize - 1) > i && src[i])
	{
		dest[i] = src[i];
		++i;
	}
	dest[i] = '\0';
	return (ft_strlen(src));
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (*s)
	{
		++i;
		++s;
	}
	return (i);
}

int ft_strchr(const char *s, int c)
{
    int i;

    i = 0;
	while (s[i] && s[i] != (char)c)
		i++;
	if (s[i] == (char)c)
		return (1);
	return (0);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*new_src;
	unsigned char	*new_dest;

	if (!dest && !src)
		return (NULL);
	i = 0;
	new_src = (unsigned char *) src;
	new_dest = (unsigned char *) dest;
	while (i < n)
	{
		new_dest[i] = new_src[i];
		++i;
	}
	return (new_dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	char	*final_string;

	final_string = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (final_string == NULL)
		return (NULL);
	i = 0;
	final_string = ft_memcpy(final_string, s1, ft_strlen(s1));
	while (s2[i])
	{
		final_string[ft_strlen(s1) + i] = s2[i];
		++i;
	}
	return (final_string);
}