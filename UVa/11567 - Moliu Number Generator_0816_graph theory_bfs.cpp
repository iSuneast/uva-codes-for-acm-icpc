/*
11567 - Moliu Number Generator

graph theory...
bfs...
从上往下bfs即可...
如果是奇数则+1(-1)
偶数/2

还有,注意题目的数据规模0<=S<=2^31
所以要long long...
*/

#include<iostream>
#include<set>
#include<queue>
using namespace std;
typedef pair<long long,int> plli;
int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	long long n;
	while(scanf("%lld",&n)!=EOF)
	{
		if(!n)
		{
			puts("0");
			continue;
		}

		queue<plli> q;
		set<long long> s;
		q.push(make_pair(n,0));	s.insert(n);
		while(!q.empty())
		{
			plli cur=q.front();	q.pop();
			long long var=cur.first,t;
			int p=cur.second;
			if(var&(long long)1)
			{
				t=var+1;
				if(s.find(t)==s.end())
				{
					s.insert(t);
					q.push(make_pair(t,p+1));
				}
				t=var-1;
				if(t==0)
				{
					printf("%d\n",p+1);
					break;
				}
				if(s.find(t)==s.end())
				{
					s.insert(t);
					q.push(make_pair(t,p+1));
				}
			}
			else
			{
				t=var/2;
				if(s.find(t)==s.end())
				{
					s.insert(t);
					q.push(make_pair(t,p+1));
				}
			}
		}
	}

	return 0;
}
