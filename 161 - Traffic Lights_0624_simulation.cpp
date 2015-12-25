/*
161 - Traffic Lights

simulation...
*/

#include<iostream>
#define MAXN 18000
#define INF 0x7f7f7f7f
using namespace std;

int light[MAXN+3];

void sieve(int var)
{
	for(int i=0;i<=MAXN;i+=var*2)		//有"="
		for(int j=i;j<i+var-5 && j<=MAXN;++j)
			++light[j];
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int n;
	while(cin>>n && n)
	{
		memset(light,0,sizeof(light));
		int cnt=0,start=INF;
		do
		{
			++cnt;
			start=min(start,n-5);		//应该取最小
			sieve(n);
		}while(cin>>n && n);

		int key=-1;
		for(int i=start;i<=MAXN && key==-1;++i)
			if(light[i]==cnt)
				key=i;
		if(key==-1)
			puts("Signals fail to synchronise in 5 hours");
		else
			printf("%02d:%02d:%02d\n",key/3600,key/60%60,key%60);
	}

	return 0;
}
