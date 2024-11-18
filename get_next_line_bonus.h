/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajodar-c <ajodar-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 12:18:24 by ajodar-c          #+#    #+#             */
/*   Updated: 2024/10/16 13:26:43 by ajodar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <fcntl.h>  // Para open()
# include <unistd.h> // Para read() y close()
# include <stdlib.h> // Para malloc() y free()
# include <stdio.h>  // Para printf()

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
void	*ft_calloc(size_t num, size_t size);
size_t	ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_join(char *buffer, char *nread);
char	*ft_strchr(const char *str, int c);

#endif