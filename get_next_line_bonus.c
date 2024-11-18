/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajodar-c <ajodar-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 11:40:20 by ajodar-c          #+#    #+#             */
/*   Updated: 2024/10/18 11:26:48 by ajodar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

//read function of file
static char	*ft_read(int fd, char *memory)
{
	ssize_t		bytesread;
	char		*nbuffer;

	bytesread = 1;
	nbuffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (nbuffer == NULL)
		return (free(memory), NULL);
	while (bytesread > 0 && !ft_strchr(memory, '\n'))
	{
		bytesread = read(fd, nbuffer, BUFFER_SIZE);
		if (bytesread < 0)
			return (free(nbuffer), free(memory), NULL);
		nbuffer[bytesread] = '\0';
		if (bytesread == 0)
			return (free(nbuffer), memory);
		memory = ft_join(memory, nbuffer);
	}
	return (free(nbuffer), memory);
}

//create a line with memory read
static char	*ft_line(char *memory)
{
	char	*line;
	int		i;

	i = 0;
	while (memory[i] != '\0' && memory[i] != '\n')
		i++;
	if (memory[i] == '\n')
		i++;
	line = ft_substr(memory, 0, i);
	return (line);
}

//save rest of line on the memory
static char	*ft_save(char *memory, int *malloc_flag)
{
	int		i;
	char	*savemem;

	i = 0;
	while (memory[i] != '\0' && memory[i] != '\n')
		i++;
	if (memory[i] == '\n')
		i++;
	if (memory[i] == '\0')
		return (free(memory), NULL);
	savemem = ft_substr(memory, i, ft_strlen(memory) - i);
	if (savemem == NULL)
		*malloc_flag = 1;
	return (free(memory), savemem);
}

//version 4.1 (dinamic buffer and line stop at \n)
//Get ft_read with read in a while
//Take a line with ft_line
//Save the rest in memory with ft_save
char	*get_next_line(int fd)
{
	int			malloc_flag;
	char		*line;
	static char	*memory[1024];

	malloc_flag = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (free(memory[fd]), memory[fd] = NULL, NULL);
	memory[fd] = ft_read(fd, memory[fd]);
	if (memory[fd] == NULL)
		return (NULL);
	line = ft_line(memory[fd]);
	if (line == NULL)
		return (free(memory[fd]), memory[fd] = NULL, NULL);
	memory[fd] = ft_save(memory[fd], &malloc_flag);
	if (malloc_flag == 1)
		return (free(line), NULL);
	return (line);
}
