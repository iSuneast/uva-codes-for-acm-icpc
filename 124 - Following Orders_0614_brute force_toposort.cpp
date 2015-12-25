/*
124 - Following Orders

brute force...
暴力回溯+剪枝就可以了...
*/

#include<iostream>
#include<sstream>
#include<string>
#include<algorithm>
#define MAXN 25
using namespace std;

char key[MAXN],cons[MAXN<<1][2],ans[MAXN];
int cnt,tot;
int flag[MAXN];
int next[MAXN][MAXN<<1],sz[MAXN],hash[MAXN];

bool chk(int cur)
{
	for(int i=0;i<sz[cur];++i)
	{
		int v=next[cur][i];
		if(flag[v]==-1)
			return false;
	}
	return true;
}

bool dfs(int dep)
{
	if(dep==cnt)
	{
		puts(ans);
		return true;
	}
	else for(int i=0;i<cnt;++i)
		if(flag[i]==-1)
		{
			ans[dep]=hash[i];
			flag[i]=dep;
			if(chk(i))
				dfs(dep+1);
			flag[i]=-1;
		}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	string s;
	bool first=true;
	while(getline(cin,s))
	{
		if(!first)
			putchar('\n');
		first=false;

		stringstream strin(s);
		cnt=0;
		while(strin>>key[cnt])
			++cnt;
		sort(key,key+cnt);
		for(int i=0;i<cnt;++i)
		{
			hash[ key[i] ]=i;
			hash[i]=key[i];
		}

		getline(cin,s);
		stringstream strin2(s);
		tot=0;
		memset(sz,0,sizeof(sz));
		while(strin2>>cons[tot][1]>>cons[tot][0])
		{
			int p=hash[ cons[tot][0] ];
			next[p][ sz[p]++ ]=hash[ cons[tot][1] ];
			++tot;
		}

		ans[cnt]=0;
		memset(flag,-1,sizeof(flag));
		dfs(0);
	}

	return 0;
}
