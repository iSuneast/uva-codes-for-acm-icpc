/*
439 - Knight Moves

BFS...
*/

#include<iostream>
#include<string>
#include<queue>
#define MAXN 8
#define BOUND 64
#define STATE 8
using namespace std;
const int d[MAXN]={-17,-15,-10,-6,6,10,15,17};
const int chk[2][MAXN]={-2,-2,-1,-1,1,1,2,2,	//这里要么输错,要么漏了",".无语..
						-1,1,-2,2,-2,2,-1,1};
int dist[MAXN*MAXN];
//hash函数算位置
int hash(string s)	{	return (s[0]-'a')+('8'-s[1])*8;	}

int main()
{
//	freopen("in.txt","r",stdin);

	string s1,s2;
	while(cin>>s1>>s2)
	{
		memset(dist,-1,sizeof(dist));
		int start=hash(s1);
		int target=hash(s2);
		queue<int> q;
		q.push(start);
		dist[start]=0;
		while(!q.empty())
		{
			int p=q.front();
			q.pop();
			int dis=dist[p];
			if(p==target)
				break;
			for(int i=0;i<STATE;i++)
			{
				int next=p+d[i];
				if(next>=0 && next<BOUND && dist[next]==-1
					&& p/MAXN+chk[0][i]==(p+d[i])/MAXN
					&& p%MAXN+chk[1][i]==(p+d[i])%MAXN	)
				{
					dist[next]=dis+1;
					q.push(next);
				}
			}
		}
		cout<<"To get from "<<s1<<" to "
			<<s2<<" takes "
			<<dist[target]<<" knight moves."<<endl;
	}

return 0;
}
