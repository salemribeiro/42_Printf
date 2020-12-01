/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfreitas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 22:13:40 by salem             #+#    #+#             */
/*   Updated: 2020/11/30 22:14:09 by salem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	*ft_strdup(const char *src)
{
	char	*ans;
	int		i;

	i = 0;
	while (src[i] != '\0')
		i++;
	if (!(ans = malloc(sizeof(char) * i + 1)))
		return (0);
	i = 0;
	while (src[i] != '\0')
	{
		ans[i] = src[i];
		i++;
	}
	ans[i] = '\0';
	return (ans);
}
