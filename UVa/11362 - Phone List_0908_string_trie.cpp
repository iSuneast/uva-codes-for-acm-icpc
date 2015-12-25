/*
11362 - Phone List

string...
trie..
oh~ I have got dozen of WA...
a silly mistake trap me...

for every string in the input
a shouldn't be the prefix of b, nor b
*/

#include<iostream>
#include<ctime>
#define MAXN 100000
using namespace std;

struct TRIE
{
	TRIE *num[10];
	bool flag;
	void init(){memset(num,0,sizeof(num));flag=false;}
}root,data[MAXN];;
int tot,n;

bool insert(char *s)
{
	int p=0;
	TRIE *cur=&root;
	while(s[p])
	{
		if(!cur->num[ s[p]-'0' ])
		{
			data[tot].init();
			cur->num[ s[p]-'0' ]=&data[tot++];
		}
		cur=cur->num[ s[p++]-'0' ];

		if(cur->flag)
			return false;
	}
	cur->flag=true;
	for(int i=0;i<10;++i)
		if(cur->num[i])
			return false;
	return true;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int dataset;
	char str[130];

	scanf("%d",&dataset);
	while(dataset--)
	{
		root.init();
		tot=0;

		bool fade=false;
		scanf("%d",&n);
		while(n--)
		{
			scanf("%s",str);
			if(!fade && !insert(str))
				fade=true;
		}
		puts(fade?"NO":"YES");
	}

	return 0;
}

void random_data()
{
	freopen("in","w",stdout);

	int dataset=100;
	srand((unsigned)time(NULL));
	cout<<dataset<<endl;
	while(dataset--)
	{
		int n=rand()*rand()%1000+1;
		cout<<n<<endl;
		while(n--)
		{
			int l=rand()%7+3;
			while(l--)
				cout<<rand()%10;
			cout<<endl;
		}
		cout<<endl;
	}
}
