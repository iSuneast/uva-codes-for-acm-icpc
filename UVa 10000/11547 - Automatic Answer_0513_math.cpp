/*
11547 - Automatic Answer

math...
直接退出通式即可...
*/

#include<iostream>
#include<cmath>
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
		printf("%d\n",abs((315*n+36962)%100/10));
	}

	return 0;
}
