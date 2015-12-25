/*
11060 - Beverages

graph theory...
topo-sort
just a simple topo-sort problem
use priority-queue to solve it
pop the top Beverages with in-degree=0 && minimum-index
*/

#include<iostream>
#include<string>
#include<algorithm>
#include<map>
#include<vector>
#define MAXN 103
using namespace std;

vector<int> vi[MAXN];
int n,m,id[MAXN];
string b1,b2,Beverages[MAXN];;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int cas=1;
	while(scanf("%d",&n)!=EOF)
	{
		map<string,int> msi;
		memset(id,0,sizeof(id));

		for(int i=0;i<n;++i)
		{
			cin>>Beverages[i];
			msi[ Beverages[i] ]=i;
			vi[i].clear();
		}

		scanf("%d",&m);
		while(m--)
		{
			cin>>b1>>b2;
			id[ msi[b2] ]++;
			vi[ msi[b1] ].push_back( msi[b2] );
		}

		priority_queue<int,vector<int>,greater<int> > pq;

		for(int i=0;i<n;++i)
		{
			if(!id[i])
				pq.push(i);
		}

		cout<<"Case #"<<cas++<<": Dilbert should drink beverages in this order:";

		while(!pq.empty())
		{
			int cur=pq.top();	pq.pop();
			cout<<' '<<Beverages[cur];

			int sz=vi[ cur ].size();

			for(int i=0;i<sz;++i)
			{
				if(!(--id[ vi[cur][i] ]))
					pq.push( vi[cur][i] );
			}
		}

		cout<<'.'<<endl<<endl;
	}

	return 0;
}
