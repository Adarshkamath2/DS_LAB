/*
PROGRAM - 12 and 13
12. Develop a menu driven program to implement the following types of Queues by allocating memory dynamically.
i) Circular Queue ii) Double ended Queue
13. Develop a menu driven program to implement the following types of Queues by allocating memory dynamically.
i) Circular Queue ii) Priority Queue
*/

#include<stdio.h>
#include<stdlib.h>

struct CQueue{
	int *items;
	int F,R,count;
};
typedef struct CQueue CQUE;

void Insert(CQUE*);
void Delete(CQUE*);
void Display(CQUE*);
int SIZE;

void main()
{
	CQUE Q;
	Q.count = 0;
	Q.F = 0;
	Q.R = -1;
	int choice;

    printf("SIZE : ");
    scanf("%d",&SIZE);
    Q.items = (int*)malloc(SIZE*sizeof(struct CQueue));
    
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
void Insert(CQUE *Q)
{
    if(Q->count == SIZE) {
        printf("QUEUE IS FULL..."); return;
    }
    int item;
    printf("Enter The Item : ");
    scanf("%d",&item);
    Q->R = (Q->R +1) % SIZE;
    *(Q->items+Q->R) = item;
    Q->count++;
}

void Delete(CQUE *Q)
{
    if(Q->count == 0) {
        printf("QUEUE IS EMPTY..."); return;
    }
    printf("Deleted : %d\n",*(Q->items+Q->F));
    Q->F = (Q->F+1)%SIZE;
    Q->count--;
    if(Q->count==0)
    {
        Q->F=0;
        Q->R=-1;
    }
}

void Display(CQUE *Q)
{
    if(Q->count == 0) {
        printf("QUEUE IS EMPTY..."); return;
    }
    int i ,j = Q->F;
    for(i =1;i<=Q->count;i++)
    {
        printf("%d\t",*(Q->items+j));
        j = (j+1)%SIZE;
    }
}
