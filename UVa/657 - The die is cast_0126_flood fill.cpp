/*
657 - The die is cast
*/

#include<iostream>
#include<algorithm>

using namespace std;

char mat[100][100],flag[100][100];
int ans[100],t,w,h;

int cmp(const int a,const int b)
{
	return a<b;
}

void dfsx(int i,int j)
{
	if(flag[i][j]||mat[i][j]!='X')
		return ;
	flag[i][j]=1;
	dfsx(i,j+1);
	dfsx(i,j-1);
	dfsx(i+1,j);
	dfsx(i-1,j);
}

void dfs(int i,int j)
{
	if((mat[i][j]!='*')&&(mat[i][j]!='X'))
		return;
	if(!flag[i][j]&&(mat[i][j]=='X'))
		t++,dfsx(i,j);
		mat[i][j]='.';
		dfs(i,j+1);
		dfs(i,j-1);
		dfs(i+1,j);
		dfs(i-1,j);
}

int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("657.txt","w",stdout);

	int cas=1,i,j,p;
	while(cin>>h>>w&&w&&h)
	{
		memset(mat,0,sizeof(mat));
		memset(flag,0,sizeof(flag));
		p=0;
		for(i=1;i<=w;i++)
			for(j=1;j<=h;j++)
				cin>>mat[i][j];
		for(i=1;i<=w;i++)
			for(j=1;j<=h;j++)
				if(mat[i][j]=='*'||mat[i][j]=='X')
				{
					t=0,dfs(i,j);
					if(t)
						ans[p++]=t;
				}
		sort(ans,ans+p,cmp);
		cout<<"Throw "<<cas++<<endl;
		if(p)
		{
			cout<<ans[0];
			for(i=1;i<p;i++)
				cout<<' '<<ans[i];
			cout<<endl;
		}
		cout<<endl;
	}

return 0;
}
