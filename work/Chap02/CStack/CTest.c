/*  CTest.c
    Interactive test program for C style stack module
*/

#include <stdio.h>
#include <string.h>
#include "CStack.h"

int main()
{
    int item;
    char cmd[80]; // command

    init();
    printf(": "); // prompt
    scanf("%s", cmd);
    while (strcmp(cmd, "quit") != 0)
    {
        if (strcmp(cmd, "push") == 0)
        {
            printf("push item: ");
            // read an integer item and push onto stack
            scanf("%d", &item);
            push(item);
        }
        else if (strcmp(cmd, "pop") == 0)
        {
            // pop an item from stack and print a line
            // displaying the popped item
            item = pop();
            printf("popped item = %d\n", item);
        }
        else if (strcmp(cmd, "print") == 0)
        {
            // print all the items on the stack
            print();
        }
        else
        {
            printf("legal commands are:\n");
            printf("\tpush\n");
            printf("\tpop\n");
            printf("\tprint\n");
            printf("\tquit\n");
        }
        printf(": ");
        scanf("%s", cmd);
    }
    return 0;
}