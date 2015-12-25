/*
699 - The Falling Leaves

data struct...
���Ƕ�����...
��ws�Ĵ������...

�����Ĺ�����ʵ���Ժϲ������й���������
�ݹ鶨��
	root->left->right==root
	root->right->left==root
�����rootΪ���,һ��dfs�������ǰ���������...
*/

#include<iostream>
using namespace std;

struct TREE
{
	int var;
	TREE *l,*r,*fa;
	TREE(){var=0;l=r=fa=NULL;}
	void init(){var=0;l=r=fa=NULL;}
}root;
int var;

void build(TREE *cur,bool l,bool isroot)
{
	if(scanf("%d",&var)==EOF || var==-1)
		return ;
	if(isroot)
	{
		cur->var+=var;
		build(cur,true,false);
		build(cur,false,false);
		return ;
	}

	if(l)
	{
		if(!cur->l)
		{
			cur->l=new TREE;
			cur->l->fa=cur;
		}
		cur=cur->l;
	}
	else
	{
		if(!cur->r)
		{
			cur->r=new TREE;
			cur->r->fa=cur;
		}
		cur=cur->r;
	}

	cur->var+=var;

	if(l)
	{
		build(cur,true,false);
		if(cur->fa->fa)
			build(cur->fa->fa,true,false);
		else
			build(cur->fa,false,true);
	}
	else
	{
		if(cur->fa->fa)
			build(cur->fa->fa,false,false);
		else
			build(cur->fa,true,true);
		build(cur,false,false);
	}
}

bool first;

void dfs(TREE *cur)
{
	if(!cur)
		return ;
	dfs(cur->l);

	if(!first)
		putchar(' ');
	first=false;
	printf("%d",cur->var);

	dfs(cur->r);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int cas=1;
	while(build(&root,true,true),root.var)
	{
		printf("Case %d:\n",cas++);
		first=true;
		dfs(&root);
		putchar('\n');
		putchar('\n');
		root.init();
	}

	return 0;
}
