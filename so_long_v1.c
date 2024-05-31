#include "so_long.h"
prout

void check_ber(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (str[i - 1] != 'r' || str[i - 2] != 'e' || str[i - 3] != 'b' || str[i - 4] != '.')
		{
			ft_printf("extension error\n");
			exit(-1);
		}
}

void free_tab_and_exit(t_data_map *var_map, char *str)
{
	int i;

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

void free_tab(char **tab, int len)
{
	int i;

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

void ft_count_height_and_width(t_data_map *var_map, char **argv)
{
    int fd;
    char *str;

    fd = open(argv[1], O_RDONLY);
	var_map->count_height = 0;
    while (1)
    {
		str = get_next_line(fd);
		if (var_map->count_height == 0)
			var_map->count_width_line_1 = ft_strlen_spe(str);
		if (str == NULL)
			break ;
        var_map->count_height++;
    }
    close(fd);
}

void find_player(int *i, int *j, t_data_jeu *var_jeu)
{
	while(var_jeu->double_tab[*i] != NULL)
	{
		*j = 0;
		while (var_jeu->double_tab[*i][*j] && var_jeu->double_tab[*i][*j] != '\n')
		{
			if (var_jeu->double_tab[*i][*j] == 'P')
				return ;
			*j = *j + 1;
		} 
		*i = *i + 1;
	}
}

void find_player_map(int *i, int *j, t_data_map *var_map)
{
	while(var_map->double_tab[*i] != NULL)
	{
		*j = 0;
		while (var_map->double_tab[*i][*j] && var_map->double_tab[*i][*j] != '\n')
		{
			if (var_map->double_tab[*i][*j] == 'P')
				return ;
			*j = *j + 1;
		} 
		*i = *i + 1;
	}
}

int check_if_mouvement_is_valid_top(t_data_jeu *var_jeu, int i, int j)
{
	if (var_jeu->double_tab[i - 1][j] == '1')
		return (1);
	else 
		return (0);
}

int check_if_mouvement_is_valid_down(t_data_jeu *var_jeu, int i, int j)
{
	if (var_jeu->double_tab[i + 1][j] == '1')
		return (1);
	else 
		return (0);
}

int check_if_mouvement_is_valid_left(t_data_jeu *var_jeu, int i, int j)
{
	if (var_jeu->double_tab[i][j - 1] == '1')
		return (1);
	else 
		return (0);
}

int check_if_mouvement_is_valid_right(t_data_jeu *var_jeu, int i, int j)
{
	if (var_jeu->double_tab[i][j + 1] == '1')
		return (1);
	else 
		return (0);
}

int check_if_mouvement_is_valid(t_data_jeu *var_jeu, int move)
{
	int i;
	int j;

	i = 0;
	j = 0;
	find_player(&i, &j, var_jeu);
	if (move == 0)
		return (check_if_mouvement_is_valid_top(var_jeu, i, j));
	else if (move == 2)
		return (check_if_mouvement_is_valid_down(var_jeu, i, j));
	else if (move == 3)
		return (check_if_mouvement_is_valid_left(var_jeu, i, j));
	else if (move == 1)
		return (check_if_mouvement_is_valid_right(var_jeu, i, j));
	else 
		return (-1);
}

void close_window(t_data_jeu *var_jeu)
{
	mlx_destroy_window(var_jeu->mlx_ptr, var_jeu->win_ptr);
	exit(0);
}

void replace_texture_new_place_player_top(t_data_jeu *var_jeu)
{
	int i;
	int j;

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
	mlx_put_image_to_window(var_jeu->mlx_ptr, var_jeu->win_ptr, var_jeu->img_ptr_background, j * var_jeu->img_height, i * var_jeu->img_width);
	mlx_put_image_to_window(var_jeu->mlx_ptr, var_jeu->win_ptr, var_jeu->img_ptr_little_man, j * var_jeu->img_height, (i - 1) * var_jeu->img_width);
	ft_printf("%i\n", ++var_jeu->move);
}

void replace_texture_new_place_player_left(t_data_jeu *var_jeu)
{
	int i;
	int j;

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
	mlx_put_image_to_window(var_jeu->mlx_ptr, var_jeu->win_ptr, var_jeu->img_ptr_background, j * var_jeu->img_height, i * var_jeu->img_width);
	mlx_put_image_to_window(var_jeu->mlx_ptr, var_jeu->win_ptr, var_jeu->img_ptr_little_man, (j - 1) * var_jeu->img_height, i * var_jeu->img_width);
	ft_printf("%i\n", ++var_jeu->move);
}

void replace_texture_new_place_player_right(t_data_jeu *var_jeu)
{
	int i;
	int j;

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
	mlx_put_image_to_window(var_jeu->mlx_ptr, var_jeu->win_ptr, var_jeu->img_ptr_background, j * var_jeu->img_height, i * var_jeu->img_width);
	mlx_put_image_to_window(var_jeu->mlx_ptr, var_jeu->win_ptr, var_jeu->img_ptr_little_man, (j + 1) * var_jeu->img_height, i * var_jeu->img_width);
	ft_printf("%i\n", ++var_jeu->move);

}

void replace_texture_new_place_player_down(t_data_jeu *var_jeu)
{
	int i;
	int j;

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
	mlx_put_image_to_window(var_jeu->mlx_ptr, var_jeu->win_ptr, var_jeu->img_ptr_background, j * var_jeu->img_height, i * var_jeu->img_width);
	mlx_put_image_to_window(var_jeu->mlx_ptr, var_jeu->win_ptr, var_jeu->img_ptr_little_man, j * var_jeu->img_height, (i + 1) * var_jeu->img_width);
	ft_printf("%i\n", ++var_jeu->move);

}

int	key_hook(int keycode, t_data_jeu *var_jeu)
{
	if (keycode == 65307) // 53 for external keyboards, 65307 for internal keyboards
		close_window(var_jeu);
	if (keycode == 'z')
	{
		if (check_if_mouvement_is_valid(var_jeu, 0) == 0)
		{
			replace_texture_new_place_player_top(var_jeu);
			
		}
	}
	if (keycode == 'q')
	{
		if (check_if_mouvement_is_valid(var_jeu, 3) == 0)
			{
				replace_texture_new_place_player_left(var_jeu);
				
			}
	}
	if (keycode == 'd')
	{
		if (check_if_mouvement_is_valid(var_jeu, 1) == 0)
		{
			replace_texture_new_place_player_right(var_jeu);
			
		}
	}
	if (keycode == 's')
	{
		if (check_if_mouvement_is_valid(var_jeu, 2) == 0)
		{
			replace_texture_new_place_player_down(var_jeu);
			
		}
	}

	return (0);
}

int close_hook(t_data_jeu *var_jeu)
{
	close_window(var_jeu);
	return (0);
}

int ft_strlen_spe(char *str)
{
	int i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

void ft_check_first_line_map(char *str)
{
	int i;

	i = 0;
	while (str[i] && str[i] != '\n')
	{
		if (str[i] != '1')
		{
			ft_printf("parsing error 1 ERE ligne et derniere\n");
			exit(1);
		}
		i++;
	}
	return ;
}

void ft_put_map_in_touble_tab(t_data_map *var_map)
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
		var_map->double_tab[var_map->i] = malloc(sizeof(char) * var_map->count_width_other_line);
		if (!var_map->double_tab)
			free_tab_and_exit(var_map, "error malloc");
		var_map->double_tab[var_map->i] = var_map->str;
		var_map->i++;
	}
	var_map->count_height = var_map->i;
}

int ft_check_valid_map(t_data_map *var_map, int i, int j, char **map)
{
	static int count_c;
	static int count_e;

	if (count_e >= 1 && count_c == var_map->count_item)
		return (1);
	if (i < 0 || j < 0 || i > var_map->count_height || j > var_map->count_width_line_1)
		return (0);
	if (map[i][j] == 'C')
		count_c++;
	if (map[i][j] == 'E')
		count_e++;
	if (map[i][j] == '1' || (map[i][j] == 'E' && count_c != var_map->count_item))
		return (0);
	map[i][j] = '1';
	if (ft_check_valid_map(var_map, i + 1, j, map) || ft_check_valid_map(var_map, i - 1, j, map) || ft_check_valid_map(var_map, i, j + 1, map) || ft_check_valid_map(var_map, i, j - 1, map))
		return (1);
	return (0);
}


static size_t	map_flood_fill(t_data_map *map, size_t x,
				size_t y, char **copied_map)
{
	static size_t	collected;
	static size_t	exit_count;
	fprintf(stderr, "%zu and %d and exit : %zu\n", collected, map->count_item, exit_count);
	if (exit_count >= 1 && collected == map->count_item)
		return (1);
	fprintf(stderr, "%d and %zu, %d and %zu\n", map->count_width_line_1, x, map->count_height, y);
	if (x < 0 || y < 0 || x > map->count_width_line_1 || y > map->count_height)
		return (0);
	if (copied_map[y][x] == 'C')
		collected++;
	if (copied_map[y][x] == 'E')
		exit_count++;
	fprintf(stderr, "test\n");
	if (copied_map[y][x] == '1' || copied_map[y][x] == 'V'
	|| (copied_map[y][x] == 'E' && collected != map->count_item))
		return (0);
	copied_map[y][x] = 'V';
	if (map_flood_fill(map, x + 1, y, copied_map)
		|| map_flood_fill(map, x - 1, y, copied_map)
		|| map_flood_fill(map, x, y + 1, copied_map)
		|| map_flood_fill(map, x, y - 1, copied_map))
		return (1);
	return (0);
}

char **cpy_map(t_data_map *var_map)
{
	char **new_map;
	int i;
	int new_count;

	i = 0;
	new_count = 0;
	new_map = malloc(sizeof(char *) * var_map->count_height);
	if (!new_map)
	{
		free_tab(new_map, 0);
		free_tab_and_exit(var_map, "error malloc");
	}
	while (new_count < var_map->count_height)
	{ 
		new_map[new_count] = malloc(sizeof(char) * var_map->count_width_line_1);
		if (!new_map[new_count])
		{
			free_tab(new_map, new_count);
			free_tab_and_exit(var_map, "error malloc");
		}
		i = 0;
		while(i < var_map->count_width_line_1)
		{
			new_map[new_count][i] = var_map->double_tab[new_count][i];
			i++;
		}
		new_count++;
	}
	return (new_map);
}

char **parsing_map(t_data_map *var_map, char **argv)
{
	int i;
	int j;
	char **map;

	i = 0;
	j = 0;
	ft_count_height_and_width(var_map, argv);
	var_map->fd = open(argv[1], O_RDONLY);
	var_map->j = 0;
	var_map->i = 0;
	ft_put_map_in_touble_tab(var_map);
	ft_test_map(var_map);
	ft_check_count(var_map);
	map = cpy_map(var_map);//cpy map
	find_player_map(&i, &j, var_map);
	if (ft_check_valid_map(var_map, i, j, map) == 0)
	{
		ft_printf("error path invalid\n");
		free_tab(map, var_map->count_height);
		free_tab(var_map->double_tab, var_map->count_height);
		exit(0);
	}
	return (var_map->double_tab);
}

void ft_test_map(t_data_map *var_map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < var_map->count_height)
	{
		var_map->count_width_other_line = ft_strlen_spe(var_map->double_tab[i]);
		if (var_map->count_width_line_1 != var_map->count_width_other_line)
		{
			ft_printf("error parsing width\n");
			exit(1);
		}
		if (var_map->double_tab[i][0] != '1' || var_map->double_tab[i][var_map->count_width_other_line - 1] != '1')
		{
			ft_printf("error parsing bordure\n");
			exit(1);
		}
		j = 0;
		while (var_map->double_tab[i][j] && var_map->double_tab[i][j] != '\n')
		{
			if (var_map->double_tab[i][j] == 'C')
				var_map->count_item++;
			if (var_map->double_tab[i][j] == 'P')
				var_map->count_start++;
			if (var_map->double_tab[i][j] == 'E')
				var_map->count_exit++;
			j++;
		}
		i++;
	}
}

void ft_check_count(t_data_map *var_map)
{
	if (var_map->count_item == 0)
	{
		ft_printf("error parsing item\n");
		exit(1);
	}
	if (var_map->count_start != 1)
	{
		ft_printf("error parsing start\n");
		exit(1);
	}
	if (var_map->count_exit != 1)
	{
		ft_printf("error parsing exit\n");
		exit(1);
	}
	ft_check_first_line_map(var_map->double_tab[0]);
	ft_check_first_line_map(var_map->double_tab[var_map->count_height - 1]);
}

void ft_link_tab_to_mlx(char **tab, t_data_jeu *var_jeu, t_data_map *var_map)
{
	int i;
	int j;

	i = 0;
	while (i < var_map->count_height)
	{
		j = 0;
		while(tab[i][j] && tab[i][j] != '\n')
		{
			if (tab[i][j] == '1')
				mlx_put_image_to_window(var_jeu->mlx_ptr, var_jeu->win_ptr, var_jeu->img_ptr_tree, j * var_jeu->img_height, i * var_jeu->img_width);
			if (tab[i][j] == '0')
				mlx_put_image_to_window(var_jeu->mlx_ptr, var_jeu->win_ptr, var_jeu->img_ptr_background, j * var_jeu->img_height, i * var_jeu->img_width);
			if (tab[i][j] == 'C')
				mlx_put_image_to_window(var_jeu->mlx_ptr, var_jeu->win_ptr, var_jeu->img_ptr_beer, j * var_jeu->img_height, i * var_jeu->img_width);
			if (tab[i][j] == 'E')
				mlx_put_image_to_window(var_jeu->mlx_ptr, var_jeu->win_ptr, var_jeu->img_ptr_portail, j * var_jeu->img_height, i * var_jeu->img_width);
			if (tab[i][j] == 'P')
				mlx_put_image_to_window(var_jeu->mlx_ptr, var_jeu->win_ptr, var_jeu->img_ptr_little_man, j * var_jeu->img_height, i * var_jeu->img_width);
			j++;
		}
		i++;
	}
}

void ft_init_create_window(t_data_jeu *var_jeu, t_data_map *var_map)
{
	var_jeu->win_width = var_map->count_width_line_1 * 50;
	var_jeu->win_height = var_map->count_height * 50;
	var_jeu->mlx_ptr = mlx_init();
	if (var_jeu->mlx_ptr == NULL)
	{
		ft_printf("mlx init error\n");
		exit(1);
	}
	var_jeu->win_ptr = mlx_new_window(var_jeu->mlx_ptr, var_jeu->win_width, var_jeu->win_height, "so_long");
	if (var_jeu->win_ptr == NULL)
	{
		ft_printf("mlx window error\n");
		exit(1);
	}
	ft_init_var_img_jeu(var_jeu);
}

void ft_init_var_img_jeu(t_data_jeu *var_jeu)
{
	var_jeu->img_height = 50;
	var_jeu->img_width = 50;
	var_jeu->move = 0;
	var_jeu->relative_path_portail = "./portail.xpm";
	var_jeu->relative_path_little_man = "./little_man.xpm";
	var_jeu->relative_path_tree = "./arbre_vert_background.xpm";
	var_jeu->relative_path_beer = "./beer.xpm";
	var_jeu->relative_path_background = "./sol_vert.xpm";
	var_jeu->img_ptr_portail = mlx_xpm_file_to_image(var_jeu->mlx_ptr, var_jeu->relative_path_portail, &var_jeu->img_width,&var_jeu->img_height);
	var_jeu->img_ptr_little_man = mlx_xpm_file_to_image(var_jeu->mlx_ptr, var_jeu->relative_path_little_man, &var_jeu->img_width,&var_jeu->img_height);
	var_jeu->img_ptr_tree = mlx_xpm_file_to_image(var_jeu->mlx_ptr, var_jeu->relative_path_tree, &var_jeu->img_width,&var_jeu->img_height);
	var_jeu->img_ptr_beer = mlx_xpm_file_to_image(var_jeu->mlx_ptr, var_jeu->relative_path_beer, &var_jeu->img_width,&var_jeu->img_height);
	var_jeu->img_ptr_background = mlx_xpm_file_to_image(var_jeu->mlx_ptr, var_jeu->relative_path_background, &var_jeu->img_width,&var_jeu->img_height);
}

void ft_closing_window(t_data_jeu *var_jeu)
{
	mlx_key_hook(var_jeu->win_ptr, key_hook, var_jeu);
	mlx_hook(var_jeu->win_ptr, 17, 1, close_hook, var_jeu);
}

int main(int argc, char **argv)
{
	t_data_jeu var_jeu;
	t_data_map var_map;
	char **double_tab;

	if (argc != 2)
	{
		printf("input error\n");
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
