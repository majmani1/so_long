/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majmani <majmani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 18:03:17 by majmani           #+#    #+#             */
/*   Updated: 2023/01/26 14:55:24 by majmani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_help2(t_player *player, char *l, int i, int j)
{
	t_data	img;

	img.img = mlx_xpm_file_to_image(player->mlx, l,
			&player->width, &player->width);
	mlx_put_image_to_window(player->mlx, player->mlx_win,
		img.img, i * 60, j * 60);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

int	check_point(char *str)
{
	int	a;
	int	b;

	b = -1;
	a = 0;
	while (str[a])
	{
		if (str[a] == '.')
			b = a;
		a++;
	}
	return (b);
}

int	ft_check_name(char *str)
{
	char			*st;
	unsigned int	i;
	int				j;

	if (check_point(str) == -1)
		return (0);
	j = 0;
	i = check_point(str);
	st = malloc(ft_strlen(str) - i + 1);
	while (i < ft_strlen(str))
	{
		st[j] = str[i];
		i++;
		j++;
	}
	st[j] = '\0';
	if (ft_strcmp(st, ".ber") == 0)
	{
		free(st);
		return (1);
	}
	free(st);
	return (0);
}

void	ft_put_steep(t_player *player)
{
	char	*l;

	l = ft_itoa(player->step);
	mlx_string_put(player->mlx,
		player->mlx_win, 3 * 60, 10, 16711680, l);
	free(l);
}
