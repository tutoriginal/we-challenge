#include "color.h"

int parse_color(char **av, color *rgb)
{
    rgb->r = ft_atoi(av[1]);
    rgb->g = ft_atoi(av[2]);
    rgb->b = ft_atoi(av[3]);
    valid_rgb(rgb);
    return (-1);
}

int prompt(color *rgb)
{
    char *input;

    input = NULL;
    while (1)
    {
        ft_printf("\033[38;0;255;255;255m%s", "_WEC02_ > ");
        if (get_next_line(0, &input) == -1)
            return (my_strerror(1, 0, "Malloc failed\n"));
        if (exit_pls(input, "!exit") == 1)
            break ;
        ft_printf("\033[38;2;%d;%d;%dm%s", rgb->r, rgb->g, rgb->b, input);
        if (*input != '\0')
            ft_printf("\n");
        free(input);
    }
    return (1);
}

int main(int ac, char **av)
{
    color *rgb;

    if (!(rgb = malloc(sizeof(color))))
        return (my_strerror(1, 0, "Malloc failed\n"));
    if (ac == 4)
    {
        parse_color(av, rgb);
        ft_printf("R%d G%d B%d\n", rgb->r, rgb->g, rgb->b);
        ft_printf("If you want to leave just type: $>!exit\n");
        if (prompt(rgb) == 1)
            ft_printf("Goodbye !\n");
        free(rgb);
    }
    else
        return (my_strerror(1, rgb, 
                    "Need 4 args .. ex : $> ./color 65 98 210\n"));
    return (0);
}
