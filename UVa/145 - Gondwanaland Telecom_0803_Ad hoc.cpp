/*
145 - Gondwanaland Telecom

Ad hoc...
直接把时间化成分钟的形式...
然后一次while循环扫描即可...

p.s.有起始时间=终止时间的特殊情况
*/

#include<iostream>
using namespace std;

struct STEP
{
	double a,b,c;
}step[5],cur;
int hash[128];

void init()
{
	step[0].a=0.10;	step[0].b=0.06;	step[0].c=0.02;
	step[1].a=0.25;	step[1].b=0.15;	step[1].c=0.05;
	step[2].a=0.53;	step[2].b=0.33;	step[2].c=0.13;
	step[3].a=0.87;	step[3].b=0.47;	step[3].c=0.17;
	step[4].a=1.44;	step[4].b=0.80;	step[4].c=0.30;
	hash['A']=0;
	hash['B']=1;
	hash['C']=2;
	hash['D']=3;
	hash['E']=4;
}

struct MY_TIME
{
	int h,m;
}s,e;

char buf[33],type;
double cost;

int dist(MY_TIME &a,MY_TIME &b)
{
	return (b.h-a.h)*60+(b.m-a.m);
}

int d1,d2,d3;

void add(int t)
{
	if(480<=t && t<1080)
		++d1;
	else if(1080<=t && t<1320)
		++d2;
	else
		++d3;
}

void calc()
{
	d1=d2=d3=0;
	cost=0;

	STEP cur=step[ hash[type] ];
	int front=s.h*60+s.m,rear=e.h*60+e.m;

	if(front==rear)
	{
		d1=600;	d2=240;	d3=600;
	}
	else while(front!=rear)
	{
		add(front++);
		if(front==1440)
			front=0;
	}

	cost=d1*cur.a+d2*cur.b+d3*cur.c;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	init();

	while(scanf("%s",buf)!=EOF && strcmp(buf,"#"))
	{
		type=buf[0];
		scanf("%s",buf);
		scanf("%d%d",&s.h,&s.m);
		scanf("%d%d",&e.h,&e.m);

		calc();
		printf("%10s%6d%6d%6d%3c%8.2lf\n",buf,d1,d2,d3,type,cost);
	}

	return 0;
}
