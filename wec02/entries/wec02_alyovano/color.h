#ifndef COLOR_H
# define COLOR_H
# include "./srcs/alyovano.h"

typedef struct  t_color
{
    int r;
    int g;
    int b;
}               color;  

int     my_strerror(int fd, color *rgb, char *output);
int     exit_pls(char *input, char *to_catch);
void    valid_rgb(color *rgb);


#endif
