/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caroua <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 11:41:20 by caroua            #+#    #+#             */
/*   Updated: 2017/08/21 20:26:04 by caroua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0 || nb == 1)
		return (1);
	if (power == 1)
		return (nb);
	else
		return (nb = nb * ft_power(nb, power - 1));
}

int		ft_nb_in_basefrom(char *nbr, char *base_from)
{
	int i;
	int j;
	int rslt;
	int size_nbr;
	int size_bf;

	i = 0;
	rslt = 0;
	size_nbr = 0;
	size_bf = 0;
	while (nbr[size_nbr] != '\0')
		size_nbr++;
	while (base_from[size_bf] != '\0')
		size_bf++;
	while (nbr[i] != '\0')
	{
		j = 0;
		while (nbr[i] != base_from[j])
			j++;
		rslt = rslt + j * ft_power(size_bf, size_nbr - 1 - i);
		i++;
	}
	return (rslt);
}

char	*ft_nb_in_baseto(char *base_to, int rslt, int power, int size_bt)
{
	int		factor;
	int		i;
	char	*dest;

	dest = (char*)malloc(sizeof(*dest) * (power + 1));
	i = 0;
	if (rslt == 0)
		dest[i++] = base_to[0];
	while (rslt > 0)
	{
		factor = 0;
		while ((factor * ft_power(size_bt, power - 1)) <= rslt)
			factor++;
		dest[i] = base_to[factor - 1];
		rslt = rslt - (factor - 1) * ft_power(size_bt, power - 1);
		power--;
		i++;
	}
	while (power - 1 >= 0)
	{
		dest[i++] = base_to[0];
		power--;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		size_bt;
	int		rslt;
	int		power;
	char	*dest;

	size_bt = 0;
	while (base_to[size_bt] != '\0')
		size_bt++;
	rslt = ft_nb_in_basefrom(nbr, base_from);
	power = 0;
	while (ft_power(size_bt, power) <= rslt)
		power++;
	dest = (char*)malloc(sizeof(*dest) * (power + 1));
	dest = ft_nb_in_baseto(base_to, rslt, power, size_bt);
	return (dest);
}
