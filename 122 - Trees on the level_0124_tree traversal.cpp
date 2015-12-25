/*
122 - Trees on the level
*/

#include<iostream>
#include<cstring>
#include<cctype>

using namespace std;

char s[500];
int failed,n,ans[500];

struct node
{
	bool flag;
	int v;
	node *left,*right;
}*root;

node * newnode()
{
	node *u=(node *)malloc(sizeof(node));
	if(u!=NULL)
	{
		u->flag=0;
		u->left=u->right=NULL;
	}
	return u;
}

void addnode(int v,char *s)
{
	int n=strlen(s);
	int i;
	node *u=root;
	for(i=0;i<n;i++)
		if(s[i]=='L')
		{
			if(u->left==NULL)
				u->left=newnode();
			u=u->left;
		}
		else if(s[i]=='R')
		{
			if(u->right==NULL)
				u->right=newnode();
			u=u->right;
		}
		if(u->flag)
			failed=1;
		u->v=v;
		u->flag=1;
}

int get()
{
	int v=0,i;
	failed=0;
	root=newnode();
	if(cin>>s)
	{
		do	{
			sscanf(s+1,"%d",&v);
			i=0;
			while(s[i]!=',')
				i++;
			addnode(v,s+i+1);
			cin>>s;
		}while(strcmp(s,"()"));
	}
	else
		return 0;
	return 1;
}

int bfs()
{
	int front=0,rear=1;
	node *q[300];
	q[0]=root;
	while(front<rear)
	{
		node *u=q[front++];
		if(!u->flag)
			return 0;
		ans[n++]=u->v;
		if(u->left!=NULL)
			q[rear++]=u->left;
		if(u->right!=NULL)
			q[rear++]=u->right;
		free(u);
	}
	return 1;
}

int main()
{
//	freopen("in.txt","r",stdin);
	int i;
	while(get())
	{
//		failed=0;					//那时就是这个地方错了.....
		n=0;
		if(bfs()&&!failed)
		{
			cout<<ans[0];
			for(i=1;i<n;i++)
				cout<<' '<<ans[i];
			cout<<endl;
		}
		else
			cout<<"not complete"<<endl;
	}
return 0;
}