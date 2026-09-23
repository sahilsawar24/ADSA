#include <stdio.h>
#include <conio.h>
#include <string.h>

#define MAX 20

void main()
{
    char x[] = "vasai";
    char y[] = "sai";
    int c[MAX][MAX];
    int i, j;
    int m, n;

    clrscr();

    m = strlen(x);
    n = strlen(y);

    for (i = 0; i <= m; i++)
    {
	for (j = 0; j <= n; j++)
	{
	    if (i == 0 || j == 0)
		c[i][j] = 0;
	    else if (x[i - 1] == y[j - 1])
		c[i][j] = c[i - 1][j - 1] + 1;
	    else
	    {
		if (c[i - 1][j] > c[i][j - 1])
		    c[i][j] = c[i - 1][j];
		else
		    c[i][j] = c[i][j - 1];
	    }
	}
    }

    printf("String X = %s\n", x);
    printf("String Y = %s\n", y);
    printf("Length of LCS = %d\n", c[m][n]);

    getch();
}