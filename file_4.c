/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathan <jonathan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 13:04:42 by jonathan          #+#    #+#             */
/*   Updated: 2024/05/30 14:43:47 by jonathan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_create_window(t_data_jeu *var_jeu, t_data_map *var_map)
{
	var_jeu->win_width = var_map->count_width_line_1 * 50;
	var_jeu->win_height = var_map->count_height * 50;
	var_jeu->mlx_ptr = mlx_init();
	if (var_jeu->mlx_ptr == NULL)
		free_tab_and_exit(var_map, "error init mlx");
	var_jeu->win_ptr = mlx_new_window(var_jeu->mlx_ptr, var_jeu->win_width,
			var_jeu->win_height, "so_long");
	if (var_jeu->win_ptr == NULL)
		free_tab_and_exit(var_map, "error windows init");
	ft_init_var_img_jeu(var_jeu);
}

void	ft_init_var_img_jeu(t_data_jeu *var_jeu)
{
	var_jeu->img_height = 50;
	var_jeu->img_width = 50;
	var_jeu->move = 0;
	var_jeu->relative_path_portail = "./portail.xpm";
	var_jeu->relative_path_little_man = "./little_man.xpm";
	var_jeu->relative_path_tree = "./arbre_vert_background.xpm";
	var_jeu->relative_path_beer = "./beer.xpm";
	var_jeu->relative_path_background = "./sol_vert.xpm";
	var_jeu->img_ptr_portail = mlx_xpm_file_to_image(var_jeu->mlx_ptr,
			var_jeu->relative_path_portail, &var_jeu->img_width,
			&var_jeu->img_height);
	var_jeu->img_ptr_little_man = mlx_xpm_file_to_image(var_jeu->mlx_ptr,
			var_jeu->relative_path_little_man, &var_jeu->img_width,
			&var_jeu->img_height);
	var_jeu->img_ptr_tree = mlx_xpm_file_to_image(var_jeu->mlx_ptr,
			var_jeu->relative_path_tree, &var_jeu->img_width,
			&var_jeu->img_height);
	var_jeu->img_ptr_beer = mlx_xpm_file_to_image(var_jeu->mlx_ptr,
			var_jeu->relative_path_beer, &var_jeu->img_width,
			&var_jeu->img_height);
	var_jeu->img_ptr_background = mlx_xpm_file_to_image(var_jeu->mlx_ptr,
			var_jeu->relative_path_background, &var_jeu->img_width,
			&var_jeu->img_height);
}

void	ft_link_tab_to_mlx(char **tab, t_data_jeu *var_jeu, t_data_map *var_map)
{
	int	i;
	int	j;

	i = 0;
	while (i < var_map->count_height)
	{
		j = 0;
		parsing_letter_tab(var_jeu, i, j, tab);
		i++;
	}
}

void	parsing_letter_tab(t_data_jeu *var_jeu, int i, int j, char **tab)
{
	while (tab[i][j] && tab[i][j] != '\n')
	{
		if (tab[i][j] == '1')
			mlx_put_image_to_window(var_jeu->mlx_ptr,
				var_jeu->win_ptr, var_jeu->img_ptr_tree,
				j * var_jeu->img_height, i * var_jeu->img_width);
		if (tab[i][j] == '0')
			mlx_put_image_to_window(var_jeu->mlx_ptr,
				var_jeu->win_ptr, var_jeu->img_ptr_background,
				j * var_jeu->img_height, i * var_jeu->img_width);
		if (tab[i][j] == 'C')
			mlx_put_image_to_window(var_jeu->mlx_ptr,
				var_jeu->win_ptr, var_jeu->img_ptr_beer,
				j * var_jeu->img_height, i * var_jeu->img_width);
		if (tab[i][j] == 'E')
			mlx_put_image_to_window(var_jeu->mlx_ptr,
				var_jeu->win_ptr, var_jeu->img_ptr_portail,
				j * var_jeu->img_height, i * var_jeu->img_width);
		if (tab[i][j] == 'P')
			mlx_put_image_to_window(var_jeu->mlx_ptr,
				var_jeu->win_ptr, var_jeu->img_ptr_little_man,
				j * var_jeu->img_height, i * var_jeu->img_width);
		j++;
	}
}

void	ft_closing_window(t_data_jeu *var_jeu)
{
	mlx_key_hook(var_jeu->win_ptr, key_hook, var_jeu);
	mlx_hook(var_jeu->win_ptr, 17, 1, close_hook, var_jeu);
}
