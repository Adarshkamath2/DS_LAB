#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct stk1
{
	char item[20];
	int TOP;
};
typedef struct stk1 Oprstk;

struct stk2
{
	char item[10][20];
	int TOP;
};
typedef struct stk2 Opndstk;

void push1(char c , Oprstk *s)
{
	if(s->TOP == 19)
		printf("STACK FULL...\n");
	else
		
		s->TOP++;
	s->item[s->TOP]=c;
}		

char pop1(Oprstk *s)
{
	char c;
	if(s->TOP == -1)
		printf("STACK EMPTY....\n");
	else
	
		c = s->item[s->TOP];
		s->TOP--;
		return c;	
}

void push2(char c[] , Opndstk *s)
{
	if(s->TOP == 19)
		printf("STACK FULL...\n");
	else
		
		s->TOP++;
	strcpy(s->item[s->TOP],c);
		
}

char* pop2(Opndstk *s)
{
	char *c;
	if(s->TOP == -1)
		printf("STACK EMPTY....\n");
	else
	
		c = s->item[s->TOP];
		s->TOP--;
		return c;
	
	
}

void par(Oprstk* oprtr,Opndstk *opnd)
{
	char *op1,*op2,opr,t[2],pexp[20];
	opr = pop1(oprtr);
	t[0] = opr;
	t[1] = '\0';
	op2 = pop2(opnd);
	op1 = pop2(opnd);
	strcpy(pexp,t);
	strcat(pexp,op1);
	strcat(pexp,op2);
	push2(pexp,opnd);

}

int isOperand(char c)
{
	switch(c)
	{
	case '+' : 
	case '-' :
	case '*' :
	case '/' :
	case '(' :
	case ')' :
	case '$' :
	case '^' : return 0;
	default : return 1;
	}
}
	
int stkPre(char c)
{
	switch(c)
	{
	case '+' : 
	case '-' :return 2;
	case '*' :
	case '/' :return 4;
	
	
	case '$' :
	case '^' : return 7;
	case '(' : return 0;
	}
}	
int inPrc(char c)
{
switch(c)
	{
	case '+' : 
	case '-' : return 1;
	case '*' :
	case '/' : return 3;
	case '$' :
	case '^' : return 8;
	case '(' : return 9;
	case ')' : return 0;
	}
}

void inPost(char in[],char po[])
{
	Oprstk s;
	char c;
	int i=0;
	int j=0;
	s.TOP = -1;
	while((c = in[i++])!='\0')
	{
		if(isOperand(c))
			po[j++] = c;
		else
		{
			while(s.TOP!= -1 && stkPre(s.item[s.TOP])>inPrc(c))
			{
				if(c== ')')
				{
					while(s.item[s.TOP]!= '(')
					
						po[j++] = pop1(&s);
					pop1(&s);
					break;
					
				}
				else
					po[j++] = pop1(&s);
			}
			if(c!=')')
				push1(c,&s);		
		}
	}
	while(s.TOP != -1)
	
		po[j++] = pop1(&s);
	po[j] = '\0';
	
}	

void inPre(char in[],char pre[])
{
	Oprstk s1;
	Opndstk s2;
	char c,temp[2];
	
	int i=0;
	int j=0;
	s1.TOP = -1;
	s2.TOP = -1;
	while((c = in[i++])!='\0')
	{
		if(isOperand(c))
			{
			temp[0] = c;
			temp[1] = '\0';
			push2(temp,&s2);
			
			}
		else
		{
			while(s1.TOP!= -1 && stkPre(s1.item[s1.TOP])>inPrc(c))
			{
				if(c== ')')
				{
					while(s1.item[s1.TOP]!= '(')
					
						par(&s1,&s2);
					pop1(&s1);
					break;
					
				}
				else
					par(&s1,&s2);
			}
			if(c!=')')
				push1(c,&s1);		
		}
	}
	while(s1.TOP != -1)
	
		par(&s1,&s2);
		
	strcpy(pre,s2.item[s2.TOP]);
	
}	
	
	
void main()
{
  int ch;
	char in[30],po[30],pre[30];
	for(;;)
	{	printf("Enter Your Choice..\n1.Infix to Postfix\n2.Infix to Prefix\n0.exit\n");
		scanf("%d",&ch);
		printf("Enter the Expression and 0 to Stop Execution..\n");
		scanf("%s",in);
		if(strcmp(in,"0")==0)
			break;
		switch(ch)
		{
		case 1: inPost(in,po);
		printf("%s\n",po);break;
		case 2:inPre(in,pre);
		printf("Given Infix Expression is : %s \n",in);
		printf("Converted Prefix Expression is : %s\n",pre);
		break;
		case 0: exit(0);
		default : printf("Invalid choice...");break;
		
		}		
	}	
}
