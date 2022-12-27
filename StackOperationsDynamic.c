//Using Static Allocation

#include<stdio.h>
#include<stdlib.h>

int SIZE;

struct stack
{
	int *items;
	int TOP;
};

typedef struct stack STK;


void Disp(STK *);
void push(STK *);
void pop(STK *);
void peek(STK *);
//STK* Realloc(STK *);



void main()
{
	STK s;
	s.TOP = -1;
	printf("Enter the STACK SIZE : ");
	scanf("%d",&SIZE);
	s.items = (int*)malloc(SIZE * sizeof(int));
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
			printf("%d\n",*(ps->items+i));
			
}

void push(STK*ps)
{
	if(ps->TOP == SIZE-1)
	{
		printf("STACK is FULL.....\n");
		return;//ps = Realloc(ps);
	}
int item;
	printf("Enter The Item To Be Pushed : ");
	scanf("%d",&item);
	ps->TOP++;
	*(ps->items+ps->TOP) = item;
}


void pop(STK *ps)
{
	if(ps->TOP == -1)
	{
	printf("EMPTY STACK...\n");
	return;
	}
	printf("Deleted is %d\n",*(ps->items+ps->TOP));
	ps->TOP--;
}

void peek(STK *ps)
{
	if(ps->TOP == -1)
	{
		printf("EMPTY STACK...\n");
		return;
	}
	printf("The Topmost element of the Stack is : %d\n",*(ps->items+ps->TOP));
}

/*STK* Realloc(STK* ps)
{	
	printf("Reallocating....\n");
	ps = (STK *)realloc(ps,(SIZE*2)*sizeof(struct stack));
	printf("DONE...\n");
	SIZE = SIZE*2;
	return ps;
}
*/
