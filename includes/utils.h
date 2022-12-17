/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <42.fr>                             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 16:30:31 by marvin            #+#    #+#             */
/*   Updated: 2022/12/17 15:49:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

#include <stddef.h>

size_t	ft_strlen(const char *str);
void	ft_strreplace(char **a, char *b);
char	*ft_strnjoin(char *s1, char *s2, size_t n);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
char	*read_line(int fd);

#endif
