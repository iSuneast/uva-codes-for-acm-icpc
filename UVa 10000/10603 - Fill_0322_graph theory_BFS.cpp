/*
10603 - Fill

BFS...
*/

#include<iostream>
#include<queue>
#define MAXN 9000000
using namespace std;

int flag[MAXN];
class graph
{
public:
	int a,b,c,dis;
	graph& operator=(graph g)
	{		//晕,我跟你说过多少次了...不要copy自己的东西...慢慢写!!!
		a=g.a;	b=g.b;	c=g.c;	dis=g.dis;
		return *this;
	}
}pnt;

int main()
{
//	freopen("in.txt","r",stdin);

	int dataset;
	cin>>dataset;
	while(dataset--)
	{
		int a,b,c,d,key1=0,key2=0,cur;
		cin>>a>>b>>c>>d;
		queue<graph> pq;
		pnt.a=pnt.b=0;	pnt.c=c;
		pnt.dis=0;
		pq.push(pnt);
		memset(flag,0,sizeof(flag));
		while(!pq.empty() && key2!=d)
		{
			pnt=pq.front();	pq.pop();
			cur=pnt.a*200*200+pnt.b*200+pnt.c;
			if(flag[cur])
				continue;
			flag[cur]=1;
			if(abs(pnt.a-d)<abs(key2-d))
			{
				key2=pnt.a;	key1=pnt.dis;
			}
			if(abs(pnt.b-d)<abs(key2-d))
			{
				key2=pnt.b;	key1=pnt.dis;
			}
			if(abs(pnt.c-d)<abs(key2-d))
			{
				key2=pnt.c;	key1=pnt.dis;
			}
			graph t;
			if(pnt.a)
			{
				if(pnt.b<b)
				{
					t=pnt;
					t.b+=t.a;
					t.a=0;
					if(t.b>b)
					{
						t.a=t.b-b;
						t.b=b;
					}
					t.dis+=(t.b-pnt.b);
				pq.push(t);
				}
				if(pnt.c<c)
				{
					t=pnt;
					t.c+=t.a;
					t.a=0;
					if(t.c>c)
					{
						t.a=t.c-c;
						t.c=c;
					}
					t.dis+=(t.c-pnt.c);
					pq.push(t);
				}
			}

			if(pnt.b)
			{
				if(pnt.a<a)
				{
					t=pnt;
					t.a+=t.b;
					t.b=0;
					if(t.a>a)
					{
						t.b=t.a-a;
						t.a=a;
					}
					t.dis+=(t.a-pnt.a);
					pq.push(t);
				}
				if(pnt.c<c)
				{
					t=pnt;
					t.c+=t.b;
					t.b=0;
					if(t.c>c)
					{
						t.b=t.c-c;
						t.c=c;
					}
					t.dis+=(t.c-pnt.c);
				pq.push(t);
				}
			}

			if(pnt.c)
			{
				if(pnt.a<a)
				{
					t=pnt;
					t.a+=t.c;
					t.c=0;
					if(t.a>a)
					{
						t.c=t.a-a;
						t.a=a;
					}
					t.dis+=(t.a-pnt.a);
					pq.push(t);
				}
				if(pnt.b<b)
				{
					t=pnt;
					t.b+=t.c;
					t.c=0;
					if(t.b>b)
					{
						t.c=t.b-b;
						t.b=b;
					}
					t.dis+=(t.b-pnt.b);
					pq.push(t);
				}
			}
		}
		cout<<key1<<' '<<key2<<endl;
	}

return 0;
}
