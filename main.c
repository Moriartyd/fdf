#include "fdf.h"

int	close_pls(int key, void *param)
{
	if (key == K_ESC)
		exit(0);
	return (0);
}

int	main(int ac, char **av)
{
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "FDF");
	mlx_pixel_put(mlx_ptr, win_ptr, 250, 250, 0xFFFFFF);
	mlx_hook(win_ptr, 2, 0L, close_pls, (void *)0);
	mlx_loop(mlx_ptr);
	return (0);
}
