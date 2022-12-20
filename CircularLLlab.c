//Circular Double Linked list with Header program

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *LL;
	struct node *RL;
};

typedef struct node *NODE;

void InsertFront(NODE);
NODE CreateNode();
void Display(NODE);
void InsertRear(NODE);
void DeleteFront(NODE);
void DeleteRear(NODE);
NODE SearchByValue(NODE);
void InsertByPos(NODE);
void InsertByOrder(NODE);
void DeleteByKey(NODE);
void DeleteByPos(NODE);
NODE Reverse(NODE);
NODE Copy(NODE);


void main()
{
	NODE Head,cop,SN;
	Head = CreateNode();
	Head->info = 0;
	Head->LL = Head->RL = Head;

	int ch;
	for(;;)
	{
		printf("\n---------------------\nEnter Your Choice for Operation : \n1.Insert Front\n2.Display\n3.Insert Rear\n4.Delete Front\n5.Delete Rear\n6.Search by value\n7.Insert By Position\n8.Insert By order\n9.Delete  By Key\n10.Delete By Pos\n11.Copy\n12.Reverse\n0.Exit\n------------------------------\n");
		scanf("%d",&ch);

		switch(ch)
		{
		case 0: exit (0);
			break;
		case 1:InsertFront(Head);Display(Head);
			break;
		case 2: Display(Head);
			break;
		case 3:InsertRear(Head);Display(Head);
			break;
		case 4:DeleteFront(Head);Display(Head);
			break;
		case 5:DeleteRear(Head);Display(Head);
			break;
		case 6: SN = SearchByValue(Head);
			if(SN == NULL)
			printf("NOT FOUND...\n");
			else
			printf("Node info is : %d",SN->info);
			break;
		case 7:InsertByPos(Head);Display(Head);
			break;
		case 8:InsertByOrder(Head);Display(Head);
			break;
		case 9:DeleteByKey(Head);Display(Head);
			break;
		case 10:DeleteByPos(Head);Display(Head);
			break;
		case 11:cop = Copy(Head);Display(cop);
			break;
		case 12:Head =  Reverse(Head);Display(Head);
			break;

		default : printf("Invalid Choice... Try again\n");
			break;


		}

	}

}

void InsertFront(NODE pH)
{
	NODE NN;
	NN = CreateNode();
	printf("Enter the Node Info : ");
	scanf("%d",&NN->info);

	NN->LL = pH;
	NN->RL = pH->RL;
	pH->RL = NN;
	NN->RL->LL = NN;

	pH->info++;

}

NODE CreateNode()
{
	NODE NN;
	NN = (NODE)malloc(sizeof(struct node));
	return NN;
}
void Display(NODE PH)
{
	if(PH->info == 0)
	{
		printf("The List is Empty...please try Inserting an Element..\n");
		return;
	}

	NODE TP = PH->RL;
	while(TP!=PH)
	{
	printf("%d\t",TP->info);
	TP = TP->RL;
	}
}

void InsertRear(NODE PH)
{
	NODE NN = CreateNode();
	printf("Enter the data of the Node : ");
	scanf("%d",&NN->info);
	NN->LL = PH->LL;
	NN->RL = PH;
	PH->LL = NN;
	NN->LL->RL = NN;
	PH->info++;
}

void DeleteFront(NODE PH)
{
	if(PH->info == 0)
	{
		printf("Empty List .. \n");
		return;
	}
	NODE FN;
	FN = PH->RL;
	PH->RL = FN-> RL;
	FN->RL->LL = PH;
	printf("Deleted is %d..\n",FN->info);
	free(FN);
	PH->info--;
}


void DeleteRear(NODE PH)
{
	if(PH->info == 0)
	{
		printf("Empty List....\n");
		return;
	}
	NODE LN;
	LN = PH->LL;
	PH->LL = LN->LL;
	LN->LL->RL = PH;
	printf("Deleted is %d\n",LN->info);
	free(LN);
	PH->info--;
} 

void InsertByPos(NODE PH)
{
	int pos,cnt;
	NODE NN,TP;
	NN = CreateNode();
	printf("Enter the Data.. \n");
	scanf("%d",&NN->info);
	l1 : printf("Enter the position between 1 to %d\n",PH->info);
	scanf("%d",&pos);
	if(pos<1 || pos > PH->info +1) goto l1;
	
	TP = PH->RL;
	cnt = 1;

	while(cnt!=pos)
	{
	TP = TP->RL;
	cnt++;
	}

	NN->LL = TP->LL;
	NN->RL = TP;
	NN->LL->RL = NN;
	TP->LL = NN;
}


NODE SearchByValue(NODE PH)
{
	int key;
	NODE TP;
	if(PH->info == 0)
	{
		printf("Empty \n");
		return NULL;
	}
	printf("Enter the Key Value : ");
	scanf("%d",&key);
	TP = PH->RL;
	while(TP!=PH && TP->info!=key)
		TP = TP->RL;
	if(TP == PH)
	{
		return NULL;
	}
	return TP;
}




void DeleteByKey(NODE PH)
{
	NODE NN,TP;
	int key;
	if(PH->info == 0)
	{
		printf("Empty \n");
		return;
	}

	printf("Enter the Key Value : ");
	scanf("%d",&key);
	TP = PH->RL;
	while(TP!=PH && TP->info!=key)
		TP = TP->RL;
	if(TP == PH)
	{
		printf("Not Found..\n");
		return;
	}
	TP->LL->RL = TP ->RL;
	TP->RL->LL = TP->LL;
	printf("Deleted is %d\n",PH->info);
	free(TP);
	PH->info--;
}

void DeleteByPos(NODE PH)
{
	NODE NN,TP;
	int pos,cnt;
	if(PH->info == 0)
	{
		printf("Empty List \n");
		return;
	}
	l1:printf("Enter The Position between 1 to %d\n",PH->info);
	scanf("%d",&pos);
	if(pos<1 || pos > PH->info) goto l1;
	cnt = 1;

	TP = PH->RL;
	while(cnt!=pos)
	{
		TP = TP->RL;
		cnt++;
	}
	TP->LL->RL = TP->RL;
	TP->RL->LL = TP->LL;
	printf("%d is Deleted\n",TP->info);
	free(TP);
	PH->info--;
}

NODE Reverse(NODE PH)
{
	NODE temp = PH;
	NODE prev = NULL;
	NODE curr = NULL;
	while(temp != NULL)
	{
		curr = temp->RL;
		temp->RL = prev;
		temp->LL = curr;
		prev = temp;
		temp = curr;
	}
	PH = prev;
	return PH;
}

void InsertByOrder(NODE PH)
{
	NODE NN,TP;
	NN = CreateNode();
	printf("Enter The Data of the Node : ");
	scanf("%d",&NN->info);
	TP = PH->RL;
	while(TP!=PH && TP->info < NN->info)
		TP = TP->RL;

	NN->LL = TP->LL;
	NN->RL = TP;
	NN->LL->RL = NN;
	TP->LL = NN;
	PH->info++;
}


NODE Copy(NODE PH)
{
	NODE NN,TP,cpy,temp;
	NN = CreateNode();
	NN->info = PH->info;
	cpy =NN;
	TP = PH->RL;

	while(TP !=PH)
	{
		NN->RL = CreateNode();
		temp = NN;
		NN = NN->RL;
		NN->info = TP->info;
		NN->LL = temp;
		TP = TP->RL;
	}
	NN->RL = cpy;
	cpy->LL = NN;
	return cpy;
}


