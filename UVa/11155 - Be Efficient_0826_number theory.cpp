/*
11155 - Be Efficient

number theory...

we got the function from the problem description
	x[i]=(x[i-1]*b+c)%m+1;
let sum=sum(x[0,i]) , ++mod[ sum%m ]
we know that if mod[k]>2, then the number of key section
	=mod[k]*(mod[k]-1)/2	(k<m)

you should also notice that the empty set is also verify
so a set consider as {},its sum is 0.
*/

#include<iostream>
#define MAXN 10003
using namespace std;

int a,b,c,m,n,x[MAXN],sum,mod[MAXN];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int dataset;
	scanf("%d",&dataset);
	for(int cas=1;cas<=dataset;++cas)
	{
		scanf("%d%d%d%d%d",&a,&b,&c,&m,&n);
		memset(mod,0,sizeof(mod));
		x[0]=a;
		sum=x[0];
		mod[ sum%=m ]++;
		mod[0]++;

		for(int i=1;i<n;++i)
		{
			x[i]=(x[i-1]*b+c)%m+1;
			sum=(sum+x[i])%m;
			mod[sum]++;
		}

		int key=0;
		for(int i=0;i<m;++i)
		{
			if(mod[i])
				key+=mod[i]*(mod[i]-1)/2;
		}

		printf("Case %d: %d\n",cas,key);
	}

	return 0;
}
