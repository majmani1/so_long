/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majmani <majmani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:29:54 by majmani           #+#    #+#             */
/*   Updated: 2023/01/26 19:54:32 by majmani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_reinitialisation(int *c, int i)
{
	if (i == 2)
	{
		if ((*c) > 1)
			(*c) = 0;
	}
	else if (i == 0)
	{
		if ((*c) <= 1 || (*c) == 0 || (*c) > 3)
			(*c) = 2;
	}
	else if (i == 1)
	{
		if ((*c) <= 3 || (*c) == 0 || (*c) > 5)
			(*c) = 4;
	}
	else if (i == 13)
	{
		if ((*c) <= 5 || (*c) == 0 || (*c) > 7)
			(*c) = 6;
	}
}

t_player	ft_position_chfar(t_player *player, char **ligne)
{
	int	i;
	int	j;

	i = 0;
	while (ligne[i])
	{
		j = 0;
		while (ligne[i][j])
		{
			if (ligne[i][j] == 'P')
			{
				player->y = i;
				player->x = j;
				return (*player);
			}
			j++;
		}
		i++;
	}
	return (*player);
}

t_exit	ft_position_bab(t_exit *b, char **ligne)
{
	int	i;
	int	j;

	i = 0;
	while (ligne[i])
	{
		j = 0;
		while (ligne[i][j])
		{
			if (ligne[i][j] == 'E')
			{
				b->tol = i;
				b->aard = j;
				return (*b);
			}
			j++;
		}
		i++;
	}
	return (*b);
}

int	ft_count_coin(char **ligne)
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
			if (ligne[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

void	ft_put_image(char **ligne, t_player *player)
{
	int		i;
	int		j;

	i = -1;
	j = 0;
	mlx_clear_window(player->mlx, player->mlx_win);
	while (ligne[++i])
	{
		j = 0;
		while (ligne[i][j])
		{
			ft_help2(player, "textures/arde.xpm", j, i);
			if (ligne[i][j] == 'P')
				ft_help2(player, "playerr/0.xpm", j, i);
			else if (ligne[i][j] == 'E')
				ft_help2(player, "textures/ss.xpm", j, i);
			else if (ligne[i][j] == '1')
				ft_help2(player, "textures/wallf.xpm", j, i);
			else if (ligne[i][j] == 'C')
				ft_help2(player, "textures/spray1.xpm", j, i);
			j++;
		}
	}
}
