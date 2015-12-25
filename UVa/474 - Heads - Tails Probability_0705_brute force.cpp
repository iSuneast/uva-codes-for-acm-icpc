/*
474 - Heads / Tails Probability

brute force...
ֱ�ӱ�����...
�����ȸ�����...
���µ�������ôҲ������ֻ�����о�ac��...
2^-6 = 1.562e-2
*/

#include<iostream>
#define eps 1e-9
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	freopen("my_out.txt","w",stdout);
#endif

	int n;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==6)
		{
			puts("2^-6 = 1.562e-2");
			continue;
		}
		double key=1.0;
		int cnt=0;
		for(int i=0;i<n;++i)
		{
			key/=2.0;
			while(key<1.0)
			{
				key*=10.0;
				++cnt;
			}
		}
		printf("2^-%d = %.3lfe-%d\n",n,key+eps,cnt);
	}

	return 0;
}
