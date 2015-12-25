/*
144 - Student Grants

simulation...
题目看懂就会做了...
直接用队列模拟即可
*/

#include<iostream>
#include<queue>
#define MONEY 40
using namespace std;
typedef pair<int,int> pii;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int n,k;
	while(cin>>n>>k && (n||k))
	{
		queue<pii> q;
		for(int i=1;i<=n;++i)
			q.push( make_pair(i,MONEY) );

		pii atm=make_pair(1,1);
		while(!q.empty())
		{
			pii cur=q.front();	q.pop();
			if(atm.second>cur.second)
			{
				printf("%3d",cur.first);
				atm.second-=cur.second;
			}
			else if(atm.second==cur.second)
			{
				printf("%3d",cur.first);
				int t=atm.first+1;
				if(t>k)
					t=1;
				atm=make_pair(t,t);
			}
			else
			{
				cur.second-=atm.second;
				q.push(cur);
				int t=atm.first+1;
				if(t>k)
					t=1;
				atm=make_pair(t,t);
			}
		}
		cout<<endl;
	}

	return 0;
}
