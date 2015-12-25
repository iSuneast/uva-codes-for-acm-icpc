#include<iostream>

using namespace std;

int n,prime[50],a[20],flag[20];

void dfs(int cur)
{
	int i;
	if(cur==n&&prime[a[0]+a[n-1]])
	{
		cout<<a[0];
		for(i=1;i<n;i++)
			cout<<' '<<a[i];
		cout<<endl;
	}
	else for(i=2;i<=n;i++)
		if(!flag[i]&&prime[i+a[cur-1]])
			a[cur]=i,
			flag[i]=1,
			dfs(cur+1),
			flag[i]=0;
}

int main()
{//	freopen("in.txt","r",stdin);
	int cas=1,end=0;
	memset(prime,0,sizeof(prime));
	memset(flag,0,sizeof(flag));
	prime[2]=prime[3]=prime[5]=prime[7]=
		prime[11]=prime[13]=prime[17]=prime[19]=
		prime[23]=prime[29]=prime[31]=prime[37]=1;
	a[0]=1;
	
	while(cin>>n)
	{
		if(end)
			cout<<endl;
		cout<<"Case "<<cas++<<':'<<endl,dfs(1);
		end=1;
	}

return 0;
}
