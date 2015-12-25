/*
160 - Factors and Factorials
*/

#include<iostream>

using namespace std;

int prime[110],ans[110][110],p=2,key[110],n;

void init()
{
	memset(ans,0,sizeof(ans));
	memset(key,0,sizeof(key));
	memset(prime,1,sizeof(prime));
	int i,j;
	for(i=2;i<101;i++)
		for(j=i;i*j<101;j++)
			prime[i*j]=0;
	for(i=2,j=0;i<101;i++)
		if(prime[i])
			prime[j++]=i;
}

void calc()
{
	for(;p<=n;p++)
	{
		int t=p,j=0;
		for(j=0;j<=key[p-1];j++)
			ans[p][j]=ans[p-1][j];
		j=0;
		while(t!=1)
			if(t%prime[j]==0)
			{
				t/=prime[j];
				ans[p][j]++;
			}
			else
				j++;
		key[p]=j>key[p-1]?j:key[p-1];
	}
}

int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);

	init();
	while(cin>>n && n)
	{
		printf("%3d! =",n);
		calc();
		for(int i=0;i<=key[n];i++)
		{
			if(i==15)
				cout<<endl<<"      ";
			printf("%3d",ans[n][i]);
		}
		cout<<endl;
	}

return 0;
}
