/*
10567 - Helping Fill Bates

b_search...
对字符串里面的元素排序,并记录初始位置
然后从ss开始,去排好序的字符串里面找字符
记录下当前找到的字符的有效位置
每个字符的有效位置必须严格递增
*/

#include<iostream>
#include<algorithm>
#define MAXN 1000010
#define MAXLEN 110
using namespace std;

struct DATA
{
	char c;
	int p;
	bool operator<(const DATA &t)const
	{
		if(c==t.c)
			return p<t.p;
		return c<t.c;
	}
}data[MAXN];
int l,q;
char s[MAXN],ss[MAXLEN];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	while(scanf("%s",s)!=EOF)
	{
		for(l=0;s[l];++l)
		{
			data[l].c=s[l];
			data[l].p=l;
		}
		sort(data,data+l);

		scanf("%d",&q);
		while(q--)
		{
			scanf("%s",ss);
			int len=0,s=-1;
			DATA cur;
			bool bk=false;
			cur.p=0;
			while(ss[len] && !bk)
			{
				cur.c=ss[len++];
				int p=lower_bound(data,data+l,cur)-data;
				if(data[p].c!=cur.c)
					bk=true;
				cur.p=data[p].p+1;
				if(s==-1)
					s=cur.p-1;
			}

			if(bk)
				puts("Not matched");
			else
				printf("Matched %d %d\n",s,cur.p-1);
		}
	}

	return 0;
}
