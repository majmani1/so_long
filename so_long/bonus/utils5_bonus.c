/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majmani <majmani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 14:00:05 by majmani           #+#    #+#             */
/*   Updated: 2023/01/26 15:08:05 by majmani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_help4(char **ligne, t_player *player, int c)
{
	if ((ligne[player->y][player->x + 1] != '1'
		&& ligne[player->y][player->x + 1] != 'E'
		&& ligne[player->y][player->x + 1] != 'x') && c == 1)
		return (1);
	else if ((ligne[player->y][player->x - 1] != '1'
		&& ligne[player->y][player->x - 1] != 'E'
		&& ligne[player->y][player->x - 1] != 'x') && c == 2)
		return (1);
	else if ((ligne[player->y - 1][player->x] != '1'
		&& ligne[player->y - 1][player->x] != 'E'
		&& ligne[player->y - 1][player->x] != 'x') && c == 3)
		return (1);
	else if ((ligne[player->y + 1][player->x] != '1'
		&& ligne[player->y + 1][player->x] != 'E'
		&& ligne[player->y + 1][player->x] != 'x') && c == 4)
		return (1);
	return (0);
}

void	put_enemie(t_player *player, t_enemie *en)
{
	player->map = en->map;
	en->destination = malloc(sizeof(int) * nember_enemie(en->map));
	en->lisser = malloc(sizeof(int) * nember_enemie(en->map));
	en->limen = malloc(sizeof(int) * nember_enemie(en->map));
	(ft_add_zero(en, 3), ft_add_zero(en, 2));
	(ft_add_zero(en, 1), mlx_loop_hook(en->mlx, ft_move_enemie, en));
}
