/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitoe <thitoe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 21:20:10 by thitoe            #+#    #+#             */
/*   Updated: 2025/08/15 05:30:49 by thitoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <stddef.h>
# include <string.h>
# include <unistd.h>

unsigned long	ft_putnbr_fd(int n, int fd);
unsigned long	ft_putnbr_ab(unsigned int n, int fd);
unsigned long	ft_putchar(char c);
int				ft_printf(const char *format, ...);
void			ft_putstr(const char *s, int fd);
size_t			ft_strlen(const char *s);
ssize_t			ft_putchar_ssize(char c);
int				ft_judgment(va_list args, char format);
unsigned long	ft_write_pointer(void *ptr);
unsigned long	ft_write(const char *str);
ssize_t			ft_write_hex(unsigned int num, int uppercase);
int				ft_atoi(const char *str);

#endif