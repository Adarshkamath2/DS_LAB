/*
PROGRAM 3 and 5
Implement circular single linked list to perform the following operations 
i) Insert by order 
ii ) Delete by position 
iii) Search for an item by key
iv) Insert front 
v) Insert rear 
vi) Delete a node with the given key 
vii) Search for an item by position
Display the list contents after each operation
*/

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node *link;
};
typedef struct node *NODE;

NODE InsertFront(NODE);
NODE CreateNode();
void Display(NODE);
void InsertRear(NODE);
NODE SearchByValue(NODE);
void InsertByOrder(NODE);
void DeleteByKey(NODE);
void DeleteByPos(NODE);

void main()
{
    NODE Head,SN;
	Head = CreateNode();
	Head->info = 0;
	Head->link = Head;
	int ch;

	for(;;)
	{
		printf("\n---------------------\nEnter Your Choice for Operation : \n1.Insert Front\n2.Display\n3.Insert Rear\n4.Search by value\n5.Insert By order\n6.Delete  By Key\n7.Delete By Pos\n0.Exit\n------------------------------\n");
		scanf("%d",&ch);

		switch(ch)
		{
            case 0: exit (0);
                    break;
            case 1: InsertFront(Head);Display(Head);
                    break;
            case 2: Display(Head);
                    break;
            case 3: InsertRear(Head);Display(Head);
                    break;
            case 4: SN = SearchByValue(Head);
                    if(SN == NULL)
                    printf("NOT FOUND...\n");
                    else
                    printf("Node info is : %d",SN->info);
                    break;
            case 5: InsertByOrder(Head);Display(Head);
                    break;
            case 6: DeleteByKey(Head);Display(Head);
                    break;
            case 7: DeleteByPos(Head);Display(Head);
                    break;
            default :printf("Invalid Choice... Try again\n");
                    break;
		}
	}
}

NODE CreateNode()
{
    return (NODE)malloc(sizeof(struct node));
}

NODE InsertFront(NODE PH)
{
    NODE NN;
    NN = CreateNode();
    printf("Info : ");
    scanf("%d",&NN->info);
    NN->link = PH->link;
    PH->link = NN;
    PH->info++;
}

void InsertRear(NODE PH)
{
    NODE NN = CreateNode();
    printf("Info : ");
    scanf("%d",&NN->info);
    NODE TP = PH;
    while(TP->link != PH)
        TP = TP->link;
    TP->link = NN;
    NN->link = PH;
    PH->info++;
}

void Display(NODE PH)
{
    if(PH->info == 0)
    {
        printf("EMPTY LIST...");return;
    }
    NODE TP = PH->link;
    while(TP != PH)
    {
        printf("%d\t",TP->info);
        TP = TP->link;
    }
}

void InsertByOrder(NODE PH)
{
    NODE PN = PH;
    NODE TP = PH->link;
    NODE NN = CreateNode();
    printf("Info : ");
    scanf("%d",&NN->info);
    
    while(TP != PH && TP->info < NN->info)
    {
        PN = TP;
        TP = TP->link;
    }
    NN->link = TP;
    PN->link = NN;
    PH->info++;
}

void DeleteByPos(NODE pH)
{
	int pos;
	printf("Position Between 1 to %d",pH->info);
	int cnt = 1;
	NODE ND = pH;
	scanf("%d",&pos);
	while(cnt != pos)
	{
		ND = ND-> link;
		cnt++;
	}
	NODE k = ND ->link;
	ND->link = k->link;
	free(k);
	pH->info--;
}

void DeleteByKey(NODE pH)
{
	NODE TP = pH,ND;
	int key;
	printf("Key value : ");
	scanf("%d",&key);
	
    do{
		ND = TP;
		TP = TP->link;
		if(TP->info == key)
		break;
	}while(TP != pH);

	if(TP == pH)
	{
		printf("Element Not Found ..."); return;
	}
	else
  {
		ND->link = TP->link;
		pH->info--;
		free(TP);
	}
}

NODE SearchByValue(NODE pH)
{
	if(pH->info ==0)
	{
		printf("Empty List.."); return NULL;
	}
	int key;
	NODE TP = pH->link;
	printf("Enter The Element To be Searched : ");
	scanf("%d",&key);

	while(TP != pH)
	{
		if(TP ->info == key)
			return TP;
		TP = TP->link;
	}
	return NULL;
}
