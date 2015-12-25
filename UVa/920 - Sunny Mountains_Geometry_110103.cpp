/*
 * 920 - Sunny Mountains
 * 
 * Geometry...
 * sort the points according to their y-coordinate
 * scan from right to left...
 * store the current high value and check if a segment is fine
 * if no, continue
 * else add the extra segment length and modify the high value
 */

#include<cstdio>
#include<cmath>
#include<algorithm>
#define MAXN 103
using namespace std;

struct POINT
{
	int x,y;
	bool operator<(const POINT &t)const
	{
		return x<t.x;
	}
}pnt[MAXN];
int n;

double sqr(double t)
{
	return t*t;
}

double dis(POINT &a,POINT &b)
{
	return sqrt(sqr(a.x-b.x)+sqr(a.y-b.y));
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif
    
    int dataset;
    scanf("%d",&dataset);
    while(dataset--)
    {
    	scanf("%d",&n);
    	for(int i=0;i<n;++i)
    	{
    		scanf("%d%d",&pnt[i].x,&pnt[i].y);
    	}
    	sort(pnt,pnt+n);
    	int h=0;
    	double key=0;
    	for(int i=n-1;i;--i)
    	{
    		if(pnt[i].y>=pnt[i-1].y || pnt[i-1].y<=h)
    			continue;
    		key+=dis(pnt[i],pnt[i-1])*(pnt[i-1].y-h)/(pnt[i-1].y-pnt[i].y);
    		h=pnt[i-1].y;
    	}
    	
    	printf("%.2lf\n",key);
    }

    return 0;
}

