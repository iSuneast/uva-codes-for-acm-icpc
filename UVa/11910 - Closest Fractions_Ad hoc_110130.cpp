/*
11910 - Closest Fractions

Ad hoc...
先把所有的x/y算出来~
排好序...
用字符串读入数据,然后原样输出,(防止浮点误差)
二分查找打好的表,向前/后各读入3个值,排好序,输出即可

happy coding~
*/

#include<cstdio>
#include<cmath>
#include<algorithm>
#define MAXN 608385
using namespace std;

struct DATA
{
	int a,b;
	double dis;
	bool operator<(const DATA &t)const
	{
		return dis<t.dis;
	}
}data[MAXN],ok[MAXN];
bool flag[MAXN];
int tot;
double dis[MAXN];

int gcd(int a,int b)
{
	return b==0?a:gcd(b,a%b);
}

void output(double t)
{
	char s[30];
	sprintf(s,"%.20lf",t);
	bool add=false;
	if(s[11]-'0'>4)
		add=true;
	s[11]=0;

	int p=10;
	for(int p=10; add; --p)
	{
		if(s[p]=='.')
			continue;
		if(s[p]=='9')
			s[p]='0';
		else
		{
			++s[p];
			add=false;
		}
	}

	if(add)
		while(1);

	printf("%s",s);
}

void init()
{
	tot=0;
	for(int i=1;i<=1000;++i)
	{
		for(int j=1;j<=1000;++j)
		{
			if(gcd(i,j)!=1)
				continue;
			data[tot].a=i;
			data[tot].b=j;
			data[tot].dis= (double)i/(j);
			++tot;
		}
	}
	sort(data,data+tot);
	for(int i=0;i<tot;++i)
	{
		dis[i]=data[i].dis;
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	init();
	double var;
	char str[20];
	while(scanf("%s",&str)!=EOF)
	{
		printf("Input : ");
		puts(str);

		sscanf(str,"%lf",&var);
		int p=lower_bound(dis,dis+tot,var)-dis;
		int sz=0;
		for(int i=p-1;i>=0 && i>=p-5; --i)
		{
			ok[sz]=data[i];	ok[sz].dis=abs( ok[sz].dis-var );
			++sz;
		}

		for(int i=p; i<tot && i<=p+5; ++i)
		{
			ok[sz]=data[i];	ok[sz].dis=abs( ok[sz].dis-var );
			++sz;
		}
		sort(ok,ok+sz);

		for(int i=0;i<3;++i)
		{
			printf("%5d : ", i+1);
			output(ok[i].a / (double)ok[i].b);
			printf(" = %4d / %d\n" , ok[i].a, ok[i].b);
		}
	}

	return 0;
}
