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
void InsertFront(QUE *);
void DeleteRear(QUE *);

void main()
{
	QUE Q;
	Q.F = 0;
	int choice;
	Q.R = -1;
	for(;;)
	{
		printf("Enter Your Choice \n1.Insert\n2.Delete\n3.Display\n4.InsertFront\n5.DeleteRear");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: Insert(&Q),Display(Q);break;
			case 2 : Delete(&Q),Display(Q);break;
			case 3: Display(Q);break;
			case 4: InsertFront(&Q);Display(Q);break;
			case 5: DeleteRear(&Q);Display(Q);break;
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
		printf("Empty \n"); return;	
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
void InsertFront(QUE *PQ)
{	

int items;
	if(PQ->R == SIZE -1)
	{
		printf("Full\n");return;
	}
	printf("Enter The Item : ");
	scanf("%d",&items);
	if(PQ->F ==0 && PQ->R == -1)

		PQ->item[++PQ->R] = items;
	else
	if(PQ->F != 0)
		PQ->item[--PQ->F] = items;
	else
	printf("Front Insertion Not POssible ..");
	

}

void DeleteRear(QUE *PQ)
{
if(PQ ->F > PQ->R)
	{
		printf("Empty \n");return;
		
	}
printf("Deleted is %d",PQ->item[PQ->R]);
PQ->R--;
if(PQ->F>PQ->R)
{
PQ->F = 0;
PQ->R = -1;
}

}
