//Program to evaluate postfix expression
//Please enter 'X' or 'x' instead of '*' for multiplication
//Please enter 'e' instead of '^' for exponent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include"stack.h"

int posteval(int,char **);

int main(int argc, char* argv[])
{
    int answer;
    stk_char.top = -1;
    stk_char.push_char=push_char;
    stk_char.pop_char=pop_char;
    stk_char.display_char=display_char;

    answer=posteval(argc,&argv[0]);
    printf("The value of the expression is %d",answer);
}
//Function to evaluvate
int posteval(int argc,char *argv[])
{
    int i, a, b;
    int val = 0;

    for(i=1; i<argc; i++)
    {
        if((strcmp(argv[i], "*") == 0) || (strcmp(argv[i], "X")==0) || (strcmp(argv[i], "x")==0))
        {
            a = pop_char(&stk_char);
            b = pop_char(&stk_char);
            val = a*b;
            push_char(val,&stk_char);
        }

        else if(strcmp(argv[i], "/") == 0)
        {
            a = pop_char(&stk_char);
            b = pop_char(&stk_char);
            val = b/a;
            push_char(val,&stk_char);
        }

        else if(strcmp(argv[i], "+") == 0)
        {
            a = pop_char(&stk_char);
            b = pop_char(&stk_char);
            val = a+b;
            push_char(val,&stk_char);
        }

        else if(strcmp(argv[i], "-") == 0)
        {
            a = pop_char(&stk_char);
            b = pop_char(&stk_char);
            val = b-a;
            push_char(val,&stk_char);
        }

        else if(strcmp(argv[i], "e") == 0 || strcmp(argv[i], "^")==0)
        {
            a = pop_char(&stk_char);
            b = pop_char(&stk_char);
            val = (int)pow(a,b);
            push_char(val,&stk_char);
        }

        else if(strcmp(argv[i], "%") == 0)
        {
            a = pop_char(&stk_char);
            b = pop_char(&stk_char);
            val = b%a;
            push_char(val,&stk_char);
        }

        else
        {
            push_char(atoi(argv[i]),&stk_char);
        }
    }
    return (pop_char(&stk_char));
}
