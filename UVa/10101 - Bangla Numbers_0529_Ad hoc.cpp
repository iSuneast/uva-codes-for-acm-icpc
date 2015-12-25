/*
10101 - Bangla Numbers

Ad hoc..
注意题目没有说n=0的时候是结束条件...
直接对n递归搜索就可以了...
*/

#include<iostream>
using namespace std;

void dfs(long long n,int dep)
{
	if(!n)
	{
		if(!dep)
			printf(" 0");
	}
	else if(!dep)
	{
		dfs(n/100,dep+1);
		if(n%100)
			printf(" %d",n%100);
	}
	else if(dep%4==1)
	{
		dfs(n/10,dep+1);
		if(n%10)
			printf(" %d shata",n%10);
	}
	else if(dep%4==2)
	{
		dfs(n/100,dep+1);
		if(n%100)
			printf(" %d hajar",n%100);
	}
	else if(dep%4==3)
	{
		dfs(n/100,dep+1);
		if(n%100)
			printf(" %d lakh",n%100);
	}
	else
	{
		dfs(n/100,dep+1);
		if(n%100)
			printf(" %d kuti",n%100);
		else if(n/100)	//这句话要输出
			printf(" kuti");
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	long long n;
	int cas=1;
	while(scanf("%lld",&n)!=EOF)
	{
		printf("%4d.",cas++);
		dfs(n,0);
		putchar('\n');
	}

	return 0;
}
