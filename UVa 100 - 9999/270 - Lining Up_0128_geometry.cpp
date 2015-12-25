/*
270 - Lining Up
*/

#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

struct point
{
	double x,y;
}p[800];

int n,cnt,i,j,k,ans,key;
char buf[250];
double tmp[800];

int cmp(const point a,const point b)
{
	if(a.y==b.y)
		return a.x<b.x;
	return a.y<b.y;
}

int cmp2(const double a,const double b)
{
	return a<b;
}

double slope(point a,point b)
{
	if(a.x==b.x)
		return 1e8;
	return (a.y-b.y)/(a.x-b.x);
}

int calc()
{
	if(cnt<=2)
		return cnt;
	sort(p,p+cnt,cmp);
	for(i=0;i<cnt;i++)
	{
		k=0;
		for(j=i+1;j<cnt;j++)
			tmp[k++]=slope(p[j],p[i]);
		sort(tmp,tmp+k,cmp2);
		for(key=2,j=1;j<k;j++)
		{
			if(fabs(tmp[j]-tmp[j-1])<=1e-9)
				key++;
			else
				key=2;
			ans=ans>key?ans:key;
		}
	}
	return ans;
}

int main()
{
//	freopen("in.txt","r",stdin);

	cin>>n;getchar();gets(buf);
	while(n--)
	{
		cnt=ans=0;
		while(gets(buf))
			if(strcmp(buf,""))
				sscanf(buf,"%lf%lf",&p[cnt].x,&p[cnt].y),cnt++;
			else
				break;
		cout<<calc()<<endl;
		if(n)
			cout<<endl;
	}
return 0;
}
