/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcampas- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 15:39:38 by dcampas-          #+#    #+#             */
/*   Updated: 2024/10/01 12:36:52 by dcampas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}
/*
int main()
{
    ft_putchar_fd('A', 1);  // Escribe 'A' en la pantalla
    ft_putchar_fd('\n', 1); // Escribe un salto de línea en la pantalla
    ft_putchar_fd('B', 2);  // Escribe 'B' como
	 un mensaje de error (error estándar)
    return 0;
}*/
