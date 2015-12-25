/*
140 - Bandwidth

brute force...
暴力枚举所有情况.
逐一匹配选择最优解即可.

要求解字典序最小.
则在开始的时候可以做个映射.
这样一来在dfs的枚举下,先得到的解字典序就一定是小的...
*/

#include<iostream>
#include<string>
#include<map>
#define abs(a) ((a)<0?-(a):a)
#define MAXN 40321
#define NODES 10
#define INF 0x7f7f7f7f
using namespace std;

char buf[NODES],key[NODES];
int next[NODES][NODES],cnt[NODES],hash[NODES],tot,ans;
bool flag[NODES],tab[128];

void dfs(int dep)
{
	if(dep==tot)
	{
		int tmp=0,t;
		for(int i=0;i<tot;++i)
			hash[ buf[i] ]=i;

		for(int i=1;i<=tot;++i)
		{
			for(int j=0;j<cnt[i];++j)
			{
				t=abs(hash[i]-hash[ next[i][j] ]);
				tmp=max(tmp,t);
			}
		}
		if(tmp<ans)
		{
			ans=tmp;
			memcpy(key,buf,sizeof(buf));
		}
	}
	else for(int i=1;i<=tot;++i)
		if(!flag[i])
		{
			flag[i]=true;
			buf[dep]=i;
			dfs(dep+1);
			flag[i]=false;
		}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	string s;
	while(getline(cin,s) && s!="#")
	{
		int l=s.length();
		tot=0;
		map<char,int> mci;
		map<int,char> mic;

		memset(tab,0,sizeof(tab));
		for(int i=0;i<l;++i)
			tab[ s[i] ]=true;
		for(char i='A';i<='Z';++i)
		{
			if(tab[i])
			{
				mci[i]=++tot;
				mic[tot]=i;
			}
		}

		memset(cnt,0,sizeof(cnt));
		bool new_node=true;
		int top;
		for(int i=0;i<l;++i)
		{
			if(new_node)
			{
				top=mci[ s[i] ];
				new_node=false;
				++i;
			}
			else if(s[i]==';')
				new_node=true;
			else
				next[top][cnt[top]++]=mci[ s[i] ];
		}

		ans=INF;
		dfs(0);
		putchar(mic[key[0]]);
		for(int i=1;i<tot;++i)
			printf(" %c",mic[key[i]]);
		printf(" -> %d\n",ans);
	}

	return 0;
}
