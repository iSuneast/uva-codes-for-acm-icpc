/*
11234 - Expressions

data struct...
simulation...
�ú�׺���ʽ����һ�ű��ʽ��
Ȼ���������һ��bfs����
���ʽڵ������,���Ǵ���...


--------------------sample------------------
w
wz
wzy
wzyx
Ȼ������I,wz����,���zIw,Ȼ�����
yx(zIw)
����P,yx����,���xPy,Ȼ�����
(zIw)(xPy)
����P,(zIw).(xPy)����,���(xPy)M(zIw) 
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
