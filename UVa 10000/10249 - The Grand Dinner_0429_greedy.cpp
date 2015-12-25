/*
10249 - The Grand Dinner

greedy...
�������������TLE��...
̰�ĵĲ���Ҳ������...
ֻ��Ҫ������������Ӵ�С����...Ȼ��̰��һ�μ���...
������Ϊʲô��Ҫ����������?
*/

#include<iostream>
#include<algorithm>
#define MAXN 110
using namespace std;
typedef pair<int,int> pii;
int g[MAXN][MAXN],n,m;
pii table[MAXN],team[MAXN];

int cmp(const pii a,const pii b)
{
	return a.first>b.first;
}

bool greedy()
{
	memset(g,0,sizeof(g));
	sort(team,team+n,cmp);
	for(int i=0;i<n;++i)
	{
		int cnt=team[i].first,p=team[i].second;
		for(int j=0;j<m && cnt;++j)
			if(table[j].first)
			{
				g[p][table[j].second+1]=1;
				--table[j].first;
				--cnt;
			}
		if(cnt)
			return false;
	}
	return true;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	while(cin>>n>>m && (n||m))
	{
		int i,j;
		for(i=0;i<n;++i)
		{
			cin>>team[i].first;
			team[i].second=i;
		}
		for(i=0;i<m;++i)
		{
			cin>>table[i].first;
			table[i].second=i;
		}
		if(greedy())
		{
			puts("1");
			for(i=0;i<n;++i)
			{
				bool first=true;
				for(j=0;j<=m;++j)
					if(g[i][j])
					{
						if(first)
							first=false;
						else
							putchar(' ');
						cout<<j;
					}
				cout<<endl;
			}
		}
		else
			puts("0");
	}

	return 0;
}
