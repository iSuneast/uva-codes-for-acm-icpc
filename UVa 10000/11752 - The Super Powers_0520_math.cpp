/*
11752 - The Super Powers

math...
重点在判断溢出...
判 a*b=c 是否溢出,则
只需判 c/a==b 是否成立即可...
p^q为解,p->[2,65535],q->[4,64]的非素数
*/

#include<iostream>
#include<algorithm>
#define MAXN 67820
using namespace std;
typedef unsigned long long ull;

ull key[MAXN];
bool notprime[100];

void init()
{
	memset(notprime,0,sizeof(notprime));
	for(ull i=2;i<=64;++i)
		for(ull j=i+i;j<=64;j+=i)
			notprime[j]=1;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("11752-out.txt","w",stdout);
#endif

	init();
	int cnt=0;
	for(int i=2;i<=65535;++i)
	{
		ull t=i,pre;
		for(int j=2;;++j)
		{
			pre=t;
			t*=i;
			if(t/pre!=i)
				break;
			if(notprime[j])
				key[cnt++]=t;
		}
	}
	sort(key,key+cnt);
	int n=0;
	for(int i=0;i<cnt;++i)
		if(key[n]!=key[i])
			key[++n]=key[i];
	puts("1");
	for(int i=0;i<=n;++i)
		cout<<key[i]<<endl;		//用printf竟然wa...

	return 0;
}
