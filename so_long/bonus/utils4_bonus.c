/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majmani <majmani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 13:59:43 by majmani           #+#    #+#             */
/*   Updated: 2023/01/26 19:54:36 by majmani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_add_zero(t_enemie *en, int c)
{
	int	i;

	i = -1;
	if (c == 1)
	{
		while (++i < nember_enemie(en->map))
			en->destination[i] = 0;
	}
	if (c == 2)
	{
		while (++i < nember_enemie(en->map))
			en->limen[i] = 0;
	}
	if (c == 3)
	{
		while (++i < nember_enemie(en->map))
			en->lisser[i] = 4;
	}
}

void	ft_initialis(t_enemie *en, t_player *player, char *l, char **ligne)
{
	player->path = ft_split(l, '\n');
	player->path_e = ft_split(l, '\n');
	en->position = enemie(ligne);
	en->map = ligne;
	player->map = en->map;
	player->coin = ft_count_coin(ligne);
	player->step = 0;
}

void	ft_help3(t_enemie *player, char *l, int i, int j)
{
	t_data	img;

	img.img = mlx_xpm_file_to_image(player->mlx, l,
			&player->width, &player->height);
	mlx_put_image_to_window(player->mlx, player->mlx_win,
		img.img, i * 60, j * 60);
}

int	ft_conditons(t_enemie *en, int i, int c)
{
	if (((en->map[en->position[i][1]][en->position[i][0] + 1] == 'P'
				&& en->destination[i] == 0)
				|| (en->map[en->position[i][1]][en->position[i][0] - 1] == 'P'
					&& en->destination[i] == 1)
					|| en->map[en->position[i][1]][en->position[i][0]] == 'P')
					&& c == 1)
		return (1);
	if (((en->map[en->position[i][1]][en->position[i][0] + 1] == '1'
				|| en->map[en->position[i][1]][en->position[i][0] + 1] == 'C'
				|| en->map[en->position[i][1]][en->position[i][0] + 1] == 'E'))
				&& c == 2)
		return (1);
	if ((en->map[en->position[i][1]][en->position[i][0] - 1] == '1'
				|| en->map[en->position[i][1]][en->position[i][0] - 1] == 'C'
				|| en->map[en->position[i][1]][en->position[i][0] + 1] == 'E')
				&& c == 3)
		return (1);
	return (0);
}

void	ft_change_destination(t_enemie *en, int i, int c)
{
	if (c == 0)
	{
		if (en->limen[i] > 3)
			en->limen[i] = 0;
		en->map[en->position[i][1]][en->position[i][0]] = '0';
		en->map[en->position[i][1]][en->position[i][0] + 1] = 'x';
		ft_help3(en, "textures/arde.xpm",
			en->position[i][0], en->position[i][1]);
		en->position[i][0] = en->position[i][0] + 1;
		ft_move1(en, en->position[i][0], en->position[i][1], en->limen[i]);
		en->limen[i]++;
	}
	if (c == 1)
	{
		if (en->lisser[i] > 7)
			en->lisser[i] = 4;
		en->map[en->position[i][1]][en->position[i][0]] = '0';
		en->map[en->position[i][1]][en->position[i][0] - 1] = 'x';
		ft_help3(en, "textures/arde.xpm", en->position[i][0],
			en->position[i][1]);
		en->position[i][0] = en->position[i][0] - 1;
		ft_move1(en, en->position[i][0], en->position[i][1], en->lisser[i]);
		en->lisser[i]++;
	}
}
