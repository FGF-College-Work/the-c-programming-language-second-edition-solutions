#include <stdio.h>
#include <ctype.h>

#define BUFSIZE 100

int getch(void);
void ungetch(int c);

int buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0;     /* next free position in buf */
char token[100];

int main(void)
{
	int i = 0;
	char ch;
	char *p = token;

	puts("\nInput an integer followed by a char:\n");

	while ((ch = getch()) == ' ') {
		printf("in-ch: %d \n", ch);
	}

	printf("out-ch: %c \n", ch);

	for (*p++ = ch; isalnum(ch = getch()); ) /* SUPPOSING [5] */ {
		*p++ = ch;
		printf("in-ch: %c \n", ch);
    }

	printf("*p-ch: %d \n", ch);

	printf("\n\ni = %d, next char in buffer = %c\n", i, getch());
	return 0;
}

/* getch: get a (possibly pushed back) character */
int getch(void)
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

/* ungetch: push a character back onto the input */
void ungetch(int c)
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters \n");
	else
		buf[bufp++] = c;
}
