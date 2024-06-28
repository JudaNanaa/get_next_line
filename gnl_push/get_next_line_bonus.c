/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@contact.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 14:38:31 by madamou           #+#    #+#             */
/*   Updated: 2024/05/23 20:59:26 by itahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_check_if_newline(char *all)
{
	int	i;

	i = 0;
	while (all && all[i])
	{
		if (all[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_norminette(int fd, char *all)
{
	char	*buff;

	buff = NULL;
	return (ft_moulinette(all, buff, fd, BUFFER_SIZE));
}

char	*ft_moulinette(char *all, char *buff, int fd, int byte_read)
{
	while (ft_check_if_newline(buff) == 0)
	{
		free(buff);
		buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buff)
			return (free(all), NULL);
		byte_read = read(fd, buff, BUFFER_SIZE);
		if ((byte_read == 0 && !all) || byte_read == -1)
			return (free(buff), free(all), NULL);
		buff[byte_read] = '\0';
		if (byte_read < BUFFER_SIZE)
			break ;
		all = ft_buff_to_all(all, buff, byte_read);
		if (!all)
			return (NULL);
	}
	if (byte_read < BUFFER_SIZE)
	{
		all = ft_buff_to_all(all, buff, byte_read);
		if (!all)
			return (NULL);
	}
	return (free(buff), all);
}

char	*get_next_line(int fd)
{
	static char	*all[10000];
	char		*sortie;

	if (fd < 0)
		return (NULL);
	all[fd] = ft_norminette(fd, all[fd]);
	if (!all[fd])
		return (NULL);
	if (ft_check_if_newline(all[fd]) == 1)
	{
		sortie = ft_strdup1(all[fd], 2);
		if (all[fd][0] == '\0')
		{
			free(all[fd]);
			all[fd] = NULL;
		}
	}
	else
	{
		sortie = ft_strdup1(all[fd], 1);
		all[fd] = NULL;
	}
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
