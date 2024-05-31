/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_7.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathan <jonathan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 13:35:22 by jonathan          #+#    #+#             */
/*   Updated: 2024/05/30 16:57:21 by jonathan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_tab_and_exit(t_data_map *var_map, char *str)
{
	int	i;

	if (!var_map->double_tab)
		return ;
	i = 0;
	while (i < var_map->count_height)
	{
		free(var_map->double_tab[i]);
		i++;
	}
	free(var_map->double_tab);
	ft_printf("%s\n", str);
	exit(1);
}

void	free_tab(char **tab, int len)
{
	int	i;

	if (!tab)
		return ;
	i = 0;
	while (i < len)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	close_window(t_data_jeu *var_jeu)
{
	mlx_destroy_window(var_jeu->mlx_ptr, var_jeu->win_ptr);
	exit(0);
}

int	close_hook(t_data_jeu *var_jeu)
{
	close_window(var_jeu);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data_jeu	var_jeu;
	t_data_map	var_map;
	char		**double_tab;

	if (argc != 2)
	{
		ft_printf("input error\n");
		return (0);
	}
	check_ber(argv[1]);
	double_tab = parsing_map(&var_map, argv);
	var_jeu.double_tab = double_tab;
	var_jeu.item_count = var_map.count_item;
	ft_init_create_window(&var_jeu, &var_map);
	ft_link_tab_to_mlx(double_tab, &var_jeu, &var_map);
	ft_closing_window(&var_jeu);
	mlx_loop(var_jeu.mlx_ptr);
}
