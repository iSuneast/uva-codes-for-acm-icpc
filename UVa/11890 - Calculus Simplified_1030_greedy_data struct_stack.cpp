/*
11890 - Calculus Simplified

data struct...
stack...
greedy

use stack to simulate to Expression
try to calculate how many "-" exist
when all the "(" and ")" are deleted...

finally, greedy calc the answer is OK
*/

#include<iostream>
#include<algorithm>
#define MAXN 100003
using namespace std;

char op[MAXN];
int var[MAXN],cnt,n;
struct STATE
{
	int p,n;
}st[MAXN];
char MyStack[MAXN];

void process()
{
	int top=0,MyTop=0;
	for(int i=0;op[i];++i)
	{
		if(op[i]=='(')
			MyStack[MyTop++]='(';
		else if(op[i]==')')
		{
			while(MyStack[MyTop-1]!='(')
			{
				STATE a=st[--top];
				STATE b=st[--top];

				if(MyStack[MyTop-1]=='+')
				{
					b.n+=a.n;
					b.p+=a.p;
				}
				else
				{
					b.n+=a.p;
					b.p+=a.n;
				}
				st[top++]=b;

				--MyTop;
			}
			--MyTop;
		}
		else if(!isalpha(op[i]))
		{
			if(MyTop)
			{
				if(MyStack[MyTop-1]=='+')
				{
					STATE a=st[--top];
					STATE b=st[--top];
					b.n+=a.n;
					b.p+=a.p;
					st[top++]=b;
					--MyTop;
				}
				else if(MyStack[MyTop-1]=='-')
				{
					STATE a=st[--top];
					STATE b=st[--top];
					b.n+=a.p;
					b.p+=a.n;
					st[top++]=b;
					--MyTop;
				}
			}
			MyStack[MyTop++]=op[i];
		}
		else
		{
			st[top].n=0;
			st[top].p=1;
			++top;
		}
	}

	if(MyTop)
	{
		if(MyStack[MyTop-1]=='+')
		{
			STATE a=st[--top];
			STATE b=st[--top];
			b.n+=a.n;
			b.p+=a.p;
			st[top++]=b;
			--MyTop;
		}
		else if(MyStack[MyTop-1]=='-')
		{
			STATE a=st[--top];
			STATE b=st[--top];
			b.n+=a.p;
			b.p+=a.n;
			st[top++]=b;
			--MyTop;
		}
	}

	cnt=st[0].n;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int dataset;
	scanf("%d",&dataset);
	while(dataset--)
	{
		scanf("%s%d",op,&n);

		int key=0;
		for(int i=0;i<n;++i)
		{
			scanf("%d",&var[i]);
			key+=var[i];
		}

		sort(var,var+n);
		cnt=0;
		process();

		for(int i=0;i<cnt;++i)
			key-=2*var[i];

		printf("%d\n",key);
	}

	return 0;
}
