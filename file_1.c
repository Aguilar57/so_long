/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathan <jonathan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 16:50:37 by jonathan          #+#    #+#             */
/*   Updated: 2024/05/30 16:52:24 by jonathan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_ber(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (str[i - 1] != 'r' || str[i - 2] != 'e' || str[i - 3] != 'b'
		|| str[i - 4] != '.')
	{
		ft_printf("extension error\n");
		exit(0);
	}
}

char	**parsing_map(t_data_map *var_map, char **argv)
{
	int		i;
	int		j;
	char	**map;

	i = 0;
	j = 0;
	ft_count_height_and_width(var_map, argv);
	var_map->fd = open(argv[1], O_RDONLY);
	var_map->j = 0;
	var_map->i = 0;
	ft_put_map_in_touble_tab(var_map);
	ft_test_map(var_map);
	ft_check_count(var_map);
	map = cpy_map(var_map);
	find_player_map(&i, &j, var_map);
	if (ft_check_valid_map(var_map, i, j, map) == 0)
	{
		free_tab(map, var_map->count_height);
		free_tab_and_exit(var_map, "error path invalid");
	}
	free_tab(map, var_map->count_height);
	return (var_map->double_tab);
}

void	ft_count_height_and_width(t_data_map *var_map, char **argv)
{
	int		fd;
	char	*str;

	fd = open(argv[1], O_RDONLY);
	var_map->count_height = 0;
	while (1)
	{
		str = get_next_line(fd);
		if (str == NULL)
			break ;
		if (var_map->count_height == 0)
			var_map->count_width_line_1 = ft_strlen_spe(str);
		var_map->count_height++;
	}
	close(fd);
}

int	ft_strlen_spe(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

int	ft_check_first_line_map(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
	{
		if (str[i] != '1')
			return (1);
		i++;
	}
	return (0);
}
