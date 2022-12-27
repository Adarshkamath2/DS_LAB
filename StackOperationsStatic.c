//Using Static Allocation

#include<stdio.h>
#include<stdlib.h>

#define SIZE 10

struct stack
{
	int items[SIZE];
	int TOP;
};

typedef struct stack STK;

void Disp(STK *);
void push(STK *);
void pop(STK *);
void peek(STK *);

void main()
{
	STK s;
	s.TOP = -1;
	for(;;)
	{
		int ch;
		printf("\n---------------------------------\nEnter Your Choice For Operation \n1.PUSH\n2.POP\n3.PEEK\n4.DISPLAY\n0.Exit-------------------------------------\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: push(&s);Disp(&s);break;
			case 2: pop(&s);Disp(&s);break;
			case 3: peek(&s);break;
			case 4: Disp(&s);break;
			case 0: exit(0);
			default : printf("Invalid Choice.....Please Try again...");break;
		}
	}
}

void Disp(STK *ps)
{
	if(ps->TOP == -1)
		{
			printf("Empty STACK..");return;

		}
		for(int i=ps->TOP;i>=0;i--)
			printf("%d\n",ps->items[i]);
			
}

void push(STK*ps)
{
	if(ps->TOP == SIZE-1)
	{
		printf("STACK is FULL.....\n");return;
	}
	int item;
	printf("Enter The Item To Be Pushed : ");
	scanf("%d",&item);
	ps->TOP++;
	ps->items[ps->TOP] = item;
}


void pop(STK *ps)
{
	if(ps->TOP == -1)
	{
	printf("EMPTY STACK...\n");
	return;
	}
	printf("Deleted is %d\n",ps->items[ps->TOP]);
	ps->TOP--;
}

void peek(STK *ps)
{
	if(ps->TOP == -1)
	{
		printf("EMPTY STACK...\n");
		return;
	}
	printf("The Topmost element of the Stack is : %d\n",ps->items[ps->TOP]);
}
