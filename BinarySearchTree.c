#include<stdio.h>
#include<stdlib.h>

struct node{

int info;
struct node *Llink,*Rlink;
};

typedef struct node *NODE;

NODE BST_Construction(NODE);
int Max(NODE);
int Min(NODE);
NODE Search(NODE R,int key);
NODE Delete(NODE R,int key);
void inorder(NODE);
void preorder(NODE);
void postorder(NODE);
NODE CreateNode();
int Count(NODE);
int CountLeafNode(NODE);
int Height(NODE);
int NonLeafNode(NODE);
NODE Copy(NODE);
int Maxi(int,int);

void main()
{

	NODE SN = NULL;
	int key,res;
	NODE cop = NULL;
	NODE Root = NULL;
	int ch = 0;
	for(;;)
	{
		printf("Enter Your Choice : \n1.Tree Construction\n2.Search\n3.Delete\n4.Inorder Traversal\n5.PreOrder Traversal\n6.PostOrder Traversal\n7.Find Min\n8.Find Max \n9.Total Nodes\n10.Leaf Nodes\n11.HEight\n12.Non Leaf Nodes\n13.Copy\n\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 0 : exit(0);
			case 1 : Root = BST_Construction(Root);break;
			case 2 : printf("Enter the Value : ");
					 scanf("%d",&key);
					 SN = Search(Root, key);
					 if(SN!=NULL)
					 printf("Element is Found.. ");
					 else
					 printf("NOT Found ");
					 break;
			case 3 : printf("Enetr the Value : ");
					 scanf("%d",&key);
					 Root = Delete(Root,key);
					 break;
			case 4 : inorder(Root);break;
			case 5 : preorder(Root);break;
			case 6 : postorder(Root);break;
			case 7 : printf("Minimum Value : %d\n",Min(Root));break;
			case 8 : printf("Maximum Value : %d\n",Max(Root));break;
			case 9 : printf("Count : %d\n",Count(Root));break;
			case 10 : printf("Leaf Nodes : %d\n",CountLeafNode(Root));break;
			case 11 : printf("Height : %d\n",Height(Root));break;
			case 12 : printf("Non Leaf Node : %d\n",NonLeafNode(Root));break;
			case 13 : cop = Copy(Root);break;
			default : printf("Invalid choice ..");break;
		}
	}
}

void preorder(NODE R)
{
	if(R==NULL) return;
	printf("%d\t",R->info);
	preorder(R->Llink);
	preorder(R->Rlink);
}

void inorder(NODE R)
{
	if(R==NULL) return;
	inorder(R->Llink);
	printf("%d\t",R->info);
	inorder(R->Rlink);
}

void postorder(NODE R)
{
	if(R==NULL) return;
	postorder(R->Llink);
	postorder(R->Rlink);
	printf("%d\t",R->info);
}

int Count(NODE R)
{
	if(R == NULL) return 0;
	int count = 0;
	count ++;
	count = count + Count(R->Llink);
	count = count + Count(R->Rlink);
	return count; 
}

NODE CreateNode()
{
	NODE NN = (NODE)malloc(sizeof(struct node));
	return NN;
}
NODE BST_Construction(NODE R)
{
	NODE PN,NN,TP;
	int ch;
	for(;;)
	{
	printf("Enter The Info(-1 for Termination) : ");
	scanf("%d",&ch);
	if(ch == -1) break;
	NN = CreateNode();
	NN->info = ch;
	NN->Llink = NN->Rlink = NULL;
	if(R == NULL) return NN;
	
	TP = R;
	while(TP != NULL)
	{
	PN = TP;
	if(NN->info<TP->info)
		TP = TP->Llink;
		else
		TP = TP->Rlink;
	
	}
	if(NN->info < PN->info)
	
		PN->Llink = NN;
		else
		PN->Rlink = NN;
		
	}
	return R;
	}

int Max(NODE R)
{
	NODE TP = R;
	while(TP ->Rlink != NULL)
		TP = TP->Rlink;
	return TP->info;
}

int Min(NODE R)
{
	NODE TP = R;
	while(TP ->Llink != NULL)
		TP = TP->Llink;
	return TP->info;
}

NODE Search(NODE R,int key)
{
	NODE SN = NULL;
	if(R == NULL) return NULL;
	if(R->info == key) SN = R;
	if(SN == NULL)
	{
		if(key<R->info)
			SN = Search(R->Llink,key);
		else
			SN = Search(R->Rlink,key);
	}
	return SN;
}


NODE Delete(NODE R,int key)
{
	if(R==NULL)
	{
	printf("Empty Tree..\n");
	return NULL;
	}
	NODE SN,TP,PN,temp;
	SN = TP = PN = NULL;
	temp = TP = R;
	SN = Search(temp,key);
	if(SN == NULL)
	{
	printf("Element Not Found\n");return R;
	}
	if(SN == R) goto label;
	while(TP != NULL)
	{
		PN = TP;
		if(SN ->info < TP->info)
			TP = TP->Llink;
		else
			TP = TP ->Rlink;
		if(SN->info == TP->info) break;
	}
	
	if(SN->Llink == NULL && SN->Rlink == NULL)
	{
		if(SN->info < PN->info)
			PN->Llink = NULL;
		else
			PN->Rlink = NULL;
	}
	
	if(SN->Llink != NULL && SN->Rlink == NULL || SN->Llink == NULL && SN->Rlink != NULL)
	{
	
		TP = NULL;
		if(SN->Llink == NULL)
			TP = SN->Rlink;
		else
			TP = SN->Llink;
			
		if(SN->info < PN->info)
			PN->Llink = TP;
		else
			PN->Rlink = TP;
	}
	
	
label: if(SN->Llink != NULL && SN->Rlink != NULL)
	   {
		NODE RST,IS,Par;
		RST = IS = Par = NULL;
		RST = SN->Rlink;
		IS = RST;
		
		Par = SN;
		while(IS->Llink != NULL)
		{
			Par = IS;
			IS = IS->Llink;
		}
		SN->info = IS->info;
		
		if(IS->Llink == NULL && IS->Rlink == NULL)
		{
		if(IS->info < Par->info)
			Par->Llink = NULL;
		else
			Par->Rlink = NULL;
		}
	
		if(IS->Llink != NULL && IS->Rlink == NULL || IS->Llink == NULL && IS->Rlink != NULL)
		{
			TP = NULL;
			TP = IS->Rlink;
			
			if(IS->info < Par->info)
				Par->Llink = TP;
			else
				Par->Rlink = TP;
		}
		printf("Deleted is %d",key);
		free(IS);
		return R;	
	}
	printf("Deleted is %d",SN->info);
	free(SN);
	return R;
}

int CountLeafNode(NODE R)
{
	if(R == NULL) return 0;
	int count = 0;
	if(R->Rlink == NULL && R->Llink == NULL)
	count ++;
	count = count + CountLeafNode(R->Llink);
	count = count + CountLeafNode(R->Rlink);
	return count; 
}

int Height(NODE R)
{
	if(R == NULL) return -1;
	return (1+Maxi(Height(R->Llink),Height(R->Rlink)));
}

int Maxi(int a ,int b)
{
	if(a>b)
	return a;
	else
	return b;
}

int NonLeafNode(NODE R)
{
	return (Count(R) - CountLeafNode(R)); 
}

NODE Copy(NODE R)
{
	if(R == NULL) return NULL;
	NODE TN;
	TN = CreateNode();
	TN->info = R->info;
	TN->Llink = Copy(R->Llink);
	TN->Rlink = Copy(R->Rlink);
	return TN;	
}
