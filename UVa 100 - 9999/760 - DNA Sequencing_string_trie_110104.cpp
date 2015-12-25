/*
 * 760 - DNA Sequencing
 * 
 * string...
 * use TIRE to handle the substring of a[] of: a[0~n], a[1~n], a[2~n]...
 * search the TIRE using substring of b[]: b[0~n], b[1~n], b[2~n]...
 * find the string with maximum length and then sort them delete the dump
 * 
 * happy coding...
 */

#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
#include<algorithm>
#define MAXN 303
using namespace std;

int h[128];

struct TRIE
{
	struct NODE
	{
		NODE *son[4];		
	}root,node[MAXN*MAXN];
	int tot;
	void init()
	{
		tot=0;
		memset(root.son,0,sizeof(root.son));
	}
	
	NODE *NewNode()
	{
		memset(node[tot].son,0,sizeof(node[tot].son));
		return &node[tot++];
	}
	
	void insert(char *s)
	{
		NODE *cur=&root;
		for(int p=0;s[p];++p)
		{
			if(!cur->son[ h[ s[p] ] ])
				cur->son[ h[ s[p] ] ]=NewNode();
			cur=cur->son[ h[ s[p] ] ];
		}
	}
	
	int find(char *s)
	{
		int p=0;
		for(NODE *cur=&root;s[p];cur=cur->son[ h[ s[p] ] ],++p)
			if(!cur->son[ h[ s[p] ] ])
				break;		
		return p;
	}
}key;

string s[MAXN];
char a[MAXN],b[MAXN];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif
    
    h['a']=0;    h['t']=1;
    h['g']=2;    h['c']=3;
    bool first=true;
    while(scanf("%s%s",a,b)!=EOF)
    {
    	if(!first)
    		putchar(10);
    	first=false;
    	
    	key.init();
    	int lb=strlen(b),l=1,n=0,t;
    	
    	for(int i=0;a[i];++i)
    		key.insert(a+i);
    	for(int i=0;b[i];++i)
    	{
    		t=key.find(b+i);
    		if(t>l)
    		{
    			l=t;	n=0;
    			t=b[i+l];	b[i+l]=0;
    			s[n++]=b+i;
    			b[i+l]=t;
    		}
    		else if(t==l)
    		{
    			t=b[i+l];	b[i+l]=0;
    			s[n++]=b+i;
    			b[i+l]=t;
    		}
    	}
    	
    	sort(s,s+n);
    	t=0;
    	for(int i=0;i<n;++i)
    	{
    		if(s[i]!=s[t])
    			s[++t]=s[i];
    	}
    	
    	if(!n)
    		puts("No common sequence.");
    	else for(int i=0;i<=t;++i)
    		cout<<s[i]<<endl;
    }

    return 0;
}

