/*
10954 - Add All
....
( ⊙ o ⊙ )啊！....
又搞这种无聊的错误啊...
....orz...
*/

#include<iostream>
#include<queue>

using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);
	priority_queue<long long,vector<long long>,greater<long long> > q;
	int n,i;
	long long ans,t;
	while(cin>>n && n)
	{
		for(i=0;i<n;i++)
			cin>>t,
			q.push(t);
		ans=0;
		while(--n)
		{
			t=q.top();q.pop();
			t+=q.top();q.pop();
			q.push(t);
			ans+=t;
		}
		q.pop();			//晕呐...忘了清空了...
		cout<<ans<<endl;
	}

return 0;
}
