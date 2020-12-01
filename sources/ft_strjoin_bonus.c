/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfreitas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 22:14:18 by salem             #+#    #+#             */
/*   Updated: 2020/11/30 22:14:36 by salem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int			contador(const char *ptr)
{
	int i;

	i = 0;
	while (ptr[i] != '\0')
		i++;
	return (i);
}

static char			*execjoin(char const *s1, char const *s2, char *ptr)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		ptr[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		ptr[i] = s2[j];
		i++;
		j++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char				*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*ptr;

	if (!s1 || !s2)
		return (NULL);
	i = contador(s1);
	j = contador(s2);
	ptr = (char*)malloc(sizeof(char) * (i + j + 1));
	if (!ptr)
		return (0);
	ptr = execjoin(s1, s2, ptr);
	return (ptr);
}
