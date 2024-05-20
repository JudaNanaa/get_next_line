/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@contact.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 14:38:31 by madamou           #+#    #+#             */
/*   Updated: 2024/05/19 18:23:56 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_check_if_newline(char *all)
{
	int	i;

	i = 0;
	if (!all)
		return (0);
	while (all[i])
	{
		if (all[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_clear_all(char *all)
{
	int		i;
	int		j;
	int		len_all;
	char	*tmp;

	i = 0;
	len_all = ft_strlen(all, 1);
	while (all[i] != '\n')
		i++;
	i++;
	tmp = malloc(sizeof(char) * (len_all - i + 1));
	if (!tmp)
		return (free(all), NULL);
	j = 0;
	while (all[i])
		tmp[j++] = all[i++];
	tmp[j] = '\0';
	all = ft_strcpy(all, tmp);
	free(tmp);
	if (!all)
		return (NULL);
	return (all);
}

char	*ft_norminette(int fd, char *all)
{
	char	*buff;

	buff = "";
	return (all = ft_moulinette(all, buff, fd, BUFFER_SIZE));
}

char	*ft_moulinette(char *all, char *buff, int fd, int byte_read)
{
	while (ft_check_if_newline(all) == 0)
	{
		buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buff)
			return (free(all), NULL);
		byte_read = read(fd, buff, BUFFER_SIZE);
		if ((byte_read == 0 && !all) || byte_read == -1)
			return (free(buff), free(all), NULL);
		buff[byte_read] = '\0';
		if (byte_read < BUFFER_SIZE)
			break ;
		all = ft_buff_to_all(all, buff);
		if (!all)
			return (NULL);
	}
	if (byte_read < BUFFER_SIZE)
	{
		all = ft_buff_to_all(all, buff);
		if (!all)
			return (NULL);
	}
	return (all);
}

char	*get_next_line(int fd)
{
	static char	*all;
	char		*sortie;

	if (fd < 0)
		return (NULL);
	all = ft_norminette(fd, all);
	if (!all)
		return (free(all), NULL);
	if (ft_check_if_newline(all) == 1)
	{
		sortie = ft_strdup(all, 2);
		if (all[0] == '\0')
		{
			free(all);
			all = NULL;
		}
	}
	else
	{
		sortie = ft_strdup(all, 1);
		all = NULL;
	}
	if (!sortie)
		return (free(all), NULL);
	return (sortie);
}

/*#include<fcntl.h>
int	main(void)
{
        int fd;
        char *line;

        // Ouvrir le fichier en lecture
        fd = open("oui", O_RDONLY);
        if (fd == -1)
        {
                perror("Error opening file");
                return (1);
        }

        // Lire et afficher chaque ligne du fichier
        line = get_next_line(fd);
        printf("[%s]", line);
        free(line); // Libérer la mémoire allouée par get_next_line
        line = get_next_line(fd);
        printf("[%s]", line);
        free(line); // Libérer la mémoire allouée par get_next_line
        line = get_next_line(fd);
        printf("[%s]", line);
        free(line); // Libérer la mémoire allouée par get_next_line
        line = get_next_line(fd);
        printf("[%s]", line);
        free(line); // Libérer la mémoire allouée par get_next_line
        line = get_next_line(fd);
        printf("[%s]", line);
        free(line); // Libérer la mémoire allouée par get_next_line
        close(fd);

        return (0);
}*/
