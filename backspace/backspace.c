#include <string.h>
#include <stdbool.h>
#include <stdio.h>

/*
 * treats # as backspace, replaces the # with space, each # encountered results
 * in the replacement of a # with ' '
 */
static void do_bkspc(char *s)
{
	char *ps = s + strlen(s) - 1;
	int bpc;

	bpc = 0;

	while (ps != s - 1) {
		if (*ps == '#') {
			*ps = ' ';
			bpc++;
		} else if (bpc) {
			*ps = ' ';
			bpc--;
		}
		ps--;
	}
}

/* compares 2 strings, spaces are ignored */
static bool are_equal(char *s, char *t)
{
	char *ps = s;
	char *pt = t;
	int ls = strlen(s);
	int lt = strlen(t);
	bool cmp = true;

	while (cmp && (ps < s + ls || pt < t + lt)) {
		int cont = 0;

		if (ps < s + ls && *ps == ' ') {
			ps++;
			cont = 1;
		}

		if (pt < t + lt && *pt == ' ') {
			pt++;
			cont = 1;
		}

		if (cont)
			continue;

		if (ps < s + ls && pt < t + lt)
			cmp = *ps == *pt;
		else
			cmp = false;

		pt++;
		ps++;
	}

	return cmp;
}

bool backspaceCompare(char *s, char *t)
{
	do_bkspc(s);
	do_bkspc(t);

	return are_equal(s, t);
}

int main(int argc, char **argv)
{
	printf("%d\n", backspaceCompare(argv[1], argv[2]));
}
