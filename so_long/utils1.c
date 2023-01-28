/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majmani <majmani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:27:09 by majmani           #+#    #+#             */
/*   Updated: 2023/01/26 16:59:27 by majmani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move(t_player *player, int i, int j, int c)
{
	char	**move;
	t_data	img;

	move = malloc(sizeof(char *) * 8);
	move[0] = "playerr/1.xpm";
	move[1] = "playerr/2.xpm";
	move[2] = "playerr/4.xpm";
	move[3] = "playerr/5.xpm";
	move[4] = "playerr/6.xpm";
	move[5] = "playerr/7.xpm";
	move[6] = "playerr/8.xpm";
	move[7] = "playerr/9.xpm";
	img.img = mlx_xpm_file_to_image(player->mlx, move[c],
			&player->width, &player->width);
	mlx_put_image_to_window(player->mlx, player->mlx_win,
		img.img, i * 60, j * 60);
	free(move);
}

void	ft_check_new_line(char *map)
{
	int	i;

	i = 0;
	if (map[0] == '\n')
		(write(1, "Empty ligne\n", 12), exit(127));
	while (map[i])
	{
		if (map[i] == '\n' && (map[i + 1] == '\n' || map[i + 1] == '\0'))
			(write(1, "Empty ligne\n", 12), exit(127));
		i++;
	}
}

void	ft_free_ligne(char **ligne)
{
	int	i;

	i = 0;
	while (ligne[i])
	{
		free(ligne[i]);
		i++;
	}
	free(ligne);
}

void	ft_putnbr(int nb)
{
	char	val;

	if (nb == -2147483648)
		write (1, "-2147483648", 11);
	else
	{
		if (nb < 0)
		{
			write(1, "-", 1);
			nb *= -1;
		}
		if (nb < 10)
		{
			val = nb + '0';
			write (1, &val, 1);
		}
		else
		{
			ft_putnbr(nb / 10);
			val = (nb % 10) + '0';
			write (1, &val, 1);
		}
	}
}

char	*ft_strdup(char *src)
{
	int		l;
	char	*str;
	int		i;

	i = 0;
	l = ft_strlen(src);
	str = malloc(sizeof(char) * l + 1);
	if (str == 0)
		return (0);
	while (src[i] != '\0')
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
