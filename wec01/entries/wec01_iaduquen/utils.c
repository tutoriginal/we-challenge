#include "morse.h"

int ft_strlen(char *s)
{
    int i = 0;
    if (*s)
        while (s[i])
            i++;
    return (i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int ft_isalpha(char c)
{
    return((c >= 'a' && c <= 'z') ? 1 : 0);
}

int ft_compar(char *s, char c)
{
    while (*s)
    {
        if (*s == c)
            return (1);
        s++;
    }
    return (0);
}
