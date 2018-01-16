#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool
is_numeric_palindrome(long long int number)
{
	long long int ldiv;
	long long int rdiv;

	ldiv = 1;
	while (number/ldiv >= 10)
		ldiv = ldiv * 10;
	rdiv = 1;
	while (ldiv > rdiv) {
		int l = (number / ldiv) % 10;
		int r = (number / rdiv) % 10;
		if (l != r)
			return false;
		ldiv = ldiv / 10;
		rdiv = rdiv * 10;
	}
	return true;
}

int main(int argc, char **argv)
{
	printf("%d\n", is_numeric_palindrome(atoll(argv[1])));
}
