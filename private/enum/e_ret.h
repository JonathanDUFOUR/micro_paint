/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_ret.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 21:34:50 by jodufour          #+#    #+#             */
/*   Updated: 2021/10/01 00:44:49 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef E_RET_H
# define E_RET_H

enum	e_ret
{
	SUCCESS,
	AC_ERR,
	FOPEN_ERR,
	PARSE_ERR,
	MALLOC_ERR,
	LINE_FORMAT_ERR,
	MP_FILE_CONTENT_GET_ERR
};

#endif
