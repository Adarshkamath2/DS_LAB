/*
PROGRAM 7
Develop a menu driven program to convert infix expression to postfix expression using stack (Test for nested parenthesized expressions)
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stack{
    char items[20];
    int Top;
};
typedef struct stack STK;

void Push(char c, STK *S)
{
    if(S->Top == 19)  printf("Stack Is Full..");
    S->items[++S->Top] = c;
}

char Pop(STK *S)
{
    if(S->Top==-1)  printf("Empty Stack");
    return S->items[S->Top--];
}

int isOperand(char c)
{
    switch(c)
    {
    case '+':
    case '-':
    case '*':
    case '/':
    case '^':
    case '$':
    case '(':
    case ')': return 0;
    default : return 1;
    }
}

int stkPre(char c)
{
    switch(c)
    {
    case '+':
    case '-': return 2;
    case '*':
    case '/': return 4;
    case '^':
    case '$': return 7;
    case '(': return 0;
    }
}

int inPre(char c)
{
    switch(c)
    {
    case '+':
    case '-': return 1;
    case '*':
    case '/': return 3;
    case '^':
    case '$': return 8;
    case '(': return 9;
    case ')': return 0;
    }
}

void inPost(char in[],char po[])
{
    int i,j;
    i=j=0;
    STK S;
    S.Top = -1;
    char c;

    while((c=in[i++])!= '\0')
    {
        if(isOperand(c))
            po[j++] = c;
        else
        {
            while(S.Top!= -1 && stkPre(S.items[S.Top])>inPre(c))
            {
                if(c == ')')
                {
                    while(S.items[S.Top]!='(')
                        po[j++] = Pop(&S);
                    Pop(&S);
                    break;
                }
                else
                    po[j++] = Pop(&S);
            }
            if(c != ')')
                Push(c,&S);
        }
    }
    while(S.Top!=-1)
        po[j++] = Pop(&S);
    po[j] = '\0';
}

void main()
{
    char in[30],po[30];
    for(;;)
    {
        printf("Enter Expression and 0 to STOP \n");
        scanf("%s",in);
        if(strcmp(in,"0")==0) break;
        printf("Tne Expression before Conversion is : %s\n",in);
        inPost(in,po);
        printf("Postfix Expression : %s",po);
    }
}
