/*
200 - Rare Order

toposort...
不懂之前为什么还RE了一次...
*/

#include<iostream>
#define MAXN 30
using namespace std;

int g[MAXN][MAXN],flag[MAXN],cnt=0;
char topo[MAXN];

void dfs(int u)
{
	flag[u]=0;
	for(int v=0;v<MAXN;++v)
		if(g[u][v] && flag[v])
			dfs(v);
	topo[--cnt]='A'+u;
}

int main()
{
	freopen("in.txt","r",stdin);
//
	char buf[2][MAXN];
	int p=-1,i,l;
	cin>>buf[p=(p+1)%2];
	l=strlen(buf[p]);
	for(i=0;i<l;++i)
		if(!flag[buf[p][i]-'A'])
			flag[buf[p][i]-'A']=1,++cnt;
	while(cin>>buf[p=(p+1)%2] && strcmp(buf[p],"#"))
	{
		for(i=0;i<MAXN;++i)
			if(buf[0][i]!=buf[1][i])
			{
				if(buf[0][i] && buf[1][i])
				{
					if(p)
						g[buf[0][i]-'A'][buf[1][i]-'A']=1;
					else
						g[buf[1][i]-'A'][buf[0][i]-'A']=1;
				}
				break;
			}
		l=strlen(buf[p]);
		for(i=0;i<l;++i)
			if(!flag[buf[p][i]-'A'])
				flag[buf[p][i]-'A']=1,++cnt;
	}
	for(i=0;i<MAXN;++i)
		if(flag[i])
			dfs(i);
	cout<<topo<<endl;

	return 0;
}
