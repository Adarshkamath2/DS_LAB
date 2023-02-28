/*
PROGRAM-1b
Define a structure called Time containing 3 integer members (Hour, Minute, Second). Develop a menu driven program to perform the following by writing separate function for each operation.
a) Read (T) :To read time 
b) Display (T):To display time 
c) update(T):To Update time 
d) Add (T1, T2) : Add two time variables.
Update function increments the time by one second and returns the new time (if the increment results in 60 seconds, then the second member is set to zero and minute member is incremented by one. If the result is 60 minutes, the minute member is set to zero and the hour member is incremented by one. Finally, when the hour becomes 24, Time should be reset to zero. While adding two time variables, normalize the resultant time value as in the case of update function. Note: Illustrate the use of pointer to pass time variable to different functions.
*/

#include<stdio.h>
#include<stdlib.h>

struct time
{
    int H,M,S;
};
typedef struct time TIME;

void Read(TIME*);
void Disp(TIME*);
void Update(TIME*);
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


		case 3: Update(&t1);
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

void init(TIME *T)
{
    T->S = T->M = T->H = 0;
}

void Read(TIME *T)
{
    printf("Enter Time(HH:MM:SS) : ");
    scanf("%d%d%d",&T->H,&T->M,&T->S);
}

void Disp(TIME *T)
{
    printf("Time is - %d:%d:%d",T->H,T->M,T->S);
}

void Update(TIME *T)
{
    T->S++;
    if(T->S >= 60)
    {
        T->M = T->M + T->S/60;
        T->S = T->S%60;
    }
    if(T->M >= 60)
    {
        T->H = T->H + T->M/60;
        T->M = T->M%60;
        if(T->H >=24)
            init(T);
    }
}

TIME Add(TIME T1,TIME T2,TIME T3)
{
    T3.H = T1.H+T2.H;
    T3.M = T1.M+T2.M;
    T3.S = T1.S+T2.S;
    T3.S--;
    Update(&T3);
    return T3;
}
