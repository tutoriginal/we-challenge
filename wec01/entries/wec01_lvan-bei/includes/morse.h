#ifndef MORSE_H
# define MORSE_H

# include <string.h>
# include <unistd.h>

typedef struct s_morse
{
    char *letter_index[26];
    char letter[4];
}               t_morse;

int             init_morse(t_morse *m);
void            save_letter(int start, int end, char *str, t_morse *m);
int             error(char *str);
char            *strtrim(char *str);
int             ft_isalpha(int c);

#endif