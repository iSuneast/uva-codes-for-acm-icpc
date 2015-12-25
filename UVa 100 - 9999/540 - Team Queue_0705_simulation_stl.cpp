/*
540 - Team Queue

data struct...
stl...
simulation...
要大量运用stl的模拟题...
不过有tricky...

用链表加队列来模拟就够了...

*******************
2
2 1 2
2 3 4
ENQUEUE 1
ENQUEUE 2
ENQUEUE 3
ENQUEUE 4
DEQUEUE
DEQUEUE
ENQUEUE 1
ENQUEUE 2
DEQUEUE
DEQUEUE
STOP
0
*******************
Scenario #1
1
2
3
4

*******************
*/

#include<iostream>
#include<queue>
#include<map>
#include<list>
#define MAXN 1010
#define INF 0x7f7f7f7f
#define eps 1e-9
using namespace std;

list<int> ls[MAXN];
int team,ppln,var,pos;
bool inq[MAXN];
char s[13];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int cas=1;
	while(scanf("%d",&team)!=EOF && team)
	{
		printf("Scenario #%d\n",cas++);

		map<int,int> mii;
		for(int i=0;i<team;++i)
		{
			ls[i].clear();
			inq[i]=false;
			scanf("%d",&ppln);
			while(ppln--)
			{
				scanf("%d",&var);
				mii[var]=i;
			}
		}

		queue<int> q;
		while(scanf("%s",s)!=EOF && strcmp(s,"STOP"))
		{
			if(s[0]=='E')
			{
				scanf("%d",&var);
				pos=mii[var];
				ls[pos].push_back(var);
				if(!inq[pos])
					q.push(pos);
				inq[pos]=true;
			}
			else
			{
				while(true)
				{
					pos=q.front();
					if(!ls[pos].empty())
					{
						printf("%d\n",ls[pos].front());
						ls[pos].pop_front();
						if(ls[pos].empty())
						{
							q.pop();
							inq[pos]=false;
						}
						break;
					}
					inq[pos]=false;
					q.pop();
				}
			}
		}
		putchar('\n');			
	}

	return 0;
}
