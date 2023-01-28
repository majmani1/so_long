/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majmani <majmani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:33:45 by majmani           #+#    #+#             */
/*   Updated: 2023/01/26 20:05:08 by majmani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include <string.h>
# include <mlx.h>

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;
typedef struct s_exit {
	int		tol;
	int		aard;
}				t_exit;

typedef struct s_player {
	void	*mlx;
	void	*mlx_win;
	int		y;
	int		x;
	int		height;
	int		width;
	char	**map;
	char	**path;
	char	**path_e;
	int		coin;
	int		step;
}				t_player;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char		*ft_strdup(char *src);
void		ft_free_ligne(char **ligne);
int			ft_lenght_map(char *ma);
char		*ft_read_map(char *ma);
int			ft_check_lenght(char **ligne);
int			ft_composed_alphapet(char c);
int			ft_player(char **ligne, char sh);
int			ft_composed(char **ligne);
int			ft_wall(char **ligne, char *map);
int			ft_check_map(char *map);
void		ft_put_image(char **ligne, t_player *player);
t_player	ft_position_chfar(t_player *player, char **ligne);
void		ft_arde(char **ligne, t_player *player);
t_exit		ft_position_bab(t_exit *b, char **ligne);
int			ft_count_coin(char **ligne);
void		ft_move(t_player *player, int i, int j, int c);
void		ft_putnbr(int nb);
void		ft_move_d(t_player *player, char **ligne, int c, int *coin);
void		ft_move_a(t_player *player, char **ligne, int c, int *coin);
void		ft_move_w(t_player *player, char **ligne, int c, int *coin);
void		ft_move_s(t_player *player, char **ligne, int c, int *coin);
int			ft_move_chfar(int i, t_player *player);
void		ft_no_move(t_player *player, char **ligne, int c);
int			ft_move_chfar_wa9af(int i, t_player *player);
void		ft_lance_map(char *map);
char		*ft_itoa(int n);
void		ft_check_new_line(char *map);
void		ft_reinitialisation(int *c, int i);
void		ft_help2(t_player *player, char *l, int i, int j);
int			check_point(char *str);
int			ft_check_name(char *str);
int			ft_strcmp(char *s1, char *s2);
void		check_path(int i, int j, char **map);
int			check_path_valide(int i, int j, char **map);
void		check_path_e(int i, int j, char **map);
int			check_path_valide_e(int k, int l, char **map);
void		ft_put_steep(t_player *player);
int			ft_exit(void);

char		*get_next_line(int fd);
int			ft_strchr(char *s, int c);
size_t		ft_strlen( char *str);
char		*ft_strjoin(char *s1, char *s2);
char		*after(char *s);
char		*before(char *s);
char		*ft_read(int fd, char *str);
char		**ft_split(char const *s, char c);

#endif
