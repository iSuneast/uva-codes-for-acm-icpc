/*
624 - CD

DP...
集合上的动态规划...
*/

#include<iostream>
#define MAXN 25
using namespace std;
int n,bound,cd[MAXN],key,ans;

void dp()
{
	key=ans=0;
	for(int s=0;s<(1<<n);++s)
	{
		int t=0;
		for(int i=0;i<n;++i)
			if(s & (1<<i))
				t+=cd[i];
		if(t>ans && t<=bound)
		{
			ans=t;
			key=s;
		}
	}
}

int main()
{
//	freopen("in.txt","r",stdin);

	while(cin>>bound)
	{
		int i=0;
		cin>>n;
		for(i=0;i<n;++i)
			cin>>cd[i];
		dp();
		bool first=true;
		for(i=0;i<n;++i)
			if(key & (1<<i))
			{
				if(first)
					first=false;
				else
					cout<<' ';
				cout<<cd[i];
			}
		cout<<" sum:"<<ans<<endl;
	}

return 0;
}
