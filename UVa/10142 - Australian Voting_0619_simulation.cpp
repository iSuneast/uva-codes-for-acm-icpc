/*
10142 - Australian Voting

simulation...
Ö±½ÓÄ£Äâ...
*/

#include<iostream>
#include<sstream>
#include<string>
#define MAXPPL 25
#define MAXN 1010
#define INF 0x7f7f7f7f
using namespace std;

int ballot[MAXN][MAXPPL],cnt[MAXPPL];
string name[MAXPPL],s;
int tot,n,rem;
int flag[MAXPPL];

void vote()
{
	memset(flag,0,sizeof(flag));
	rem=0;

	while(true)
	{
		memset(cnt,0,sizeof(cnt));
		
		for(int j=0;j<tot;++j)
		{
			int i=0;
			while(flag[ ballot[j][i] ])
				++i;
			++cnt[ ballot[j][i] ];
		}

		int mini=INF,maxn=0;
		for(int i=1;i<=n;++i)
			if(!flag[i])
			{
				mini=min(mini,cnt[i]);
				maxn=max(maxn,cnt[i]);
			}

		if(maxn>tot/2)
			for(int i=1;i<=n;++i)
				if(cnt[i]==maxn)
				{
					cout<<name[i]<<endl;
					return ;
				}

		if(mini==INF)
		{
			for(int i=1;i<=n;++i)
				if(flag[i]==rem)
					cout<<name[i]<<endl;
			return ;
		}

		++rem;
		for(int i=1;i<=n;++i)
			if(cnt[i]==mini)
				flag[i]=rem;
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int dataset;
	cin>>dataset;
	while(dataset--)
	{
		cin>>n;
		getline(cin,s);
		for(int i=1;i<=n;++i)
			getline(cin,name[i]);

		tot=0;
		while(getline(cin,s) && s!="")
		{
			stringstream sin(s);
			int p=0;
			while(sin>>ballot[tot][p])
				++p;
			++tot;
		}

		vote();

		if(dataset)
			cout<<endl;
	}

	return 0;
}
