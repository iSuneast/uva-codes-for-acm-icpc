/*
117 - The Postal Worker Rings Once

graph theory...
euler tour...
bellman-ford...
这道题最多只有两个度数为奇数...
*/

#include<iostream>
#include<string>
#include<queue>
#define MAXN 30
#define INF 0x7f7f7f7f
using namespace std;

int g[MAXN][MAXN],d[MAXN],dis[MAXN];
bool inq[MAXN];
string s;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	while(true)
	{
		memset(g,0x7f,sizeof(g));
		memset(d,0,sizeof(d));
		int key=0;
		while(cin>>s && s!="deadend")
		{
			int l=s.length();
			int u=s[0]-'a',v=s[l-1]-'a';
			g[u][v]=g[v][u]=min(g[u][v],l);
			++d[u];		++d[v];
			key+=l;
		}
		if(!key)
			break;
		int buf[10],cnt=0;
		for(int i=0;i<26;++i)
			if(d[i]%2)
				buf[cnt++]=i;
		if(!cnt)
			printf("%d\n",key);
		else
		{
			queue<int> q;
			memset(dis,0x7f,sizeof(dis));
			q.push(buf[0]);
			inq[buf[0]]=true;
			dis[buf[0]]=0;
			while(!q.empty())
			{
				int u=q.front();	q.pop();
				inq[u]=false;
				for(int v=0;v<MAXN;++v)
					if(g[u][v]!=INF && dis[v]>dis[u]+g[u][v])
					{
						dis[v]=dis[u]+g[u][v];
						if(!inq[v])
							q.push(v);
						inq[v]=true;
					}
			}
			printf("%d\n",key+dis[buf[1]]);
		}
	}

	return 0;
}
