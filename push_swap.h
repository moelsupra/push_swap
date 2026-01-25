#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>

typedef struct s_node
{
	int 			value;
	int 			index;
	struct s_node	*next;
}	t_node;

char    **parse_input(int argc, char **argv);

#endif