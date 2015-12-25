/*
10305 - Ordering Tasks
...
topsort
...
û��Ū������..
*/

#include<iostream>

using namespace std;

int n,m,g[110][110],topo[110],c[110],t;

bool dfs(int u)
{
	c[u]=-1;			//��ʾ���ڷ���
	for(int v=1;v<=n;v++)
		if(g[u][v] && (c[v]<0 || (!c[v] && !dfs(v))))
			return false;
	c[u]=1;				//��ʾ���ʽ���
	topo[--t]=u;
	return true;
}

void topsort()
{	
	memset(topo,0,sizeof(topo));
	memset(c,0,sizeof(c));			//����ڵ��Ƿ���ʹ�
	t=n;
	for(int i=1;i<=n;i++)
		if(!c[i])
			dfs(i);
}

int main()
{
//	freopen("in.txt","r",stdin);
	int i,x,y;
	while(cin>>n>>m && (n||m))
	{
		memset(g,0,sizeof(g));
		while(m--)
			cin>>x>>y,
			g[x][y]=1;
		topsort();
		cout<<topo[0];
		for(i=1;i<n;i++)
			cout<<' '<<topo[i];
		cout<<endl;
	}

return 0;
}
