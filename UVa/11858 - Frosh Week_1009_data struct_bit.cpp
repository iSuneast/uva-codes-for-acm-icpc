/*
11858 - Frosh Week

data struct...
BIT...
use Binary Indexed Tree to solve it...
for example
{3 1 2}
we know {3} is in front of {1}, +1
delete {1} from the list, we got {3 2}
{3} is in front of {2}, +1
delete {2} from the list, we got {3}
none is in front of 3, +0

so the final answer is +1+1+0=2
*/

#include<iostream>
#include<algorithm>
#define MAXN 1000003
using namespace std;

struct DATA
{
	int var,pos;
	bool operator<(const DATA &t)const
	{
		return var<t.var;
	}
}data[MAXN];
int n,s[MAXN];

int lowbit(int var)
{
	return var&(-var);
}

void insert(int p,int var)
{
	for(;p<=n;p+=lowbit(p))
		s[p]+=var;
}

int sum(int p)
{
	int key=0;
	for(;p;p-=lowbit(p))
		key+=s[p];
	return key;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	while(scanf("%d",&n)!=EOF)
	{
		memset(s,0,sizeof(s));
		for(int i=1;i<=n;++i)
		{
			insert(i,1);
			scanf("%d",&data[i].var);
			data[i].pos=i;
		}
		sort(data+1,data+n+1);

		long long key=0;
		for(int i=1;i<=n;++i)
		{
			key+=sum(data[i].pos-1);
			insert(data[i].pos,-1);
		}

		printf("%lld\n",key);
	}
	
	return 0;
}
