/*
661 - Blowing Fuses

simulation...
怎么会有这么简单的题目...
*/

#include<iostream>
#define MAXN 25
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int n,m,c,state[MAXN];
	int cas=1;
	while(cin>>n>>m>>c && (n||m||c))
	{
		for(int i=1;i<=n;++i)
			cin>>state[i];
		int v,key=0,cur=0;
		while(m--)
		{
			cin>>v;
			cur+=state[v];
			state[v]*=-1;
			key=max(key,cur);
		}
		cout<<"Sequence "<<cas++<<endl;
		if(key>c)
			cout<<"Fuse was blown."<<endl<<endl;
		else
			cout<<"Fuse was not blown."<<endl
			<<"Maximal power consumption was "<<key<<" amperes."<<endl<<endl;
	}

	return 0;
}
