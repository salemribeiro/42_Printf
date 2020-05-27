/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier_options.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfreitas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 22:57:57 by sfreitas          #+#    #+#             */
/*   Updated: 2020/04/29 22:58:33 by sfreitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		specifier_options(char *subtext, void *arg)
{
	size_t	i;
	size_t	j;
	char	specifier[20];

	i = 1;
	j = 0;
	ft_strlcpy(specifier,"diuoxXfFeEgGaAcspn%", 20);
	while (subtext[i])
	{
		while (specifier[j] && subtext[i] != specifier[j])
			j++;
		if (specifier[j])
		{
			flag_options(ft_substr(subtext, 1, i), specifier[j]);
			return(i);
		}
		j = 0;
		i++;
	}
	return(0);
}

char	width_options(char flags , char *f)
{
	char *width;

	width = NULL;
	while (*f == '+' || *f == '-' || *f == '#' || *f == '0' || *f == ' ')
		f++;
	while (ft_isdigit(*f))
	{
		if (width != NULL)
		{
			free(width);
			width = NULL;
		}
		width = width_buffer(width, *f);
		f++;
	}
	printf("%s\n", f);
	return (0);
}

void	*width_buffer(char *width, char c)
{
	char *temp;
	int size;

	size = 0;
	if (!width && c)
	{
	 	width = calloc(2, sizeof(char));
		*width = c;
		return (width);
	}
	else if (!width && !c)
		return (NULL);
	size = ft_strlen(width);
	temp = calloc(size, sizeof(char));
	ft_strlcpy(temp, width, size)
	temp[size + 1] = c;
	free (width);
	return (temp);
}



