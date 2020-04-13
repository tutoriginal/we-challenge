#include "../morse.h"

char		*av_strjoin_free(char *s1, char *morse_code)
{
	char	*tab;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s1 && s1[i] && s1[i] != 0)
		i++;
	while (morse_code && morse_code[j] && morse_code[j] != 0)
		j++;
	if (!(tab = malloc(i + j + 1)))
        return (0);
	i = 0;
	j = 0;
	while (s1 && s1[j] && s1[j] != '\n')
		tab[i++] = s1[j++];
	while (morse_code && *morse_code && *morse_code != 0)
		tab[i++] = *morse_code++;
	tab[i] = 0;
	free(s1);
	return (tab);
}

int reverse_morse(char *str, s_morse *morse)
{
    if (!(morse->trad = malloc(1)))
        return (-1);
    while (str[morse->j])
    {
        if (str[morse->j] == 'a' || str[morse->j] == 'A')
        {
            if (!(morse->trad = av_strjoin_free(morse->trad, ".- ")))
                return (-1);
        }
        else if (str[morse->j] == 'b' || str[morse->j] == 'B')
        {
            if (!(morse->trad = av_strjoin_free(morse->trad, "-... ")))
                return (-1);
        }
        else if (str[morse->j] == 'c' || str[morse->j] == 'C')
        {
            if (!(morse->trad = av_strjoin_free(morse->trad, "-.-. ")))
                return (-1);
        }
        else if (str[morse->j] == 'd' || str[morse->j] == 'D')
        {
            if (!(morse->trad = av_strjoin_free(morse->trad, "-.. ")))
                return (-1);
        }
        else if (str[morse->j] == 'e' || str[morse->j] == 'E')
        {
            if (!(morse->trad = av_strjoin_free(morse->trad, ". ")))
                return (-1);
        }
        else if (str[morse->j] == 'f' || str[morse->j] == 'F')
        {
            if (!(morse->trad = av_strjoin_free(morse->trad, "..-. ")))
                return (-1);
        }
        else if (str[morse->j] == 'g' || str[morse->j] == 'G')
        {
            if (!(morse->trad = av_strjoin_free(morse->trad, "--. ")))
                return (-1);
        }
        else if (str[morse->j] == 'h' || str[morse->j] == 'H')
        {
            if (!(morse->trad = av_strjoin_free(morse->trad, ".... ")))
                return (-1);
        }
        else if (str[morse->j] == 'i' || str[morse->j] == 'I')
        {
            if (!(morse->trad = av_strjoin_free(morse->trad, ".. ")))
                return (-1);
        }
        else if (str[morse->j] == 'j' || str[morse->j] == 'J')
        {
            if (!(morse->trad = av_strjoin_free(morse->trad, ".--- ")))
                return (-1);
        }
        else if (str[morse->j] == 'k' || str[morse->j] == 'K')
        {
            if (!(morse->trad = av_strjoin_free(morse->trad, "-.- ")))
                return (-1);
        }
        else if (str[morse->j] == 'l' || str[morse->j] == 'L')
        {
            if (!(morse->trad = av_strjoin_free(morse->trad, ".-..  ")))
                return (-1);
        }
        else if (str[morse->j] == 'm' || str[morse->j] == 'M')
        {
            if (!(morse->trad = av_strjoin_free(morse->trad, "-- ")))
                return (-1);
        }
        else if (str[morse->j] == 'n' || str[morse->j] == 'N')
        {
            if (!(morse->trad = av_strjoin_free(morse->trad, "-. ")))
                return (-1);
        }
        else if (str[morse->j] == 'o' || str[morse->j] == 'O')
        {
            if (!(morse->trad = av_strjoin_free(morse->trad, "--- ")))
                return (-1);
        }
        else if (str[morse->j] == 'p' || str[morse->j] == 'P')
        {
            if (!(morse->trad = av_strjoin_free(morse->trad, ".--. ")))
                return (-1);
        }
        else if (str[morse->j] == 'q' || str[morse->j] == 'Q')
        {
            if (!(morse->trad = av_strjoin_free(morse->trad, "--.- ")))
                return (-1);
        }
        else if (str[morse->j] == 'r' || str[morse->j] == 'R')
        {
            if (!(morse->trad = av_strjoin_free(morse->trad, ".-. ")))
                return (-1);
        }
        else if (str[morse->j] == 's' || str[morse->j] == 'S')
        {
            if (!(morse->trad = av_strjoin_free(morse->trad, "... ")))
                return (-1);
        }
        else if (str[morse->j] == 't' || str[morse->j] == 'T')
        {
            if (!(morse->trad = av_strjoin_free(morse->trad, "- ")))
                return (-1);
        }
        else if (str[morse->j] == 'u' || str[morse->j] == 'U')
        {
            if (!(morse->trad = av_strjoin_free(morse->trad, "..- ")))
                return (-1);
        }
        else if (str[morse->j] == 'v' || str[morse->j] == 'V')
        {
            if (!(morse->trad = av_strjoin_free(morse->trad, "...- ")))
                return (-1);
        }
        else if (str[morse->j] == 'w' || str[morse->j] == 'W')
        {
            if (!(morse->trad = av_strjoin_free(morse->trad, ".-- ")))
                return (-1);
        }
        else if (str[morse->j] == 'x' || str[morse->j] == 'X')
        {
            if (!(morse->trad = av_strjoin_free(morse->trad, "-..- ")))
                return (-1);
        }
        else if (str[morse->j] == 'y' || str[morse->j] == 'Y')
        {
            if (!(morse->trad = av_strjoin_free(morse->trad, "-.-- ")))
                return (-1);
        }
        else if (str[morse->j] == 'z' || str[morse->j] == 'Z')
        {
            if (!(morse->trad = av_strjoin_free(morse->trad, "--.. ")))
                return (-1);
        }
        else if (str[morse->j] == ' ')
        {
            if (!(morse->trad = av_strjoin_free(morse->trad, "/ ")))
                return (-1);
        }
        morse->j++;
    }
    if (!(morse->trad = av_strjoin_free(morse->trad, "\n")))
        return (-1);
    return (0);
}
