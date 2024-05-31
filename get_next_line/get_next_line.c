/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathan <jonathan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 18:24:02 by jonathan          #+#    #+#             */
/*   Updated: 2023/09/19 17:26:50 by jonathan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*str;
	char		*buf;
	char		*line;
	char		*tmp;

	tmp = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= INT_MAX - 1)
		return (ft_free(str));
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (ft_free(str));
	str = ft_read_buf(fd, buf, tmp, str);
	if (!str)
		return (ft_free(str));
	line = ft_before_bn(str);
	str = ft_after_nb(str);
	return (line);
}

char	*ft_read_buf(int fd, char *buf, char *tmp, char *str)
{
	int	i;

	i = 1;
	while (i != 0)
	{
		i = read(fd, buf, BUFFER_SIZE);
		if (i == -1)
		{
			free(buf);
			free(str);
			return (NULL);
		}
		buf[i] = '\0';
		tmp = str;
		tmp = tmp_mallocked(tmp);
		if (!tmp)
			return (ft_free(buf));
		str = ft_strjoin(tmp, buf);
		free(tmp);
		if (ft_check_if_newline(str) == 1)
			break ;
	}
	free(buf);
	return (str);
}

int	ft_check_if_newline(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_before_bn(char *str)
{
	int		i;
	char	*new_str;

	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	if (str[0] == '\0')
		return (NULL);
	new_str = malloc(i + 2);
	if (!new_str)
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i])
	{
		new_str[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		new_str[i] = '\n';
		new_str[i + 1] = '\0';
	}
	else
		new_str[i] = '\0';
	return (new_str);
}

char	*ft_after_nb(char *str)
{
	int		i;
	int		j;
	char	*new_str;

	i = 0;
	j = ft_strlen(str);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\0')
		return (ft_free(str));
	new_str = malloc(j - i);
	if (!new_str)
		return (ft_free(str));
	j = 0;
	i++;
	while (str[i])
		new_str[j++] = str[i++];
	new_str[j] = '\0';
	ft_free(str);
	return (new_str);
}
