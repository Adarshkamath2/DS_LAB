#include<stdio.h>
#include<stdlib.h>


struct CQueue{
	int *item;
	int F,R,cnt;
};

typedef struct CQueue CQUE;
int SIZE;
void Insert(CQUE*);
void Delete(CQUE*);
void Display(CQUE*);

void main()
{
	CQUE Q;
	Q.cnt = 0;
	Q.F = 0;
	int choice;
	Q.R = -1;
printf("Enter The SIZE : ");
scanf("%d",&SIZE);
Q.item = (int *)malloc(SIZE*sizeof(struct CQueue));

	for(;;)
	{
		printf("Enter Your Choice \n1.Insert\n2.Delete\n3.Display\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: Insert(&Q),Display(&Q);break;
			case 2 : Delete(&Q),Display(&Q);break;
			case 3: Display(&Q);break;
			default : exit(0); 
		}
	}
}

void Insert(CQUE * PQ)
{
	int item;
	if(PQ->cnt == SIZE)
	{
		printf("Full\n");return;
	}
	printf("Enter The Item : ");
	scanf("%d",&item);
	PQ->R = (PQ->R+1)%SIZE;
*(PQ->item+PQ->R) = item;
	PQ->cnt++;

}

void Delete(CQUE * PQ)
{
	int item;
	if(PQ->cnt ==0)
	{
		printf("Empty \n");return;
		
	}
	printf("Deleted is %d\n",*(PQ->item+PQ->F));
	PQ->F = (PQ->F+1)%SIZE;
	PQ ->cnt--;
	if(PQ->cnt ==0)
{
PQ->F = 0;
PQ->R = -1;
}
}

void Display(CQUE *PQ)
{int i ,j=PQ->F;


for(i=1;i<=PQ->cnt;i++)
{
	
		printf("%d\t",*(PQ->item+j));
j=(j+1)%SIZE;
}
}
		
