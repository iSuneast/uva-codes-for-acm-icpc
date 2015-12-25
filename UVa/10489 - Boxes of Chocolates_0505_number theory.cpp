/*
10489 - Boxes of Chocolates

number theory...
计算过程要步步求余...
避免溢出...
*/

#include<iostream>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int dataset;
	scanf("%d",&dataset);
	while(dataset--)
	{
		int n,b,k,ans=0;
		scanf("%d%d",&n,&b);
		for(int i=0;i<b;++i)
		{
			scanf("%d",&k);
			int key=1,var;
			while(k--)
			{
				scanf("%d",&var);
				key=key*var%n;
			}
			ans+=key;
		}
		printf("%d\n",ans%n);
	}

	return 0;
}
