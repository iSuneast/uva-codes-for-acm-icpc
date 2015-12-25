/*
 * 778 - Recording a tape
 * 
 * brute force...
 * no input limit...
 * but actually, the input set is quite small...
 * just brute force enum will do...
 * 
 * happy coding...
 */

#include<cstdio>
#include<cstring>
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#define MAXN 100
using namespace std;

int song[MAXN],n,sum;
string buf;
vector<int> tape;

struct ANSWER
{
	bool side[MAXN];
	int a,b;
	void init()
	{
		a=b=0;
		memset(side,0,sizeof(side));
	}
	bool operator<(const ANSWER &t)const
	{
		return abs(a-b)<abs(t.a-t.b);
	}
}key,cur;
bool first;

void dfs(int dep,ANSWER cur)
{
	if(dep==n)
	{
		if(first || cur<key)
			key=cur;
		first=false;
		return ;
	}
	
	ANSWER t=cur;
	t.side[dep]=true;
	t.a+=song[dep];
	dfs(dep+1,t);
	
	t=cur;
	t.side[dep]=false;
	t.b+=song[dep];
	dfs(dep+1,t);
}

void output()
{
	int p=-1;
	for(int i=0;i<tape.size();++i)
	{
		if(tape[i]>=key.a*2 && tape[i]>=key.b*2)
		{
			if(p==-1 || tape[p]>tape[i])
				p=i;
		}
	}
	
	printf("%d\n",tape[p]/60);
	puts("Side A");
	for(int i=0;i<n;++i)
	{
		if(key.side[i])
			printf("%dm %ds\n",song[i]/60,song[i]%60);
	}
	puts("Side B");
	for(int i=0;i<n;++i)
	{
		if(!key.side[i])
			printf("%dm %ds\n",song[i]/60,song[i]%60);
	}
	puts("%");
}

void read()
{
	int t;
	char c;
	
	tape.clear();
	for(stringstream sin(buf);sin>>t;)
	{
		t*=60;
		tape.push_back(t);
	}
	
	for(sum=n=0; getline(cin,buf) && buf!="%"; ++n)
	{
		stringstream sin(buf);
		sin>>t>>c>>song[n]>>c;
		song[n]+=t*60;
		sum+=song[n];
	}
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif

    while(getline(cin,buf))
    {
    	read();
    	
    	cur.init();
    	first=true;
    	dfs(0,cur);
    	
    	output();
    }

    return 0;
}

