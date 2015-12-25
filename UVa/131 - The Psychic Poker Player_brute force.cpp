/*
131 - The Psychic Poker Player

brute force....
其实就是情况很多而已...
逐个考虑...
然后认真敲代码就可以了...
*/

#include<iostream>
using namespace std;

const char card[]="A23456789TJQKA";
const char suit[]="CDHS";
const char dic[9][30]={"straight-flush","four-of-a-kind","full-house","flush","straight","three-of-a-kind","two-pairs","one-pair","highest-card"};
int cnt[128],key;
char c[10][3];

bool input()
{
	for(int i=0;i<10;++i)
		if(scanf("%s",c[i])==EOF)
			return false;
	return true;
}

bool flag[10];

void process()
{
	bool three=false,four=false,flush=false,straight=false;
	int two=0;

	for(int i=0;i<=13;++i)
	{
		if(cnt[ card[i] ])
		{
			if(cnt[ card[i] ]==4)
				four=true;
			else if(cnt[ card[i] ]==3)
				three=true;
			else if(cnt[ card[i] ]==2)
				++two;

			if(i+4<=13)
			{
				bool bk=false;
				for(int j=i;j<i+5 && !bk;++j)
					if(!cnt[ card[j] ])
						bk=true;
				if(!bk)
					straight=true;
			}
		}
	}

	for(int i=0;i<4;++i)
		if(cnt[ suit[i] ]==5)
			flush=true;

	if(flush && straight)	key=min(key,0);
	if(four)				key=min(key,1);
	if(three && two)		key=min(key,2);
	if(flush)				key=min(key,3);
	if(straight)			key=min(key,4);
	if(three)				key=min(key,5);
	if(two==2)				key=min(key,6);
	if(two)					key=min(key,7);
}

void calc()
{
	for(int i=0;i<10;++i)
		if(flag[i])
		{
			++cnt[ c[i][0] ];
			++cnt[ c[i][1] ];
		}

	process();

	for(int i=0;i<10;++i)
		if(flag[i])
		{
			--cnt[ c[i][0] ];
			--cnt[ c[i][1] ];
		}
}

bool buf[10];

void dfs(int cur,int dep)
{
	int cnt=5-dep;
	for(int i=0;i<cnt;++i)
		flag[i+5]=true;
	calc();
	for(int i=0;i<cnt;++i)
		flag[i+5]=false;

	if(dep>5)
		return ;
	else for(int i=cur;i<5;++i)
		if(!flag[i])
		{
			flag[i]=true;
			dfs(i+1,dep+1);
			flag[i]=false;
		}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	while(input())
	{
		printf("Hand:");
		for(int i=0;i<5;++i)
			printf(" %s",c[i]);
		printf(" Deck:");
		for(int i=5;i<10;++i)
			printf(" %s",c[i]);
		printf(" Best hand: ");

		key=8;
		dfs(0,0);
		puts(dic[key]);
	}

	return 0;
}
