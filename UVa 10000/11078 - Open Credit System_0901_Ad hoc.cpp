/*
11078 - Open Credit System

Ad hoc...
for variable var[]
we are to calculate to maximum value of var[i]-var[j] (i<j)
if we scan from the end to begin of the array
we will get the minimum value of var[] from j->n-1 O(1)
then max(var[i]-minimum) is the answer
*/

#include<iostream>
#define MAXN 100003
using namespace std;
const int INF=0x3f3f3f3f;

int var[MAXN],n;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int dataset;
	scanf("%d",&dataset);
	while(dataset--)
	{
		scanf("%d",&n);
		for(int i=0;i<n;++i)
		{
			scanf("%d",&var[i]);
		}
		int mini=var[n-1],key=-INF;
		for(int i=n-2;i>=0;--i)
		{
			key=max(key,var[i]-mini);
			mini=min(mini,var[i]);
		}
		printf("%d\n",key);
	}

	return 0;
}
