/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemie.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majmani <majmani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 14:38:52 by majmani           #+#    #+#             */
/*   Updated: 2023/01/27 11:50:13 by majmani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move1(t_enemie *player, int i, int j, int c)
{
	char	**move;
	t_data	img;

	move = malloc(sizeof(char *) * 8);
	move[0] = "police/4.xpm";
	move[1] = "police/1.xpm";
	move[2] = "police/2.xpm";
	move[3] = "police/3.xpm";
	move[4] = "police/4r.xpm";
	move[5] = "police/1r.xpm";
	move[6] = "police/2r.xpm";
	move[7] = "police/3r.xpm";
	img.img = mlx_xpm_file_to_image(player->mlx, move[c],
			&player->width, &player->width);
	mlx_put_image_to_window(player->mlx, player->mlx_win,
		img.img, i * 60, j * 60);
	free(move);
}

int	ft_move_enemie(t_enemie *en)
{
	static int	c;
	int			n;
	int			i;

	i = -1;
	n = nember_enemie(en->map);
	if (c == 3000)
	{
		while (++i < n)
		{
			if (ft_conditons(en, i, 1) == 1)
				(write(1, "GAME OVER\n", 10), exit(1));
			if (ft_conditons(en, i, 2) == 1)
				en->destination[i] = 1;
			else if (ft_conditons(en, i, 3) == 1)
				en->destination[i] = 0;
			if (en->destination[i] == 0)
				ft_change_destination(en, i, 0);
			if (en->destination[i] == 1)
				ft_change_destination(en, i, 1);
		}
		c = 0;
	}
	c++;
	return (0);
}
