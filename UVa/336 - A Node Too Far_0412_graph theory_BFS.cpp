/*
336 - A Node Too Far

graph theory...
BFS...
*/

#include<iostream>
#include<queue>
#include<map>
#define MAXN 35
using namespace std;
typedef pair<int,int> pii;
int g[MAXN][MAXN],flag[MAXN];

int main()
{
//	freopen("in.txt","r",stdin);

	int n,v,s,e,ttl,TTL,i,j,cas=1;
	while(cin>>n && n)
	{
		memset(g,0,sizeof(g));
		map<int,int> mii;
		int cnt=1;
		for(i=0;i<n;++i)
		{
			cin>>v;
			if(mii.find(v)==mii.end())
				mii[v]=cnt++;
			s=mii[v];
			cin>>v;
			if(mii.find(v)==mii.end())
				mii[v]=cnt++;
			e=mii[v];
			g[s][e]=g[e][s]=1;
		}
		while(cin>>s>>ttl && (s||ttl))
		{
			queue<pii> q;
			TTL=ttl;	e=s;	s=mii[s];
			pii cur;
			int key=cnt-2;
			q.push(make_pair(s,ttl));
			memset(flag,0,sizeof(flag));
			flag[s]=1;
			while(!q.empty())
			{
				cur=q.front();	q.pop();
				s=cur.first;	ttl=cur.second;
				if(!ttl)
					continue;
				flag[s]=1;
				for(i=1;i<cnt;++i)
					if(g[s][i] && !flag[i])
					{
						flag[i]=1;
						--key;
						q.push(make_pair(i,ttl-1));
					}
			}
			cout<<"Case "<<cas++<<": "<<key
				<<" nodes not reachable from node "
				<<e<<" with TTL = "<<TTL<<"."<<endl;
		}
	}


	return 0;
}
