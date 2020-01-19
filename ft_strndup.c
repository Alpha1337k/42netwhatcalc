/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strndup.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: okruitho <okruitho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/12 14:13:26 by okruitho       #+#    #+#                */
/*   Updated: 2020/01/12 14:18:57 by okruitho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_netwhat.h"
#include <stdlib.h>

char	*ft_strndup(char *s1, int len)
{
	int		x;
	int		i;
	char	*rval;

	x = 0;
	i = 0;
	rval = (char *)malloc(sizeof(char) * len);
	if (rval != 0)
	{
		while (x != len)
		{
			rval[x] = s1[i];
			if (s1[i] != 0)
				i++;
			x++;
		}
	}
	return (rval);
}
