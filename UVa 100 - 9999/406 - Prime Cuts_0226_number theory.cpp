/*
406 - Prime Cuts
*/

#include<iostream>
#include<algorithm>

using namespace std;

int prime[1010],cnt=0;

void init()
{
	memset(prime,1,sizeof(prime));
	prime[cnt++]=1;
	for(int i=2;i<1010;i++)
	{
		if(prime[i])
			prime[cnt++]=i;
		for(int j=i*i;j<1010;j+=i)
			prime[j]=0;
	}
}

int main()
{
//	freopen("in.txt","r",stdin);
	init();
	int n,c,k;
	while(cin>>n>>c)
	{
		cout<<n<<' '<<c<<':';
		int *p=upper_bound(prime,prime+cnt,n);
		k=p-prime;
		c*=2;
		if(k%2)
			c--;
		k=(k-c)/2;
		if(k<0)
		{
			k=0;
			c=p-prime;
		}
		while(c--)
			cout<<' '<<prime[k++];
		cout<<endl<<endl;
	}

return 0;
}
