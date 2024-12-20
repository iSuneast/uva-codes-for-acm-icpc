/*
11753 - Creating Palindrome

dp...
NlogN的LCS...

最长公共子序列向最长递增子序列退化
设有序列A，B。记序列A中各个元素在B 中的位子(降序排列)，
然后按在A中的位置依次列出按后求A的最长递增子序列。

例如：有A={a,b,a,c,x}，B= {b,a,a,b,c,a}
则有a={6,3,2},b={4,1},c={5};x=/;（注意降序排列）

然后按A中次序排出 {a(6,3,2),b(4,1),a(6,3,2),c(5),x()}={6,3,2,4,1,6,3,2,5}；
对此序列求最长递增子序列即可
http://blog.163.com/jiang_xinan/blog/static/1192952120089261717156/

原来还有这么一回事...
赞一个!
*/
#include<iostream>
#include<algorithm>
#define MAXN 10010
using namespace std;

struct pii
{
	int var,idx;
	bool operator <(const pii &t)const
	{
		if(var==t.var)
			return idx>t.idx;
		else
			return var<t.var;
	}
}num[MAXN];

int var[MAXN],tmp[MAXN],buf[MAXN],n,k;

int dp()
{
	int key=0;
	for(int i=n-1;i>=0;--i)
	{
		int p=lower_bound(tmp,tmp+n,var[i])-tmp;
		while(p<n && tmp[p]==var[i])
		{
			int np=0;
			if(key)
				np=lower_bound(buf,buf+key,num[p].idx)-buf;
			if(np==key)
				buf[key++]=num[p].idx;
			else
				buf[np]=num[p].idx;
			++p;
		}
	}
	return n-key;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int dataset;
	scanf("%d",&dataset);
	for(int cas=1;cas<=dataset;++cas)
	{
		scanf("%d%d",&n,&k);
		for(int i=0;i<n;++i)
		{
			scanf("%d",var+i);
			num[i].var=var[i];
			num[i].idx=i;
			tmp[i]=var[i];
		}
		sort(num,num+n);
		sort(tmp,tmp+n);
		int key=dp();
		if(!key)
			printf("Case %d: Too easy\n",cas);
		else if(key>k)
			printf("Case %d: Too difficult\n",cas);
		else
			printf("Case %d: %d\n",cas,key);
	}

	return 0;
}
