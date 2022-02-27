/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omazoz <omazoz@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 21:00:49 by omazoz            #+#    #+#             */
/*   Updated: 2022/02/18 13:31:01 by omazoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom_into(t_calc *calc, float scale, int x, int y)
{
	double	mouse_i;
	double	mouse_r;
	double	half_size;

	mouse_i = (x / (double)HEIGHT) * (calc->max_i - calc->min_i) + calc->min_i;
	mouse_r = (y / (double)WIDTH) * (calc->max_r - calc->min_r) + calc->min_r;
	calc->min_i = (calc->min_i - mouse_i) * scale + mouse_i;
	calc->max_i = (calc->max_i - mouse_i) * scale + mouse_i;
	calc->min_r = (calc->min_r - mouse_r) * scale + mouse_r;
	calc->max_r = (calc->max_r - mouse_r) * scale + mouse_r;
}

int	mouse_events(int button , int x, int y, void *param)
{
	t_env *env;

	env = param;
	if (button == MOUSE_SCROLL_DOWN)
		zoom_into(&env->calc, 0.9, WIDTH/2, HEIGHT/2);
	else if (button == MOUSE_SCROLL_UP)
		zoom_into(&env->calc, 1.1, WIDTH/2, HEIGHT/2);
	return (0);
}

int	keyboard_events(int keycode, void *param)
{
	t_env *env;

	env = param;
	if (keycode == KEY_ESC)
		exit(0);
	printf("pressed the key %d\n", keycode);
	return (0);
}
