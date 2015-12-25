/*
11488 - Hyper Prefix Sets

ds..
string...
trie...
������һ���ֵ���...
����һ���ֵ���,����Ӵ���0���Ҷ��Ӵ���1��cnt������ʴ���
����Ŀ��˼�����ֵ�����..
�Ӹ���ʼdfs,depΪdfs���
�����max(cnt*dep)
*/

#include<iostream>
#define MAXN 10000003
using namespace std;

struct TRIE
{
	int cnt;
	TRIE *l,*r;
}trie[MAXN],root;
int tot,key;
char s[203];

void clear(TRIE *cur)
{
	cur->cnt=0;
	cur->l=cur->r=NULL;
}

void insert(char *s)
{
	int l=0;
	TRIE *cur=&root;
	while(s[l])
	{
		if(s[l]=='1')
		{
			if(!cur->r)
			{
				cur->r=&trie[tot++];
				clear(cur->r);
			}
			cur=cur->r;
		}
		else
		{
			if(!cur->l)
			{
				cur->l=&trie[tot++];
				clear(cur->l);
			}
			cur=cur->l;
		}
		cur->cnt++;
		++l;
	}
}

void init()
{
	root.l=root.r=0;
	tot=0;
}

void dfs(TRIE *cur,int dep)
{
	if(cur->r)
	{
		key=max(cur->r->cnt*dep,key);
		dfs(cur->r,dep+1);
	}
	if(cur->l)
	{
		key=max(cur->l->cnt*dep,key);
		dfs(cur->l,dep+1);
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int dataset,n;
	scanf("%d",&dataset);
	while(dataset--)
	{
		init();
		scanf("%d",&n);
		while(n--)
		{
			scanf("%s",s);
			insert(s);
		}

		key=0;
		dfs(&root,1);
		printf("%d\n",key);
	}

	return 0;
}
