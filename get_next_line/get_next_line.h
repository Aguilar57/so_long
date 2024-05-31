/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathan <jonathan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 18:24:00 by jonathan          #+#    #+#             */
/*   Updated: 2023/09/18 19:32:24 by jonathan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

char	*ft_after_nb(char *str);
char	*get_next_line(int fd);
char	*ft_read_buf(int fd, char *buf, char *tmp, char *str);
int		ft_check_if_newline(char *str);
char	*ft_strjoin(const char *str1, const char *str2);
char	*ft_before_bn(char *str);
int		ft_strlen(char *str);
char	*tmp_mallocked(char *tmp);
char	*ft_free(char *str);

#endif