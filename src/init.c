/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omazoz <omazoz@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 21:01:52 by omazoz            #+#    #+#             */
/*   Updated: 2022/02/14 19:04:47 by omazoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	init_mlx(t_env *env)
{
	env->mlx = mlx_init();
	if (!env->mlx)
		return (0);
	env->win = mlx_new_window(env->mlx, WIDTH, HEIGHT, TITLE);
	if (!env->win)
		return (0);
	env->image.image = mlx_new_image(env->mlx, WIDTH, HEIGHT);
	if (!env->image.image)
		return (0);
	env->image.pixels = (int *)mlx_get_data_addr(env->image.image,
		&env->image.bpp, &env->image.line_size,
		&env->image.endian);
	if (!env->image.pixels)
		return (0);
	return (1);
}

int	exit_event(void *param)
{
	(void)param;
	exit(0);
	return (0);
}

int	init_mlx_events(t_env *env)
{
	mlx_mouse_hook(env->win, mouse_events, env);
	mlx_key_hook(env->win, keyboard_events, env);
	mlx_hook(env->win, EVENT_CLOSE, 0, exit_event, NULL);
	return (1);
}
