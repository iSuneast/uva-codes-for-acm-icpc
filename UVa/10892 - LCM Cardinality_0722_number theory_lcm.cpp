/*
10892 - LCM Cardinality

number theory...
lcm...
求lcm==n的数对个数
求出n的所有因子(除了1,n)
如果n为1,ans={ 1 | (1,1) }
如果因子数为0,n为素数,ans={ 2 | (1,n),(n,n) }
否则ans={ total+2 | (k,n) k为n因子}+{ 满足条件的数对 | lcm(a,b)==n }
*/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int gcd(int a,int b)
{
	return b==0?a:gcd(b,a%b);
}

int lcm(int a,int b)
{
	return a/gcd(a,b)*b;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int n;
	while(scanf("%d",&n)!=EOF && n)
	{
		vector<int> f;
		int i;
		for(i=2;i*i<n;++i)
			if(n%i==0)
			{
				f.push_back(n/i);
				f.push_back(i);
			}

		if(i*i==n)
			f.push_back(i);

		sort(f.begin(),f.end());

		if(n==1)
			puts("1 1");
		else if(!f.size())
			printf("%d 2\n",n);
		else
		{
			int sz=f.size();
			int key=sz+2;
			for(int i=0;i<sz;++i)
				for(int j=i;j<sz;++j)
					if(lcm(f[i],f[j])==n)
						++key;
			printf("%d %d\n",n,key);
		}
	}

	return 0;
}
