/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omazoz <omazoz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 21:00:49 by omazoz            #+#    #+#             */
/*   Updated: 2022/02/28 22:14:12 by omazoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** CHANGING colors + ART OF DARHAM
*/
const int	g_colors[3][9] = {
{2899536,
	1752220,
	2600544,
	10181046,
	15844367,
	15105570,
	15158332,
	9807270,
	8359053},
{15686491,
	12937576,
	10254197,
	7505539,
	4822160,
	2139038,
	5023629,
	7974012,
	10858603},
{873,
	7174573,
	461421,
	659055,
	922226,
	15397088,
	1248352,
	11031330,
	15843717}};

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

int	mouse_events(int button, int x, int y, void *param)
{
	t_env	*env;

	env = param;
	if (button == MOUSE_SCROLL_DOWN)
		zoom_into(&env->calc, 0.9, x, y);
	else if (button == MOUSE_SCROLL_UP)
		zoom_into(&env->calc, 1.1, x, y);
	return (0);
}

void	get_julia(int keycode, t_env *env)
{
	if (keycode == KEY_PAD_1)
	{
		env->ca = 0.3;
		env->cb = 0.5;
	}
	if (keycode == KEY_PAD_2)
	{
		env->ca = 0.285;
		env->cb = 0.01;
	}
	if (keycode == KEY_PAD_3)
	{
		env->ca = -0.8;
		env->cb = 0.156;
	}
	if (keycode == KEY_PAD_4)
	{
		env->ca = -0.4;
		env->cb = 0.6;
	}
	if (keycode == KEY_PAD_5)
	{
		env->cb = 0;
		env->ca = -1.476;
	}
}

int	keyboard_events(int keycode, void *param)
{
	t_env	*env;

	env = param;
	if (keycode == KEY_ESC)
		exit(0);
	if (keycode == KEY_C)
		env->color = (env->color + 1) % 3;
	get_julia(keycode, env);
	env->calc.draw(env, &env->calc);
	printf("pressed the key %d\n", keycode);
	return (0);
}
