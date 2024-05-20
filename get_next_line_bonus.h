/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@contact.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 14:38:37 by madamou           #+#    #+#             */
/*   Updated: 2024/05/08 23:11:00 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

//# define BUFFER_SIZE 5

int		ft_check_if_newline(char *all);
int		ft_strlen1(char *str, int cas);

char	*ft_clear_all(char *all);
char	*ft_norminette(int fd, char *all);
char	*ft_strdup1(char *src, int cas);
char	*ft_buff_to_all(char *all, char *buff);
char	*get_next_line(int fd);
char	*ft_strcpy1(char *dest, char *src);
char	*ft_moulinette(char *all, char *buff, int fd, int byte_read);

#endif
