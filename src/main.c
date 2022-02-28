/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omazoz <omazoz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 19:01:11 by abiri             #+#    #+#             */
/*   Updated: 2022/02/28 22:18:46 by omazoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

const t_fract_set	g_fract_set[FRACTAL_COUNT] = {
{
	.name = "mandelbrot",
	.function = draw_mandelbrot
},
{
	.name = "julia",
	.function = draw_julia
},
{
	.name = "burning_ship",
	.function = draw_burningship
}};

void	init_calc(t_calc *calc)
{
	calc->min_i = -2;
	calc->max_i = 2;
	calc->min_r = -2;
	calc->max_r = 2;
	calc->area = (t_rect){0, WIDTH, 0, HEIGHT};
}

int	set_fractal(t_env *env, char *name)
{
	int	i;

	i = 0;
	while (i < FRACTAL_COUNT)
	{
		if (ft_strequ(g_fract_set[i].name, name))
		{
			env->calc.draw = g_fract_set[i].function;
			init_calc(&env->calc);
			return (1);
		}
		i++;
	}
	return (0);
}

int	loop_hook(void *param)
{
	t_env	*env;

	env = param;
	env->calc.draw(env, &env->calc);
	mlx_put_image_to_window(env->mlx, env->win, env->image.image, 0, 0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_env	env;

	if (argc != 2)
	{
		ft_putstr_fd("Usage : ./fract-ol <fractal_name>\n", 2);
		return (1);
	}
	if (!set_fractal(&env, argv[1]))
	{
		ft_putstr_fd("Please enter a valid fractal name\n", 2);
		return (1);
	}
	if (!init_mlx(&env))
		return (1);
	if (!init_mlx_events(&env))
		return (1);
	mlx_loop_hook(env.mlx, loop_hook, &env);
	mlx_loop(env.mlx);
	return (0);
}
