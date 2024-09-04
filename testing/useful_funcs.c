int	is_in(long *arr, int val, int size)
{
	int	i;

	i = -1;
	while (++i < size)
		if (arr[i] == val)
			return (1);
	return (0);
}

/* Fills stacks->a with a random array. */
void	fill_stack_rand(t_stacks **sts, unsigned int seed)
{
	int		size;
	int		i;
	int		val;
	long	**a;

	size = (*sts)->initial_size;
	a = &((*sts)->a->st);
	srand(seed);
	val = (double)rand() / (double)RAND_MAX * size * 2;
	i = size;
	while (--i >= 0)
	{
		while (is_in(*a, val, size))
			val = (double)rand() / (double)RAND_MAX * size * 2;
		(*a)[i] = val;
	}
}
