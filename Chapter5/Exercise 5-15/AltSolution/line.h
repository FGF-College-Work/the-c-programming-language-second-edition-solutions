int getLine(char *s, int maxline);
int readlines(char *lineptr[], int maxlines, int dir);
void writelines(char *lineptr[], int nlines);

#define MAXLINES 500 /* max #lines to be sorted */
#define MAXLEN 100 /* max length of any input line */