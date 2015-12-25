/*
11063 - B2-Sequence

brute force...

1. check 1 ¡Ü b1 < b2 < ...
2. brute force enum b[i]+b[j] ,check whether it exist...
*/

#include<iostream>
using namespace std;
const int MAXN=20003;
const int INF=0x3f3f3f3f;
const double eps=1e-9;

int n,var[103];
bool flag[MAXN];

bool chk()
{
	memset(flag,0,sizeof(flag));
	for(int i=1;i<=n;++i)
	{
		if(var[i-1]>=var[i])
			return false;
		for(int j=1;j<=i;++j)
			if(!flag[ var[j]+var[i] ])
				flag[ var[j]+var[i] ]=true;
			else
				return false;
	}
	return true;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int cas=1;
	while(scanf("%d",&n)!=EOF)
	{
		var[0]=0;
		for(int i=1;i<=n;++i)
		{
			scanf("%d",&var[i]);
		}
		printf("Case #%d: It is %sa B2-Sequence.\n\n",cas++,chk()?"":"not ");
	}

	return 0;
}
