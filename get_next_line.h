/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@contact.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 15:12:28 by itahri            #+#    #+#             */
/*   Updated: 2024/06/28 20:34:21 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

// # define BUFFER_SIZE 5
# include <bsd/string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 512
# endif // !BUFFER_SIZE

int		ft_strlen(char *str, int cas);
int		ft_strlen(char *str, int cas);
int		ft_check_if_newline(char *sortie);

char	*get_next_line(int fd);
char	*ft_strcpy(char *dest, char *src);

char	*ft_format_sortie(char *sortie);

#endif
