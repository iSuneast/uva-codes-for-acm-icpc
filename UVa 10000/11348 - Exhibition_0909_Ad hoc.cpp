/*
11348 - Exhibition

Ad hoc...
*
* The stamp type is called unique if and only if 
* this type of stamps of owned only by one person
*
so for test case
3
4 1 2 3 1
2 4 5
3 4 2 6
the answer is the same as
3
3 1 2 3
2 4 5
3 4 2 6
use set to store the stamps a person own and check whether it's unique

all the test data is legal
*/

#include<iostream>
#include<set>
#define MAXN 10003
#define FRIEND 53
using namespace std;

int cnt[MAXN],data[FRIEND][FRIEND];
int n,tot;
set<int> s;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int dataset;
	scanf("%d",&dataset);
	for(int cas=1;cas<=dataset;++cas)
	{
		scanf("%d",&n);
		memset(cnt,0,sizeof(cnt));
		for(int i=1;i<=n;++i)
		{
			scanf("%d",&data[i][0]);
			s.clear();
			for(int j=1;j<=data[i][0];++j)
			{
				scanf("%d",&data[i][j]);
				if(s.find(data[i][j])==s.end())
				{
					s.insert(data[i][j]);
					++cnt[ data[i][j] ];
				}
			}
		}

		tot=0;
		for(int i=0;i<MAXN;++i)
		{
			if(cnt[i]==1)
				++tot;
		}

		printf("Case %d:",cas);
		for(int i=1;i<=n;++i)
		{
			int key=0;
			s.clear();
			for(int j=1;j<=data[i][0];++j)
			{
				if(cnt[ data[i][j] ]==1 && s.find(data[i][j])==s.end())
				{
					++key;
					s.insert(data[i][j]);
				}
			}
			printf(" %.6lf%%",key*100.0/tot);
		}
		putchar(10);
	}

	return 0;
}
