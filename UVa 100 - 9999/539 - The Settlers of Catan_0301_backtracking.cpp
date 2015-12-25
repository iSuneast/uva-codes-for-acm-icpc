/*
539 - The Settlers of Catan
*/

#include<iostream>

using namespace std;
int n,m,g[30][30],ans;
//�Ǹ�,��ĿҪ����㿴.
void dfs(int p,int cur)
{
	for(int i=0;i<n;i++)	//�Ǳ߼�,���ǵ㼯
		if(g[p][i])
		{
			g[p][i]=g[i][p]=0;
			dfs(i,cur+1);
			g[p][i]=g[i][p]=1;
		}
	ans=ans>cur?ans:cur;
}

int main()
{
//	freopen("in.txt","r",stdin);

	while(cin>>n>>m && (n||m))
	{
		int i,x,y;
		memset(g,0,sizeof(g));
		for(i=0;i<m;i++)
		{
			cin>>x>>y;
			g[x][y]=g[y][x]=1;
		}
		ans=0;
		for(i=0;i<n;i++)
			dfs(i,0);
		cout<<ans<<endl;
	}

return 0;
}
