#include <stdio.h>
#include <math.h>
#include <string.h>

void Evaluate(char []);
float Compute(float ,float,char);

struct stk
{
	float item[20];
	int top;
};

typedef struct stk STK;

void push(float c,STK *s)
{
	if(s->top == 19)
		{printf("Stack is Full..\n");return;
}
	else
		s->top++;
		s->item[s->top] = c;
}

float pop(STK *s)
{
		float c;
		if(s->top == -1)
			printf("Stack is Empty..");
		else
			c = s->item[s->top];
			
		s->top--;
		return c;
}

int isOperand(char c)
{
	switch(c)
	{
	case '+' : 
	case '-' :
	case '*' :
	case '/' :
	case '(' :
	case ')' :
	case '$' :
	case '^' : return 0;
	default : return 1;
	}
}

void Evaluate(char po[])
{
	STK s;
	char c;
	float op1,op2,res;
	int i = 0;
	s.top = -1;
	while((c = po[i++])!= '\0')
	{
		if(isOperand(c))
			push(c - '0' ,&s);
		else{
			op2 = pop(&s);
			op1 = pop(&s);
			res = Compute(op1,op2,c);
			push(res,&s);
		}
	}
	res = pop(&s);
	if(s.top!=-1)
		printf("Invalid Expression \n");
	else
		printf("Value of the Expression is : %f\n",res);
}

float Compute(float op1,float op2,char opr)
{
	switch(opr)
	{
		case '+' : return(op1+op2); 
		case '-' : return (op1-op2);
		case '*' : return (op1*op2);
		case '/' : return (op1/op2);
		case '$' : return pow(op1,op2);
		case '^' : return pow(op1,op2);
	default : printf("Invalid expression\n");
	}

}

void main()
{
	char pos[30];
	for(;;)
	{
		printf("Enter Expression and 0 to Stop Execution \n");
		scanf("%s",pos);
		if(strcmp(pos,"0") == 0) break;
		Evaluate(pos);
	
	}

}
