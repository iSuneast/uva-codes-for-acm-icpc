/*
10887 - Concatenation of Languages

trie...
杯具...
trie数组开得太小...
RE了一个下午...
*/

#include<iostream>
#define MAXN 1510
#define MAXLEN 13
#define ALPHA 30
using namespace std;

char dic[MAXN][MAXLEN],buf[MAXLEN];
int cnt;

struct TRIE
{
	TRIE *next[ALPHA];
	bool flag;
}trie[MAXN*MAXN],root;		//晕,是乘起来啊...

bool insert(char *a,char *b)
{
	TRIE *cur=&root;
	int p=0;
	while(a[p])
	{
		if(cur->next[ a[p]-'a' ]==NULL)
			cur->next[ a[p]-'a' ]=&trie[cnt++];
		cur=cur->next[ a[p]-'a' ];
		++p;
	}
	p=0;
	while(b[p])
	{
		if(cur->next[ b[p]-'a' ]==NULL)
			cur->next[ b[p]-'a' ]=&trie[cnt++];
		cur=cur->next[ b[p]-'a' ];
		++p;
	}
	if(!cur->flag)
	{
		cur->flag=true;
		return true;
	}
	else
		return false;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int dataset,n,m;
	scanf("%d",&dataset);
	for(int cas=1;cas<=dataset;++cas)
	{
		scanf("%d%d",&n,&m);
		gets(dic[0]);
		for(int i=0;i<n;++i)
			gets(dic[i]);

		for(int i=0;i<ALPHA;++i)
			root.next[i]=NULL;
		root.flag=false;
		while(cnt)
		{
			--cnt;
			for(int i=0;i<ALPHA;++i)
				trie[cnt].next[i]=NULL;
			trie[cnt].flag=false;
		}

		int key=0;
		for(int j=0;j<m;++j)
		{
			gets(buf);
			for(int i=0;i<n;++i)
				if(insert(dic[i],buf))
					++key;
		}
		printf("Case %d: %d\n",cas,key);
	}

	return 0;
}
