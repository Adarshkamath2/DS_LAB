// time program


#include<stdio.h>
#include<stdlib.h>

struct time
{

int h,m,s;
};

typedef struct time TIME;

void Read(TIME*);
void Disp(TIME*);
void update(TIME*);
TIME Add(TIME ,TIME,TIME);
void init(TIME*);

void main()
{
	int ch;
	TIME t1,t2,t3;
	init(&t1);
	init(&t2);
	init(&t3);

	for(;;)
	{
		printf("Enter Your CHoice : \n1.Read\n2.Display\n3.Update\n4.Add\n");
		scanf("%d",&ch);

		switch(ch)

		{
		case 1: {
			printf("Enter time 1 : ");
			Read(&t1);
			printf("Enter Time 2: ");
			Read(&t2);
			break;
			}
		case 2: printf("Time 1 = ");
			Disp(&t1);
			printf("Time 2 = ");
			Disp(&t2);
			break;


		case 3: update(&t1);
			printf("Updated Time is ....\n");
			Disp(&t1);
			break;

		case 4: t3 = Add(t1,t2,t3);
			Disp(&t3);
			break;

		default : exit (0);
		}
	}
}

void Read(TIME *t)
	{
		printf("Enter the Hours , MInute and seconds :\n");
		scanf("%d%d%d",&t->h,&t->m,&t->s);

	}

void Disp(TIME *t)
{

	printf("%d:%d:%d\n",t->h,t->m,t->s);

}


void update(TIME *t)
{
	t ->s++;
	if(t->s>=60)
	{
		t->m = t->m+(t->s)/60;
		t->s = (t->s)%60;
	}
	if(t->m >=60)
	{
		t->h = t->h+(t->m)/60;
		t->m = (t->m)%60;

		if(t->h >= 24)
			init(t);
	}
}

TIME Add(TIME t1,TIME t2,TIME t3)
{
	t3.h = t1.h + t2.h;
	t3.m = t1.m + t2.m;
	t3.s = t1.s + t2.s;
	t3.s--;
	update(&t3);
return t3;
}

void init(TIME *t)
{
	t->m = t->h = t->s = 0;
}



