/*
143 - Orchard Trees
*/

#include<iostream>
#include<cmath>

using namespace std;

double sn;
int x,y,cnt;

struct co
{
	double x,y;
}p[3];

int cmp(const void *a,const void *b)
{
	struct co *tx=(co *)a;
	struct co *ty=(co *)b;
	if(tx->x!=ty->x)
		return tx->x-ty->x;
	return tx->y-ty->y;
}

double s(double a0,double b0,double a1,double b1,double a2,double b2)
{
	return fabs(a0*b1+a1*b2+a2*b0-a0*b2-a1*b0-a2*b1);
}

int inside()
{
	double s0=s(x,y,p[0].x,p[0].y,p[1].x,p[1].y);
	double s1=s(x,y,p[1].x,p[1].y,p[2].x,p[2].y);
	double s2=s(x,y,p[2].x,p[2].y,p[0].x,p[0].y);

	return s0+s1+s2-sn<1e-5?1:0;
}

void judge(double a0,double a1,double b0,double b1)
{
	sn=(b1-a1)*(b1-a1)+(b0-a0)*(b0-a0);
	sn=sqrt(sn);
	for(x=1;x<100;x++)
		for(y=1;y<100;y++)
			if(sqrt((y-a1)*(y-a1)+(x-a0)*(x-a0))+sqrt((y-b1)*(y-b1)+(x-b0)*(x-b0))-sn<1e-5)
				cnt++;
}

int main()
{
//	freopen("in.txt","r",stdin);///////////////
//	freopen("143.txt","w",stdout);///////////////

	while(cin>>p[0].x>>p[0].y>>p[1].x>>p[1].y>>p[2].x>>p[2].y&&(p[0].x||p[0].y||p[1].x||p[1].y||p[2].x||p[2].y))
	{
		cnt=0;
		qsort(p,3,sizeof(p[0]),cmp);

		if((p[0].x==p[2].x)&&(p[0].y==p[2].y))										//三点重合
		{
			if(p[0].x!=100&&p[0].y!=100&&(p[0].x-(int)p[0].x<1e-5)&&(p[1].x-(int)p[1].x<1e-5))
				cnt=1;
		}

		else if((p[1].x==p[2].x)&&(p[1].y==p[2].y))										//后面两点重合
			judge(p[1].x,p[1].y,p[0].x,p[0].y);
		else if((p[1].x==p[0].x)&&(p[1].y==p[0].y))											//前面两点重合
			judge(p[1].x,p[1].y,p[2].x,p[2].y);
		else if(fabs((p[2].x-p[1].x)*(p[1].y-p[0].y)-(p[2].y-p[1].y)*(p[1].x-p[0].x))<1e-5)		//三点共线
			judge(p[2].x,p[2].y,p[0].x,p[0].y);
		else
		{
			sn=s(p[0].x,p[0].y,p[1].x,p[1].y,p[2].x,p[2].y);
			for(x=1;x<100;x++)
				for(y=1;y<100;y++)
					if(inside())
						cnt++;
		}
		printf("%4d\n",cnt);
	}

return 0;
}
