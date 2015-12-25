/*
10964 - Strange Planet

simulation...
geometry...
find the law£¬and then just simulate
we can easy observe that 
level 0 : 0			(1 element)
level 1 : 1 2 3 4	(4 element)
level 2 : 5 ... 12	(8 element)
...
level n : 2*level*(level-1)+1 ... (4n element)

give a value p
we can calc its level using format level=(1+(int)sqrt(2*p-1.0))/2
special if p=0, level=0
*/

#include<iostream>
#include<cmath>
using namespace std;

struct POINT
{
	double x,y;
	POINT(){x=y=0;}
}dara,sara;

double sqr(double var)
{
	return var*var;
}

POINT mapping(int p)
{
	POINT t;
	if(!p)
		return t;

	int level=(1+(int)sqrt(2*p-1.0))/2;
	t.y=1;	t.x=1-level;
	int cur=2*level*(level-1)+1,dis,jump;

	for(int d=0;d<4;++d)
	{
		dis=p-cur;
		if(d==0)
		{
			if(dis<level)
			{
				t.x+=dis,t.y+=dis;
				break;
			}
			cur+=level;
			t.x+=level-1,t.y+=level-1;
			++t.x,--t.y;
		}
		else if(d==1)
		{
			if(dis<level)
			{
				t.x+=dis,t.y-=dis;
				break;
			}
			cur+=level;
			t.x+=level-1,t.y-=level-1;
			t.x--,t.y--;
		}
		else if(d==2)
		{
			if(dis<level)
			{
				t.x-=dis,t.y-=dis;
				break;
			}
			cur+=level;
			t.x-=level-1,t.y-=level-1;
			t.x--,t.y++;
		}
		else
		{
			t.x-=dis,t.y+=dis;
		}
	}

	return t;
}

void chk();

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int a,b;
	while(scanf("%d%d",&a,&b)!=EOF && (a!=-1 || b!=-1))
	{
		dara=mapping(a);
		sara=mapping(b);
		printf("%.2lf\n",sqrt( sqr(dara.x-sara.x) + sqr(dara.y-sara.y) ));
	}

	return 0;
}

void chk()
{
	int cnt[100];
	memset(cnt,0,sizeof(cnt));

	for(int i=1;i<=10000;++i)
		++cnt[ (1+(int)sqrt(2*i-1.0))/2 ];

	int key=4;
	for(int i=1;i<=10000;++i)
	{
		if(cnt[i])
		{
			if(cnt[i]==key)
				puts("nice");
			else
				puts("= =");
			key+=4;
		}
		else
			return ;
	}
}
