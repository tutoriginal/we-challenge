#include "../morse.h"

int catch_point(char *str, s_morse *morse)
{
    if (str[morse->i + 1] == ' ' || str[morse->i + 1] == '/' || str[morse->i + 1] == 0)
    {
        morse->trad[morse->j] = 'e';
        morse->j++;
        return (0);
    }
    morse->i++;
    if (str[morse->i] == '.')
    {
        if (str[morse->i + 1] == ' ' || str[morse->i + 1] == '/' || str[morse->i + 1] == 0)
        {
            morse->trad[morse->j] = 'i';
            morse->j++;
            return (0);
        }
        morse->i++;
        if (str[morse->i] == '.')
        {
            if (str[morse->i + 1] == ' ' || str[morse->i + 1] == '/' || str[morse->i + 1] == 0)
            {
                morse->trad[morse->j] = 's';
                morse->j++;
                return (0);
            }
            morse->i++;
            if (str[morse->i] == '.')
            {

                if (str[morse->i + 1] && str[morse->i + 1] == '.')
                {
                    morse->trad[morse->j] = 10;
                    morse->j++;
                    morse->i++;
                    return (0);
                }
                morse->trad[morse->j] = 'h';
                morse->j++;
                return (0);
            }
            else if (str[morse->i] == '-')
            {
                morse->trad[morse->j] = 'v';
                morse->j++;
                return (0);
            }
        }
        else if (str[morse->i] == '-')
        {
            if (str[morse->i + 1] == ' ' || str[morse->i + 1] == '/' || str[morse->i + 1] == 0)
            {
                morse->trad[morse->j] = 'u';
                morse->j++;
                return (0);
            }
            morse->i++;
            if (str[morse->i] == '.')
            {
                morse->trad[morse->j] = 'f';
                morse->j++;
                return (0);
            }
        }
    }
    else if (str[morse->i] == '-')
    {
        if (str[morse->i + 1] == ' ' || str[morse->i + 1] == '/' || str[morse->i + 1] == 0)
        {
            morse->trad[morse->j] = 'a';
            morse->j++;
            return (0);
        }
        morse->i++;
        if (str[morse->i] == '-')
        {
            if (str[morse->i + 1] == ' ' || str[morse->i + 1] == '/' || str[morse->i + 1] == 0)
            {
                morse->trad[morse->j] = 'w';
                morse->j++;
                return (0);
            }
            morse->i++;
            if (str[morse->i] == '-')
            {
                morse->trad[morse->j] = 'j';
                morse->j++;
                return (0);
            }
            else if (str[morse->i] == '.')
            {
                morse->trad[morse->j] = 'p';
                morse->j++;
                return (0);
            }
        }
        else if (str[morse->i] == '.')
        {
            if (str[morse->i + 1] == ' ' || str[morse->i + 1] == '/' || str[morse->i + 1] == 0)
            {
                morse->trad[morse->j] = 'r';
                morse->j++;
                return (0);
            }
            morse->i++;
            if (str[morse->i] == '.')
            {
                morse->trad[morse->j] = 'l';
                morse->j++;
                return (0);
            }
            else if (str[morse->i] == '-')
            {
                morse->trad[morse->j] = '.';
                morse->j++;
                return (0);
            }
        }
    }
    return (0);
}

int catch_sp(char *str, s_morse *morse)
{
    if (str[morse->i + 1] == ' ' || str[morse->i + 1] == '/' || str[morse->i + 1] == 0)
    {
        morse->trad[morse->j] = 't';
        morse->j++;
        return (0);
    }
    morse->i++;
    if (str[morse->i] == '.')
    {
        if (str[morse->i + 1] == ' ' || str[morse->i + 1] == '/' || str[morse->i + 1] == 0)
        {
            morse->trad[morse->j] = 'n';
            morse->j++;
            return (0);
        }
        morse->i++;
        if (str[morse->i] == '.')
        {
            if (str[morse->i + 1] == ' ' || str[morse->i + 1] == '/' || str[morse->i + 1] == 0)
            {
                morse->trad[morse->j] = 'd';
                morse->j++;
                return (0);
            }
            morse->i++;
            if (str[morse->i] == '.')
            {
                morse->trad[morse->j] = 'b';
                morse->j++;
                return (0);
            }
            else if (str[morse->i] == '-')
            {
                morse->trad[morse->j] = 'x';
                morse->j++;
                return (0);
            }
        }
        else if (str[morse->i] == '-')
        {
            if (str[morse->i + 1] == ' ' || str[morse->i + 1] == '/' || str[morse->i + 1] == 0)
            {
                morse->trad[morse->j] = 'k';
                morse->j++;
                return (0);
            }
            morse->i++;
            if (str[morse->i] == '.')
            {
                morse->trad[morse->j] = 'c';
                morse->j++;
                return (0);
            }
            else if (str[morse->i] == '-')
            {
                morse->trad[morse->j] = 'y';
                morse->j++;
                return (0);
            }
        }
    }
    else if (str[morse->i] == '-')
    {
        if (str[morse->i + 1] == ' ' || str[morse->i + 1] == '/' || str[morse->i + 1] == 0)
        {
            morse->trad[morse->j] = 'm';
            morse->j++;
            return (0);
        }
        morse->i++;
        if (str[morse->i] == '-')
        {
            if (str[morse->i + 1] == ' ' || str[morse->i + 1] == '/' || str[morse->i + 1] == 0)
            {
                morse->trad[morse->j] = 'o';
                morse->j++;
                return (0);
            }
            morse->i++;
            if (str[morse->i] == '-')
            {
                 morse->trad[morse->j] = '-';
                 morse->j++;
                 return (0);
            }
            else if (str[morse->i] == '.')
            {
                morse->trad[morse->j] = '?';
                morse->j++;
                return (0);
            }
        }
        else if (str[morse->i] == '.')
        {
            if (str[morse->i + 1] == ' ' || str[morse->i + 1] == '/' || str[morse->i + 1] == 0)
            {
                morse->trad[morse->j] = 'g';
                morse->j++;
                return (0);
            }
            morse->i++;
            if (str[morse->i] == '.')
            {
                morse->trad[morse->j] = 'z';
                morse->j++;
                return (0);
            }
            else if (str[morse->i] == '-')
            {
                morse->trad[morse->j] = 'q';
                morse->j++;
                return (0);
            }
        }
    }
    return (0);
}

int morse_interpreter(char *str, s_morse *morse)
{
    while (str[morse->i])
    {
        if (str[morse->i] == '.')
            catch_point(str, morse);
        else if (str[morse->i] == '-')
            catch_sp(str, morse);
        else if (str[morse->i] == '/')
        {
            morse->trad[morse->j] = ' ';
            morse->j++;
        }
        morse->i++;
    }
    morse->trad[morse->j] = 0;
    return (morse->i);
}

int main(int ac, char **av)
{
    s_morse *morse;

    if (!(morse = malloc(sizeof(s_morse))))
    {
        av_putstr("Morse interpreter : Sys call:Error. (Malloc)");
        return (-1);
    }
    morse->i = 0;
    morse->j = 0;
    if (ac == 2)
    {
        if (!(morse->trad = malloc(sizeof(char) * morse_len(av[1]))))
        {
            free(morse);
            av_putstr("Morse interpreter : Sys call:Error. (Malloc)\n");
            return (-1);
        }
        morse_interpreter(av[1], morse);
        syntax_my_str(morse);
        av_putstr(morse->trad);
        free(morse->trad);
    }
    else if (ac == 3 && av[1][0] == '-' && av[1][1] == 'r' && !av[1][2])
    {
        if (reverse_morse(av[2], morse) == -1)
        {
            free(morse);
            av_putstr("Morse interpreter : Sys call:Error. (Malloc)\n");
            return (-1);
        }
        av_putstr(morse->trad);
        free(morse->trad);
    }
    else if (ac != 2 && ac != 3)
    {
        av_putstr("Arg number : Error.\n");
        av_putstr("Use <cat README> for more informations.\n");
        free(morse);
        return (-1);
    }
    else
    {
        av_putstr("Bad conditioning\n -> <cat README>\n");
        free(morse);
        return (-1);
    }
    free(morse);
    return (0);
}
