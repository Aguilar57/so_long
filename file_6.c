/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_6.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathan <jonathan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 13:28:26 by jonathan          #+#    #+#             */
/*   Updated: 2024/05/30 13:28:53 by jonathan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_if_mouvement_is_valid_top(t_data_jeu *var_jeu, int i, int j)
{
	if (var_jeu->double_tab[i - 1][j] == '1')
		return (1);
	else
		return (0);
}

int	check_if_mouvement_is_valid_down(t_data_jeu *var_jeu, int i, int j)
{
	if (var_jeu->double_tab[i + 1][j] == '1')
		return (1);
	else
		return (0);
}

int	check_if_mouvement_is_valid_left(t_data_jeu *var_jeu, int i, int j)
{
	if (var_jeu->double_tab[i][j - 1] == '1')
		return (1);
	else
		return (0);
}

int	check_if_mouvement_is_valid_right(t_data_jeu *var_jeu, int i, int j)
{
	if (var_jeu->double_tab[i][j + 1] == '1')
		return (1);
	else
		return (0);
}

int	check_if_mouvement_is_valid(t_data_jeu *var_jeu, int move)
{
	int	i;
	int	j;

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
