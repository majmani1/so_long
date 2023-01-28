/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majmani <majmani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 10:49:18 by majmani           #+#    #+#             */
/*   Updated: 2023/01/26 20:03:07 by majmani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_lenght_map(char *ma)
{
	char	*t;
	int		c;
	int		map;

	map = open(ma, O_RDONLY);
	c = 0;
	while (1)
	{
		t = get_next_line(map);
		if (t == NULL)
			break ;
		c++;
		free(t);
	}
	return (c);
}

char	*ft_read_map(char *ma)
{
	int		m;
	char	*t;
	char	*map;
	int		size;

	t = NULL;
	m = open(ma, O_RDONLY);
	size = ft_lenght_map(ma);
	map = ft_strdup("");
	while (1)
	{
		t = get_next_line(m);
		if (t == NULL)
			break ;
		map = ft_strjoin(map, t);
		free(t);
	}
	ft_check_new_line(map);
	return (map);
}

int	ft_check_map(char *map)
{
	char	**ligne;
	char	*l;
	int		i;

	i = 0;
	l = ft_read_map(map);
	ligne = ft_split(l, '\n');
	if (ft_check_lenght(ligne) == 0)
	{
		write (1, "Problem in Map {Lenght}\n", 25);
		return (0);
	}
	if (ft_composed(ligne) == 0)
	{
		write (1, "Problem in Map {Composed}\n", 27);
		return (0);
	}
	if (ft_wall(ligne, map) == 0)
	{
		write (1, "Problem in Map3 {Wall}\n", 24);
		return (0);
	}
	ft_free_ligne(ligne);
	free(l);
	return (1);
}

void	ft_lance_map(char *map)
{
	t_player	player;
	t_exit		b;
	char		**ligne;
	char		*l;

	l = ft_read_map(map);
	ligne = ft_split(l, '\n');
	player.map = ligne;
	player.path = ft_split(l, '\n');
	player.path_e = ft_split(l, '\n');
	player.coin = ft_count_coin(ligne);
	player.step = 0;
	ft_position_chfar(&player, ligne);
	ft_position_bab(&b, ligne);
	if (check_path_valide(player.y, player.x, player.path) == 0
		|| check_path_valide_e(player.y, player.x, player.path_e) == 0)
		(write(1, "path no valide\n", 15), exit(1));
	player.mlx = mlx_init();
	player.mlx_win = mlx_new_window(player.mlx,
			ft_strlen(ligne[0]) * 60, 60 * ft_lenght_map(map), "Bank!");
	ft_put_image(ligne, &player);
	mlx_hook(player.mlx_win, 2, 0, ft_move_chfar, &player);
	mlx_hook(player.mlx_win, 3, 0, ft_move_chfar_wa9af, &player);
	mlx_hook(player.mlx_win, 17, 0, ft_exit, &player);
	mlx_loop(player.mlx);
}

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	i = open(argv[1], O_RDONLY);
	if (argc != 2 || ft_check_name(argv[1]) == 0 || i == -1)
		exit(0);
	if (ft_check_map(argv[1]) == 0)
		return (0);
	else
		ft_lance_map(argv[1]);
}
