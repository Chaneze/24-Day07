/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caroua <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 09:59:30 by caroua            #+#    #+#             */
/*   Updated: 2017/08/18 14:45:09 by caroua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_count_words(char *str)
{
	int i;
	int word;
	int count;

	i = 0;
	word = 0;
	count = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\t' && str[i] != ' ' \
				&& str[i] != '\n' && str[i])
		{
			i++;
			word = 1;
		}
		if (str[i] == '\t' || str[i] == ' ' \
				|| str[i] == '\n' || str[i] == '\0')
			i++;
		if (word == 1)
		{
			count++;
			word = 0;
		}
	}
	return (count);
}

int		ft_s(char *str, int i)
{
	int length;

	length = 0;
	while (str[i] != '\t' && str[i] != ' ' && str[i] != '\n' && str[i] != '\0')
	{
		length++;
		i++;
	}
	return (length);
}

char	**ft_split_whitespaces(char *str)
{
	char	**dest;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	if ((dest = malloc(sizeof(dest) * (ft_count_words(str) + 1))) == NULL)
		return (NULL);
	while (str[i] != '\0')
	{
		while ((str[i] == '\t' || str[i] == ' ' || str[i] == '\n') && str[i])
			i++;
		if (str[i] != '\0')
		{
			k = 0;
			if ((dest[j] = malloc(sizeof(*dest) * (ft_s(str, i) + 1))) == NULL)
				return (NULL);
			while (str[i] != '\t' && str[i] != ' ' && str[i] != '\n' && str[i])
				dest[j][k++] = str[i++];
			dest[j++][k] = '\0';
		}
	}
	dest[j] = NULL;
	return (dest);
}
