/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enmie.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majmani <majmani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 13:24:49 by majmani           #+#    #+#             */
/*   Updated: 2023/01/26 14:09:51 by majmani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (str1[i] != '\0' || str2[i] != '\0'))
	{
		if (str1[i] == str2[i])
			i++;
		else
			return (((unsigned char *)str1)[i] - ((unsigned char *)str2)[i]);
	}
	return (0);
}

int	nember_enemie(char **ligne)
{
	int	i;
	int	j;
	int	e;
	int	t;

	i = 0;
	t = -1;
	e = 0;
	while (ligne[++i])
	{
		j = 0;
		while (ligne[i][j])
		{
			if (ft_strncmp(ligne[i] + j, "000", 3) == 0
				&& (ft_strncmp(ligne[i + 1], "111", 3) != 0))
			{
				e++;
				t = j;
				break ;
			}
			j++;
		}
	}
	return (e);
}

void	position_enemie(char **ligne, int **en)
{
	int	i;
	int	j;
	int	e;

	i = 0;
	e = 0;
	while (ligne[++i])
	{
		j = -1;
		while (ligne[i][++j])
		{
			if (ft_strncmp(ligne[i] + j, "000", 3) == 0
				&& (ft_strncmp(ligne[i + 1], "111", 3) != 0))
			{
				ligne[i][j] = 'x';
				break ;
			}
		}
		if (strncmp(ligne[i] + j, "x00", 3) == 0)
		{
			en[e][0] = j;
			en[e][1] = i;
			e++;
		}
	}
}

void	ft_allocat_enemie(int i, int **f)
{
	int	j;

	j = 0;
	while (i > j)
	{
		f[j] = malloc(sizeof(int) * 2);
		j++;
	}
}

int	**enemie(char **ligne)
{
	int	**en;

	en = malloc(sizeof(int *) * nember_enemie(ligne));
	ft_allocat_enemie(nember_enemie(ligne), en);
	position_enemie(ligne, en);
	return (en);
}
