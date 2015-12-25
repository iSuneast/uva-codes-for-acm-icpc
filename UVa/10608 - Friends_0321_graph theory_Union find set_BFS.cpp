/*
10608 - Friends

Union find set.
*/

#include<iostream>
#define FN 30010
using namespace std;

int friends[FN],cnt[FN];

int find(int p)
{
	return p==friends[p]?p:friends[p]=find(friends[p]);
}

int main()
{
//	freopen("in.txt","r",stdin);

	int dataset;
	cin>>dataset;
	while(dataset--)
	{
		int n,m,i,a,b,ans=0;
		scanf("%d %d",&n,&m);
		for(i=1;i<=n;i++)
		{
			cnt[i]=1;
			friends[i]=i;
		}
		for(i=0;i<m;i++)
		{
			scanf("%d %d",&a,&b);
			a=find(a);b=find(b);
			if(a!=b)
			{
				cnt[b]+=cnt[a];
				cnt[a]=0;
				friends[a]=b;
			}
		}
		for(i=1;i<=n;i++)
			ans=cnt[i]>ans?cnt[i]:ans;
		cout<<ans<<endl;
	}

return 0;
}

/*
BFS...
晕,题目有问题耶....
我就觉得说这么好的算法怎么可能会超时....

#include<iostream>
#include<queue>
#define FN 30010
using namespace std;

int flag[FN],tn;
vector<int> vi[FN];

int bfs(int cur)
{
	flag[cur]=1;
	queue<int> q;
	int cnt=1;
	q.push(cur);
	while(!q.empty())
	{
		int p=q.front();
		q.pop();
		int sz=vi[p].size();
		for(int i=0;i<sz;i++)
		{
			int v=vi[p][i];
			if(!flag[v])
			{
				q.push(v);
				flag[v]=1;
				++cnt;
			}
		}
	}
	return cnt;
}

int main()
{
//	freopen("in.txt","r",stdin);

	int dataset;
	cin>>dataset;
	while(dataset--)
	{
		int n,m,i,a,b,ans=0;
		scanf("%d %d",&n,&m);
		for(i=1;i<=n;i++)
			vi[i].clear();
		for(i=0;i<m;i++)
		{
			scanf("%d %d",&a,&b);
			vi[a].push_back(b);
			vi[b].push_back(a);
		}
		memset(flag,0,sizeof(flag));
		for(i=1;i<=n;i++)
			if(!flag[i])
			{
				int cnt=bfs(i);
				if(cnt>ans)
					ans=cnt;
			}
		cout<<ans<<endl;
	}

return 0;
}

*/