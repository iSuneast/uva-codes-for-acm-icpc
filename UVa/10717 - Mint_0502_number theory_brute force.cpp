/*
10717 - Mint

math...
number theory...
竟然tle的说...
Orz...

要先求一个集合里面的任意4个元素的集合...
由于规模较小c(50,4)=230300所以用4个for枚举一遍即可...
求4个元素的lcm可以嵌套定义
lcm(var[a],lcm(var[b],lcm(var[c],var[d])))...
lcm(a,b)=a*b/gcd(a,b)

然后对于任意h,只需遍历集合里面的元素..
查找与h相关的最小元素的值...
特别的...
若h%s[i]==0直接输出h即可...
*/

#include<iostream>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define MAXSZ 230303
#define MAXN 60
using namespace std;

int var[MAXN],n,t,s[MAXSZ],cnt;

int gcd(int a,int b)
{	return b==0?a:gcd(b,a%b);}

int lcm(int a,int b)
{	return a*b/gcd(a,b);}

void judge(int h)
{
	int p=(h/s[0])*s[0],q=(h/s[0]+1)*s[0];
	for(int j=0;j<cnt;++j)
	{
		if(s[j]>h)
			q=min(s[j],q);
		else if(s[j]<h)
		{
			if(h%s[j]==0)
			{
				cout<<h<<' '<<h<<endl;
				return ;
			}
			int t=h/s[j]*s[j];
			p=max(p,t);
			t=(h/s[j]+1)*s[j];
			q=min(q,t);
		}
		else
		{
			cout<<h<<' '<<h<<endl;
			return ;
		}
	}
	cout<<p<<' '<<q<<endl;
}

int main()
{
#ifndef ONLINE_JUDGE
//	freopen("in.txt","r",stdin);
#endif

	while(cin>>n>>t && (n||t))
	{
		int i,j,h;
		for(i=0;i<n;++i)
			cin>>var[i];
		cnt=0;
		for(int a=0;a<n;++a)
			for(int b=a+1;b<n;++b)
				for(int c=b+1;c<n;++c)
					for(int d=c+1;d<n;++d)
						s[cnt++]=lcm(var[a],lcm(var[b],lcm(var[c],var[d])));
		for(i=0;i<t;++i)
		{
			scanf("%d",&h);
			judge(h);
		}
	}

	return 0;
}
