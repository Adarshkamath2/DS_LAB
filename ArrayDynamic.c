//Array operations dynamically

#include<stdio.h>
#include<stdlib.h>

int* Read(int*);
void Disp(int*);
int *Realloc(int *);
int* InsertByPos(int *);
void DeleteByPos(int *);
int InsertByOrder(int* );
int SearchByKey(int *);

int n = 0,SIZE =10;

void main()
{
	int res =0 ,*a,ch;

	a = (int*)malloc(SIZE*sizeof(int)); 

	for(;;)
	{
		printf("Enter Your Choice For Array Operation \n1.Read\n2.Display\n3.Insert By Position\n4.Delete By position\n5Insert By Order\n6.Search by Key\n7.Reverse\n");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1: a = Read(a);break;
			case 2: Disp(a);break;
			case 3: a = InsertByPos(a);Disp(a);break;
			case 4: DeleteByPos(a);Disp(a);break;
			case 5: a = InsertByOrder(a);Disp(a);break;
			case 6: res = SearchByKey(a);
				if(res == -1)
				printf("Not Present \n");
				else
				printf("%d present at %d\n",a[res],(res+1));
				break;

			default : exit(0);
		}
	}
}

int *Read(int *p)
{
	int i ;
	printf("Enter the Value of N \n");
	scanf("%d",&n);
	if(n > SIZE)
	{
		printf("Reallocating........");
		p = Realloc(p);
	}
	for(i=0;i<n;i++)
		scanf("%d",p+i);
	return p;
}

void display(int **p)
{
	for(int i =0;i<n;i++)
		printf("%d\t",*(p+i));
}

int *Realloc(int **p)
{
	p = (int *)realloc(p,(SIZE *2)*sizeof(int));
	if(p == NULL)
	{
		printf("Memory Full \n");
		exit(0);
	}
	return p;
}

void InsertByPos(int *p)
{
	int i, pos , item;
	if(n== SIZE)
		p = Realloc(p);
	printf("Enter the positon\n");
	scanf("%d",&pos);
	printf("Enter the Item : ");
	scanf("%d",&item);

	for(i=n-1;i>= pos-1;i--)
		*(p+i+1) = *(p+i);
	*(p+pos-1) = item;
	N++;
	return(p);
}

void DeleteByPos(int *p)
{
	int i,pos;
	if(n==0)
	{
		printf("Array empty\n"); return;
	}
	printf("Enter the Position..\n");
	scanf("%d",&pos);

	for(i=pos-1;i<n;i++)
		*(p+i) = *(p+i+1);
	N--;
}

int SearchByKey(int *p)
{
	if(n==0) return -1;

	int i,item;
	printf("Enter the Item to be searched : \n");
	scanf("%d",&item);
	for(i=0;i<=n-1;i++)
	{
		if(*(p+i)== item) return i;
	}
	return (-1);
}

void InsertByOrder(int * p)
{
	int i,item;
	if(n== SIZE) p = Realloc(p);
	printf("Enter the Item to be Inserted :\n");
	scanf("%d",&item);
	for(i=n-1;i>=0&& *(p+i)>item ;i--);
		*(p+i+1)= *(p+i);
	*(p+i+1) = item;
	N++;
	return p;
}
