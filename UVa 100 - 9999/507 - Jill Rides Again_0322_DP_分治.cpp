/*
507 - Jill Rides Again

DP
分治.
*/

#include<iostream>
#define MAXN 20010
using namespace std;

int ride[MAXN];
class point
{
public:
	int max,s,e;
	point(int a,int b,int c){max=a,s=b,e=c;}
	point operator=(point b)
	{
		max=b.max;
		s=b.s;
		e=b.e;
		return *this;
	}
	bool operator>(point &b)	//这里的operator运算一定要注意.
	{
		if(max==b.max)
		{
			if(e-s==b.e-b.s)
				return s<b.s;
			return e-s>b.e-b.s;
		}
		else
			return max>b.max;
	}
};

point maxsum(point cur)
{
	int i,m,v,x=cur.s,y=cur.e;
	if(y-x==1)
	{
		cur.max=ride[x];
		return cur;
	}

	m=x+(y-x)/2;
	point max1(0,x,m),max2(0,m,y);
	max1=maxsum(max1);
	max2=maxsum(max2);
	if(max1>cur)
		cur=max1;
	if(max2>cur)		//之前这里竟然用else if.WA了n次终于调出来了..
		cur=max2;
	v=0;	max1.max=ride[m-1];
	max1.s=x;
	for(i=m-1;i>=x;--i)
	{
		v+=ride[i];
		if(max1.max<=v)
		{
			max1.max=v;
			max1.s=i;
		}
	}
	v=0;	max2.max=ride[m];
	max2.e=y;
	for(i=m;i<y;++i)
	{
		v+=ride[i];
		if(max2.max<=v)
		{
			max2.max=v;
			max2.e=i+1;
		}
	}
	max1.max+=max2.max;
	max1.e=max2.e;
	if(max1>cur)
		cur=max1;
	return cur;
}

int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("507.txt","w",stdout);

	int dataset,cas=1;
	cin>>dataset;
	ride[0]=0;
	while(dataset--)
	{
		int n,i,flag=1;
		cin>>n;
		for(i=1;i<n;i++)
		{
			scanf("%d",ride+i);
			if(ride[i]<=0)
				flag++;
		}
		if(flag==n)
		{
			cout<<"Route "<<cas++<<" has no nice parts"<<endl;
			continue;
		}
		point key(0,1,n);
		key=maxsum(key);
		cout<<"The nicest part of route "<<cas++
			<<" is between stops "<<key.s<<" and "
			<<key.e<<endl;
	}

return 0;
}
/*
朴素的O(n^2)算法	TLE

#include<iostream>

#define MAXN 20010
using namespace std;
int ride[MAXN];

int main()
{
//	freopen("in.txt","r",stdin);

	int dataset,cas=1;
	cin>>dataset;
	ride[0]=0;
	while(dataset--)
	{
		int n,i,j,m,s,e,t,flag=1;
		cin>>n;
		for(i=1;i<n;i++)
		{
			scanf("%d",ride+i);
			if(ride[i]<0)
				flag++;
			ride[i]+=ride[i-1];
		}
		if(flag==n)
		{
			cout<<"Route "<<cas++<<" has no nice parts"<<endl;
			continue;
		}
		m=s=e=0;
		for(i=1;i<n;i++)
			for(j=i+1;j<n;j++)
			{
				t=ride[j]-ride[i];
				if(t>m)
				{
					m=t;
					s=i;
					e=j;
				}
				else if(t==m && j-i>e-s)
				{
					s=i;
					e=j;
				}
			}
			cout<<"The nicest part of route "<<cas++
				<<" is between stops "<<s+1<<" and "<<e+1<<endl;
	}

return 0;
}

*/