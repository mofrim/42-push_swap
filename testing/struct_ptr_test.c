#include <stdlib.h>
#include <limits.h>
#include <stdio.h>


/* Struct for the individual stacks A and B. */
typedef struct s_stack
{
	long	*st;
	int		size;
}	t_stack;

/* The mother struct. Keeping Stacks A and B and all auxiliary vars. */
typedef struct s_stacks
{
	t_stack	*a;
	t_stack	*b;
	int		*dsts_a;
	int		*dsts_b;
	int		*targets;
	int		initial_size;
}	t_stacks;

void	set_initial_values(t_stacks **sts, int size)
{
	(*sts)->a->size = size;
	(*sts)->b->size = 0;
	(*sts)->dsts_a = NULL;
	(*sts)->dsts_b = NULL;
	(*sts)->targets = NULL;
	(*sts)->initial_size = size;
}

t_stacks	*init_stacks_with_args(long **args, int size)
{
	t_stacks	*stacks;
	int			i;

	stacks = malloc(sizeof(t_stacks));
	if (!stacks)
		return (NULL);
	stacks->a = malloc(size * sizeof(t_stack));
	stacks->b = malloc(size * sizeof(t_stack));
	if (!stacks->a || !stacks->b)
		return (NULL);
	stacks->a->st = malloc(size * sizeof(long));
	stacks->b->st = malloc(size * sizeof(long));
	if (!stacks->a->st || !stacks->b->st)
		return (NULL);
	i = -1;
	while (++i < size)
	{
		stacks->a->st[i] = (*args)[i];
		stacks->b->st[i] = LONG_MAX;
	}
	set_initial_values(&stacks, size);
	return (stacks);
}

int main(void)
{
	t_stacks	*sts;

	sts = malloc(sizeof(t_stacks));
	printf("sts->a = %p\n", sts->a);
	printf("sts->b = %p\n", sts->b);
	printf("sts->dsts_a = %p\n", sts->dsts_a);
	printf("sts->dsts_b = %p\n", &sts->dsts_b);
	printf("NULL = %p\n", NULL);
	return (0);
}
