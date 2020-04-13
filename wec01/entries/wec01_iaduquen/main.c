#include "morse.h"

int main(int ac, char **av)
{
    (void)ac;
    node *b_tree;
    if (!av[1])
    {
        write(1, "please enter some morse code !\n", 31);
        write (1, "format supported: \".- /\".\n", 26);
    }
    else
    {
	if ((b_tree = create_node()))
        	morse_decryptor(b_tree, av[1]);
	let_it_free(b_tree);
    }
 return (0);
}
