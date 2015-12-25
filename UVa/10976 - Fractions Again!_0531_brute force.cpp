/*
10976 - Fractions Again?!

brute force...
一直枚举到2*k就可以了...
dfs可以直接搞定...
*/

#include<iostream>
using namespace std;

int cnt,k;

void dfs(int cur)
{
	if(cur==k)
		printf("%d\n",cnt);
	else
	{
		int t1=cur-k,t2=cur*k;
		if(t2%t1==0)
		{
			++cnt;
			dfs(cur-1);
			printf("1/%d = 1/%d + 1/%d\n",k,t2/t1,cur);
		}
		else
			dfs(cur-1);
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	while(scanf("%d",&k)!=EOF)
	{
		cnt=0;
		dfs(k*2);
	}

	return 0;
}
