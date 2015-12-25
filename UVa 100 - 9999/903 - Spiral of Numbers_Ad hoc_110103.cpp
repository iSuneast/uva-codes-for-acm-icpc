/*
 * 903 - Spiral of Numbers
 * 
 * Ad hoc...
 * I just try to re-located the number into a (x,y) coordinate
 * then put the coordinate into the number again...
 */

#include <cstdio>
#include <algorithm>
#define MAXN (1<<15)
#define BOUND (1<<30)
using namespace std;

int sqr[MAXN],sz,ans[3][3];

void init()
{
	sz=0;
	for(int i=1;i<MAXN;++i)
	{
		sqr[sz++]=(2*i-1)*(2*i-1);
		if(sqr[sz]>BOUND)
			break;
	}
}

const int dx[]={-1,0,1,-1,1,-1,0,1};
const int dy[]={1,1,1,0,0,-1,-1,-1};

int process(int x,int y)
{
	int p=max( abs(x), abs(y) );
	int jump=2*p;
	
	if(x==p)
	{
		if(y==p)
			return sqr[p];
		return sqr[p-1]+(p-y);
	}
	else if(x==-p)
		return sqr[p-1]+jump*2+(p+y);
	else if(y==p)
		return sqr[p-1]+jump*3+(p+x);
	else
		return sqr[p-1]+jump+(p-x);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	init();
	while(scanf("%d",&ans[1][1])!=EOF)
	{
		int p=lower_bound(sqr,sqr+sz,ans[1][1])-sqr,x,y;

		if(!p)
			x=y=0;
		else
		{
			int jmp=p<<1,rem=ans[1][1]-sqr[p-1]-1;
			int a=rem/jmp,b=rem%jmp;

			if(a==0)
				x=p, y=p-1-b;
			else if(a==1)
				x=p-b-1, y=-p;
			else if(a==2)
				x=-p, y=b-p+1;
			else if(a==3)
				x=b-p+1, y=p;			
		}
		
		for(int d=0;d<8;++d)
		{
			ans[1-dy[d]][1+dx[d]]=process(x+dx[d],y+dy[d]);
		}
		
		for(int i=0;i<3;++i)
		{
			printf("%d;%d;%d;\n",ans[i][0],ans[i][1],ans[i][2]);
		}
	}

	return 0;
}

