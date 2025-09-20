/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtran-nh <mtran-nh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 19:15:19 by mtran-nh          #+#    #+#             */
/*   Updated: 2025/09/20 22:46:22 by mtran-nh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static char	*gnl_join(char *s1, char *s2, int len2)
{
	int		len1;
	char	*res;
	int		i;

	len1 = 0;
	if (s1)
		while (s1[len1])
			len1++;
	res = malloc(len1 + len2 + 1);
	if (!res)
		return (NULL);
	i = -1;
	while (++i < len1)
		res[i] = s1[i];
	i = -1;
	while (++i < len2)
		res[len1 + i] = s2[i];
	res[len1 + len2] = 0;
	if (s1)
		free(s1);
	return (res);
}

static char	*extract_line(char **remain)
{
	char	*line;
	char	*new_remain;
	char	*nl;
	size_t	len;

	if (!*remain || !**remain)
		return (NULL);
	nl = ft_strchr(*remain, '\n');
	if (nl)
		len = nl - *remain + 1;
	else
		len = ft_strlen(*remain);
	line = ft_strndup(*remain, len);
	if (!line)
		return (NULL);
	if (nl)
	{
		new_remain = ft_strdup(*remain + len);
		if (!new_remain)
			return (free(line), NULL);
	}
	free(*remain);
	*remain = new_remain;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*remain;
	char		buf[BUFFER_SIZE];
	char		*line;
	int			bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (!remain || !ft_strchr(remain, '\n'))
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes <= 0)
			break ;
		buf[bytes] = '\0';
		remain = gnl_join(remain, buf, bytes);
		if (!remain)
			return (NULL);
	}
	if (!remain || !*remain)
		return (NULL);
	line = extract_line(&remain);
	return (line);
}
