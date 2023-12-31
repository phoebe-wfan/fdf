/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 16:27:59 by wfan              #+#    #+#             */
/*   Updated: 2023/09/10 16:28:08 by wfan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	error(int exit_code)
{
	if (exit_code == 0)
		ft_putstr_fd("fdf closed. bye\n", 1);
	else if (exit_code == 1)
		ft_putstr_fd("wrong usage. try'./fdf <file_path>'\n", 1);
	else if (exit_code == 2)
		ft_putstr_fd("cannot read file\n", 1);
	else if (exit_code == 3)
		ft_putstr_fd("cannot initialize fdf\n", 1);
	else if (exit_code == 4)
		ft_putstr_fd("cannot parse map\n", 1);
	else if (exit_code == 5)
		ft_putstr_fd("cannot create image\n", 1);
	else if (exit_code == 6)
		ft_putstr_fd("cannot initialize camera\n", 1);
	else if (exit_code == 7)
		ft_putstr_fd("unable to render\n", 1);
	else if (exit_code == 8)
		ft_putstr_fd("unable to initialize color\n", 1);
	else if (exit_code == 9)
		ft_putstr_fd("map error\n", 1);
	exit(exit_code);
}
