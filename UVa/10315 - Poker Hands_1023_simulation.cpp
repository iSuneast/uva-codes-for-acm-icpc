/*
10315 - Poker Hands

simulation...
just a complex coding problem...
*/

#include<iostream>
using namespace std;

struct CARD
{
	struct PAIR
	{
		int value,suit;
		bool operator<(const PAIR &t)const
		{
			return value<t.value;
		}
	}hand[5];
	int poker,key[5];
}black,white;

const char ans[][17]={"Tie.","Black wins.","White wins."};
char buf[7];
int h[128];
int suit[5],v[15];

void located(int var,int ans[3],int p)
{
	for(int i=14;i>=2;--i)
		if(v[i]==var)
			ans[p++]=i;
}

bool input(CARD &cur)
{
	memset(suit,0,sizeof(suit));
	memset(v,0,sizeof(v));

	memset(cur.key,0,sizeof(cur.key));

	for(int i=0;i<5;++i)
	{
		if(scanf("%s",buf)==EOF)
			return false;
		cur.hand[i].suit=h[ buf[1] ];
		cur.hand[i].value=h[ buf[0] ];

		++suit[ cur.hand[i].suit ];
		++v[ cur.hand[i].value ];
	}

	bool Flush=false;
	for(int i=0;i<4;++i)
		if(suit[i]==5)
			Flush=true;

	int cnt[6]={};
	bool Straight=false;
	for(int i=2;i<=14;++i)
	{
		if(v[i]==1)
		{
			int t=0;
			for(int j=i;j<=14;++j)
			{
				if(v[j]==1)
					++t;
				else
					break;
			}
			if(t==5)
				Straight=true;
		}
		else
			++cnt[ v[i] ];
	}

	if(Flush && Straight)
	{
		cur.poker=8;
		located(1,cur.key,0);
	}
	else if(cnt[4])
	{
		cur.poker=7;
		located(4,cur.key,0);
	}
	else if(cnt[3] && cnt[2])
	{
		cur.poker=6;
		located(3,cur.key,0);
	}
	else if(Flush)
	{
		cur.poker=5;
		located(1,cur.key,0);
	}
	else if(Straight)
	{
		cur.poker=4;
		located(1,cur.key,0);
	}
	else if(cnt[3])
	{
		cur.poker=3;
		located(3,cur.key,0);
	}
	else if(cnt[2]==2)
	{
		cur.poker=2;
		located(2,cur.key,0);
		located(1,cur.key,2);
	}
	else if(cnt[2])
	{
		cur.poker=1;
		located(2,cur.key,0);
		located(1,cur.key,1);
	}
	else
	{
		cur.poker=0;
		located(1,cur.key,0);
	}

	return true;
}

void init()
{
	h['2']=2;
	h['3']=3;
	h['4']=4;
	h['5']=5;
	h['6']=6;
	h['7']=7;
	h['8']=8;
	h['9']=9;
	h['T']=10;
	h['J']=11;
	h['Q']=12;
	h['K']=13;
	h['A']=14;

	h['C']=0;
	h['D']=1;
	h['H']=2;
	h['S']=3;
}

int process()
{
	if(black.poker!=white.poker)
		return black.poker>white.poker?1:2;
	for(int i=0;i<5;++i)
		if(black.key[i]!=white.key[i])
			return black.key[i]>white.key[i]?1:2;
	return 0;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	init();
	while(input(black) && input(white))
		puts(ans[process()]);

	return 0;
}
