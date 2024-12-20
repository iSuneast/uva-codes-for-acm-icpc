/*
11491 - Erasing and Winning

greedy...
每次对链表里面的元素从当前位置的前一个开始扫描
如果当前元素比下一个元素小
则删除当前元素
指针变为被删除元素的下一个元素的上一个元素...
(无需从头开始扫描)
*/

#include<iostream>
#define MAXN 100010
using namespace std;

struct list
{
	char var;
	list *back,*front;
}ls[MAXN];

int n,d;
char s[MAXN];

void make_list()
{
	ls[0].var=s[0];
	ls[0].back=NULL;
	for(int i=1;i<n;++i)
	{
		ls[i].var=s[i];
		ls[i-1].front=&ls[i];
		ls[i].back=&ls[i-1];
	}
	ls[n-1].front=NULL;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	while(scanf("%d%d",&n,&d)!=EOF && (n||d))
	{
		scanf("%s",s);
		make_list();
		list *cur=&ls[0];
		for(int i=0;i<d;++i)
		{
			while(cur->front && cur->var >= cur->front->var )
				cur=cur->front;
			if(cur->back)
				cur->back->front=cur->front;
			if(cur->front)
				cur->front->back=cur->back;
			cur->var=0;
			if(cur->front)
				cur=cur->front;
			if(cur->back)
				cur=cur->back;

		}
		for(int i=0;i<n;++i)
			if(ls[i].var)
				putchar(ls[i].var);
		putchar('\n');
	}

	return 0;
}
