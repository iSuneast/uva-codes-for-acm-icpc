/*
714 - Copying Books
*/

#include<iostream>

using namespace std;

long long p[510],insert[510],k,m,sum,ins;

void print()
{
	cout<<p[0];
	for(long long i=1;i<m;i++)
		if(insert[i-1])
			cout<<" / "<<p[i];
		else if(ins)
			cout<<" / "<<p[i],ins--;
		else
			cout<<' '<<p[i];
	cout<<endl;
}

long long ok(long long bound)
{
	long long i=m-1,j,equ=0,t;
	ins=k;
	memset(insert,0,sizeof(insert));
	while(i>=0)					//从右向左划分
	{
		t=0;
		while(i>=0 && t+p[i]<=bound)
			t+=p[i--];
		insert[i]=ins--;
		if(t==bound)
			equ=1;
		if(t==0)
			return -1;
	}
	if(ins<0)
		return -1;
	if(equ)
		return 0;
	return 1;
}

void b_locate(long long s,long long e)
{
	long long mid,res;
	while(s<e)
	{
		mid=s+(e-s)/2;
		res=ok(mid);
		if(!res)
			return ;
		else if(res>0)
			e=mid;
		else
			s=mid+1;
	}
}

int main()
{
//	freopen("in.txt","r",stdin);
	long long cas,i;
	cin>>cas;
	while(cas--)
	{
		cin>>m>>k;
		sum=0;
		for(i=0;i<m;i++)
			cin>>p[i],sum+=p[i];
		if(k==m)
		{
			memset(insert,1,sizeof(insert));
			print();
			continue;
		}
		b_locate(1,sum);
		print();
	}

return 0;
}
