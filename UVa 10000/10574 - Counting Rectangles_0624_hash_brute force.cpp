/*
10574 - Counting Rectangles

hash...
brute force...
暴力匹配对角线上的点...
用hash保存所有的点
然后判断一下另外一条对角线的点是否存在

由于两条对角线有两次计数
所以最后的解要/2.
*/

#include<iostream>
#include<vector>
#define MAXN 5010
#define SIZE 11111
using namespace std;
typedef pair<int,int> pii;

pii pnt[MAXN];
vector<pii> hash[11111];
int n;

int h(pii t)
{
	long long key=t.first;
	return (key*MAXN+t.second)%SIZE;
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
		scanf("%d",&n);
		for(int i=0;i<SIZE;++i)
			hash[i].clear();
		for(int i=0;i<n;++i)
		{
			scanf("%d%d",&pnt[i].first,&pnt[i].second);
			hash[ h(pnt[i]) ].push_back(pnt[i]);
		}
		int key=0;
		for(int i=0;i<n;++i)
			for(int j=i+1;j<n;++j)
				if(pnt[i].first!=pnt[j].first && pnt[i].second!=pnt[j].second)
				{
					pii cur=make_pair(pnt[i].first,pnt[j].second);
					int p=h(cur);
					int sz=hash[p].size();
					if(sz)
					{
						for(int k=0;k<sz;++k)
							if(hash[p][k]==cur)
							{
								cur=make_pair(pnt[j].first,pnt[i].second);
								p=h(cur);
								sz=hash[p].size();
								if(sz)
								{
									for(int l=0;l<sz;++l)
										if(hash[p][l]==cur)
										{
											++key;
											break;
										}
								}
								break;
							}
					}
				}
				printf("Case %d: %d\n",cas,key/2);
	}

	return 0;
}
