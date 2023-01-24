
//Structure student program

#include<stdio.h>
#include<stdlib.h>

struct student
{
	int reg_no;
	int M[3];
	char Name[10];
	float Avg;

};

typedef struct student STD;

void Read(STD*);
void Disp(STD*);
void Average(STD*);

int SIZE,N;


void main()
	{

		int ch;
		STD *p;
		printf("Enter the SIZE : ");
		scanf("%d",&SIZE);
	
		p = (STD*)malloc(SIZE* sizeof(STD));

		for(;;)
		{

		printf("Enter the Choice \n1.Read\n2.Display\n");



		scanf("%d",&ch);

		switch(ch)
		{
		case 1: Read(p);
		break;

		case 2 : Disp(p);
		break;

		default : exit(0);
		}
		}
}

void Read(STD *s)
	{

	int i,j;
	printf("Read N :");
	scanf("%d",&N);

	for(i=0;i<N;i++)

	{
	printf("Enter Reg No and Name of Student : \n");
	scanf("%d%s",&(s+i)->reg_no,(s+i)->Name);

	printf("Enter the Three Test Marks of the student :\n");

	for(j=0;j<3;j++)
	{

	scanf("%d",&(s+i)-> M[j]);

	}

	Average(s);

	}
	}

void Disp(STD *s)
	{
	
	int i,j;
	printf("Reg No\tName\tTest1\tTest2\tTest3\tAverage of best 2\n");
	printf("--------------------------------------------------------------------------\n");

	for(i=0;i<N;i++)
	{
	printf("%d\t%s\t",(s+i)->reg_no,(s+i)->Name);

	for(j=0;j<3;j++)
	{
	printf("%d\t",(s+i)-> M[j]);
	}
	printf("%f\n",(s+i)-> Avg);
	}
	
}

void Average(STD *s)
{
	int i,j,sum = 0,min;
	for(i=0;i<N;i++)
	{
	min = (s+i)-> M[0];
	sum = min;

	for(j=1;j<3;j++)
	{
	
	sum = sum +(s+j)->M[j];
	if((s+j)-> M[j] < min)
	min = (s+j)-> M[j];

	}
	(s+i)-> Avg = (sum - min)/2.0;
	}
	}



