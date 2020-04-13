#include "morse.h"

void	let_it_free(node *b_tree)
{
/*
**Hope this work perfectly, couldn't check leaks cause valgrind not supported onto catalina...
*/
	if (b_tree)
	{
		let_it_free(b_tree->right);
		let_it_free(b_tree->left);
		free(b_tree);
	}
}

node	*new_node(char data)
{
	node *new;
	if (!(new = (node*)malloc(sizeof(node))))
		return (NULL);
	new->data = data;
	new->left = NULL;
	new->right = NULL;
	return (new);
}

node	*create_node()
{
/*creation of a binary tree model find on wiki
**(https://fr.wikipedia.org/wiki/Code_Morse_international#/media/Fichier:Morse_tree.svg)
**			/        \
**		      E		   T
**		    /   \       /     \
**		  I       A    N       M
**			     .
**			     .
**			     .
*/

    node *b_tree = new_node(' ');
//	left side
	if (!b_tree ||
    !(b_tree->left    			= new_node('e')) ||
	!(b_tree->left->left			= new_node('i')) ||
	!(b_tree->left->right			= new_node('a')) ||
	!(b_tree->left->left->left		= new_node('s')) ||
	!(b_tree->left->left->right		= new_node('u')) ||
	!(b_tree->left->right->left		= new_node('r')) ||
	!(b_tree->left->right->right		= new_node('w')) ||
	!(b_tree->left->left->left->left		= new_node('h')) ||
	!(b_tree->left->left->left->right		= new_node('v')) ||
	!(b_tree->left->left->right->left		= new_node('f')) ||
	!(b_tree->left->right->left->left		= new_node('l')) ||
	!(b_tree->left->right->right->left	= new_node('p')) ||
	!(b_tree->left->right->right->right	= new_node('j')))
		return (NULL);

//	right side
	if (!(b_tree->right			= new_node('t')) ||
	!(b_tree->right->left		    = new_node('n')) ||
	!(b_tree->right->right			= new_node('m')) ||
	!(b_tree->right->left->left		= new_node('d')) ||
	!(b_tree->right->left->right		= new_node('k')) ||
	!(b_tree->right->right->left		= new_node('g')) ||
	!(b_tree->right->right->right		= new_node('o')) ||
	!(b_tree->right->left->left->left		= new_node('b')) ||
	!(b_tree->right->left->left->right	= new_node('x')) ||
	!(b_tree->right->left->right->left	= new_node('c')) ||
	!(b_tree->right->left->right->right	= new_node('y')) ||
	!(b_tree->right->right->left->left	= new_node('z')) ||
	!(b_tree->right->right->left->right	= new_node('q')))
		return (NULL);
	return (b_tree);
}
