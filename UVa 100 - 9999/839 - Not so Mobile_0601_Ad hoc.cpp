/*
839 - Not so Mobile

Ad hoc...
dfs的策略果然是正确的...
递归的东西就用该dfs来...
*/

#include<iostream>
using namespace std;

bool eq;

int dfs(int wl,int dl,int wr,int dr)
{
	if(!wl)
	{
		int twl,tdl,twr,tdr;
		scanf("%d%d%d%d",&twl,&tdl,&twr,&tdr);
		wl=dfs(twl,tdl,twr,tdr);
	}
	if(!wr)
	{
		int twl,tdl,twr,tdr;
		scanf("%d%d%d%d",&twl,&tdl,&twr,&tdr);
		wr=dfs(twl,tdl,twr,tdr);
	}
	if(wl*dl!=wr*dr)
		eq=false;
	return wl+wr;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int dataset;
	scanf("%d",&dataset);
	while(dataset--)
	{
		int wl,dl,wr,dr;
		scanf("%d%d%d%d",&wl,&dl,&wr,&dr);
		eq=true;
		dfs(wl,dl,wr,dr);
		if(eq)
			puts("YES");
		else
			puts("NO");
		if(dataset)
			putchar('\n');
	}

	return 0;
}
