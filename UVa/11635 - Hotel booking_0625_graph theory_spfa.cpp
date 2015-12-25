/*
11635 - Hotel booking

graph theory...
spfa...
���·����...
�տ�ʼ�븴����...

����������:һ������Դ��,һ������spfa

��Դ�㿪ʼ�����·(ÿ��Զ�·�����޶�����)
������Ե���ĳ����Ϣ��
�������Ϣ�����Դ�����,����ǵ�ǰԴ��Ϊ��i��
���spfa���Ե����յ�,��������Դ����������i���Ǵ���
*/

#include<iostream>
#include<queue>
#define MAXN 10010
#define TIME 600
#define INF 0x7f7f7f7f
#define eps 1e-9
using namespace std;

struct EDGE{int v,w;};

vector<EDGE> edge[MAXN];
bool inq[MAXN],head[MAXN];
int u,v,w,dis[MAXN];
int n;

void spfa()
{
	queue<int> q;
	queue<pair<int,int> > src;
	u=1;
	src.push(make_pair(u,0));
	while(!src.empty())
	{
		u=src.front().first;
		memset(inq,0,sizeof(inq));
		q.push(u);	inq[u]=true;
		memset(dis,0x7f,sizeof(dis));
		dis[u]=0;

		while(!q.empty())
		{
			u=q.front();	q.pop();	inq[u]=false;
			int sz=edge[u].size();
			for(int i=0;i<sz;++i)
			{
				v=edge[u][i].v;	w=edge[u][i].w;
				if(dis[v]>dis[u]+w && dis[u]+w<=TIME)
				{
					dis[v]=dis[u]+w;
					if(!inq[v])
					{
						q.push(v);
						inq[v]=true;
						if(head[v])
						{
							head[v]=false;
							src.push(make_pair(v,src.front().second+1));
						}
					}
				}
			}
		}

		if(dis[n]!=INF)
		{
			printf("%d\n",src.front().second);
			return ;
		}
		u=src.front().first;	src.pop();
		edge[u].clear();
	}
	puts("-1");
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	while(scanf("%d",&n)!=EOF && n)
	{
		for(int i=1;i<=n;++i)
			edge[i].clear();

		int sp,m;
		scanf("%d",&sp);
		memset(head,0,sizeof(head));
		while(sp--)
		{
			scanf("%d",&u);
			head[u]=true;
		}

		scanf("%d",&m);
		EDGE cur;
		while(m--)
		{
			scanf("%d%d%d",&u,&v,&w);
			cur.w=w;
			cur.v=v;	edge[u].push_back(cur);
			cur.v=u;	edge[v].push_back(cur);
		}
		spfa();
	}

	return 0;
}
