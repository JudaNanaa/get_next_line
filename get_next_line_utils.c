/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@contact.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 14:38:34 by madamou           #+#    #+#             */
/*   Updated: 2024/05/19 18:14:41 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str, int cas)
{
	int	i;

	i = 0;
	if (cas == 1)
	{
		while (str && str[i])
			i++;
	}
	if (cas == 2)
	{
		while (str && str[i] != '\n')
			i++;
		i++;
	}
	return (i);
}

char	*ft_buff_to_all(char *all, char *buff)
{
	char	*str;
	int		i;
	int		j;

	i = ft_strlen(all, 1);
	str = malloc(sizeof(char) * (i + ft_strlen(buff, 1) + 1));
	if (!str)
		return (free(all), free(buff), NULL);
	str[0] = '\0';
	str = ft_strcpy(str, all);
	free(all);
	j = -1;
	while (buff[++j])
		str[i + j] = buff[j];
	str[i + j] = '\0';
	return (free(buff), str);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = -1;
	if (!src)
	{
		return (dest);
	}
	while (src[++i])
		dest[i] = src[i];
	return (dest[i] = '\0', dest);
}

char	*ft_strdup(char *src, int cas)
{
	char				*dest;
	long unsigned int	i;

	i = -1;
	dest = malloc(sizeof(char) * (ft_strlen(src, cas) + 1));
	if (dest == NULL)
		return (free(src), NULL);
	if (cas == 1)
	{
		while (src[++i])
			dest[i] = src[i];
		free(src);
	}
	if (cas == 2)
	{
		while (src[++i] != '\n')
			dest[i] = src[i];
		dest[i] = src[i];
		i++;
		src = ft_clear_all(src);
		if (!src)
			return (free(dest), NULL);
	}
	return (dest[i] = '\0', dest);
}
