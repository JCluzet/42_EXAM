
int	main(int argc, char **argv)
{
	if (argc > 1)
		ft_swapcases(argv[1]);
	write(1, "\n", 1);
	return (0);
}