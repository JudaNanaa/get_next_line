/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@contact.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 14:38:37 by madamou           #+#    #+#             */
/*   Updated: 2024/05/23 21:08:03 by itahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

int		ft_check_if_newline(char *all);
int		ft_strlen(char *str, int cas);

char	*ft_norminette(int fd, char *all);
char	*ft_strdup(char *src, int cas);
char	*ft_buff_to_all(char *all, char *buff);
char	*get_next_line(int fd);
char	*ft_strcpy(char *dest, char *src);
char	*ft_moulinette(char *all, char *buff, int fd, int byte_read);

#endif
