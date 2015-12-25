/*
103 - Stacking Boxes
*/

#include<iostream>
#include<algorithm>

using namespace std;

int n,k,hash[35],box[35][12],g[35][35],d[35];

bool belong(int a,int b)
{
	for(int i=0;i<k;i++)
		if(box[a][i]>=box[b][i])
			return false;
	return true;
}

int dp(int i)
{
	if(d[i])
		return d[i];
	d[i]=1;
	for(int j=0;j<n;j++)
		if(g[i][j])
		{
			int t=dp(j)+1;
			d[i]=d[i]>t?d[i]:t;
		}
	return d[i];
}

void print(int i)
{
	for(int j=0;j<n;j++)
		if(g[i][j] && d[i]==d[j]+1)
		{
			cout<<' '<<j+1;
			print(j);
			return ;
		}
}

int main()
{
//	freopen("in.txt","r",stdin);
	while(cin>>n>>k)
	{
		int i,j;
		memset(g,0,sizeof(g));
		memset(d,0,sizeof(d));
		for(i=0;i<n;i++)
		{
			for(j=0;j<k;j++)
				cin>>box[i][j];
			sort(box[i],box[i]+k);
			if(i)
				for(j=0;j<i;j++)
				{
					if(box[i][0]<box[j][0] && belong(i,j))
						g[i][j]=1;
					else if(box[i][0]>=box[j][0] && belong(j,i))
						g[j][i]=1;
				}
		}
		for(j=i=0;i<n;i++)
		{
			dp(i);
			if(i)
				j=d[j]>d[i]?j:i;
		}
		cout<<d[j]<<endl<<j+1;
		print(j);
		cout<<endl;
	}

return 0;
}
