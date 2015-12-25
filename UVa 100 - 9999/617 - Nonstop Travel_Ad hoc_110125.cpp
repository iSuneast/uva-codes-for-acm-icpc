/*
617 - Nonstop Travel

Ad hoc...
a precision error cause me so many times of WA...
an easy problem, just enum and check whether the speed is valid

happy coding...
*/

#include<cstdio>
#include<cmath>
#include<algorithm>
#define MAXN 10
using namespace std;
const double eps=1e-9;

struct LIGHT
{
	double l;
	int g,y,r,p;
	void read()
	{
		scanf("%lf%d%d%d",&l,&g,&y,&r);
		p=g+y+r;
	}
	bool operator<(const LIGHT &t)const
	{
		return l<t.l;
	}
}light[MAXN];
int n;
bool flag[66];

bool ok(int s)
{
	for(int i=0;i<n;++i)
	{
		double t=light[i].l/s*3600.0;
		double key=t-floor(t/light[i].p+eps)*light[i].p;
		if(key>light[i].g+light[i].y+eps)
			return false;
	}

	return true;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	freopen("314","w",stdout);
#endif

	int cas=1;
	while(scanf("%d",&n)!=EOF && n!=-1)
	{
		for(int i=0;i<n;++i)
		{
			light[i].read();
		}
		sort(light,light+n);

		memset(flag,0,sizeof(flag));
		for(int s=30;s<=60;++s)
		{
			flag[s]=ok(s);
		}

		bool first=true;
		printf("Case %d: ",cas++);
		for(int s=30;s<=60;++s)
		{
			if(flag[s])
			{
				if(flag[s-1])
				{
					if(!flag[s+1])
					{
						printf("-%d",s);
					}
				}
				else
				{
					if(!first)
						printf(", ");
					first=false;
					printf("%d",s);
				}
			}
		}

		if(first)
			puts("No acceptable speeds.");
		else
			putchar(10);
	}

	return 0;
}
