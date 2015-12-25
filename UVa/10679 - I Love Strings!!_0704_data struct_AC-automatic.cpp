/*
10679 - I Love Strings!!

data struct...
AC_automatic
ac自动机...
其实就是trie和kmp的合体...

题目的规模不是很大...
可以直接用多叉树简化代码...
但是左儿子右兄弟表示法可以节省大量内存...
在大规模数据下应该是有更好的应用价值...
*/

#include<iostream>
#include<queue>
#include<vector>
#define MAXN 100010
#define MAXLEN 1010
using namespace std;

struct AC
{
	AC *fail,*child,*sibling;
	char c;
	bool flag;
	vector<int> pos;
	AC(){fail=child=sibling=NULL;c=0;flag=false;}
};

void insert(char *s,int pos,AC &root)
{
	AC *cur=&root;
	int p=0;
	while(s[p])
	{
		if(!cur->child)
		{
			cur->child=new AC;
			cur=cur->child;
			cur->c=s[p++];
			continue;
		}
		cur=cur->child;
		while(cur->c!=s[p] && cur->sibling)
			cur=cur->sibling;
		if(cur->c!=s[p])
		{
			cur->sibling=new AC;
			cur=cur->sibling;
			cur->c=s[p];
		}
		++p;
	}
	cur->pos.push_back(pos);
}

void build(AC &root)
{
	AC *cur=&root;
	cur->fail=NULL;
	queue<AC*> q;
	q.push(cur);

	while(!q.empty())
	{
		cur=q.front();
		if(cur==&root)
		{
			cur=cur->child;
			while(cur)
			{
				q.push(cur);
				cur->fail=&root;
				cur=cur->sibling;
			}
			q.pop();
			continue;
		}

		cur=cur->child;
		while(cur)
		{
			AC *p=q.front()->fail;
			while(p && !cur->fail)
			{
				AC *t=p->child;
				while(t)
				{
					if(t->c==cur->c)
					{
						cur->fail=t;
						break;
					}
					t=t->sibling;
				}
				p=p->fail;
			}
			if(!p)
			{
				cur->fail=&root;
			}
			q.push(cur);
			cur=cur->sibling;
		}
		q.pop();
	}
}

char tar[MAXN],str[MAXLEN];
bool flag[MAXLEN];

void query(AC &root)
{
	int p=0;
	AC *cur=&root;
	while(tar[p])
	{
		AC *tmp=cur;
		while(cur)
		{
			cur=cur->child;
			while(cur && cur->c!=tar[p])
				cur=cur->sibling;
			if(!cur)
				cur=tmp=tmp->fail;
			else
				break;
		}
		if(!cur)
			cur=&root;
		tmp=cur;
		while(cur && !cur->flag)
		{
			cur->flag=true;
			int sz=cur->pos.size();
			for(int i=0;i<sz;++i)
				flag[ cur->pos[i] ]=true;
			cur=cur->fail;
		}
		cur=tmp;
		++p;
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int dataset;
	scanf("%d",&dataset);
	while(dataset--)
	{
		AC root;
		scanf("%s",tar);
		int q;
		scanf("%d",&q);
		for(int i=0;i<q;++i)
		{
			scanf("%s",str);
			insert(str,i,root);
			flag[i]=false;
		}
		build(root);
		query(root);
		for(int i=0;i<q;++i)
		{
			if(flag[i])
				puts("y");
			else
				puts("n");
		}
	}

	return 0;
}
