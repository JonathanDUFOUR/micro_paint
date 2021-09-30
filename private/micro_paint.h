/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   micro_paint.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 21:34:09 by jodufour          #+#    #+#             */
/*   Updated: 2021/10/01 00:18:15 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MICRO_PAINT_H
# define MICRO_PAINT_H

# ifndef BUFF_SIZE
#  define BUFF_SIZE 4096
# endif

# include <stdio.h>
# include <stddef.h>
# include <stdbool.h>

int		mp_err_msg(int const err);
int		mp_file_content_check(char const *filename);

void	mp_memdel(void *addr);

char	*mp_file_content_get(FILE *stream);
char	*mp_strchr(char const *str, char const c);
char	*mp_strjoin(char const *s0, char const *s1);

bool	mp_isdigit(char const c);
bool	mp_isspace(char const c);

size_t	mp_line_len(char const *str);
size_t	mp_strlen(char const *str);

#endif
