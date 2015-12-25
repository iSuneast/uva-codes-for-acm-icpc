/*
115 - Climbing Trees

data struct...
lca...
小心一下重复出现的parent-child关系即可
如果重复加边的话会出现自环...

还有如果abs(n-m)=0的话,不要输出结果
*/

#include<iostream>
#include<string>
#include<map>
#define MAXN 311
using namespace std;

struct TREE
{
	int dep,idx;
	TREE *fa,*child,*sibling;
	TREE(){dep=idx=-1;fa=child=sibling=NULL;}
}tree[MAXN];

int flag[MAXN];
int tree_idx=0;

void dfs(TREE *cur,int dep)
{
	while(cur)
	{
		flag[ cur->idx ]=tree_idx;
		cur->dep=dep;
		dfs(cur->child,dep+1);
		cur=cur->sibling;
	}
}

void look_up(int u)
{
	TREE *cur=&tree[u];
	while(cur->fa)
		cur=cur->fa;
	dfs(cur,0);
}

void print(int dep,bool change)
{
	while(dep>2)
		cout<<"great ",--dep;
	if(dep==2)
		cout<<"grand ",--dep;
	if(change)
		puts("parent");
	else
		puts("child");
}

void query(int u,int v)
{
	bool change=false;
	if(tree[u].dep<tree[v].dep)
	{
		swap(u,v);
		change=true;
	}

	int n=0,m=0;
	while(tree[u].dep>tree[v].dep)
	{
		u=tree[u].fa->idx;
		++n;
	}
	if(u==v)
		return print(n,change);
	while(tree[u].fa!=tree[v].fa)
	{
		u=tree[u].fa->idx;
		v=tree[v].fa->idx;
		++n;	++m;
	}
	if(!n && !m)
		puts("sibling");
	else
	{
		cout<<min(n,m)<<" cousin";
		if(abs(n-m))
			cout<<" removed "<<abs(n-m);
		cout<<endl;
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	map<string,int> msi;
	string child,fa;
	int idx=0;
	while(cin>>child>>fa && child!="no.child" && fa!="no.parent")
	{
		if(msi.find(fa)==msi.end())
			msi[fa]=idx++;
		if(msi.find(child)==msi.end())
			msi[child]=idx++;

		int u=msi[fa],v=msi[child];
		TREE *cur=&tree[u];
		tree[v].fa=cur;
		tree[u].idx=u;	tree[v].idx=v;
		if(!cur->child)
			cur->child=&tree[v];
		else
		{
			cur=cur->child;
			while(cur->sibling)
			{
				if(cur->idx==v)
					break;
				cur=cur->sibling;
			}
			if(cur->idx!=v)
				cur->sibling=&tree[v];
		}
	}

	memset(flag,-1,sizeof(flag));
	for(int i=0;i<idx;++i)
		if(flag[i]==-1)
		{
			look_up(i);
			++tree_idx;
		}

	while(cin>>child>>fa)
	{
		if(msi.find(fa)==msi.end() || msi.find(child)==msi.end())
		{
			puts("no relation");
			continue;
		}
		int u=msi[child],v=msi[fa];
		if(flag[u]!=flag[v])
			puts("no relation");
		else
			query(u,v);
	}

	return 0;
}
