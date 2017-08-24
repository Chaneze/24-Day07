/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caroua <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 12:27:10 by caroua            #+#    #+#             */
/*   Updated: 2017/08/22 12:41:18 by caroua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_find_sep(char str, char *charset)
{
	int i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (charset[i] == str)
			return (1);
		i++;
	}
	return (0);
}

int		ft_count_w(char *str, char *charset)
{
	int i;
	int word;
	int count;

	i = 0;
	word = 0;
	count = 0;
	while (str[i] != '\0')
	{
		while (ft_find_sep(str[i], charset) == 0 && str[i] != '\0')
		{
			i++;
			word = 1;
		}
		if (ft_find_sep(str[i], charset) == 1)
			i++;
		if (word == 1)
		{
			count++;
			word = 0;
		}
	}
	return (count);
}

int		fs(char *str, char *charset, int i)
{
	int length;

	length = 0;
	while (ft_find_sep(str[i], charset) == 0 && str[i] != '\0')
	{
		length++;
		i++;
	}
	return (length);
}

char	**ft_split(char *str, char *charset)
{
	char	**d;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	if ((d = malloc(sizeof(d) * (ft_count_w(str, charset) + 1))) == NULL)
		return (NULL);
	while (str[i] != '\0')
	{
		while (ft_find_sep(str[i], charset) == 1)
			i++;
		if (str[i] != '\0')
		{
			k = 0;
			if ((d[j] = malloc(sizeof(*d) * (fs(str, charset, i) + 1))) == NULL)
				return (NULL);
			while (ft_find_sep(str[i], charset) == 0 && str[i])
				d[j][k++] = str[i++];
			d[j++][k] = '\0';
		}
	}
	d[j] = NULL;
	return (d);
}
