/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majmani <majmani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 10:24:08 by majmani           #+#    #+#             */
/*   Updated: 2023/01/18 13:43:54 by majmani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_lenght(char **ligne)
{
	int	i;

	i = 0;
	while (ligne[i])
	{
		if ((ft_strlen(ligne[i]) != ft_strlen(ligne[i + 1])
				&& ligne[i + 1] != '\0'))
			return (0);
		i++;
	}
	return (1);
}

int	ft_composed_alphapet(char c)
{
	int		i;
	char	*s;

	i = 0;
	s = "01CEP";
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_player(char **ligne, char sh)
{
	int	i;
	int	j;
	int	p;

	p = 0;
	i = -1;
	while (ligne[++i])
	{
		j = -1;
		while (ligne[i][++j])
		{
			if (ligne[i][j] == sh)
				p++;
		}
	}
	if (sh == 'C')
	{
		if (p < 1)
			return (0);
	}
	else if (sh != 'C' && (p > 1 || p < 1))
		return (0);
	return (1);
}

int	ft_composed(char **ligne)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 0;
	while (ligne[i])
	{
		j = 0;
		while (ligne[i][j])
		{
			if (ft_composed_alphapet(ligne[i][j]) == 0)
				return (0);
			j++;
		}
		i++;
	}
	if (ft_player(ligne, 'P') == 0 || ft_player(ligne, 'C') == 0
		|| ft_player(ligne, 'E') == 0)
		return (0);
	return (1);
}

int	ft_wall(char **ligne, char *map)
{
	int	i;
	int	j;
	int	end;

	i = 1;
	j = 0;
	end = ft_lenght_map(map);
	while (ligne[0][j] != '\0')
	{
		if (ligne[0][j] != '1' || ligne[end - 1][j] != '1')
			return (0);
		j++;
	}
	while (i < end)
	{
		if (ligne[i][0] != '1' || ligne[i][ft_strlen(ligne[0]) - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}
