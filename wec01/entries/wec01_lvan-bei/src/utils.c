#include "../includes/morse.h"

int     init_morse(t_morse *m)
{
    m->letter_index[0] = ".-";
    m->letter_index[1] = "-...";
    m->letter_index[2] = "-.-.";
    m->letter_index[3] = "-..";
    m->letter_index[4] = ".";
    m->letter_index[5] = "..-.";
    m->letter_index[6] = "--.";
    m->letter_index[7] = "....";
    m->letter_index[8] = "..";
    m->letter_index[9] = ".---";
    m->letter_index[10] = "-.-";
    m->letter_index[11] = ".-..";
    m->letter_index[12] = "--";
    m->letter_index[13] = "-.";
    m->letter_index[14] = "---";
    m->letter_index[15] = ".--.";
    m->letter_index[16] = "--.-";
    m->letter_index[17] = ".-.";
    m->letter_index[18] = "...";
    m->letter_index[19] = "-";
    m->letter_index[20] = "..-";
    m->letter_index[21] = "...-";
    m->letter_index[22] = ".--";
    m->letter_index[23] = "-..-";
    m->letter_index[24] = "-.--";
    m->letter_index[25] = "--..";
    return(0);
}

int     error(char *str)
{
    write(1, str, strlen(str));
    return(0);
}
void    save_letter(int start, int end, char *str, t_morse *m)
{
    int j = -1;
    while (++j < end)
        m->letter[j] = str[start + j];
    m->letter[j] = '\0';
}

char    *strtrim(char *str)
{
    int len = 0;

    while (str[len] == ' ' )
        len++;
    str = str + len;
    len = strlen(str);
    while (str[--len]== ' ' && len > 0)
        str[len] = '\0';
    return(str);
}

int		ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	else
		return (0);
}
