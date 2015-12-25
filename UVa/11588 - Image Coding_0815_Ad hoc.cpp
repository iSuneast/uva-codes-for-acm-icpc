/*
11588 - Image Coding

Ad hoc...
算出词频最多的字母即可...
*/

#include<iostream>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int dataset,r,c,m,n,h[128];
	char buf[33];
	scanf("%d",&dataset);
	for(int cas=1;cas<=dataset;++cas)
	{
		memset(h,0,sizeof(h));
		scanf("%d%d%d%d",&r,&c,&m,&n);
		int _max=0;
		for(int j=0;j<r;++j)
		{
			scanf("%s",buf);
			for(int i=0;i<c;++i)
				_max=max(_max,++h[ buf[i] ]);
		}

		int cnt=0;
		for(char i='A';i<='Z';++i)
			if(h[i]==_max)
				++cnt;

		printf("Case %d: %d\n",cas,(r*c-cnt*_max)*n+cnt*_max*m);
	}

	return 0;
}
