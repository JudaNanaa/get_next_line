/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@contact.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 18:32:05 by itahri            #+#    #+#             */
/*   Updated: 2024/06/28 20:34:42 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_buff_to_all(char *all, char *buff)
{
	char	*str;
	int		i;

	i = ft_strlen(all, 1);
	str = malloc(sizeof(char) * (i + ft_strlen(buff, 1) + 1));
	if (!str)
		return (free(all), NULL);
	str[0] = '\0';
	ft_strcpy(str, all);
	free(all);
	ft_strcpy(&str[i], buff);
	return (str);
}

char	*ft_read_file(int fd, char *sortie, char *buff)
{
	int	nb_read;

	buff[0] = '\0';
	nb_read = BUFFER_SIZE;
	while (ft_check_if_newline(sortie) == 0)
	{
		nb_read = read(fd, buff, BUFFER_SIZE);
		if (nb_read == -1)
			return (free(sortie), NULL);
		buff[nb_read] = '\0';
		if (nb_read < BUFFER_SIZE)
			break ;
		sortie = ft_buff_to_all(sortie, buff);
		if (!sortie)
			return (NULL);
	}
	if (nb_read < BUFFER_SIZE)
	{
		sortie = ft_buff_to_all(sortie, buff);
		if (!sortie)
			return (NULL);
	}
	return (sortie);
}

char	*get_next_line(int fd)
{
	static char	stach[BUFFER_SIZE + 1];
	char		*sortie;

	if (fd < 0)
		return (NULL);
	sortie = malloc(sizeof(char) * (ft_strlen(stach, 1) + 1));
	if (!sortie)
		return (stach[0] = '\0', NULL);
	sortie[0] = '\0';
	sortie = ft_strcpy(sortie, stach);
	sortie = ft_read_file(fd, sortie, stach);
	if (!sortie)
		return (stach[0] = '\0', NULL);
	if (ft_check_if_newline(sortie) == 1)
	{
		ft_strcpy(stach, &sortie[ft_strlen(sortie, 2)]);
		sortie = ft_format_sortie(sortie);
	}
	else
	{
		stach[0] = '\0';
		if (sortie[0] == '\0')
			return (free(sortie), NULL);
	}
	return (sortie);
}

// #include <fcntl.h>

// int	main(void)
// {
// 	int		fd;
// 	char	*line;

// 	// Ouvrir le fichier en lecture
// 	fd = open("mutiple.txt", O_RDONLY);
// 	if (fd == -1)
// 	{
// 		perror("Error opening file");
// 		return (1);
// 	}
// 	line = get_next_line(fd);
// 	printf("%s", line);
// 	free(line);
// 	close(fd);
// 	printf("%d\n", fd);
// 	line = get_next_line(10);
// 	printf("oui = |%s|", line);
// 	fd = open("mutiple.txt", O_RDONLY);
// 	line = get_next_line(fd);
// 	printf("%s", line);
// 	free(line);
// 	line = get_next_line(fd);
// 	printf("[%s]\n", line);
// 	free(line);
// 	line = get_next_line(10);
// 	printf("[%s]\n", line);
// 	free(line);
// 	close(fd);
// 	fd = open("read_error.txt", O_RDONLY);
// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		printf("%s", line);
// 		free(line);
// 	}
// 	return (0);
// }
