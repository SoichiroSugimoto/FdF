/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosugimo <sosugimo@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 13:39:10 by sosugimo          #+#    #+#             */
/*   Updated: 2021/10/19 13:39:11 by sosugimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int	all_error_free(char **s1, char **s2)
{
	free(*s1);
	*s1 = NULL;
	free(*s2);
	*s2 = NULL;
	return (ERROR);
}

int	error_free(char **buf)
{
	free(*buf);
	*buf = NULL;
	return (ERROR);
}

int	final_free(char **save, int i)
{
	if (i == 0)
		free(*save);
	return (i);
}
