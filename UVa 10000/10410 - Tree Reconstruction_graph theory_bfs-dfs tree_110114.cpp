/*
 * 10410 - Tree Reconstruction
 * 
 * graph theory...
 * Tree Reconstruction
 * 
 * BFS + DFS -> TREE
 * just try to find the principle...
 * give 2 array bfs[] dfs[]
 * use a stack to store the current dfs[] node
 * # if dfs[i] is early than dfs[i-1] in bfs[]
 *      @ if the stack has more than 1 element, dfs[i] is the sibling of dfs[i-1]
 *      @ else, dfs[i] is the son of dfs[i-1]
 * # else
 *     @ delete the top element in the stack until the top node's place is early than dfs[i]'s place in bfs[]
 *       now dfs[i] is the sibling of top node
 *       
 * just do it..
 * happy coding...
 */

#include<cstdio>
#include<cstring>
#include<vector>
#define MAXN 1003
using namespace std;
struct NODE
{
	vector<int> child;
}node[MAXN];
int n,bfs[MAXN],dfs[MAXN],h[MAXN],s[MAXN];

void read()
{
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&bfs[i]);
		node[i].child.clear();
		h[ bfs[i] ]=i;
	}
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&dfs[i]);
	}
}

void output()
{
	for(int i=1;i<=n;++i)
	{
		printf("%d:",i);
		for(int j=0,sz=node[i].child.size(); j<sz; ++j)
			printf(" %d",node[i].child[j]);
		putchar(10);
	}
}

void build()
{
	int top=0;
	s[top++]=dfs[1];
	
	for(int i=2;i<=n;++i)
	{
		int p=h[ dfs[i] ];
		int fa=h[ dfs[i-1] ];
		if(fa<p)
		{
			if(fa+1 == p && top>1)
			{
				--top;
				node[ s[top-1] ].child.push_back(dfs[i]);
			}
			else
				node[ dfs[i-1] ].child.push_back(dfs[i]);
		}
		else
		{
			while(top>0 && p<h[ s[top-1] ])
				--top;
			--top;
			
			node[ s[top-1] ].child.push_back(dfs[i]);
		}
		s[top++]=dfs[i];
	}
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif
    
    while(scanf("%d",&n)!=EOF)
    {
    	read();
    	build();
    	output();
    }

    return 0;
}

