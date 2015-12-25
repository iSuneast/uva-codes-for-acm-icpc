/*
10365 - Blocks

Ad hoc...
n = length * width * height
s = 2 * ( length * width + width * height + length * height )

happy coding...
*/

#include<iostream>
using namespace std;
const int INF=0x3f3f3f3f;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int dataset,n;
	scanf("%d",&dataset);
	while(dataset--)
	{
		scanf("%d",&n);
		int key=INF;
		for(int i=1;i<=n;++i)
		{
			if(n%i)
				continue;
			int n1=n/i;
			for(int j=i;j<=n1;++j)
			{
				if(n1%j)
					continue;
				int n2=n1/j;
				for(int k=j;k<=n2;++k)
				{
					if(n2%k)
						continue;
					key=min(key, 2*( i*j + i*n2 + j*n2 ));
				}
			}
		}

		printf("%d\n",key);
	}


	return 0;
}
