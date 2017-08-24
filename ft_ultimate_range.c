/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caroua <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/16 14:50:57 by caroua            #+#    #+#             */
/*   Updated: 2017/08/16 14:56:10 by caroua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_ultimate_range(int **range, int min, int max)
{
	int i;
	int *tmp;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	tmp = (int*)malloc(sizeof(*tmp) * (max - min));
	i = 0;
	while (min < max)
	{
		tmp[i] = min;
		i++;
		min++;
	}
	*range = tmp;
	return (i);
}
