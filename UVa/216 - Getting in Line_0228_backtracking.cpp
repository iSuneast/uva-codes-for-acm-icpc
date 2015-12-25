/*
216 - Getting in Line
*/

#include<iostream>
#include<cmath>
#include<cstdlib>

using namespace std;

struct point
{
	double x,y;
}com[10];
struct boolen
{
	int p,key;
}flag[10];
double dis[10][10],ans;
int fa[10],n;

int cmp(const void *a,const void *b)
{
	return ((boolen *)a)->key - ((boolen *)b)->key;
}

void dfs(double t,int p,int cur)
{
	int i;
	if(cur==n)
	{
		if(t<ans)
		{
			ans=t;
			for(i=0;i<n;i++)
				flag[i].key=fa[i];
		}
		return ;
	}
	fa[p]=cur;
	for(i=0;i<n;i++)
		if(!fa[i])
			dfs(t+dis[p][i],i,cur+1);
	fa[p]=0;
}

int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("216.txt","w",stdout);

	int cas=1;
	while(cin>>n && n)
	{
		int i,j;
		double dx,dy;
		for(i=0;i<n;i++)
			cin>>com[i].x>>com[i].y;
		for(i=1;i<n;i++)
			for(j=0;j<i;j++)
			{
				dx=com[i].x-com[j].x;
				dy=com[i].y-com[j].y;
				dis[j][i]=dis[i][j]=sqrt(dx*dx+dy*dy);
			}
		memset(fa,0,sizeof(fa));
		for(i=0;i<n;i++)
			flag[i].p=i;
		ans=1e4;
		for(i=0;i<n;i++)
			dfs(0,i,1);
		qsort(flag,n,sizeof(flag[0]),cmp);
		cout<<"**********************************************************"<<endl
			<<"Network #"<<cas++<<endl;
		for(i=1;i<n;i++)
		{
			cout<<"Cable requirement to connect ("
				<<com[flag[i].p].x<<","<<com[flag[i].p].y
				<<") to ("
				<<com[flag[(i+1)%n].p].x<<","<<com[flag[(i+1)%n].p].y<<") is ";
			printf("%.2lf feet.\n",dis[flag[i].p][flag[(i+1)%n].p]+16);
		}
		printf("Number of feet of cable required is %.2lf.\n",ans+16*n-16);
	}

return 0;
}
