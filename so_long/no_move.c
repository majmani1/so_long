/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majmani <majmani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:37:52 by majmani           #+#    #+#             */
/*   Updated: 2023/01/26 19:54:00 by majmani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_help(t_player *player, char *l)
{
	t_data	img;

	img.img = mlx_xpm_file_to_image(player->mlx, l,
			&player->width, &player->width);
	mlx_put_image_to_window(player->mlx, player->mlx_win,
		img.img, player->x * 60, player->y * 60);
}

void	ft_no_move(t_player *player, char **ligne, int c)
{
	t_data	img;

	ft_position_chfar(player, ligne);
	img.img = mlx_xpm_file_to_image(player->mlx, "textures/arde.xpm",
			&player->width, &player->width);
	mlx_put_image_to_window(player->mlx, player->mlx_win,
		img.img, player->x * 60, player->y * 60);
	if (c == 1)
		ft_help(player, "playerr/0.xpm");
	if (c == 2)
		ft_help(player, "playerr/10.xpm");
	if (c == 3)
		ft_help(player, "playerr/11.xpm");
	if (c == 4)
		ft_help(player, "playerr/12.xpm");
}

int	ft_move_chfar_wa9af(int i, t_player *player)
{
	if (i == 2)
		ft_no_move(player, player->map, 2);
	if (i == 0)
		ft_no_move(player, player->map, 4);
	if (i == 13)
		ft_no_move(player, player->map, 3);
	if (i == 1)
		ft_no_move(player, player->map, 1);
	return (0);
}
