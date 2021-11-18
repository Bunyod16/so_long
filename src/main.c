#include "../so_long.h"

int main(int argc, char **argv)
{
    void    *mlx_ptr;
    void    *win_ptr;

    if (ft_parse_map(argc, argv) == 0)
        perror("Error");
        return (0);

    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, 500, 500, "42 so_long");
    mlx_loop(mlx_ptr);
}