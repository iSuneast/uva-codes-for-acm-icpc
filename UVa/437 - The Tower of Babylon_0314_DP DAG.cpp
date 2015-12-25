/*
437 - The Tower of Babylon

DAG模型...
*/

#include<iostream>
#define MAXN 100
using namespace std;

int flag[MAXN][MAXN],n,ls[3][MAXN],d[MAXN],ans;

int dp(int p)
{
	if(d[p])
		return d[p];
	for(int i=0;i<3*n;i++)
		if(flag[p][i])
		{
			int t=dp(i)+ls[2][i];
			d[p]=d[p]>t?d[p]:t;
		}
	return d[p];
}

int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("437.txt","w",stdout);

	int i,j,k,p,t,cas=1;
	while(cin>>n && n)
	{
		memset(flag,0,sizeof(flag));
		for(i=0;i<n;i++)
		{
			p=i*3;
			for(j=0;j<3;j++)
				cin>>ls[j][p];
			if(ls[0][p]>ls[1][p])
				swap(ls[0][p],ls[1][p]);
			++p;
			ls[2][p]=ls[1][p-1];
			ls[1][p]=ls[0][p-1];
			ls[0][p]=ls[2][p-1];
			if(ls[0][p]>ls[1][p])
				swap(ls[0][p],ls[1][p]);
			++p;
			/*----------
  晕,竟然在这里有个不起眼的BUG...还真的难找.
  下面的值应该更新为ls[0][p-2]而不是ls[0][p-1].
  所以,以后没事最好不要copy代码...
			----------*/
			ls[2][p]=ls[0][p-2];
			ls[1][p]=ls[2][p-2];
			ls[0][p]=ls[1][p-2];
			if(ls[0][p]>ls[1][p])
				swap(ls[0][p],ls[1][p]);
			p=i*3;
			for(k=0;k<3;++k,++p)
				for(j=0;j<p;j++)
					if(ls[0][j]<ls[0][p] && ls[1][j]<ls[1][p])
						flag[j][p]=1;
					else if(ls[0][j]>ls[0][p] && ls[1][j]>ls[1][p])
						flag[p][j]=1;
		}
		ans=0;
		for(i=0;i<n*3;i++)
		{
			memset(d,0,sizeof(d));
			t=dp(i)+ls[2][i];
			if(t>ans)
				ans=t;
		}
		cout<<"Case "<<cas++<<": maximum height = "<<ans<<endl;
	}

return 0;
}
