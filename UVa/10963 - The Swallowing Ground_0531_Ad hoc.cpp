/*
10963 - The Swallowing Ground

Ad hoc...
好久没做到这么水的题目了..
*/

#include<iostream>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int dataset,n;
	scanf("%d",&dataset);
	while(dataset--)
	{
		scanf("%d",&n);
		bool bk=false;
		int dis,a,b;
		for(int i=0;i<n;++i)
		{
			scanf("%d%d",&a,&b);
			if(!i)
				dis=a-b;
			else if(dis!=a-b)
				bk=true;
		}
		if(bk)
			puts("no");
		else
			puts("yes");
		if(dataset)
			putchar('\n');
	}

	return 0;
}
