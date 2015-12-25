/*
10336 - Rank the Languages
*/

#include<iostream>
#include<algorithm>

using namespace std;

int w,h,cnt;
char mat[1000][1000];

struct world
{
	int n;
	char lang;
}ans[30];

void print()
{
	int i,j;
	for(i=1;i<=w;i++)
	{
		for(j=1;j<=h;j++)
			cout<<mat[i][j];
		cout<<endl;
	}
}

void dfs(int i,int j,char c)
{
	if(mat[i][j]!=c)
		return ;
	mat[i][j]=0;
	dfs(i+1,j,c);
	dfs(i-1,j,c);
	dfs(i,j+1,c);
	dfs(i,j-1,c);
}

void add(char c)
{
	int i;
	for(i=0;i<cnt;i++)
		if(ans[i].lang==c)
		{
			ans[i].n++;
			return ;
		}
	ans[cnt].lang=c;
	ans[cnt++].n++;
}

int cmp(const world a,const world b)
{
	if(a.n==b.n)
		return a.lang<b.lang;
	return a.n>b.n;
}

int main()
{
//	freopen("in.txt","r",stdin);
	int cas=1,i,j,n;
	cin>>n;
	while(n--)
	{
		memset(mat,0,sizeof(mat));
		memset(ans,0,sizeof(ans));
		cnt=0;
		cin>>w>>h;
		for(i=1;i<=w;i++)
			for(j=1;j<=h;j++)
				cin>>mat[i][j];
		for(i=1;i<=w;i++)
			for(j=1;j<=h;j++)
				if(mat[i][j])
					add(mat[i][j]),
					dfs(i,j,mat[i][j]);
		sort(ans,ans+cnt,cmp);
		cout<<"World #"<<cas++<<endl;
		for(i=0;i<cnt;i++)
			cout<<ans[i].lang<<": "<<ans[i].n<<endl;
	}

return 0;
}
