/*
10150 - Doublets

trie...
字典树...
终于知道怎么理解messi大神的那题了...
*/

#include<iostream>
#include<queue>
#include<vector>
#define MAXN 25145
#define MAXLEN 18
#define BASE 26
#define DIF 'a'
using namespace std;

struct TRIE
{
	TRIE *child[BASE];
	int idx;
	TRIE()
	{
		idx=-1;
		for(int i=0;i<BASE;++i)
			child[i]=NULL;
	}
}root;

char dic[MAXN][MAXLEN],start[MAXLEN],end[MAXLEN];
int tot,len[MAXN],fa[MAXN];
vector<int> edge[MAXN];

void insert(char *s)
{
	TRIE *cur=&root;
	int p=0;
	while(s[p])
	{
		if(!cur->child[ s[p]-DIF ])
			cur->child[ s[p]-DIF ]=new TRIE;
		cur=cur->child[ s[p]-DIF ];
		++p;
	}
	len[tot]=p;
	cur->idx=tot;
}

void dfs(TRIE *cur,bool more,int idx,int dep)
{
	if(dep==len[idx])
	{
		if(cur->idx!=-1 && !more)
		{
			edge[idx].push_back(cur->idx);
			edge[cur->idx].push_back(idx);
		}
	}
	else for(int i=0;i<BASE;++i)
		if(cur->child[i])
		{
			if(i+DIF==dic[idx][dep])
				dfs(cur->child[i],more,idx,dep+1);
			else if(more)
				dfs(cur->child[i],false,idx,dep+1);
		}
}

int index(char *s)
{
	TRIE *cur=&root;
	int p=0;
	while(s[p])
		cur=cur->child[ s[p++]-DIF ];
	return cur->idx;
}

void output(int idx)
{
	if(idx==-2)
		return ;
	output(fa[idx]);
	puts(dic[idx]);
}

void bfs(int idx,int tar)
{
	queue<int> q;
	q.push(idx);
	memset(fa,-1,sizeof(fa));
	fa[idx]=-2;
	while(!q.empty())
	{
		idx=q.front();	q.pop();
		int sz=edge[idx].size();
		for(int i=0;i<sz;++i)
		{
			int v=edge[idx][i];
			if(fa[v]==-1)
			{
				fa[v]=idx;
				if(v==tar)
					return output(tar);
				q.push(v);
			}
		}
	}
	puts("No solution.");
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	tot=0;
	while(gets(dic[tot]) && dic[tot][0])
		insert(dic[tot]),++tot;
	for(int i=0;i<tot;++i)
		dfs(&root,true,i,0);

	bool first=true;
	while(scanf("%s%s",start,end)!=EOF)
	{
		if(!first)
			putchar('\n');
		first=false;

		if(strlen(start)!=strlen(end))
			puts("No solution.");
		else if(strcmp(start,end)==0)
			puts(start);
		else
			bfs(index(start),index(end));
	}

	return 0;
}
