/*
11689 - Soda Surpler

math...
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
		int e,f,c;
		scanf("%d%d%d",&e,&f,&c);
		int key=0;
		f+=e;
		while(f>=c)
		{
			key+=f/c;
			f=f/c+f%c;
		}
		printf("%d\n",key);
	}

	return 0;
}
