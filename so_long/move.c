/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majmani <majmani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:34:21 by majmani           #+#    #+#             */
/*   Updated: 2023/01/26 19:53:39 by majmani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move_d(t_player *player, char **ligne, int c, int *coin)
{
	int		i;
	int		j;
	t_exit	b;

	ft_position_chfar(player, ligne);
	if (ligne[player->y][player->x + 1] == 'C')
		(*coin)++;
	if (ligne[player->y][player->x + 1] != '1'
		&& ligne[player->y][player->x + 1] != 'E')
	{
		i = player->x + 1;
		j = player->y;
		ligne[player->y][player->x + 1] = 'P';
		ligne[player->y][player->x] = '0';
		(ft_help2(player, "textures/arde.xpm", i, j), ft_move(player, i, j, c));
		(ft_help2(player, "textures/arde.xpm", player->x, j), player->step++);
		(ft_help2(player, "textures/wallf.xpm", 3, 0));
		(ft_putnbr(player->step), write(1, " 7araka\n", 8));
	}
	if ((*coin) == player->coin)
		(ft_position_bab(&b, ligne),
			ft_help2(player, "textures/bab_close.xpm", b.aard, b.tol));
	if (ligne[player->y][player->x + 1] == 'E' && (*coin) == player->coin)
		exit(1);
}

void	ft_move_a(t_player *player, char **ligne, int c, int *coin)
{
	int		i;
	int		j;
	t_exit	b;

	ft_position_chfar(player, ligne);
	if (ligne[player->y][player->x - 1] == 'C')
		(*coin)++;
	if (ligne[player->y][player->x - 1] != '1'
		&& ligne[player->y][player->x - 1] != 'E')
	{
		i = player->x - 1;
		j = player->y;
		ligne[player->y][player->x - 1] = 'P';
		ligne[player->y][player->x] = '0';
		(ft_help2(player, "textures/arde.xpm", i, j), ft_move(player, i, j, c));
		(ft_help2(player, "textures/arde.xpm", player->x, j), player->step++);
		(ft_help2(player, "textures/wallf.xpm", 3, 0));
		(ft_putnbr(player->step), write(1, " 7araka\n", 8));
	}
	if ((*coin) == player->coin)
		(ft_position_bab(&b, ligne),
			ft_help2(player, "textures/bab_close.xpm", b.aard, b.tol));
	if (ligne[player->y][player->x - 1] == 'E' && (*coin) == player->coin)
		exit(1);
}

void	ft_move_w(t_player *player, char **ligne, int c, int *coin)
{
	int		i;
	int		j;
	t_exit	b;

	ft_position_chfar(player, ligne);
	if (ligne[player->y - 1][player->x] == 'C')
		(*coin)++;
	if (ligne[player->y - 1][player->x] != '1'
		&& ligne[player->y - 1][player->x] != 'E')
	{
		i = player->x;
		j = player->y - 1;
		ligne[player->y - 1][player->x] = 'P';
		ligne[player->y][player->x] = '0';
		(ft_help2(player, "textures/arde.xpm", i, j), ft_move(player, i, j, c));
		(ft_help2(player, "textures/arde.xpm", i, (player->y)), player->step++);
		(ft_help2(player, "textures/wallf.xpm", 3, 0));
		(ft_putnbr(player->step), write(1, " 7araka\n", 8));
	}
	if ((*coin) == player->coin)
		(ft_position_bab(&b, ligne),
			ft_help2(player, "textures/bab_close.xpm", b.aard, b.tol));
	if (ligne[player->y - 1][player->x] == 'E' && (*coin) == player->coin)
		exit(1);
}

void	ft_move_s(t_player *player, char **ligne, int c, int *coin)
{
	int		i;
	int		j;
	t_exit	b;

	ft_position_chfar(player, ligne);
	if (ligne[player->y + 1][player->x] == 'C')
		(*coin)++;
	if (ligne[player->y + 1][player->x] != '1'
		&& ligne[player->y + 1][player->x] != 'E')
	{
		ligne[player->y + 1][player->x] = 'P';
		ligne[player->y][player->x] = '0';
		i = player->x;
		j = player->y + 1;
		(ft_help2(player, "textures/arde.xpm", i, j), ft_move(player, i, j, c));
		(ft_help2(player, "textures/arde.xpm", i, (player->y)), player->step++);
		(ft_help2(player, "textures/wallf.xpm", 3, 0));
		(ft_putnbr(player->step), write(1, " 7araka\n", 8));
	}
	if ((*coin) == player->coin)
		(ft_position_bab(&b, ligne),
			ft_help2(player, "textures/bab_close.xpm", b.aard, b.tol));
	if (ligne[player->y + 1][player->x] == 'E' && (*coin) == player->coin)
		exit(1);
}

int	ft_move_chfar(int i, t_player *player)
{
	static int	c;
	static int	coin;

	if (i == 53)
		exit(1);
	if (i == 2)
		(ft_reinitialisation(&c, 2),
			ft_move_d(player, player->map, c, &coin), c++);
	else if (i == 0)
		(ft_reinitialisation(&c, 0),
			ft_move_a(player, player->map, c, &coin), c++);
	else if (i == 1)
		(ft_reinitialisation(&c, 1),
			ft_move_s(player, player->map, c, &coin), c++);
	else if (i == 13)
		(ft_reinitialisation(&c, 13),
			ft_move_w(player, player->map, c, &coin), c++);
	return (0);
}
