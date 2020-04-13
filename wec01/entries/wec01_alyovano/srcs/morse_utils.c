#include "../morse.h"

unsigned int av_strlen(char *str)
{
    unsigned int i;

    i = 0;
    while(str[i++])
        ;
    return (i);
}

int          av_putstr(char *str)
{
    return (write(1, str, av_strlen((str) + 1)));
}

int          syntax_my_str(s_morse *morse)
{
    int i;

    i = 0;
    while (morse->trad[i])
    {
        if (morse->trad[i] >= 97 && morse->trad[i] <= 122)
        {
            morse->trad[i] = morse->trad[i] - 32;
            break ;
        }
        i++;
    }
    return (0);
}

unsigned int morse_len(char *str)
{
    int i;
    int as;
    int toki;

    toki = 0;
    i = 0;
    as = 0;
    while (str[i])
    {
        if ((str[i] == '.' || str[i] == '-') && toki == 0)
        {
            toki = 1;
            as++;
        }
        else if ((str[i] == ' ' || str[i] == '/'))
        {
            toki = 0;
            as++;
        }
        i++;
    }
    return (as + 1);
}
