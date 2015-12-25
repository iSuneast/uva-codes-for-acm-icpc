/*
 * 10750 - Beautiful Points
 * 
 * geometry...
 * closest-pair...
 * find the closest-pair
 * then the mid point is the answer...
 */

#include<cstdio>
#include<algorithm>
#define MAXN 10003
using namespace std;

struct POINT
{
	double x,y;
}pnt[MAXN];

bool cmpX(const int &u,const int &v)
{
	return pnt[u].x<pnt[v].x;
}

bool cmpY(const int &u,const int &v)
{
	return pnt[u].y<pnt[v].y;
}

struct CLOSEST_PAIR
{
	int n,a,b,coX[MAXN],coY[MAXN];
	double key;

	void read()
	{
    	scanf("%d",&n);
    	for(int i=0;i<n;++i)
    	{
    		scanf("%lf%lf",&pnt[i].x,&pnt[i].y);
    		coX[i]=i;
    	}		
	}
	
	double sqr(const double &t)const
	{
		return t*t;
	}

	double dist(const int &u,const int &v)const
	{
		return sqr( pnt[u].x-pnt[v].x )+sqr( pnt[u].y-pnt[v].y );
	}

	double ChkMin(const int &_a,const int &_b)
	{
		double d=dist(_a,_b);
		if(key>d)
		{
			key=d;
			a=_a;	b=_b;			
		}
		return d;
	}
	
	void closest_pair(int l,int r)
	{
		if(l+2==r)
			ChkMin(coX[l],coX[l+1]);
		if(l+2>=r)
			return ;
		
		int mid=(l+r)>>1;
		closest_pair(l,mid);
		closest_pair(mid,r);
		
		int sz=0;
		for(int i=l;i<r;++i)
		{
			if( sqr( pnt[ coX[i] ].x-pnt[ coX[mid] ].x )<=key )
				coY[sz++]=coX[i];
		}
		sort(coY,coY+sz,cmpY);
		
		for(int i=0;i<sz;++i)
		{
			for(int j=i+1;j<sz;++j)
			{
				if( sqr( pnt[ coY[i] ].y-pnt[ coY[j] ].y )>key )
					break;
				ChkMin(coY[i],coY[j]);
			}
		}		
	}
	
	void process()
	{
		key=INF;
		sort(coX,coX+n,cmpX);
		closest_pair(0,n);
		
		printf("%.3lf %.3lf\n", (pnt[a].x+pnt[b].x)/2.0, (pnt[a].y+pnt[b].y)/2.0);
	}
}cp;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif
    
    int dataset;
    scanf("%d",&dataset);
    while(dataset--)
    {
    	cp.read();
    	cp.process();

    	if(dataset)
    		putchar(10);
    }

    return 0;
}

