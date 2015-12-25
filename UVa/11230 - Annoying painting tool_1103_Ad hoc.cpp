/*
11230 - Annoying painting tool

Ad hoc..

why is Ad hoc? 
it seems like DP or Search...

notice that,
for the same area, we only have to change it at most once...

take the TopLeft pixel
if it's black we have to change the area from [1,1]->[r,c]
because we don't have any other method : )

and also Top(Left+1) pixel
we will solve it the same way as TopLeft pixel
because we also don't get another way to handle it...

now clear?
just scan from [1,1] to [n-r+1,m-c+1]
try to modify the error pixel you see
finally check the whole graph
*/

#include<iostream>
#define MAXN 103
using namespace std;

int n,m,r,c;
char mat[MAXN][MAXN],ori[MAXN][MAXN];

int process()
{
	int tn=n-r+1,tm=m-c+1,key=0;

	for(int i=0;i<tn;++i)
	{
		for(int j=0;j<tm;++j)
			if(ori[i][j]!=mat[i][j])
			{
				++key;
				for(int a=i;a<i+r;++a)
					for(int b=j;b<j+c;++b)
						ori[a][b]=(ori[a][b]+1)%2;
			}
	}

	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j)
			if(ori[i][j]!=mat[i][j])
				return -1;

	return key;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	while(scanf("%d%d%d%d",&n,&m,&r,&c)!=EOF
		&& (n||m||r||c))
	{
		memset(ori,0,sizeof(ori));
		for(int i=0;i<n;++i)
		{
			scanf("%s",mat[i]);
			for(int j=0;j<m;++j)
				mat[i][j]-='0';
		}

		printf("%d\n",process());
	}

	return 0;
}
