/*
567 - Risk

BFS...
*/

#include<iostream>
#include<queue>
#define MAXN 20
using namespace std;
int g[MAXN+1][MAXN+1],d[MAXN+1];

int main()
{
//	freopen("in.txt","r",stdin);

	int dataset,cas=1;
	while(cin>>dataset)		//UVa的数据让代码变得有点难看..
	{
		memset(g,0,sizeof(g));
		int i,j,t;
		for(j=0;j<dataset;j++)
		{
			cin>>t;
			g[1][t]=g[t][1]=1;
		}
		for(i=2;i<MAXN;i++)
		{
			cin>>dataset;
			for(j=0;j<dataset;j++)
			{
				cin>>t;
				g[i][t]=g[t][i]=1;
			}
		}
		cout<<"Test Set #"<<cas++<<endl;
		cin>>dataset;
		while(dataset--)
		{
			int start,target;
			cin>>start>>target;
			memset(d,-1,sizeof(d));
			d[start]=0;
			queue<int> q;
			q.push(start);
			while(!q.empty())
			{
				int p=q.front();q.pop();
				if(p==target)
					break;
				for(i=1;i<=MAXN;i++)
					if(g[p][i] && d[i]==-1)
					{
						d[i]=d[p]+1;
						q.push(i);
					}
			}
			printf("%2d to %2d:%2d\n",start,target,d[target]);
		}
		cout<<endl;
	}

return 0;
}
