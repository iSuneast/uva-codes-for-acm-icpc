/*
11492 - Babel

graph theory...
spfa...
求最短路问题...
需要转化模型...
dis数组必须保存两种东西...
一个是最短路,还有一个是到达这条最短路上的最后一条边的字母
直接开个二维,dis[][30]的数组就可以了

不要太小气啊...
没事干嘛把dis搞成short...
害我无端wa了一次...
晕...
*/

#include<iostream>
#include<string>
#include<queue>
#include<map>
#include<vector>
#define ALPHA 30
#define MAXN 4010
#define INF 0x7f7f7f7f
using namespace std;
typedef pair<char,int> pci;

struct DIC
{
	char c;
	int l,v;
}cur;

int n,src,snk,tot;
vector<DIC> next[MAXN];
int dis[MAXN][ALPHA];
string s,d;

void spfa()
{
	memset(dis,0x7f,sizeof(dis));
	memset(dis[src],0,sizeof(dis[src]));
	queue<pci> q;
	q.push(make_pair('a'+28,src));

	while(!q.empty())
	{
		pci cur=q.front();	q.pop();
		int u=cur.second,sz=next[u].size();
		char c=cur.first;

		for(int i=0;i<sz;++i)
		{
			DIC t=next[u][i];
			if(t.c!=c && dis[t.v][t.c-'a']>dis[u][c-'a']+t.l)
			{
				dis[t.v][t.c-'a']=dis[u][c-'a']+t.l;
				q.push(make_pair(t.c,t.v));
			}
		}
	}

	int key=INF;
	for(int i=0;i<ALPHA;++i)
		key=min(key,dis[snk][i]);

	if(key==INF)
		puts("impossivel");
	else
		cout<<key<<endl;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	while(scanf("%d",&n)!=EOF && n)
	{
		for(int i=0;i<MAXN;++i)
			next[i].clear();
		map<string,int> msi;
		tot=0;

		cin>>s>>d;
		if(msi.find(s)==msi.end())
			msi[s]=tot++;
		if(msi.find(d)==msi.end())
			msi[d]=tot++;
		src=msi[s];		snk=msi[d];

		while(n--)
		{
			cin>>s>>d;
			if(msi.find(s)==msi.end())
				msi[s]=tot++;
			if(msi.find(d)==msi.end())
				msi[d]=tot++;
			int u=msi[s],v=msi[d];

			cin>>s;
			cur.c=s[0];	cur.l=s.length();
			cur.v=v;
			next[u].push_back(cur);
			cur.v=u;
			next[v].push_back(cur);
		}
		spfa();
	}

	return 0;
}
