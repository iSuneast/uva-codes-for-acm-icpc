/*
10015 - Joseph's Cousin

number theory...
经典的约瑟夫问题...
直接模拟即可不会TLE...
*/

#include<iostream>
#define MAXN 3550
#define MAXPRIME 40000
using namespace std;

int prime[MAXPRIME],cnt,var[MAXN];

void init()
{
	prime[cnt++]=2;
	for(int i=3;i<MAXPRIME;i+=2)
		if(prime[i]==0)
		{
			prime[cnt++]=i;
			for(int j=i+i;j<MAXPRIME;j+=i)
				prime[j]=1;
		}
}

void remove(int p,int sz)
{
	for(int i=p;i<sz-1;++i)
		var[i]=var[i+1];
}

int main()
{
//	freopen("in.txt","r",stdin);

	init();
	int n,i,p;
	while(cin>>n && n)
	{
		for(i=0;i<n;++i)
			var[i]=i+1;
		p=-1;
		for(i=0;i<n-1;++i)
		{
			p=(p+prime[i])%(n-i);
			remove(p,n-i);
			--p;
		}
		cout<<var[0]<<endl;
	}

	return 0;
}
