#ifndef MORSE_H
#define MORSE_H

#include <unistd.h>
#include <stdlib.h>

typedef struct		tree
{
	char		data;
	struct tree	*left;
	struct tree	*right;
}			node;

void	morse_decryptor(node *b_tree, char *input);
int	ft_strlen(char *s);
void	ft_putchar(char c);
int	ft_isalpha(char c);
int	ft_compar(char *s, char c);
node	*new_node(char data);
node	*create_node();
void	let_it_free(node *b_tree);

#endif
