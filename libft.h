/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarba <sgarba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 17:11:02 by sgarba            #+#    #+#             */
/*   Updated: 2025/11/28 19:19:01 by sgarba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>

int  ft_atoi(const char *nptr);

void	ft_bzero(void *ptr, size_t n);

void	*ft_memchr(void *ptr, int c, size_t n);

int ft_memcmp(const void *p1, const void *p2, size_t n);

void	*ft_memcpy(void *to, const void *from, size_t n);

void	*ft_memmove(void *to, const void *from, size_t n);

void	*ft_memset(void *p, int c, size_t n);

char	*ft_strchr(const char *str, int c);

size_t	ft_strlen(const char *str);

int	ft_isalnum(int c);

int  ft_isalpha(int c);

int	ft_isascii(int c);

int  ft_isdigit(int c);

int	ft_isprint(int c);

char  *ft_tolower(char *str);

char  *ft_toupper(char *str);

size_t	ft_strlcat(char *dst, const char *src, size_t size);

#endif