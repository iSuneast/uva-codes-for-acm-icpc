/*
11777 - Automate the Grades

Ad hoc..
估计做这题的要使不小心一定WA个半死...
*/

#include<iostream>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int dataset,var[7];
	scanf("%d",&dataset);
	for(int cas=1;cas<=dataset;++cas)
	{
		for(int i=0;i<7;++i)
			scanf("%d",var+i);
		sort(var+4,var+7);
		int key=(var[5]+var[6])/2;
		for(int i=0;i<4;++i)
			key+=var[i];
		if(key>=90)
			printf("Case %d: A\n",cas);
		else if(key>=80)
			printf("Case %d: B\n",cas);
		else if(key>=70)
			printf("Case %d: C\n",cas);
		else if(key>=60)
			printf("Case %d: D\n",cas);
		else
			printf("Case %d: F\n",cas);		//是F不是E.= =
	}

	return 0;
}
