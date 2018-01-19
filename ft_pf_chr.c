/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_chr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaber <neyl.jaber@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 13:03:22 by njaber            #+#    #+#             */
/*   Updated: 2018/01/18 11:47:32 by njaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t			pf_chr_len(t_mods mods, t_byte *parm, va_list arg)
{
	va_list	arg_cpy;
	t_ucd	c8;

	(void)parm;
	if (mods.cast == 'l')
	{
		va_copy(arg_cpy, arg);
		c8.wi = va_arg(arg_cpy, wint_t);
		va_end(arg_cpy);
		c8.wi = uctou8(c8.wi);
		c8.c[4] = 0;
		return (ft_strlen(c8.c));
	}
	return (1);
}

void			pf_chr(t_mods mods, t_byte *parm, t_buf *buf, va_list arg)
{
	t_ucd	c8;

	(void)parm;
	if (mods.cast == 'l')
	{
		c8.wi = va_arg(arg, wint_t);
		c8.wi = uctou8(c8.wi);
		c8.c[4] = 0;
		str_totmpbuf(c8.c, ft_umax(ft_strlen(c8.c), 1), buf, 0);
	}
	else
	{
		c8.c[0] = (char)va_arg(arg, int);
		chr_totmpbuf(c8.c[0], 1, buf, 0);
	}
}
