/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathan <jonathan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 17:01:53 by jonathan          #+#    #+#             */
/*   Updated: 2024/05/30 13:37:29 by jonathan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_map_in_touble_tab(t_data_map *var_map)
{
	var_map->double_tab = malloc((sizeof(char *)) * var_map->count_height);
	if (!var_map->double_tab)
		free_tab_and_exit(var_map, "error malloc");
	while (1)
	{
		var_map->str = get_next_line(var_map->fd);
		if (var_map->str == NULL)
			break ;
		var_map->count_width_other_line = ft_strlen_spe(var_map->str);
		var_map->double_tab[var_map->i] = malloc(sizeof(char)
				* var_map->count_width_other_line);
		if (!var_map->double_tab)
			free_tab_and_exit(var_map, "error malloc");
		var_map->double_tab[var_map->i] = var_map->str;
		var_map->i++;
	}
	var_map->count_height = var_map->i;
}

void	ft_test_map(t_data_map *var_map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < var_map->count_height)
	{
		var_map->count_width_other_line = ft_strlen_spe(var_map->double_tab[i]);
		if (var_map->count_width_line_1 != var_map->count_width_other_line)
			free_tab_and_exit(var_map, "error parsing : width");
		if (var_map->double_tab[i][0] != '1' || var_map->double_tab[i]
				[var_map->count_width_other_line - 1] != '1')
			free_tab_and_exit(var_map, "error parsing : border");
		j = 0;
		while (var_map->double_tab[i][j] && var_map->double_tab[i][j] != '\n')
		{
			check_letter(var_map, i, j);
			j++;
		}
		i++;
	}
}

void	check_letter(t_data_map *var_map, int i, int j)
{
	if (var_map->double_tab[i][j] == 'C')
		var_map->count_item++;
	if (var_map->double_tab[i][j] == 'P')
		var_map->count_start++;
	if (var_map->double_tab[i][j] == 'E')
		var_map->count_exit++;
}

void	ft_check_count(t_data_map *var_map)
{
	if (var_map->count_item == 0)
		free_tab_and_exit(var_map, "error parsing : item");
	if (var_map->count_start != 1)
		free_tab_and_exit(var_map, "error parsing : start");
	if (var_map->count_exit != 1)
		free_tab_and_exit(var_map, "error parsing : exit");
	if (ft_check_first_line_map(var_map->double_tab[0]) == 1)
		free_tab_and_exit(var_map, "error parsing : first line ");
	if (ft_check_first_line_map(
			var_map->double_tab[var_map->count_height - 1]) == 1)
		free_tab_and_exit(var_map, "error parsing : last line ");
}
