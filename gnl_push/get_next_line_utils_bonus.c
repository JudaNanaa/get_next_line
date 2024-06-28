/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@contact.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 14:38:34 by madamou           #+#    #+#             */
/*   Updated: 2024/05/23 20:59:30 by itahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen1(char *str, int cas)
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

char	*ft_buff_to_all(char *all, char *buff, int len_buff)
{
	char	*str;
	int		i;
	int		j;

	i = ft_strlen1(all, 1);
	str = malloc(sizeof(char) * (i + len_buff + 1));
	if (!str)
		return (free(all), NULL);
	str[0] = '\0';
	j = 0;
	while (all && all[j])
	{
		str[j] = all[j];
		j++;
	}
	str[j] = '\0';
	free(all);
	j = -1;
	while (buff[++j])
		str[i + j] = buff[j];
	str[i + j] = '\0';
	return (str);
}

char	*ft_strcpy1(char *dest, char *src)
{
	int	i;

	i = -1;
	if (!src)
		return (dest);
	while (src[++i])
		dest[i] = src[i];
	return (dest[i] = '\0', dest);
}

char	*ft_strdup1(char *src, int cas)
{
	char				*dest;
	long unsigned int	i;
	int					len_str;

	len_str = ft_strlen1(src, cas);
	i = -1;
	dest = malloc(sizeof(char) * (len_str + 1));
	if (!dest)
		return (NULL);
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
		src = ft_strcpy1(src, &src[len_str]);
	}
	return (dest[i] = '\0', dest);
}
