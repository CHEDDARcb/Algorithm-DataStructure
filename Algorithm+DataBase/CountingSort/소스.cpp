#include <iostream>
#include <unordered_map>

int fatorial(int n)
{
	if (n <= 1)
		return 1;
	return n * fatorial(n - 1);
}

int factorial_tail(int base, int exp, int acc = 1)
{
	if (exp == 0)
		return acc;

	return factorial_tail(base, exp - 1, acc * base);
}

int main()
{
	int a =	factorial_tail(2, 10);

	return 0;
}