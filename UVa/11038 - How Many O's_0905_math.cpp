/*
11038 - How Many O's?

math...
if I'm still a middle school student.
I think this problem wouldn't be so hard for me :)

calc the ZERO's number for [m,n]
so [0,n]-[0,m]+ZeroIn(m)
try to find the law using brute force
it's no hard, but be care of details
*/

#include<iostream>
#include<ctime>
using namespace std;

long long dic[13],single[13],_10[13];

int zero(char *s)
{
	int key=0,p=0;
	while(s[p])
	{
		key+=(s[p]=='0'?1:0);
		++p;
	}
	return key;
}

long long brute(int n)
{
	int key=1;
	for(int i=1;i<=n;++i)
	{
		int t=i;
		while(t)
		{
			key+=(t%10==0?1:0);
			t/=10;
		}
	}
	return key;
}

long long calc(char *s)
{
	long long key=1;
	int l=strlen(s);
	if(l==1)
		return 1;

	key=dic[ l-1 ]*(s[0]-'0'-1)+single[ l-1 ]+l-1;

	for(int i=1;i<l-1;++i)
	{
		if(s[i]=='0')
			key+=atoi(s+i+1);
		else
			key+=dic[ l-1-i ]*(s[i]-'0')+_10[l-1-i]-1;
	}

#ifdef DEBUG
	if(key==brute(atoi(s)))
		puts("Yes");
	else
		puts("No");
#endif

	return key;
}

void random_data()
{
	freopen("in","w",stdout);
	for(int i=0;i<10000;++i)
		cout<<i<<endl;
	return ;
	srand((unsigned)time(NULL));
	int t=100;
	while(t--)
	cout<<rand()%1000<<endl;
}

int main()
{
#ifdef DEBUG
	random_data();	return 0;
	void watch();watch();
#endif

#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	dic[0]=0;	dic[1]=1;	single[0]=single[1]=1;
	_10[0]=1;
	long long more=1;
	for(int i=2;i<=10;++i)
	{
		single[i]=more*9*(i-1)+single[i-1];
		more*=10;
		_10[i-1]=more;
		dic[i]=more*i;
	}

	char m[13],n[13];

	while(scanf("%s%s",m,n)!=EOF && m[0]!='-')
	{
		printf("%lld\n",calc(n)-calc(m)+zero(m));
	}

	return 0;
}

void watch()
{
	int cnt[10],f=6;
	for(int i=1;i<=f;++i)
		cnt[i]=1;
	for(int i=1;i<1000000;++i)
	{
		int l=0,t=i,c=0;
		while(t)
		{
			++l;
			c+=(t%10==0?1:0);
			t/=10;
		}
		for(int j=l;j<=f;++j)
			cnt[j]+=c;
	}
	for(int i=1;i<=f;++i)
		cout<<i<<"   "<<cnt[i]<<endl;
}
