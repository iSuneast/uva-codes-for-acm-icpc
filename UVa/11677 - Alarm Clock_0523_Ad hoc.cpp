/*
11677 - Alarm Clock

Ad hoc...
水题...
算时间差...
直接转化为分钟算一下差值即可
*/

#include<iostream>
using namespace std;
typedef pair<int,int> pii;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	pii s,e;
	while(scanf("%d%d%d%d",&s.first,&s.second,&e.first,&e.second)!=EOF 
		&& (s.first || s.second || e.first || e.second))
	{
		int st=s.first*60+s.second;
		int end=e.first*60+e.second;
		if(st>end)
			printf("%d\n",end-st+24*60);
		else
			printf("%d\n",end-st);
	}

	return 0;
}
