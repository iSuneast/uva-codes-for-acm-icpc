/*
10946 - You want what filled?
*/

#include<iostream>
#include<algorithm>

using namespace std;

char mat[60][60],cnt;

struct answer
{
	int n;
	char c;
}ans[3000];

void dfs(int i,int j,char c)
{
	if(mat[i][j]!=c)
		return ;
	mat[i][j]='.';
	cnt++;
	dfs(i+1,j,c);
	dfs(i-1,j,c);
	dfs(i,j+1,c);
	dfs(i,j-1,c);
}

int cmp(const answer a,const answer b)
{
	if(a.n==b.n)
		return a.c<b.c;
	return a.n>b.n;
}

int main()
{
//	freopen("in.txt","r",stdin);

	int x,y,i,j,n,cas=1;
	while(cin>>x>>y&&(x||y))
	{
		memset(mat,0,sizeof(mat));
		n=0;
		for(i=1;i<=x;i++)
			for(j=1;j<=y;j++)
				cin>>mat[i][j];
		for(i=1;i<=x;i++)
			for(j=1;j<=y;j++)
				if(mat[i][j]!='.')
					ans[n].c=mat[i][j],
					cnt=0,dfs(i,j,mat[i][j]),
					ans[n++].n=cnt;
		sort(ans,ans+n,cmp);
		cout<<"Problem "<<cas++<<":"<<endl;
		for(i=0;i<n;i++)
			cout<<ans[i].c<<' '<<ans[i].n<<endl;
	}

return 0;
}
