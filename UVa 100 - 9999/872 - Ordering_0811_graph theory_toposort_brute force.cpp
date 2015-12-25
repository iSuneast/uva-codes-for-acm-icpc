/*
872 - Ordering

graph theory...
toposort...
��������+ǿ��֦...
��Լ������,��ÿ�β����µ�Ԫ��ʱ,�ж������Ƿ�Ϸ�
�ж��Ƿ�Ϸ�,ֻ���¼ĳ��Ԫ�ص�����ǰ��...
Ȼ���ж�����ǰ���Ƿ�����������,���ڵĻ������...
��������в��Ϸ�...
*/

#include<iostream>
#include<algorithm>
#include<vector>
#define SZ 1000
#define MAXN 30
using namespace std;

char buf[SZ],s[MAXN];
vector<char> vc[MAXN];
int n,sz[MAXN];
char _hash[128];

void input()
{
	for(int i=0;i<MAXN;++i)
		vc[i].clear();

	gets(buf);	gets(buf);
	char *token=strtok(buf," ");
	n=0;
	while(token)
	{
		s[n++]=token[0];
		token=strtok(NULL," ");
	}
	sort(s,s+n);
	for(int i=0;i<n;++i)
	{
		_hash[ s[i] ]=i;
		_hash[i]=s[i];
	}


	gets(buf);
	char u,v;
	token=strtok(buf," ");
	while(token)
	{
		sscanf(token,"%c<%c",&u,&v);
		vc[ _hash[v] ].push_back( _hash[u] );
		token=strtok(NULL," ");
	}

	for(int i=0;i<n;++i)
		sz[i]=vc[i].size();
}

bool flag[MAXN],got;
int p[MAXN];

void output()
{
	got=true;
	putchar(_hash[ p[0] ]);
	for(int i=1;i<n;++i)
		printf(" %c",_hash[ p[i] ]);
	putchar(10);
}

bool chk(int u)
{
	for(int i=0;i<sz[u];++i)
		if(!flag[ vc[u][i] ])
			return false;
	return true;
}

void dfs(int dep)
{
	if(dep==n)
		output();
	else for(int i=0;i<n;++i)
		if(!flag[i])
		{
			flag[i]=true;
			p[dep]=i;
			if(chk(i))
				dfs(dep+1);
			flag[i]=false;
		}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int dataset;
	scanf("%d",&dataset);gets(buf);
	while(dataset--)
	{
		input();

		got=false;
		dfs(0);
		if(!got)
			puts("NO");

		if(dataset)
			putchar(10);
	}

	return 0;
}
