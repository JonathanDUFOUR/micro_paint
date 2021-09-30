/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_check_actions_array.h                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 23:59:15 by jodufour          #+#    #+#             */
/*   Updated: 2021/10/01 00:17:12 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINE_CHECK_ACTIONS_ARRAY_H
# define LINE_CHECK_ACTIONS_ARRAY_H

# include <stddef.h>
# include <stdbool.h>

typedef struct s_action	t_action;

struct s_action
{
	bool	(*check_fct)(char const c);
	char	*(*skip_fct)(char const *str);
};

bool	mp_isdigit(char const c);
bool	mp_isspace(char const c);

char	*mp_skip_float(char const *str);
char	*mp_skip_integer(char const *str);
char	*mp_skip_spaces(char const *str);

static t_action const	g_action_first_line[] = {
	{mp_isdigit, mp_skip_integer},
	{mp_isspace, mp_skip_spaces},
	{mp_isdigit, mp_skip_integer},
	{mp_isspace, mp_skip_spaces},
	{NULL, NULL}
};

static t_action const	g_action_other_line[] = {
	{mp_isspace, mp_skip_spaces},
	{mp_isdigit, mp_skip_float},
	{mp_isspace, mp_skip_spaces},
	{mp_isdigit, mp_skip_float},
	{mp_isspace, mp_skip_spaces},
	{mp_isdigit, mp_skip_float},
	{mp_isspace, mp_skip_spaces},
	{mp_isdigit, mp_skip_float},
	{mp_isspace, mp_skip_spaces},
	{NULL, NULL}
};

#endif
