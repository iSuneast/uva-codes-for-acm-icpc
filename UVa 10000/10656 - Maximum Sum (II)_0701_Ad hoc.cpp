/*
10656 - Maximum Sum (II)

Ad hoc...
晕...看错题...
wa了好多次...
今天的ac率好低啊...

求的是子序列
所以只要输出所有正数就可以了...
*/

#include<iostream>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int var,n;
	while(scanf("%d",&n)!=EOF && n)
	{
		bool first=true;
		for(int i=0;i<n;++i)
		{
			scanf("%d",&var);
			if(var)
			{
				if(!first)
					putchar(' ');
				first=false;
				printf("%d",var);
			}
		}
		if(first)
			printf("0");
		putchar('\n');
	}

	return 0;
}
