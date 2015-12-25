/*
574 - Sum It Up

brute force...
暴力枚举全集
排序
删重
输出
*/

#include<iostream>
#include<algorithm>
#define MAXN 12
using namespace std;

struct ANS
{
	int var[MAXN],cnt;
	bool operator<(const ANS &t)const
	{
		for(int i=0;i<MAXN;++i)
			if(var[i]!=t.var[i])
				return var[i]>t.var[i];
		return cnt<t.cnt;
	}
}key[1<<MAXN];

int cmp(const int a,const int b)
{
	return a>b;
}

int var[MAXN],tmp[MAXN];
int s,n;

bool array_cmp(ANS a,ANS b)
{
	if(a.cnt==b.cnt)
	{
		for(int i=0;i<a.cnt;++i)
			if(a.var[i]!=b.var[i])
				return true;
		return false;
	}
	return a.cnt!=b.cnt;
}

void out(int cnt)
{
	for(int j=0;j<key[0].cnt;++j)
	{
		if(j)
			putchar('+');
		printf("%d",key[0].var[j]);
	}
	putchar('\n');

	for(int i=1;i<cnt;++i)
		if(array_cmp(key[i-1],key[i]))
		{
			for(int j=0;j<key[i].cnt;++j)
			{
				if(j)
					putchar('+');
				printf("%d",key[i].var[j]);
			}
			putchar('\n');
		}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	while(scanf("%d%d",&s,&n)!=EOF && (n||s))
	{
		printf("Sums of %d:\n",s);
		for(int i=0;i<n;++i)
			scanf("%d",var+i);

		memset(key,0,sizeof(key));

		int cnt=0;
		for(int i=0;i<(1<<n);++i)
		{
			int t=0,p=0;
			for(int j=0;j<n;++j)
				if(i&(1<<j))
				{
					t+=var[j];
					key[cnt].var[p++]=var[j];
				}
			if(t==s && p)
			{
				key[cnt].cnt=p;
				for(int j=p;j<MAXN;++j)
					key[cnt].var[j]=0;
				sort(key[cnt].var,key[cnt].var+key[cnt].cnt,cmp);
				++cnt;
			}
		}

		if(!cnt)
			puts("NONE");
		else
		{
			sort(key,key+cnt);
			out(cnt);
		}
	}

	return 0;
}
