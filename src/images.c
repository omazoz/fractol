/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omazoz <omazoz@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 18:51:45 by omazoz            #+#    #+#             */
/*   Updated: 2022/02/14 18:54:52 by omazoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_image_put_pixel(t_image *image, int x, int y, int color)
{
	if (x < 0 || x >= WIDTH || y < 0 || y >= WIDTH)
		return (0);
	image->pixels[y * WIDTH + x] = color;
	return (1);
}
