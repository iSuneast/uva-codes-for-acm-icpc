/*
10978 - Let's Play Magic!

simulation...
use double circular linked list to simulate it...
notice that the string may be quite long...
*/

#include<iostream>
#include<string>
#define MAXN 55
using namespace std;

struct CARD
{
	string var;
	bool flag;
	CARD *next,*front;
}card[MAXN];
int n;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	while(scanf("%d",&n)!=EOF && n)
	{
		for(int i=1;i<=n;++i)
		{
			card[i].next=&card[i+1];
			card[i].front=&card[i-1];
			card[i].flag=false;
		}
		card[1].front=&card[n];
		card[n].next=&card[1];

		CARD *cur=&card[1];
		string c,s;
		for(int i=0;i<n;++i)
		{
			cin>>c>>s;
			int j=0,l=s.length();
			for(int j=0;j+1<l;++j)
			{
				while(cur->flag)
					cur=cur->next;
				cur=cur->next;
			}
			while(cur->flag)
				cur=cur->next;
			cur->var=c;
			cur->flag=true;
		}

		for(int i=1;i<n;++i)
			cout<<card[i].var<<" ";
		cout<<card[n].var<<endl;
	}

	return 0;
}
