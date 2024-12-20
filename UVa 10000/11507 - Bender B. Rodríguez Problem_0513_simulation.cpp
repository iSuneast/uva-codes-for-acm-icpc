/*
11507 - Bender B. Rodríguez Problem

simulation...
模拟题...
直接枚举即可
*/

#include<iostream>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int n;
	while(scanf("%d",&n)!=EOF && n)
	{
		char oper='+',point='x',next[10];
		for(int i=1;i<n;++i)
		{
			scanf("%s",next);
			if(!strcmp(next,"No"))
				continue;
			else if(point=='x')
			{
				point=next[1];
				if(oper=='+')
					oper=next[0];
				else
					oper=(next[0]=='-'?'+':'-');
			}
			else if(point=='y')
			{
				if(oper=='+')
				{
					if(!strcmp(next,"+y"))
						oper='-',point='x';
					else if(!strcmp(next,"-y"))
						oper='+',point='x';
				}
				else
				{
					if(!strcmp(next,"+y"))
						oper='+',point='x';
					else if(!strcmp(next,"-y"))
						oper='-',point='x';
				}
			}
			else if(point=='z')
			{
				if(oper=='+')
				{
					if(!strcmp(next,"+z"))
						oper='-',point='x';
					else if(!strcmp(next,"-z"))
						oper='+',point='x';
				}
				else
				{
					if(!strcmp(next,"+z"))
						oper='+',point='x';
					else if(!strcmp(next,"-z"))
						oper='-',point='x';
				}
			}
		}
		printf("%c%c\n",oper,point);
	}

	return 0;
}
