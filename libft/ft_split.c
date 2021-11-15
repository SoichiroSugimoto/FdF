/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosugimo <sosugimo@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 19:35:02 by sosugimo          #+#    #+#             */
/*   Updated: 2021/10/21 20:14:04 by sosugimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int	strbycnt(char const *s, char c)
{
	size_t	i;
	int		id;

	id = 0;
	if (!ft_strlen(s))
		return (0);
	if (s[0] != c)
		id++;
	i = 0;
	while (s[i + 1])
	{
		if (s[i] == c && s[i + 1] != c)
			id++;
		i++;
	}
	return (id);
}

char	**ft_all_free(char **p)
{
	int	j;

	j = 0;
	while (p[j])
	{
		free(p[j]);
		j++;
	}
	free(p);
	return (NULL);
}

int	cnt_by_not_c(const char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] == c)
		i++;
	return (i);
}

int	cnt_by_c(const char *str, char c, int len)
{
	while (str[len] && str[len] != c)
		len++;
	return (len);
}

char	**ft_split(char const *s, char c)
{
	char	**p;
	int		i;
	int		len;

	p = (char **)malloc(sizeof(char *) * (strbycnt(s, c) + 1));
	if (!s || !p)
		return (NULL);
	i = 0;
	while (*s)
	{
		len = 0;
		s += cnt_by_not_c(s, c);
		len += cnt_by_c(s, c, len);
		if (*s)
		{
			p[i] = (char *)malloc(sizeof(char) * (len + 1));
			if (!p)
				return (ft_all_free(p));
			ft_strlcpy(p[i], s, len + 1);
			s += len;
			i++;
		}
	}
	p[i] = NULL;
	return (p);
}
