#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

struct Queue{
	int item[SIZE];
	int F,R;
};

typedef struct Queue QUE;

void Insert(QUE*);
void Delete(QUE*);
void Display(QUE);

void main()
{
	QUE Q;
	Q.F = 0;
	int choice;
	Q.R = -1;
	for(;;)
	{
		printf("Enter Your Choice \n1.Insert\n2.Delete\n3.Display\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: Insert(&Q),Display(Q);break;
			case 2 : Delete(&Q),Display(Q);break;
			case 3: Display(Q);break;
			default : exit(0); 
		}
	}
}

void Insert(QUE * PQ)
{
	int item;
	if(PQ->R == SIZE -1)
	{
		printf("Full\n");return;
	}
	printf("Enter The Item : ");
	scanf("%d",&item);
	
	PQ->R++;
	PQ->item[PQ->R] = item;
}

void Delete(QUE * PQ)
{
	if(PQ ->F > PQ->R)
	{
		printf("Empty \n");
		
	}
	printf("Deleted is %d\n",PQ->item[PQ->F]);
	PQ->F++;
	
	if(PQ->F > PQ->R)
	{
	PQ->F = 0;
	PQ->R = -1;
	
	}
}

void Display(QUE Q)
{
	if(Q.F > Q.R)
	{
		printf("Empty ");
		return;
		
	}
	while (Q.F <= Q.R)
		printf("%d\t",Q.item[Q.F++]);
		
		
		
}
