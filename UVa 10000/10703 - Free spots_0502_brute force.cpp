/*
10703 - Free spots

brute force...
直接暴力枚举即可...
*/

#include<iostream>
#define MAXN 510
using namespace std;

bool g[MAXN][MAXN];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int w,h,n;
	while(cin>>w>>h>>n && (w||h||n))
	{
		int i,j,t,x1,y1,x2,y2;
		memset(g,0,sizeof(g));
		for(t=0;t<n;++t)
		{
			cin>>x1>>y1>>x2>>y2;
			if(x1>x2)
				swap(x1,x2);
			if(y1>y2)
				swap(y1,y2);
			for(i=x1;i<=x2;++i)
				for(j=y1;j<=y2;++j)
					g[i][j]=1;
		}
		int key=0;
		for(i=1;i<=w;++i)
			for(j=1;j<=h;++j)
				if(!g[i][j])
					++key;
		if(key==0)
			puts("There is no empty spots.");
		else if(key==1)
			puts("There is one empty spot.");
		else
			cout<<"There are "<<key<<" empty spots."<<endl;
	}


	return 0;
}
