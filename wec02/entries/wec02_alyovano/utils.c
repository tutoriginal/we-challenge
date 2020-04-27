#include "color.h"

int     my_strerror(int fd, color *rgb, char *output)
{
    write (fd, output, ft_strlen(output));
    if (rgb)
        free(rgb);
    return (-1);
}

int     exit_pls(char *input, char *to_catch)
{
    int i;

    i = 0;
    while (input[i] && to_catch[i])
    {
        if (to_catch[i] != input[i])
            return (-1);
        i++;
    }
    if (to_catch[i] == 0 && input[i] == 0)
        return (1);
    return (-1);
}

void    valid_rgb(color *rgb)
{
    if (rgb->r > 255 || rgb->r < 0)
    {
        ft_printf("RGB : 'R' invalid value (%d), reset to 0.\n", rgb->r);
        rgb->r = 0;
    }
    if (rgb->g > 255 || rgb->g < 0)
    {
        ft_printf("RGB : 'G' invalid value (%d), reset to 0.\n", rgb->g);
        rgb->g = 0;
    }
    if (rgb->b > 255 || rgb->b < 0)
    {
        ft_printf("RGB : 'B' invalid value (%d), reset to 0.\n", rgb->b);
        rgb->b = 0;
    }
}
