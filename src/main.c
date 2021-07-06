/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerrer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 16:51:01 by aguerrer          #+#    #+#             */
/*   Updated: 2021/07/06 19:45:30 by aguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	fdf_usage(char *argv0)
{
	ft_putstr("Usage:\n\t");
	ft_putstr(ft_program_name(argv0));
	ft_putstr(" fdf_files\n");
	ft_putstr("Controls:\n");
	ft_putstr("\t[ESC]			-> Exit the program.\n");
	ft_putstr("\t[R]			-> Reset the map.\n");
	ft_putstr("\t[M]			-> Colorize image fdf.\n");
	ft_putstr("\t[B][N]			-> Zoom in and zoom out.\n");
	ft_putstr("\t[J][K]			-> Spiky time.\n");
	ft_putstr("\t[Space]			-> Change the camera (isocetric <-> plain).\n");
	ft_putstr("\t[W][A][S][D]		-> Move the map.\n");
}

static void	random_color(t_fdf *fdf, int n)
{
	if (n == 1)
	{
		fdf->color.red = (rand() % 0x7F);
		fdf->color.green = (rand() % 0x7F);
		fdf->color.blue = (rand() % 0x7F);
	}
	else
	{
		if (fdf->map.isometric++ % 2)
			fdf->map.angle_z *= 0.2;
		else
			fdf->map.angle_z *= 5;
	}
}

static void	reset_map(t_fdf *fdf)
{
	fdf->map.coordinate_z = 0;
	fdf->map.coordinate_y = 0;
	fdf->map.x_value = 1.00;
	fdf->map.angle_y = cos(M_PI / 3);
	fdf->map.angle_z = fdf->map.angle_y * sin(M_PI / 6);
	if (ceil(fdf->map.width > fdf->map.height))
		fdf->map.zoom = (WIN_WIDTH / fdf->map.width) + MAGIC_ZOOM;
	else
		fdf->map.zoom = (WIN_HEIGHT / fdf->map.height) + MAGIC_ZOOM;
	fdf->map.isometric = 1;
	fdf->color.red = 0x4F;
	fdf->color.green = 0x4F;
	fdf->color.blue = 0x4F;
}

static int	fdf_keys(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_ESCAPE)
		exit(0);
	else if (keycode == KEY_ANSI_R)
		reset_map(fdf);
	else if (keycode == KEY_ANSI_M)
		random_color(fdf, 1);
	else if (keycode == KEY_ANSI_B)
		fdf->map.zoom += 1;
	else if ((keycode == KEY_ANSI_N) && (fdf->map.zoom > MAX_ZOOM))
		fdf->map.zoom -= 1;
	else if ((keycode == KEY_ANSI_J) && (fdf->map.x_value < MAX_X))
		fdf->map.x_value += 0.25;
	else if ((keycode == KEY_ANSI_K) && (fdf->map.x_value > -MAX_X))
		fdf->map.x_value -= 0.25;
	else if (keycode == KEY_SPACE)
		random_color(fdf, 2);
	else if (keycode == KEY_ANSI_W || keycode == KEY_UPARROW)
		fdf->map.coordinate_z += 5;
	else if (keycode == KEY_ANSI_S || keycode == KEY_DOWNARROW)
		fdf->map.coordinate_z -= 5;
	else if (keycode == KEY_ANSI_D || keycode == KEY_RIGHTARROW)
		fdf->map.coordinate_y -= 5;
	else if (keycode == KEY_ANSI_A || keycode == KEY_LEFTARROW)
		fdf->map.coordinate_y += 5;
	return (0);
}

int	main(int argc, char *argv[])
{
	t_fdf	*fdf;

	if (argc == 2)
	{
		fdf = (t_fdf *)malloc(sizeof(t_fdf));
		if (fdf == NULL)
			ft_puterror("Memory Allocation failed", 3);
		fdf_read(argv[1], fdf);
		reset_map(fdf);
		fdf->mlx.init = mlx_init();
		fdf->mlx.win = mlx_new_window(fdf->mlx.init, WIN_WIDTH, WIN_HEIGHT, \
				TITLE(ft_remove_extension(argv[1])));
		mlx_hook(fdf->mlx.win, 2, 3, fdf_keys, fdf);
		mlx_loop_hook(fdf->mlx.init, fdf_draw, fdf);
		mlx_loop(fdf->mlx.init);
	}
	else
		fdf_usage(argv[0]);
	return (0);
}
