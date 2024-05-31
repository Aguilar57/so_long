/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathan <jonathan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 13:24:11 by jonathan          #+#    #+#             */
/*   Updated: 2024/05/30 13:26:47 by jonathan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_data_jeu *var_jeu)
{
	if (keycode == 65307)
		close_window(var_jeu);
	if (keycode == 'z')
		if (check_if_mouvement_is_valid(var_jeu, 0) == 0)
			replace_texture_new_place_player_top(var_jeu);
	if (keycode == 'q')
		if (check_if_mouvement_is_valid(var_jeu, 3) == 0)
			replace_texture_new_place_player_left(var_jeu);
	if (keycode == 'd')
		if (check_if_mouvement_is_valid(var_jeu, 1) == 0)
			replace_texture_new_place_player_right(var_jeu);
	if (keycode == 's')
		if (check_if_mouvement_is_valid(var_jeu, 2) == 0)
			replace_texture_new_place_player_down(var_jeu);
	return (0);
}

void	replace_texture_new_place_player_top(t_data_jeu *var_jeu)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	find_player(&i, &j, var_jeu);
	if (var_jeu->double_tab[i - 1][j] == 'E' && var_jeu->item_count == 0)
		close_window(var_jeu);
	if (var_jeu->double_tab[i - 1][j] == 'E' && var_jeu->item_count != 0)
		return ;
	if (var_jeu->double_tab[i - 1][j] == 'C')
		var_jeu->item_count--;
	var_jeu->double_tab[i][j] = '0';
	var_jeu->double_tab[i - 1][j] = 'P';
	mlx_put_image_to_window(var_jeu->mlx_ptr, var_jeu->win_ptr,
		var_jeu->img_ptr_background, j * var_jeu->img_height,
		i * var_jeu->img_width);
	mlx_put_image_to_window(var_jeu->mlx_ptr, var_jeu->win_ptr,
		var_jeu->img_ptr_little_man, j * var_jeu->img_height,
		(i - 1) * var_jeu->img_width);
	ft_printf("%i\n", ++var_jeu->move);
}

void	replace_texture_new_place_player_left(t_data_jeu *var_jeu)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	find_player(&i, &j, var_jeu);
	if (var_jeu->double_tab[i][j - 1] == 'E' && var_jeu->item_count == 0)
		close_window(var_jeu);
	if (var_jeu->double_tab[i][j - 1] == 'E' && var_jeu->item_count != 0)
		return ;
	if (var_jeu->double_tab[i][j - 1] == 'C')
		var_jeu->item_count--;
	var_jeu->double_tab[i][j] = '0';
	var_jeu->double_tab[i][j - 1] = 'P';
	mlx_put_image_to_window(var_jeu->mlx_ptr, var_jeu->win_ptr,
		var_jeu->img_ptr_background, j * var_jeu->img_height,
		i * var_jeu->img_width);
	mlx_put_image_to_window(var_jeu->mlx_ptr, var_jeu->win_ptr,
		var_jeu->img_ptr_little_man, (j - 1) * var_jeu->img_height,
		i * var_jeu->img_width);
	ft_printf("%i\n", ++var_jeu->move);
}

void	replace_texture_new_place_player_right(t_data_jeu *var_jeu)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	find_player(&i, &j, var_jeu);
	if (var_jeu->double_tab[i][j + 1] == 'E' && var_jeu->item_count == 0)
		close_window(var_jeu);
	if (var_jeu->double_tab[i][j + 1] == 'E' && var_jeu->item_count != 0)
		return ;
	if (var_jeu->double_tab[i][j + 1] == 'C')
		var_jeu->item_count--;
	var_jeu->double_tab[i][j] = '0';
	var_jeu->double_tab[i][j + 1] = 'P';
	mlx_put_image_to_window(var_jeu->mlx_ptr, var_jeu->win_ptr,
		var_jeu->img_ptr_background, j * var_jeu->img_height,
		i * var_jeu->img_width);
	mlx_put_image_to_window(var_jeu->mlx_ptr, var_jeu->win_ptr,
		var_jeu->img_ptr_little_man, (j + 1) * var_jeu->img_height,
		i * var_jeu->img_width);
	ft_printf("%i\n", ++var_jeu->move);
}

void	replace_texture_new_place_player_down(t_data_jeu *var_jeu)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	find_player(&i, &j, var_jeu);
	if (var_jeu->double_tab[i + 1][j] == 'E' && var_jeu->item_count == 0)
		close_window(var_jeu);
	if (var_jeu->double_tab[i + 1][j] == 'E' && var_jeu->item_count != 0)
		return ;
	if (var_jeu->double_tab[i + 1][j] == 'C')
		var_jeu->item_count--;
	var_jeu->double_tab[i][j] = '0';
	var_jeu->double_tab[i + 1][j] = 'P';
	mlx_put_image_to_window(var_jeu->mlx_ptr, var_jeu->win_ptr,
		var_jeu->img_ptr_background, j * var_jeu->img_height,
		i * var_jeu->img_width);
	mlx_put_image_to_window(var_jeu->mlx_ptr, var_jeu->win_ptr,
		var_jeu->img_ptr_little_man, j * var_jeu->img_height,
		(i + 1) * var_jeu->img_width);
	ft_printf("%i\n", ++var_jeu->move);
}
