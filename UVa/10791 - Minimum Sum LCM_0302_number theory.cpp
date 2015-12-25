/*
10791 - Minimum Sum LCM

还是得到一个结论.
考虑问题一定要全面.
诸如2^31-1之类的数据一定要考虑溢出.
素数判断一定要考虑n==2的情况.
*/

#include<iostream>
#include<cmath>

using namespace std;

bool isprime(long long n)
{
	if(n==2)
		return true;
	int t=sqrt(n)+1;
	for(long long i=2;i<=t;i++)
		if(n%i==0)
			return false;
	return true;
}

int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("10791.txt","w",stdout);

	long long n,cas=1;
	while(cin>>n &&n)
	{
		long long ans=0,i=2,t,cnt=0;
		if(isprime(n))
			ans=n+1;
		else do
		{
			t=1;
			while(n!=1 && n%i==0)
			{
				t*=i;
				n/=i;
			}
			i++;
			if(t!=1)
			{
				cnt++;	//考虑一下2*2*2=8,3*3=9的情况.就会发现这种情况得出的解和n一样.
				ans+=t;
			}
		}while(n!=1);
		if(cnt==1)
			ans++;
		cout<<"Case "<<cas++<<": "<<ans<<endl;
	}

return 0;
}
