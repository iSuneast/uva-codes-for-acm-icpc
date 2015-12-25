/*
11508 - Life on Mars?

sort...
其实就是基数排序而已...
只是输入那边有点麻烦罢了...
*/

#include<iostream>
#include<sstream>
#include<string>
#define MAXN 100000
using namespace std;

string buf;
int num[MAXN+10],tmp[MAXN+10],cnt,tot;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	while(getline(cin,buf) && buf!="0")
	{
		stringstream sin(buf);
		int var,maxvar=-1;
		memset(num,-1,sizeof(num));
		bool no_ans=false;
		cnt=tot=0;
		while(sin>>var)
		{
			++tot;
			if(no_ans)
				continue;
			maxvar=max(maxvar,var);
			if(var>MAXN)
				no_ans=true;
			if(num[var]==-1)
				num[var]=0;
			else
				tmp[cnt++]=var;
		}
		if(no_ans || maxvar>=tot)
			puts("Message hacked by the Martians!!!");
		else
		{
			cnt=0;
			if(num[0]==-1)
				printf("%d",tmp[cnt++]);
			else
				putchar('0');
			for(int i=1;i<tot;++i)
				if(num[i]!=-1)
					printf(" %d",i);
				else
					printf(" %d",tmp[cnt++]);
			putchar('\n');
		}
	}

	return 0;
}
