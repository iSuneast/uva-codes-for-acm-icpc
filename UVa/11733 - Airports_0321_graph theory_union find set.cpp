/*
11733 - Airports

graph theory
union find set
*/

#include<iostream>
#include<queue>
#define MAXN 10010
using namespace std;

int fa[MAXN];

struct graph
{
	int s,t,w;
}pnt;
struct cmp
{
	bool operator()(graph a,graph b)
	{
		return a.w>b.w;
	}
};
int find(int p)
{
	return p==fa[p]?p:fa[p]=find(fa[p]);
}

int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("11733.txt","w",stdout);

	int dataset,cas=1;
	scanf("%d",&dataset);
	while(dataset--)
	{
		int n,m,a,i,x,y,cost=0;
		scanf("%d %d %d",&n,&m,&a);
		priority_queue<graph,vector<graph>,cmp> pq;
		for(i=0;i<m;i++)
		{
			scanf("%d %d %d",&pnt.s,&pnt.t,&pnt.w);
			if(pnt.w<a)		//题目要认真看.
				pq.push(pnt);
		}
		for(i=1;i<=n;i++)
			fa[i]=i;
		while(!pq.empty())
		{
			pnt=pq.top();
			pq.pop();
			x=find(pnt.s);
			y=find(pnt.t);
			if(x!=y)
			{
				fa[x]=y;
				--n;
				cost+=pnt.w;
			}
		}
		cost+=n*a;
		cout<<"Case #"<<cas++<<": "<<cost<<" "<<n<<endl;
	}

return 0;
}
/*
4
3 2 120
1 2 20
2 3 120

5 2 100
1 3 20
3 5 100

5 2 120
1 3 20
3 5 100

4 3 10
1 2 5
2 3 15
3 4 0
*/
/*
Case #1: 260 2
Case #2: 420 4
Case #3: 480 3
Case #4: 25 2
*/