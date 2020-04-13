#include "../includes/morse.h"

int         display(char *str, t_morse *m, int start, int end)
{
    int     i;
    char    tmp;

    i = -1;
    save_letter(start, end, str, m);
    while (++i < 26)
        if (strcmp(m->letter, m->letter_index[i]) == 0)
        {
            tmp = 97 + i;
            write(1, &tmp, 1);
            return (1);
        }
    return (0);
}

int         parser(char *str, t_morse *m)
{
    int     i, j;

    i = 0;
    j = 0;
    while (1)
    {
        if (str[i] == '/' && str[i+1] != '\0')
        {
            write(1, " ", 1);
            j+=2;
        }
        else if ((str[i] == ' ' && str[i - 1] != '/' ) || str[i] == '\0')
        {
            if (!display(str, m, j, i - j))
                return(0);
            j = i + 1;
        }
        if (str[i] == '\0')
            break;
        i++;
    }
    return (1);
}

int         parser_reverse(char *str, t_morse *m)
{
    int     i;

    i = -1;
    while (str[++i])
    {
        if (ft_isalpha(str[i]) == 0 && str[i] != ' ')
            return(0);
        if (str[i] == ' ')
            write(1, "/ ", 2);
        else
        {
            write(1, m->letter_index[str[i] - 97], strlen(m->letter_index[str[i] - 97]));
            if (str[i + 1] != '\0')
                write(1, " ", 1);
        }
    }
    return(1);
}

int         main(int argc, char **argv)
{
    t_morse m;

    if (argc > 3 || argc < 2)
        return(error("Wrong argument(s)\n"));
    init_morse(&m);
    if (argc == 3 && strcmp(argv[1], "-r") == 0)
    {
        argv[2] = strtrim(argv[2]);
        if (!parser_reverse(argv[2], &m))
            return(error("Not alphabetic char\n"));
    }
    else if (argc == 2)
    {
        argv[1] = strtrim(argv[1]);
        if (!parser(argv[1], &m))
            return(error("Wrong morse format\n"));
    }
    else
        return(error("not good flag use -r\n"));
    write(1, "\n", 1);
    return(0);
}
