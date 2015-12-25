/*
10245 - The Closest Pair Problem
*/

#include<iostream>
#include<cmath>
#include<cstdlib>

using namespace std;

struct point
{
	double x,y;
}p[10010];

int n;

int cmp(const void *a,const void *b)
{
	point *m=(point *)a;
	point *n=(point *)b;
	if(m->x == n->x)
		return m->y > n->y;
	return m->x > n->x;
}

inline double minimum(double a,double b)
{
	return a<b?a:b;
}

double dp(int start,int end)
{
	int i,j,m;
	double dx,dy,ans=1<<30;
	if(end-start <= 3)		//只剩三点,或两点时归并
	{
		for(i=start;i<end;i++)
			for(j=i+1;j<end;j++)
			{
				dx=p[i].x-p[j].x;
				dy=p[i].y-p[j].y;
				if(dx*dx + dy*dy < ans)
					ans=dx*dx + dy*dy;
			}
		return ans;
	}
	m=start+(end-start)/2;
	ans=minimum(dp(start,m),dp(m,end));
	double d=sqrt(ans);
	for(i=start;i<end;i++)
		for(j=i+1;j<end;j++)
			if((dx=p[j].x-p[i].x)<d 
				&& (dy=p[j].y-p[i].y)<d 
				&& dx*dx + dy*dy<ans)
				ans=dx*dx + dy*dy;
	return ans;
}

int main()
{
//	freopen("in.txt","r",stdin);

	while(cin>>n && n)
	{
		for(int i=0;i<n;i++)
			cin>>p[i].x>>p[i].y;
		if(n == 1)
		{
			cout<<"INFINITY"<<endl;
			continue;
		}
		qsort(p,n,sizeof(p[0]),cmp);
		double ans=sqrt(dp(0,n));
		if(ans > 10000.0-1e-9)
			cout<<"INFINITY"<<endl;
		else
			printf("%.4lf\n",ans);
	}

return 0;
}
