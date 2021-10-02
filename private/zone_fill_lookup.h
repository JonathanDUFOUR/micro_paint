/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zone_fill_lookup.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 15:36:03 by jodufour          #+#    #+#             */
/*   Updated: 2021/10/02 20:24:57 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZONE_FILL_LOOKUP_H
# define ZONE_FILL_LOOKUP_H

# include <stddef.h>
# include "type/t_rect.h"

typedef struct s_fill	t_fill;

struct s_fill
{
	char const	type;
	int			(*f)(t_rect rect);
};

int	mp_ctx_zone_fill_rect_empty(t_rect rect);
int	mp_ctx_zone_fill_rect_full(t_rect rect);

static t_fill const		g_fill[] = {
	{'r', mp_ctx_zone_fill_rect_empty},
	{'R', mp_ctx_zone_fill_rect_full},
	{0, NULL}
};

#endif
