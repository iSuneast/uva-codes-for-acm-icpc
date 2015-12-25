/*
154 - Recycling

brute force...

5个垃圾桶的顺序也是可以换的...
所以要重映射一下...
*/

#include<iostream>
#define MAXN 110
#define INF 0x7f7f7f7f
using namespace std;

int cnt[MAXN];
char buf[MAXN],bin[MAXN][5],hash[MAXN];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	hash['r']=0;
	hash['o']=1;
	hash['y']=2;
	hash['g']=3;
	hash['b']=4;

	while(gets(buf) && strcmp(buf,"#"))
	{
		int n=0;
		do
		{
			int p=2;
			for(int i=0;i<5;++i,p+=4)
				bin[n][ hash[ buf[p-2] ] ]=buf[p];
			++n;
			gets(buf);
		}while(buf[0]!='e');

		memset(cnt,0,sizeof(cnt));
		int key=n;
		cnt[key]=INF;

		for(int i=0;i<n;++i)
		{
			for(int j=i+1;j<n;++j)
				for(int k=0;k<5;++k)
					if(bin[i][k]!=bin[j][k])
					{
						++cnt[i];
						++cnt[j];
					}
			if(cnt[i]<cnt[key])
				key=i;
		}
		printf("%d\n",key+1);
	}

	return 0;
}
