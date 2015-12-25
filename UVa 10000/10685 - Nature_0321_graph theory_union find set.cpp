/*
10685 - Nature

graph theory
union find set
*/

#include<iostream>
#include<string>
#include<map>
#define MAXN 5010
using namespace std;

int fa[MAXN],cnt[MAXN];

int find(int p)
{
	return p==fa[p]?p:fa[p]=find(fa[p]);
}

int main()
{
//	freopen("in.txt","r",stdin);

	int c,r;
	while(cin>>c>>r && (c||r))
	{
		int i,a,b;
		string creature;
		map<string,int> m;
		for(i=1;i<=c;++i)
		{
			fa[i]=i;
			cnt[i]=1;
			cin>>creature;
			m[creature]=i;
		}
		for(i=0;i<r;i++)
		{
			cin>>creature;
			a=find(m[creature]);
			cin>>creature;
			b=find(m[creature]);
			if(a!=b)
			{
				fa[a]=b;
				cnt[b]+=cnt[a];
				cnt[a]=0;
			}
		}
		int key=0;
		for(i=1;i<=c;++i)
			if(cnt[i]>key)
				key=cnt[i];
		cout<<key<<endl;
	}

return 0;
}
