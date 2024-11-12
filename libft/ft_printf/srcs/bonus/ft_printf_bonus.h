/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 08:52:20 by hmunoz-g          #+#    #+#             */
/*   Updated: 2024/10/24 12:13:01 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include "../../includes/ft_printf.h"

void	ft_printf_c_bonus(t_flags flags, t_char c, t_res *res);
void	ft_c_setup(t_flags flags, va_list args, t_res *res);
void	ft_printf_di(t_flags flags, t_char d, t_res *res);
void	ft_di_starter(t_flags flags, t_char d, t_res *res);
void	ft_di_setup(t_flags flags, va_list args, t_res *res);
void	ft_di_001(t_flags flags, t_char d, t_res *res);
void	ft_di_100_1m10(t_flags flags, t_char d, t_res *res);
void	ft_di_110(t_flags flags, t_char d, t_res *res);
void	ft_di_111(t_flags flags, t_char d, t_res *res);
void	ft_di_101(t_flags flags, t_char d, t_res *res);
void	ft_printf_p(t_flags flags, t_res *res);
void	ft_p_starter(t_flags flags, t_char d, t_res *res);
void	ft_p_setup(t_flags flags, va_list args, t_res *res);
void	ft_p_001(t_flags flags, t_char d, t_res *res);
void	ft_p_100_1m10(t_flags flags, t_char d, t_res *res);
void	ft_p_110(t_flags flags, t_char d, t_res *res);
char	*ft_s_trimmer(t_flags flags);
void	ft_s_starter(t_flags flags, t_res *res);
void	ft_s_setup(t_flags flags, va_list args, t_res *res);
void	ft_s_number_is_zero(t_flags flags, t_res *res, char *dot);
void	ft_s_num_flags_0(t_flags flags, t_res *res);
void	ft_s_num_dot_0_min_1(t_flags flags, t_res *res, char *dot);
void	ft_s_num_dot_1_min_0(t_flags flags, t_res *res, char *dot);
void	ft_s_num_dot_1_min_1(t_flags flags, t_res *res, char *dot);
void	ft_printf_u(t_flags flags, t_char d, t_res *res);
void	ft_u_hub(t_flags flags, t_char d, t_res *res);
void	ft_u_setup(t_flags flags, va_list args, t_res *res);
void	ft_u_001(t_flags flags, t_char d, t_res *res);
void	ft_u_100_1m10(t_flags flags, t_char d, t_res *res);
void	ft_u_110(t_flags flags, t_char d, t_res *res);
void	ft_u_111(t_flags flags, t_char d, t_res *res);
void	ft_u_101(t_flags flags, t_char d, t_res *res);
void	ft_printf_x(t_flags flags, t_char d, t_res *res);
void	ft_x_hub(t_flags flags, t_char d, t_res *res);
void	ft_x_setup(t_flags flags, va_list args, t_res *res);
void	ft_x_001(t_flags flags, t_char d, t_res *res);
void	ft_x_100_1m10(t_flags flags, t_char d, t_res *res);
void	ft_x_110(t_flags flags, t_char d, t_res *res);
void	ft_x_111(t_flags flags, t_char d, t_res *res);
void	ft_x_101(t_flags flags, t_char d, t_res *res);

#endif
