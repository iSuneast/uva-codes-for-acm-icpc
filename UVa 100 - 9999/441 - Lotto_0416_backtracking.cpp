/*
441 - Lotto

backtracking...
求子集...
完美の一Y...
*/

#include<iostream>
#define MAXN 15
using namespace std;

int n,var[MAXN],flag[MAXN];
bool done[1<<13];

void dfs(int cur,int v)
{
	if(cur==6)
	{
		if(done[v])
			return ;
		bool first=true;
		int key=0;
		for(int i=0;i<n;++i)
			if(flag[i])
			{
				key+=(1<<i);
				if(first)
					first=false;
				else
					putchar(' ');
				printf("%d",var[i]);
			}
		putchar('\n');
		done[v]=true;
		return ;
	}
	else for(int i=cur;i<n;++i)
		if(!flag[i])
		{
			flag[i]=1;
			dfs(cur+1,v+(1<<i));
			flag[i]=0;
		}
}

int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("441.txt","w",stdout);

	bool first=true;
	while(cin>>n && n)
	{
		if(first)
			first=false;
		else
			putchar('\n');
		for(int i=0;i<n;++i)
			scanf("%d",&var[i]);
		memset(done,0,sizeof(done));
		dfs(0,0);
	}

	return 0;
}
