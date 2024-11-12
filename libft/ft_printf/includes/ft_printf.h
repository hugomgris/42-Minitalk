/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:59:52 by hmunoz-g          #+#    #+#             */
/*   Updated: 2024/10/23 15:55:53 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../../libft.h"

# define ALL "0# +-123456789."
# define CHARS "cspdiuxX%"
# define FLAGS "0# +-"
# define NUMBERS "123456789"
# define PRECISION "."

typedef struct s_res
{
	int	n;
}	t_res;

typedef struct s_char
{
	int						i;
	int						j;
	long long unsigned int	lui;
	char					*str;
	int						len;
	char					c;
	unsigned int			ui;
	int						ct;
}	t_char;

typedef struct s_flags
{
	int		zemin;
	int		spaplus;
	char	dot;
	int		number;
	int		dot_num;
	char	param;
	int		square;
	char	*substr;
	char	*str;
}	t_flags;

//MAIN functions
int		ft_printf(const char *str, ...);
void	ft_starter(t_flags flags, va_list args, t_res *res);

//MANAGERS functions
void	ft_padding(int s, int start, int stop, t_res *res);
int		ft_spaplus(t_flags flags, t_char d, int i, t_res *res);
int		ft_square(t_flags flags, t_char d, int i, t_res *res);
char	*ft_itoa_printf(int n);
char	*ft_itoa_printf_u(unsigned int n);
char	*ft_itoa_printf_x(unsigned int n, t_char d, t_flags flags);
char	*ft_itoa_printf_p(unsigned long int n, t_char d, t_flags flags);
void	ft_putchar_fd_print(char c, int fd, t_res *res);
void	ft_putnbase_cap_fd(unsigned long int n, int base, int fd, t_res *res);
void	ft_putnbase_low_fd(unsigned long int n, int base, int fd, t_res *res);
void	ft_putnbr_fd_print_u(unsigned int n, int fd, t_res *res);
void	ft_putnbr_fd_print(int n, int fd, t_res *res);
void	ft_putstr_fd_print(char *s, int fd, size_t len, t_res *res);

//PARSER functions
void	ft_numbers_in_flags(t_flags *flags);
void	ft_flags_conditions(t_flags *flags);
int		ft_check_char(char c);
int		ft_check_flag(char c);
int		ft_check_number(char c);
int		ft_check_all(char c);
void	ft_flag_manager(va_list args, t_flags flags, t_res *res);
void	ft_struct_init(char	*str, va_list args, t_res *res);
void	ft_get_flags(const char *str, int len, va_list args, t_res *res);
void	ft_parse_str(const char *str, va_list args, t_res *res);

//PRINTER functions
void	ft_printf_c(t_char c, t_res *res);
void	ft_c_setup(t_flags fglas, va_list args, t_res *res);
void	ft_printf_di(t_flags flags, t_char d, t_res *res);
void	ft_di_setup(t_flags flags, va_list args, t_res *res);
void	ft_printf_p_extra(t_flags flags, t_res *res);
void	ft_printf_p(t_flags flags, t_res *res);
void	ft_p_setup(t_flags flags, va_list args, t_res *res);
void	ft_printf_s(t_flags flags, t_res *res);
void	ft_s_setup(t_flags flags, va_list args, t_res *res);
void	ft_printf_u(t_flags flags, t_char d, t_res *res);
void	ft_u_setup(t_flags flags, va_list args, t_res *res);
void	ft_printf_x(t_flags flags, t_char d, t_res *res);
void	ft_x_setup(t_flags flags, va_list args, t_res *res);

#endif
