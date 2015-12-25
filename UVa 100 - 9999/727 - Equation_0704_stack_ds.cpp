/*
727 - Equation

data struct...
stack...
中缀表达式转化为后缀表达式...
直接用stack模拟即可...
'('		push
'+','-'	当top为'*','/',pop
		如果top为'+','-',pop
'*','/'	如果top为'*','/',pop
')'		当top不为'(',pop
		把'('也pop掉
是数字直接输出即可...
*/

#include<iostream>
#include<stack>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int dataset;
	char s[20];
	scanf("%d",&dataset);gets(s);gets(s);
	while(dataset--)
	{
		stack<char> sc;
		while(gets(s) && s[0])
		{
			if( !isdigit(s[0]) )
			{
				if(s[0]==')')
				{
					while(sc.top()!='(')
						printf("%c",sc.top()),sc.pop();
					sc.pop();
					continue;
				}
				else if(s[0]=='*' || s[0]=='/')
				{
					if(!sc.empty() && (sc.top()=='*' || sc.top()=='/'))
						printf("%c",sc.top()),sc.pop();
				}
				else if(s[0]=='+' || s[0]=='-')		//注意一下这里
				{
					while(!sc.empty() && sc.top()!='+' && sc.top()!='-' && sc.top()!='(')
						printf("%c",sc.top()),sc.pop();
					if(!sc.empty() && (sc.top()=='+' || sc.top()=='-'))
						printf("%c",sc.top()),sc.pop();
				}
				sc.push(s[0]);
			}
			else
				printf("%s",s);
		}

		while(!sc.empty())
			printf("%c",sc.top()),sc.pop();
		putchar('\n');
		if(dataset)
			putchar('\n');
	}

	return 0;
}
