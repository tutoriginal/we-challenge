#ifndef MORSE_H
# define MORSE_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct t_morse
{
    char *trad;
    int i;
    int j;
}              s_morse;

int          reverse_morse(char *str, s_morse *morse);
unsigned int morse_len(char *str);

/*
* *  UTILS 
*/

int          syntax_my_str(s_morse *morse);
unsigned int av_strlen(char *str);
int          av_putstr(char *str);

#endif
