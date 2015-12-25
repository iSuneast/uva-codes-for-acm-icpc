/*
10408 - Farey sequences

brute force...
general all possible answer and sort
*/

#include<iostream>
#include<algorithm>
using namespace std;

struct Farey
{
	int a,b;
	bool operator<(const Farey &t)const
	{
		return a*t.b<b*t.a;
	}
}f[1000000];
int tot,n,k;

int gcd(int a,int b)
{
	return b==0?a:gcd(b,a%b);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	while(scanf("%d%d",&n,&k)!=EOF)
	{
		tot=0;
		f[tot].a=1;
		f[tot].b=1;
		++tot;
		for(int i=1;i<=n;++i)
		{
			for(int j=i+1;j<=n;++j)
				if(gcd(i,j)==1)
				{
					f[tot].a=i;
					f[tot].b=j;
					++tot;
				}
		}
		sort(f,f+tot);
		printf("%d/%d\n",f[k-1].a,f[k-1].b);
	}

	return 0;
}
