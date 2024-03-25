/*  testci.c

    C program to test C interface to IntStack class.
*/
#include <stdio.h>
#include <string.h>
#include "cistack.h"

int main()
{
    char    cmd[80];    /* command */
    char    opr[80];    /* operand in string form */
    int     x;

    printf(": ");
    gets(cmd);
    while (strcmp(cmd, "quit") != 0)
    {
        if (strcmp(cmd, "push") == 0)
        {
            printf("integer to push: ");
            gets(opr);
            sscanf(opr, "%d", &x);
            PushStack(x);
        }
        else if (strcmp(cmd, "pop") == 0)
            printf("popped integer = %d\n", PopStack());
        else if (strcmp(cmd, "print") == 0)
            PrintStack();
        else
        {
            printf("Legal commands are:\n");
            printf("\tpush\n\tpop\n\tprint\n\tquit\n");
        }
        printf(": ");
        gets(cmd);
    }
	return 0;
}
