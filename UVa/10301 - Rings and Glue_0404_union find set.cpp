/*
10301 - Rings and Glue

union find set...
并查集的题目...
WA了...
竟然是语法错误...//= =
*/

#include<iostream>
#include<cmath>
#define MAXN 110
using namespace std;

int fa[MAXN],cnt[MAXN];
double pnt[3][MAXN];

int find(int p)
{
	return p==fa[p]?p:fa[p]=find(fa[p]);
}

int main()
{
//	freopen("in.txt","r",stdin);

	int n,i,j,x,y;
	double dx,dy,dis;
	while(cin>>n && n!=-1)
	{
		for(i=0;i<n;++i)
		{
			fa[i]=i;
			cnt[i]=1;
			scanf("%lf %lf %lf",&pnt[0][i],&pnt[1][i],&pnt[2][i]);
			x=find(i);
			for(j=0;j<i;++j)
			{
				dx=pnt[0][i]-pnt[0][j];
				dy=pnt[1][i]-pnt[1][j];
				dis=sqrt(dx*dx+dy*dy);
				if(dis>fabs(pnt[2][i]-pnt[2][j]) && dis<fabs(pnt[2][i]+pnt[2][j]))
				{
					y=find(j);
					if(y!=x)
					{
						fa[y]=x;
						cnt[x]+=cnt[y];
						cnt[y]=0;
					}
				}
			}
		}
		int key=0;
		for(i=0;i<n;++i)
			key=key>cnt[i]?key:cnt[i];
		if(key==1)			//语法错误
			cout<<"The largest component contains "<<key<<" ring."<<endl;
		else
			cout<<"The largest component contains "<<key<<" rings."<<endl;
	}

	return 0;
}
