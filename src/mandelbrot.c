/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omazoz <omazoz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 20:07:28 by omazoz            #+#    #+#             */
/*   Updated: 2022/02/20 18:01:29 by omazoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	draw_mandelbrot(t_env *env, t_calc *calc)
{
	int k;
	float x, y;
	float a, b;
	float ca, cb;

	for (int i = calc->area.min_y; i < calc->area.max_y; i++)
	{
		for (int j = calc->area.min_x; j < calc->area.max_x; j++)
		{
			x = ((float)j / HEIGHT) * (calc->max_i - calc->min_i) + calc->min_i;
			y = ((float)i / HEIGHT) * (calc->max_r - calc->min_r) + calc->min_r;
			k = 0;
		
			ca = x;
			cb = y;
			while (k < MAX_ITER)
			{
				a =  (x*x - y*y);
				b =  (x*y + x*y);
				x = (a + ca);
				y =  (b + cb);
				if ( (x*x+y*y )> 16)
					break ;
				k++;
			}
			int color;

		if (k == MAX_ITER)
				k = 0;
			color = k/0.9;
			ft_image_put_pixel(&env->image, j, i, color*k);
		}
	}
	return(0);
}
