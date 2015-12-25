/*
11234 - Expressions

data struct...
simulation...
用后缀表达式建立一颗表达式树
然后对树进行一次bfs遍历
访问节点的逆序,就是答案了...


--------------------sample------------------
w
wz
wzy
wzyx
然后遇到I,wz出队,变成zIw,然后入队
yx(zIw)
遇到P,yx出队,变成xPy,然后入队
(zIw)(xPy)
遇到P,(zIw).(xPy)出队,变成(xPy)M(zIw) 
--------------------------------------------
*/

#include<iostream>
#include<queue>
#include<stack>
#define MAXN 10010
using namespace std;

struct TREE
{
	int l,r;
}tree[MAXN];

char s[MAXN],key[MAXN];
int l;

void process()
{
	stack<int> si;
	for(int i=0;i<l;++i)
	{
		if(islower(s[i]))
			tree[i].l=tree[i].r=-1;
		else
		{
			tree[i].r=si.top();	si.pop();
			tree[i].l=si.top();	si.pop();
		}
		si.push(i);
	}

	queue<int> q;
	q.push(l-1);
	int p=l-1;
	key[p--]=s[l-1];

	while(!q.empty())
	{
		int u=q.front();	q.pop();
		if(tree[u].l!=-1)
		{
			key[p--]=s[ tree[u].l ];
			q.push(tree[u].l);
			key[p--]=s[ tree[u].r ];
			q.push(tree[u].r);
		}
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int dataset;
	scanf("%d",&dataset);
	while(dataset--)
	{
		scanf("%s",s);
		l=strlen(s);

		process();

		key[l]=0;
		puts(key);
	}

	return 0;
}
