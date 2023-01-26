// Linked list program

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
NODE InsertRear(NODE);
NODE DeleteFront(NODE);
NODE DeleteRear(NODE);
NODE SearchByValue(NODE);
NODE InsertByPos(NODE);
NODE InsertByOrder(NODE);
NODE DeleteByKey(NODE);
NODE DeleteByPos(NODE);
NODE sort(NODE);
NODE Copy(NODE);
NODE Reverse(NODE);

int N=0;
NODE SN;

void main()
{
	NODE First = NULL;
	NODE copy;
	int ch;
	for(;;)
	{
		printf("\n---------------------\nEnter Your Choice for Operation : \n1.Insert Front\n2.Display\n3.Insert Rear\n4.Delete Front\n5.Delete Rear\n6.Search by value\n7.Insert By Position\n8.Insert By order\n9.Delete  By Key\n10.Delete By Pos\n11.Sort\n12.Copy\n13.Reverse\n0.Exit\n------------------------------\n");
		scanf("%d",&ch);

		switch(ch)
		{
			case 0: exit (0);break;
			case 1: First = InsertFront(First);Display(First);break;
			case 2: Display(First);break;
			case 3: First = InsertRear(First);Display(First);break;
			case 4: First = DeleteFront(First);Display(First);break;
			case 5: First = DeleteRear(First);Display(First);break;
			case 6: SN = SearchByValue(First);
					if(SN == NULL)
					printf("NOT FOUND...\n");
					else
					printf("Node info is : %d",SN->info);
					break;
			case 7: First = InsertByPos(First);Display(First);break;
			case 8: First = InsertByOrder(First);Display(First);break;
			case 9: First = DeleteByKey(First);Display(First);break;
			case 10:First = DeleteByPos(First);Display(First);break;
			case 11:First = sort(First);Display(First);break;
			case 12:copy = Copy(First);Display(copy);break;
			case 13:copy = Reverse(First);Display(copy);break;
			default : printf("Invalid Choice... Try again\n");break;
		}
	}
}

NODE InsertFront(NODE pf)
{
	NODE NN;
	NN = CreateNode();
	printf("Enter the Node Info : ");
	scanf("%d",&NN->info);

	NN->link = pf;
	pf = NN;
	N++;
	return pf;
}

NODE CreateNode()
{
	NODE NN = (NODE)malloc(sizeof(struct node));
	return NN;
}

void Display(NODE pf)
{
	if(pf == NULL)
	{
		printf("The List is Empty.... Try Inserting an element :)\n");return;
	}
	while (pf !=NULL)
	{
		printf("%d\t",pf->info);
		pf = pf->link;
	}
}

NODE InsertRear(NODE pf)
{
	NODE NN,LN;
	NN = CreateNode();
	printf("Enter the Data of the Node : ");
	scanf("%d",&NN->info);

	NN->link = NULL;
	LN = pf;
	if(LN == NULL)
	 	return NN;
	while(LN->link != NULL)
		LN = LN->link;
	LN->link = NN;
	N++;
	return pf;
}

NODE DeleteFront(NODE pf)
{
	NODE FN;
	if(pf == NULL)
	{
		printf("List is empty....Try Inserting a value\n");return NULL;
	}
	FN = pf;
	pf = pf->link;

	printf("%d is Deleted \n",FN->info);
	free(FN);
	N--;
	return pf;
}

NODE DeleteRear(NODE pf)
{
	NODE LN,PLN;
	if(pf == NULL)
	{
		printf("List is Empty.... Try Inserting a VAlue :) \n");return NULL;
	}
	LN = pf;
	PLN = NULL;
	while(LN->link != NULL)
	{
		PLN = LN;
		LN = LN ->link;
	}
	printf("%d is Deleted ... ", LN->info);
	N--;
	free(LN);
	if(PLN!=NULL)
	{
		PLN -> link = NULL;return pf;
	} 
	else
		return NULL;
}

NODE SearchByValue(NODE pf)
{
	int val;
	printf("Enter the value : ");
	scanf("%d",&val);

	if(pf == NULL)
	{
		printf("List is Empty.... Try Inserting a VAlue :) \n");return NULL;
	}
	while(pf!=NULL)
	{
		if(pf->info == val)
			return pf;
		pf = pf->link;
	}
	return pf;	
}

NODE InsertByPos(NODE pf)
{

	NODE NN,TP,PN;
	int pos,count;

	NN = CreateNode();
	printf("Enter the Value :  ");
	scanf("%d",&NN->info);
	NN->link = NULL;

	l1: printf("Enter the Position from 1 to %d : ",N+1);
	scanf("%d",&pos);
	if(pos < 1 || pos > N+1) goto l1;

	TP = pf;
	PN = NULL;
	count = 1;
	while (count!=pos && TP !=NULL)
	{
		PN = TP;
		TP = TP->link;
		count++;
	}
	N++;
	if(PN == NULL)
	{
		NN->link = TP; return NN;
	}
	NN->link = TP;
	PN->link = NN;
	return pf;
}

NODE InsertByOrder(NODE pf)
{
	NODE NN,TP,PN;
	NN = CreateNode();

	printf("Enter the Value :  ");
	scanf("%d",&NN->info);
	NN->link = NULL;

	TP = pf;
	PN = NULL;

	while (TP !=NULL && TP->info < NN->info)
	{
		PN = TP;
		TP = TP->link;
	}
	NN->link = TP;
	N++;
	if(PN == NULL) return NN;
	PN->link = NN;
	return pf;
}

NODE DeleteByKey(NODE pf)
{
	NODE ND,PN;
	int key;
	if(pf == NULL)
		{
			printf("List is Empty.... Try Inserting a VAlue :) \n");
			return NULL;
		}
	printf("Enter the Key of the NODE : ");
	scanf("%d",&key);
	ND = pf;
	PN = NULL;

	while (ND !=NULL && ND->info != key)
		{
			PN = ND;
			ND = ND->link;
		}
	if(ND == NULL)
		printf("NOT FOUND....\n");
	else if(PN == NULL)
		pf = pf->link;
	else 
		PN->link = ND->link;

	printf("%d is Deleted ....\n",ND->info);
	free(ND);
	N--;
	return pf;
}

NODE DeleteByPos(NODE pf)
{
	NODE ND,PN;
	int pos,count;
	if(pf == NULL)
		{
			printf("The List is Empty.... Try Inserting an element :)\n");
			return NULL;
		}
	l1: printf("Enter the Position from 1 to %d : ",N);
	scanf("%d",&pos);
	if(pos < 1 || pos > N+1) goto l1;

	ND = pf;
	PN = NULL;
	count = 1;
	while (count!=pos)
	{
		PN = ND;
		ND = ND->link;
		count++;
	}
	N++;
	if(PN == NULL)
		pf = pf->link;
	else
		PN->link = ND->link;

	printf("%d is Deleted ....\n",ND->info);
	free(ND);
	N--;
	return pf;
}

NODE sort(NODE pf)
{
	NODE TP;
	int i,j,temp;
	for(i=0;i<N-1;i++)
	{
		TP = pf;
		for(j=0;j<N-1-i;j++)
		{
			if(TP->info > TP->link->info)
			{
				temp = TP->info;
				TP->info = TP->link->info;
				TP->link->info = temp;
			}
			TP = TP->link;
		}
	}
	return pf;
}



NODE Copy(NODE pf)
{
	NODE NN,cpy,ccpy;
	if(pf == NULL)
	{
		printf("List is Empty...\n");
		return NULL;
	}
	NN = CreateNode();
	ccpy = cpy =NN;
	cpy->info = pf->info;
	cpy->link = pf->link;

	pf = pf->link;
	while(pf!=NULL)
	{
		NN = CreateNode();
		cpy =NN;
		cpy->info = pf->info;
		cpy->link = pf->link;
		pf = pf->link;
	}
	cpy->link = NULL;
	return ccpy;
}

NODE Reverse(NODE pf)
{

	NODE NN,rev;
	if(pf == NULL)
	{
		printf("List is Empty...\n");return NULL;
	}
	NN = CreateNode();
	rev = NN;
	rev->info = pf->info;
	rev->link = NULL;
	pf = pf-> link;

	while(pf!=NULL)
	{
		NN = CreateNode();
		NN->link = rev;
		rev = NN;
		rev->info = pf->info;
		pf = pf->link;
	}
	return rev;
}
