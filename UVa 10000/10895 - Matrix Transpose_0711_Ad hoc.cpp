/*
10895 - Matrix Transpose

Ad hoc...
给特殊形式的矩阵转制就可以了...
*/

#include<iostream>
#include<sstream>
#include<cstdio>
#include<iomanip>
#include<cmath>
#include<cstring>
#include<string>
#include<queue>
#include<stack>
#include<algorithm>
#include<map>
#include<vector>
#include<set>
#define INF 0x7f7f7f7f
#define eps 1e-9
#define MAXN 10010
using namespace std;
typedef pair<int,int> pii;

vector<pii> mat[MAXN];
int n,m,pos[MAXN];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(int i=1;i<=m;++i)
			mat[i].clear();
		int sz,var;
		for(int k=1;k<=n;++k)
		{
			scanf("%d",&sz);
			for(int i=0;i<sz;++i)
				scanf("%d",&pos[i]);
			for(int i=0;i<sz;++i)
			{
				scanf("%d",&var);
				mat[ pos[i] ].push_back(make_pair(k,var));
			}
		}

		printf("%d %d\n",m,n);
		for(int i=1;i<=m;++i)
		{
			sz=mat[i].size();
			sort(mat[i].begin(),mat[i].end());

			printf("%d",sz);
			for(int j=0;j<sz;++j)
				printf(" %d",mat[i][j].first);
			putchar('\n');
			bool first=true;
			for(int j=0;j<sz;++j)
			{
				if(!first)
					putchar(' ');
				first=false;
				printf("%d",mat[i][j].second);
			}
			putchar('\n');
		}
	}

	return 0;
}
