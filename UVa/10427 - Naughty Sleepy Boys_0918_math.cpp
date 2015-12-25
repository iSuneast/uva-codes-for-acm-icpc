/*
10427 - Naughty Sleepy Boys

math...
try to find the law...
number with length
1. [1-9]		count = 9		sum = 9
2. [10-99]		count = 90*2	sum = 189
3. [100-999]	count = 900*3	sum = 2889
...
now, you got it?
*/

#include<iostream>
#include<string>
#include<algorithm>
#define MAXN 8
using namespace std;

int cnt[MAXN],sum[MAXN],pow_10[MAXN],n;
char buf[100];

int process(int var)
{
	int p=lower_bound(sum,sum+MAXN,var)-sum;
	if(p==1)
		return var;

	var-=sum[p-1];
	int pos=(var-1)%p+1;
	int key=(var-1)/p+pow_10[p-1];

	sprintf(buf,"%d",key);
	return buf[pos-1]-'0';
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	sum[1]=cnt[1]=9;
	pow_10[1]=10;
	for(int i=2;i<MAXN;++i)
	{
		cnt[i]=cnt[i-1]/(i-1)*i*10;
		sum[i]=cnt[i]+sum[i-1];
		pow_10[i]=pow_10[i-1]*10;
	}

	while(scanf("%d",&n)!=EOF)
	{
		printf("%d\n",process(n));
	}

	return 0;
}

void brute()
{
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	string s="0";
	char buf[10];
	for(int i=1;i<=100000;++i)
	{
		sprintf(buf,"%d",i);
		s+=buf;
	}

	while(scanf("%d",&n)!=EOF)
	{
		cout<<s[n];
		putchar(10);
	}
}

void random_data()
{
	freopen("in","w",stdout);
	for(int i=1;i<3000;++i)
		cout<<i<<endl;
}
