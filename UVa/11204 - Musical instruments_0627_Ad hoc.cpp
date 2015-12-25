/*
11204 - Musical instruments

Ad hoc..
+_+题目意思真难理解啊...
不过理解了就好做了...
只要求优先级为1的乐器就可以了.
所以和其它乐器完全无关
统计一下每个人优先级最高的乐器
然后乘起来就是答案了...
*/

#include<iostream>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int dataset;
	scanf("%d",&dataset);
	while(dataset--)
	{
		int n,m,key[35]={0},t;
		scanf("%d%d",&n,&m);
		for(int i=0;i<m;++i)
			for(int j=0;j<n;++j)
			{
				scanf("%d",&t);
				if(t==1)
					++key[j];
			}
		int ans=1;
		for(int j=0;j<n;++j)
			if(key[j])
				ans*=key[j];
		printf("%d\n",ans);
	}

	return 0;
}
