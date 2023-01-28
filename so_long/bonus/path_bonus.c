/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majmani <majmani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 18:16:37 by majmani           #+#    #+#             */
/*   Updated: 2023/01/23 15:13:03 by majmani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_path(int i, int j, char **map)
{
	if (map[i][j] == '1')
		return ;
	map[i][j] = '1';
	check_path(i + 1, j, map);
	check_path(i - 1, j, map);
	check_path(i, j + 1, map);
	check_path(i, j - 1, map);
}

int	check_path_valide(int k, int l, char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	check_path(k, l, map);
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C' || map[i][j] == 'P' || map[i][j] == 'E')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	check_path_e(int i, int j, char **map)
{
	if (map[i][j] == '1' || map[i][j] == 'E')
		return ;
	map[i][j] = '1';
	check_path_e(i + 1, j, map);
	check_path_e(i - 1, j, map);
	check_path_e(i, j + 1, map);
	check_path_e(i, j - 1, map);
}

int	check_path_valide_e(int k, int l, char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	check_path_e(k, l, map);
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C' || map[i][j] == 'P')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
