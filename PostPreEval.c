/*
PROGRAM-11
Develop a menu driven program to evaluate postfix and prefix expressions using stack.
*/

#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>


struct stk
{
  float item[20];
  int top;
};
typedef struct stk STK;

void push(float c,STK *s)
{
    if(s->top==19)
   	    printf("Stack full\n");
    else 
   	    s->item[++s->top]=c;
}

float pop(STK *s)
{
    float c;
    if(s->top==-1)
        printf("Stack empty\n");
    else
        return s->item[s->top--];
}

int isoperand(char c)
{
    switch(c)
    {
        case'+' :
        case'-' :
        case'*' :
        case'/' :
        case'(' : 
        case')' :
        case'$' :
        case'^' : return 0;
        default : return 1;
    }
}

float Compute(float op1,float op2,char opr)
{
    switch(opr)
    {
        case '+' : return(op1+op2);
        case '-' : return(op1-op2);
        case '*' : return(op1*op2);
        case '/' : return(op1/op2);
        case '^' : return pow(op1,op2);
        case '$' : return pow(op1,op2);
        default : printf("invalid expression");
    }
}

void PostEvaluate(char po[])
{
    STK s;
    s.top = -1;
    int i = 0;
    char c;
    float op1,op2,res;

    while((c = po[i++]) != '\0')
    {
        if(isoperand(c))
            push(c -'0',&s);
        else
        {
            op2 = pop(&s);
            op1 = pop(&s);
            res = Compute(op1,op2,c);
            push(res,&s); 
        }
    }
    res = pop(&s);
    if(s.top != -1)
        printf("Invalid Expression");
    else
        printf("Postfix Value : %.2f",res);          
}

void PreEvaluate(char pre[])
{
    STK s;
    s.top = -1;
    int i = 0;
    char c;
    float op1,op2,res;
    i = strlen(pre) - 1;
    while(i >= 0)
    {
        c = pre[i];
        if(isoperand(c))
            push(c-'0',&s);
        else
        {
            op1 = pop(&s);
            op2 = pop(&s);
            res = Compute(op1,op2,c);
            push(res,&s); 
        }
        i--;
    }
    res = pop(&s);
    if(s.top != -1)
        printf("Invalid Expression");
    else
        printf("Prefix Value : %.2f",res);          
}

void main()
{ 
    char fin[30];
    int ch;
    for(;;)
    { 
        printf("\n-----------------------------------------------------------------\n");
        printf("Enter the choice\n1.PostFix Exaluation\n2.Prefix Evaluation\n0.Exit\n");
        scanf("%d",&ch);

        switch(ch)
        {
            case 0: exit(0);
            case 1:	printf("Postfix Expression : ");
                    scanf("%s",fin);
                    PostEvaluate(fin);
                    break;
            case 2:	printf("Prefix Expression : ");
                    scanf("%s",fin);
                    PreEvaluate(fin);
                    break;
            default:printf("Enter the valid choice...\n\n");
                    break;
        }
    }
}
