/*
PROGRAM 4,6,8
Implement circular double linked list to perform the following operations 
i) Insert by order 
ii ) Delete by key 
iii) Search by position
iv) Insert front 
v) Insert rear
vi) Delete kth node 
vii) Search for an item by value. 
viii) Insert by order 
ix) Delete rear 
x) Delete Front 
Display the list contents after each operation
*/

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *LL;
	struct node *RL;
};
typedef struct node *NODE;

NODE CreateNode();
void Display(NODE);
void InsertFront(NODE);
void InsertRear(NODE);
void DeleteFront(NODE);
void DeleteRear(NODE);
void InsertByPos(NODE);
void InsertByOrder(NODE);
NODE SearchByValue(NODE);
void DeleteByKey(NODE);
void DeleteByPos(NODE);


void main()
{
	NODE Head,cop,SN;
	Head = CreateNode();
	Head->info = 0;
	Head->LL = Head->RL = Head;

	int ch;
	for(;;)
	{
		printf("\n---------------------\nEnter Your Choice for Operation : \n1.Insert Front\n2.Display\n3.Insert Rear\n4.Delete Front\n5.Delete Rear\n6.Search by value\n7.Insert By Position\n8.Insert By order\n9.Delete  By Key\n10.Delete By Pos\n0.Exit\n------------------------------\n");
		scanf("%d",&ch);

		switch(ch)
		{
		case 0 : exit (0);break;
		case 1 : InsertFront(Head);Display(Head);break;
		case 2 : Display(Head);break;
		case 3 : InsertRear(Head);Display(Head);break;
		case 4 : DeleteFront(Head);Display(Head);break;
		case 5 : DeleteRear(Head);Display(Head);break;
		case 6 : SN = SearchByValue(Head);
				 if(SN == NULL)
				 	printf("NOT FOUND...\n");
				 else
				 	printf("Node info is : %d",SN->info);
				 break;
		case 7 : InsertByPos(Head);Display(Head);break;
		case 8 : InsertByOrder(Head);Display(Head);break;
		case 9 : DeleteByKey(Head);Display(Head);break;
		case 10: DeleteByPos(Head);Display(Head);break;
		default: printf("Invalid Choice... Try again\n");break;
		}
	}
}

NODE CreateNode()
{
    return (NODE)malloc(sizeof(struct node));
}

void Display(NODE PH)
{
    if(PH->info==0)
    {
        printf("Empty List..."); return;        
    }
    NODE TP = PH->RL;
    while(TP != PH)
    {
        printf("%d\t",TP->info);
        TP = TP->RL;
    }
}

void InsertFront(NODE PH)
{
    NODE NN = CreateNode();
    printf("Info : ");
    scanf("%d",&NN->info);
    NN->RL = PH->RL;
    NN->LL = PH;
    PH->RL = NN;
    NN->RL->LL = NN;
    PH->info++;
}

void InsertRear(NODE PH)
{
    NODE NN = CreateNode();
    printf("Info : ");
    scanf("%d",&NN->info);

    NN->LL = PH->LL;
    NN->RL = PH;
    PH->LL->RL = NN;
    PH->LL = NN;
    PH->info++;
}

void DeleteFront(NODE PH)
{
    if(PH->info == 0)
	{
		printf("Empty \n"); return;
	}
    NODE ND = PH->RL;
    printf("Deleted : %d\n",ND->info);

    PH->RL = ND->RL;
    ND->RL->LL = PH;

    free(ND);
    PH->info--;
}

void DeleteRear(NODE PH)
{
    if(PH->info == 0)
	{
		printf("Empty \n"); return;
	}
    NODE ND = PH->LL;
    printf("Deleted : %d\n",ND->info);

    PH->LL = ND->LL;
    ND->LL->RL = PH;

    free(ND);
    PH->info--;
}

void InsertByPos(NODE PH)
{
    int pos,count = 1;
    NODE NN = CreateNode();
    l1 : printf("Position : ");
    scanf("%d",&pos);
    if(pos < 1 || pos >= PH->info+1) { printf("Enter valid Position.."); goto l1; }    
    printf("Info : ");
    scanf("%d",&NN->info);

    NODE TP = PH->RL;
    while(TP!= PH && count != pos)
    {
        TP = TP->RL;
        count++;
    }
    NN->RL = TP->RL;
    NN->LL = TP;
    TP->RL = NN;
    NN->RL->LL = NN; 
    PH->info++;
}

void DeleteByPos(NODE PH)
{
    if(PH->info == 0)
	{
		printf("Empty \n"); return;
	}
    int pos,count = 1;
    NODE NN = CreateNode();
    printf("Position : ");
    scanf("%d",&pos);    

    NODE TP = PH->RL;
    while(TP!= PH && count != pos)
    {
        TP = TP->RL;
        count++;
    }
    TP->LL->RL = TP->RL;
    TP->RL->LL = TP->LL;
    printf("Deleted : %d\n",TP->info);
    free(TP); 
    PH->info--;
}

void InsertByOrder(NODE PH)
{
    NODE NN = CreateNode();
    printf("Info : ");
    scanf("%d",&NN->info);

    NODE TP = PH->RL;
    while(TP!= PH && TP->info < NN->info)
        TP = TP->RL;
    NN->LL = TP->LL;
    NN->RL = TP;
    TP->LL = NN;
    NN->LL->RL = NN;
    PH->info++;
}

NODE SearchByValue(NODE PH)
{
	if(PH->info == 0)
	{
		printf("Empty \n");return NULL;
	}
	int key;
	printf("Key Value : ");
	scanf("%d",&key);
	NODE TP = PH->RL;

	while(TP!=PH && TP->info!=key)
		TP = TP->RL;
	if(TP == PH) return NULL;
	return TP;
}

void DeleteByKey(NODE PH)
{
	if(PH->info == 0)
	{
		printf("Empty \n"); return;
	}
	int key;
	printf("Enter the Key Value : ");
	scanf("%d",&key);

	NODE TP = PH->RL;
	while(TP!=PH && TP->info!=key)
		TP = TP->RL;
	
    if(TP == PH)
	{
		printf("Not Found..\n"); return;
	}
	TP->LL->RL = TP ->RL;
	TP->RL->LL = TP->LL;
	printf("Deleted : %d\n",PH->info);
	free(TP);
	PH->info--;
}
