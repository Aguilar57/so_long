/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathan <jonathan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 11:31:20 by jonathan          #+#    #+#             */
/*   Updated: 2024/05/30 14:49:12 by jonathan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**cpy_map(t_data_map *var_map)
{
	char	**new_map;
	int		i;
	int		new_count;

	new_count = 0;
	new_map = malloc(sizeof(char *) * var_map->count_height);
	if (!new_map)
		free_tab_and_exit(var_map, "error : malloc");
	while (new_count < var_map->count_height)
	{
		new_map[new_count] = malloc(sizeof(char) * var_map->count_width_line_1);
		if (!new_map[new_count])
		{
			free_tab(new_map, new_count);
			free_tab_and_exit(var_map, "error : malloc");
		}
		i = 0;
		while (i < var_map->count_width_line_1)
		{
			new_map[new_count][i] = var_map->double_tab[new_count][i];
			i++;
		}
		new_count++;
	}
	return (new_map);
}

void	find_player(int *i, int *j, t_data_jeu *var_jeu)
{
	while (var_jeu->double_tab[*i] != NULL)
	{
		*j = 0;
		while (var_jeu->double_tab[*i][*j]
			&& var_jeu->double_tab[*i][*j] != '\n')
		{
			if (var_jeu->double_tab[*i][*j] == 'P')
				return ;
			*j = *j + 1;
		}
		*i = *i + 1;
	}
}

void	find_player_map(int *i, int *j, t_data_map *var_map)
{
	while (var_map->double_tab[*i] != NULL)
	{
		*j = 0;
		while (var_map->double_tab[*i][*j]
			&& var_map->double_tab[*i][*j] != '\n')
		{
			if (var_map->double_tab[*i][*j] == 'P')
				return ;
			*j = *j + 1;
		}
		*i = *i + 1;
	}
}

int	ft_check_valid_map(t_data_map *var_map, int i, int j, char **map)
{
	static int	count_c;
	static int	count_e;

	if (count_e >= 1 && count_c == var_map->count_item)
		return (1);
	if (i < 0 || j < 0 || i > var_map->count_height
		|| j > var_map->count_width_line_1)
		return (0);
	if (map[i][j] == 'C')
		count_c++;
	if (map[i][j] == 'E')
		count_e++;
	if (map[i][j] == '1'
			|| (map[i][j] == 'E' && count_c != var_map->count_item))
		return (0);
	map[i][j] = '1';
	if (ft_check_valid_map(var_map, i + 1, j, map)
		|| ft_check_valid_map(var_map, i - 1, j, map)
		|| ft_check_valid_map(var_map, i, j + 1, map)
		|| ft_check_valid_map(var_map, i, j - 1, map))
		return (1);
	return (0);
}
