#include "morse.h"

char	binary_search(node **b_tree, char **input)
{
    char *str;
    node *tmp;
    
    tmp = *b_tree;
	str = *input;
	while (*str && !ft_compar(" /", *str))
	{
		if (*str == '.')
        {
            if (tmp->left)
                tmp = tmp->left;
            else
            {//handle seg fault
                *input = str;
                return (-1);
            }
        }
        else if (*str == '-')
        {
            if (tmp->right)
                tmp = tmp->right;
            else
            {//handle seg fault
                *input = str;
                return (-1);
            }
        }
        str++;
	}
	*input = str;
	return (tmp->data);
}

void	morse_decryptor(node *b_tree, char *input)
{
    char c;

	while (*input)
	{
		if (*input == '/')
		{
			input++;
			write(1, " ", 1);
		}
		else if (!(ft_compar(".-/ ", *input)))
		{//handle errors
			input++;
			write(1, "\ninvalid entrance character\n", 28);
		}
		else
		{
			c = binary_search(&b_tree, &input);
            if (ft_isalpha(c))
                ft_putchar(c);
            if (*input)
                input++;
		}
	}
}
