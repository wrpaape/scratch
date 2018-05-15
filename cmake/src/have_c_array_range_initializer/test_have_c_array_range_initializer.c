static int values[15] = {
	[0 ... 3] = 1,
	[8 ... 9] = 2
};

int
main()
{
	int is_correct = 1;
	int i;

	for (i = 0; i <= 3; ++i)
		is_correct &= (values[i] == 1);
	for (i = 4; i <= 7; ++i)
		is_correct &= (values[i] == 0);
	for (i = 8; i <= 9; ++i)
		is_correct &= (values[i] == 2);
	for (i = 10; i < 15; ++i)
		is_correct &= (values[i] == 0);

	return !is_correct;
}
