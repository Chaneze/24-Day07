/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caroua <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/16 16:04:22 by caroua            #+#    #+#             */
/*   Updated: 2017/08/16 18:05:22 by caroua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int		ft_total_len(int argc, char **argv)
{
	int i;
	int length;

	i = 1;
	length = 0;
	while (i < argc)
	{
		length = length + ft_strlen(argv[i]) + 1;
		i++;
	}
	return (length);
}

char	*ft_strcat(char *dest, char *src)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	while (src[j] != '\0')
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

char	*ft_concat_params(int argc, char **argv)
{
	int		i;
	int		j;
	char	*dest;

	dest = (char*)malloc(sizeof(*dest) * ft_total_len(argc, argv));
	i = 0;
	while (i < argc - 1)
	{
		dest = ft_strcat(dest, argv[i + 1]);
		if (i != argc - 2)
		{
			j = 0;
			while (dest[j] != '\0')
				j++;
			dest[j] = '\n';
			dest[j + 1] = '\0';
		}
		i++;
	}
	return (dest);
}
