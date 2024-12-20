#include <stdio.h>

int match(char *s1, char *s2)
{
	if ((*s1 == '*' && !*(s1 + 1)) || (!*s1 && !*s2))
		return (1);
	else if (*s1 == '/' && *s2 != '/')
		return (0);
	else if (!*s2)
		return (0);
	else if (*s1 == '*' && (match(s1, s2 + 1) || match(s1 + 1, s2)))
		return (1);
	else if (*s1 == *s2)
		return (match(s1 + 1, s2 + 1));
	return (0);
}

int main(int argc, char **argv)
{
	if (argc < 3)
		return (1);

	printf("%d\n", match(argv[1], argv[2]));
	return (0);
}

