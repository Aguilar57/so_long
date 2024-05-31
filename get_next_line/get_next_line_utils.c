/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathan <jonathan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 18:23:53 by jonathan          #+#    #+#             */
/*   Updated: 2023/09/13 20:40:04 by jonathan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(const char *str1, const char *str2)
{
	char	*new_str;
	int		i;
	int		j;
	int		len;

	len = ft_strlen((char *)str1) + ft_strlen((char *)str2);
	new_str = malloc(len + 1);
	if (!new_str)
		return (NULL);
	i = 0;
	while (str1[i])
	{
		new_str[i] = str1[i];
		i++;
	}
	j = 0;
	while (str2[j])
	{
		new_str[i + j] = str2[j];
		j++;
	}
	new_str[i + j] = '\0';
	return (new_str);
}

char	*tmp_mallocked(char *tmp)
{
	char	*new_tmp;

	if (tmp)
		return (tmp);
	new_tmp = malloc(1);
	if (!new_tmp)
		return (NULL);
	new_tmp[0] = '\0';
	return (new_tmp);
}

char	*ft_free(char *str)
{
	free(str);
	return (NULL);
}
