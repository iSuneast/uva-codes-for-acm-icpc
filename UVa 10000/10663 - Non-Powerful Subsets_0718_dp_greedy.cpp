/*
10663 - Non-Powerful Subsets

greedy...
dp...
knapsack...
求一个区间的子集,是的这个自己里面的任意元素的组合不会产生完全数
贪心思想

先对(1+1000)*1000/2范围的元素进行筛法,把完全数筛掉
然后对任意起点x,从x开始枚举x的下一个元素y
如果y和之前的集合不会产生完全数则加入y
判断集合是否产生完全数可以用背包解决

数据规模比较大
直接冲[x,1000]打表然后输出即可
*/

#include<iostream>
#define MAXN 500510
using namespace std;

bool flag[MAXN];
int key[1010][100],tot,a,b,sz[1010];
bool dp[MAXN];

void output(int p)
{
	printf("%d",key[p][0]);
	for(int i=1;i<sz[p] && key[p][i]<=b;++i)
		printf(" %d",key[p][i]);
	putchar('\n');
}

bool chk(int var)
{
	for(int j=tot;j>=0;--j)
		if(dp[j])
			if(flag[j+var])
				return false;
	return true;
}

void insert(int p,int var)
{
	key[p][ sz[p]++ ]=var;
	for(int j=tot;j>=0;--j)
		if(dp[j])
			dp[j+var]=true;
	tot+=var;
}

void init()
{
	memset(flag,0,sizeof(flag));
	for(int i=2;i<708;++i)
		if(!flag[i])
		{
			int t=i*i;
			while(t<MAXN)
			{
				flag[t]=true;
				t*=i;
			}
		}

	for(int i=1;i<=1000;++i)
	{
		sz[i]=0;
		if(!flag[i])
		{
			memset(dp,0,sizeof(dp));
			dp[0]=true;		tot=0;
			for(int j=i;j<=1000;++j)
				if(!flag[j])
					if(chk(j))
						insert(i,j);
		}
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	init();
	while(scanf("%d%d",&a,&b)!=EOF)
	{
		bool got=false;
		for(int i=a;i<=b && !got;++i)
			if(sz[i])
			{
				output(i);
				got=true;
			}
		if(!got)
			putchar('\n');
	}

	return 0;
}
