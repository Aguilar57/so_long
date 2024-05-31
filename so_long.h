/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathan <jonathan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 16:30:58 by jonathan          #+#    #+#             */
/*   Updated: 2024/05/30 14:14:30 by jonathan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "get_next_line/get_next_line.h"
# include "printf/ft_printf.h"
# include "mlx/mlx.h"

typedef struct s_data_jeu
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr_tree;
	void	*img_ptr_background;
	void	*img_ptr_beer;
	void	*img_ptr_little_man;
	void	*img_ptr_portail;
	char	*relative_path_portail;
	char	*relative_path_little_man;
	char	*relative_path_tree;
	char	*relative_path_beer;
	char	*relative_path_background;
	char	**double_tab;
	int		img_width;
	int		img_height;
	int		win_width;
	int		win_height;
	int		item_count;
	int		move;
}				t_data_jeu;

typedef struct s_data_map
{
	int		fd;
	int		count_height;
	int		count_width_line_1;
	int		count_width_other_line;
	int		count_item;
	int		count_exit;
	int		count_start;
	int		j;
	int		i;
	char	*str;
	char	**double_tab;
}				t_data_map;

void		ft_check_count(t_data_map *var_map);
void		ft_put_map_in_touble_tab(t_data_map *var_map);
void		ft_check_count(t_data_map *var_map);
void		ft_link_tab_to_mlx(char **tab, t_data_jeu *var_jeu,
				t_data_map *var_map);
void		ft_init_create_window(t_data_jeu *var_jeu, t_data_map *var_map);
void		ft_init_var_img_jeu(t_data_jeu *var_jeu);
void		ft_closing_window(t_data_jeu *var_jeu);
void		ft_test_map(t_data_map *var_map);
void		ft_init_var_img_jeu(t_data_jeu *var_jeu);
int			ft_check_first_line_map(char *str);
void		ft_put_map_in_touble_tab(t_data_map *var_map);
void		check_ber(char *str);
void		free_tab_and_exit(t_data_map *var_map, char *str);
void		free_tab(char **tab, int len);
void		ft_count_height_and_width(t_data_map *var_map, char **argv);
void		find_player(int *i, int *j, t_data_jeu *var_jeu);
void		find_player_map(int *i, int *j, t_data_map *var_map);
void		close_window(t_data_jeu *var_jeu);
void		replace_texture_new_place_player_top(t_data_jeu *var_jeu);
void		replace_texture_new_place_player_left(t_data_jeu *var_jeu);
void		replace_texture_new_place_player_right(t_data_jeu *var_jeu);
void		replace_texture_new_place_player_down(t_data_jeu *var_jeu);
int			check_if_mouvement_is_valid_top(t_data_jeu *var_jeu, int i, int j);
int			check_if_mouvement_is_valid_down(t_data_jeu *var_jeu, int i, int j);
int			check_if_mouvement_is_valid_left(t_data_jeu *var_jeu, int i, int j);
int			check_if_mouvement_is_valid_right(t_data_jeu *var_jeu,
				int i, int j);
int			check_if_mouvement_is_valid(t_data_jeu *var_jeu, int move);
int			key_hook(int keycode, t_data_jeu *var_jeu);
int			close_hook(t_data_jeu *var_jeu);
int			ft_strlen_spe(char *str);
int	ft_check_valid_map(t_data_map *var_map, int i, int j, char **map);
char		**cpy_map(t_data_map *var_map);
char		**parsing_map(t_data_map *var_map, char **argv);
void		check_ber(char *str);
void		parsing_letter_tab(t_data_jeu *var_jeu, int i, int j, char **tab);
void		check_letter(t_data_map *var_map, int i, int j);

#endif