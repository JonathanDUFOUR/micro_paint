/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_rect.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 19:39:33 by jodufour          #+#    #+#             */
/*   Updated: 2021/10/02 20:03:18 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_RECT_H
# define T_RECT_H

typedef struct s_rect	t_rect;

struct s_rect
{
	char	type;
	float	x;
	float	y;
	float	width;
	float	height;
	char	c;
};

#endif
