/*
10902 - Pick-up Sticks

geometry...
use double linked list to simulation the operations
if stick a is inserted with stick b
we can delete a from the list not to scan it again
so the total time is O(1000^2)
*/

#include<iostream>
#define MAXN 100003
#define eps 1e-9
using namespace std;

struct POINT
{
	double x,y;
};

struct STICK
{
	POINT a,b;
	STICK *next,*pre;
	bool flag;
}stick[MAXN];
int n;

double cross(POINT a,POINT b,POINT c)
{
	return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
}

bool seg_insert(STICK *u,STICK *v)
{
	return max(u->a.x,u->b.x)>=min(v->a.x,v->b.x)
		&& min(u->a.x,u->b.x)<=max(v->a.x,v->b.x)
		&& max(u->a.y,u->b.y)>=min(v->a.y,v->b.y)
		&& min(u->a.y,u->b.y)<=max(v->a.y,v->b.y)
		&& cross(u->a,u->b,v->a)*cross(u->a,u->b,v->b)<eps
		&& cross(v->a,v->b,u->a)*cross(v->a,v->b,u->b)<eps;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	while(scanf("%d",&n)!=EOF && n)
	{
		for(int i=1;i<=n;++i)
		{
			stick[i].next=&stick[i+1];
			stick[i].pre=&stick[i-1];
			stick[i].flag=false;
		}
		stick[0].next=&stick[1];

		for(int i=1;i<=n;++i)
		{
			scanf("%lf%lf",&stick[i].a.x,&stick[i].a.y);
			scanf("%lf%lf",&stick[i].b.x,&stick[i].b.y);
			for(STICK *cur=stick[0].next;cur<&stick[i];cur=cur->next)
				if(seg_insert(cur,&stick[i]))
				{
					cur->flag=true;
					cur->next->pre=cur->pre;
					cur->pre->next=cur->next;
				}
		}

		printf("Top sticks: ");
		bool first=true;
		for(int i=1;i<=n;++i)
			if(!stick[i].flag)
			{
				if(!first)
					printf(", ");
				first=false;
				printf("%d",i);
			}
		puts(".");
	}

	return 0;
}
