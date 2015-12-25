/*
10928 - My Dear Neighbours

data struct...
ֱ����һ����Ķ�������...
������С�����е���ǽ�...
*/

#include<iostream>
#define MAXN 1003
#define INF 0x3f3f3f3f
using namespace std;

int cnt[MAXN],n;
char buf[MAXN*10];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int dataset;
	scanf("%d",&dataset);
	while(dataset--)
	{
		scanf("%d",&n);gets(buf);
		int _min=INF;
		for(int i=1;i<=n;++i)
		{
			gets(buf);
			char *token=strtok(buf," ");
			cnt[i]=0;
			while(token)
			{
				++cnt[i];
				token=strtok(NULL," ");
			}
			_min=min(_min,cnt[i]);
		}

		bool first=true;
		for(int i=1;i<=n;++i)
			if(cnt[i]==_min)
			{
				if(!first)
					putchar(' ');
				first=false;
				printf("%d",i);
			}
		putchar(10);
	}

	return 0;
}
