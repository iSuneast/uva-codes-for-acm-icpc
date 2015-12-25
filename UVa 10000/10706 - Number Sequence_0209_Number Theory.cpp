/*
10706 - Number Sequence
...
再次NC...
buf是char....
直接%c不就ok....
偏偏搞什么buf[]-'0'....
亏我想的出来....

 ╭︿︿︿╮ 
 {/ .  . /}
  ( (oo) )    
  ︶ ︶ ︶ 
最后为什么不直接cout.....
*/

#include<iostream>

#define max_len 325000		//估计

using namespace std;

long long num[max_len],sum[max_len];

void init()
{
	long long i,l,t;
	num[0]=sum[0]=0;
	for(i=1;i<max_len;i++)
	{
		t=i;l=0;
		do
		l++;
		while(t/=10);
		num[i]=num[i-1]+l;
		sum[i]=sum[i-1]+num[i];
	}
}

long long locate(long long *sum,long long n)
{
	long long u=max_len,d=1,m;
	while(d<u)
	{
		m=d+(u-d)/2;
		if(sum[m]==n)
			return m;
		else if(sum[m]<n)
			d=m+1;
		else
			u=m;
	}
	return d;
}

int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("10706.txt","w",stdout);
	long long t,p,key,ans;
	char buf[10];
	cin>>t;
	init();
	while(t--)
	{
		cin>>num[0];
		p=locate(sum,num[0]);

		key=num[0]-sum[p-1];		//第key个数就是解

		ans=locate(num,key);		//key的位置

		sprintf(buf,"%d",ans);
		printf("%c\n",buf[strlen(buf)-1+key-num[ans]]);
	}

return 0;
}

/*
in.txt 生成器~~~~~~~~~~~~~~~~~~~~~~~~

#include<iostream>

using namespace std;

long long main()
{
	freopen("in.txt","w",stdout);
	long long i;
	cout<<2000<<endl;
	for(i=0;i<2000;i++)
		cout<<i+1<<endl;
return 0;
}

out.txt 生成器~~~~~~~~~~~~~~~~~~~~~~

#include<iostream>

using namespace std;

long long main()
{
	freopen("out.txt","w",stdout);
	long long i,j,t;
	char buf[10];
	for(i=1;i<50;i++)	
		for(j=1;j<=i;j++)
		{
			t=0;
			do
			sprintf(buf,"%d",j),
			cout<<buf[t++];
			while(buf[t]);
		}
return 0;
}

*/