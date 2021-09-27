/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_msg_lookup.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 21:41:34 by jodufour          #+#    #+#             */
/*   Updated: 2021/09/27 22:37:34 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERR_MSG_LOOKUP_H
# define ERR_MSG_LOOKUP_H

# include <stddef.h>
# include "enum/e_ret.h"

typedef struct s_err_msg	t_err_msg;

struct s_err_msg
{
	int const		err;
	char const		*msg;
	size_t const	len;
};

static t_err_msg const		g_err_msg[] = {
	{AC_ERR, "Error: argument\n", 16},
	{FOPEN_ERR, "Error: Operation file corrupted\n", 32},
	{PARSE_ERR, "Error: Operation file corrupted\n", 32},
	{0, NULL, 0}
};

#endif
