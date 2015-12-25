/*
11804 - Argentina

brute force...
暴力枚举所有组合..
按题意取舍即可...
可以先排序...
这样可以保证字典序最小...
*/

#include<iostream>
#include<string>
#include<algorithm>
#define MAXN 10
using namespace std;

struct PLAYER
{
	string name;
	int attack,defend;
	bool operator<(const PLAYER &t)const
	{
		return name<t.name;
	}
}player[MAXN];

bool flag[MAXN],key[MAXN];
int defend,attack;

void dfs(int p,int dep)
{
	if(dep==MAXN/2)
	{
		int d=0,a=0;
		for(int i=0;i<MAXN;++i)
			if(flag[i])
				a+=player[i].attack;
			else
				d+=player[i].defend;
		if(a>attack)
		{
			attack=a;
			defend=d;
			memcpy(key,flag,sizeof(flag));
		}
		else if(a==attack && d>defend)
		{
			defend=d;
			memcpy(key,flag,sizeof(flag));
		}
	}
	else for(int i=p;i<MAXN;++i)
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
	freopen("in.txt","r",stdin);
#endif

	int dataset;
	cin>>dataset;
	for(int cas=1;cas<=dataset;++cas)
	{
		for(int i=0;i<MAXN;++i)
			cin>>player[i].name>>player[i].attack>>player[i].defend;

		sort(player,player+MAXN);

		memset(flag,0,sizeof(flag));
		defend=attack=0;
		dfs(0,0);

		cout<<"Case "<<cas<<":"<<endl;
		cout<<"(";
		bool first=true;
		for(int i=0;i<MAXN;++i)
			if(key[i])
			{
				if(!first)
					cout<<", ";
				first=false;
				cout<<player[i].name;
			}
		cout<<")"<<endl;
		cout<<"(";
		first=true;
		for(int i=0;i<MAXN;++i)
			if(!key[i])
			{
				if(!first)
					cout<<", ";
				first=false;
				cout<<player[i].name;
			}
			cout<<")"<<endl;
	}

	return 0;
}
