/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdemetra <cdemetra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 16:48:39 by cdemetra          #+#    #+#             */
/*   Updated: 2019/04/25 14:22:03 by cdemetra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_putstr(char const *s)
{
	size_t	q;

	if (s == NULL)
		return ;
	q = 0;
	while (s[q] != '\0')
	{
		ft_putchar(s[q]);
		q++;
	}
}
