//Circular Linked list program

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *link;
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
NODE Copy(NODE);
void Reverse(NODE);



NODE Head,cop,SN;

void main()
{
	Head = CreateNode();
	Head->info = 0;
	Head->link = Head;

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
		case 12: Reverse(Head);Display(Head);
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

	NN->link = pH->link;
	pH->link = NN;
	pH->info++;

}

NODE CreateNode()
{
	NODE NN;
	NN = (NODE)malloc(sizeof(struct node));
	return NN;
}



void Display(NODE pH)
{
	if(pH->info == 0)
	{
		printf("The List is Empty.... Try Inserting an element :)\n");
		return;
	}
	NODE TP = pH->link;

	while (TP !=pH)
	{
		printf("%d\t",TP->info);
		TP = TP->link;
	}
}

void InsertRear(NODE pH)
{
	NODE NN;
	NODE TP = pH->link;
	NN = CreateNode();
	printf("Enter The Data of the Node : ");
	scanf("%d",&NN->info);
	while(TP->link != pH)
		TP = TP->link;

	TP->link = NN;
	TP=TP->link;
	TP->link = pH;
	pH->info++;


}

void DeleteRear(NODE pH)
{
	NODE PN;
	if(pH->info == 0)
	{
		printf("Empty List \n");
		return;
	}
	NODE TP = pH->link;
	PN = pH;
	while(TP->link != pH)
	{
		PN = TP;
		TP = TP->link;
	}

	PN->link =pH;

	free(TP);
	pH->info--;


}

void DeleteFront(NODE pH)
{

	NODE TP;
	if(pH->info == 0)
	{
	printf("Empty List \n");
	return;
	}

	TP = pH->link;
	pH->link =TP->link;
	free(TP);
	pH->info--;


}

void InsertByOrder(NODE pH)
{
	NODE NN;NODE PN;
	PN= pH;
	NODE TP = pH->link;

	NN = CreateNode();
	printf("Enter the Node Value : ");
	scanf("%d",&NN->info);
	while(TP!=pH && NN->info > TP->info)
	{

		PN = TP;
		TP = TP->link;

	}
	NN->link = TP;
	PN->link = NN;
	pH->info++;
}

void DeleteByPos(NODE pH)
{
	int pos;
	printf("Enter The Position Between 1 to %d",pH->info);
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
	NODE TP,ND;
	TP = pH;
	int key;
	printf("Enter the Key value : ");
	scanf("%d",&key);
	do{
		ND = TP;
		TP = TP->link;
		if(TP->info == key)
		break;
	}while(TP != pH);

	if(TP == pH)
	{
		printf("Element Not Found ...");
		return;
	}
	else{
		ND->link = TP->link;
		pH->info--;
		free(TP);
	}

}

NODE SearchByValue(NODE pH)
{
	if(pH->info ==0)
	{
		printf("Empty List..");
		return NULL;
	}
	int key;
	NODE TP;
	printf("Enter The Element To be Searched : ");
	scanf("%d",&key);
	TP = pH->link;
	while(TP != pH)
	{
		if(TP ->info = key)
			return TP;
		TP = TP->link;
	}
	return NULL;
}

NODE Copy(NODE pH)
{

	NODE NN,TP,cpy;
	NN = CreateNode();
	NN->info = pH->info;
	cpy = NN;
	TP = pH->link;
	while(TP!=pH)
	{
		NN->link = CreateNode();
		NN = NN->link;
		NN->info = TP->info;
		TP = TP->link;
	}

	NN->link = cpy;
	return cpy;
}

void InsertByPos(NODE pH)
{
	int pos;
	NODE TP,NN,PN;
	NN = CreateNode();
	printf("Enter The Position Between 1 to %d",pH->info);
	scanf("%d",&pos);
	printf("Enter The Data of the Node : ");
	scanf("%d",&NN->info);
	int cnt = 1;
	PN = pH;
	TP = pH->link;

	while (cnt!=pos)
	{
		PN = TP;
		TP = TP->link;
		cnt++;
	}
	NN->link = TP;
	PN->link = NN;
	pH->info++;
}

void Reverse(NODE pH)
{
	NODE TP,PN,SN;
	TP = pH->link;
	SN = pH;
	while(TP != pH)
	{
		PN = TP;
		TP = TP->link;
		PN->link = SN;
		SN = PN;
	}
	pH->link = PN;

}



