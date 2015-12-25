/*
11239 - Open Source

Ad hoc...
Just do as problem description...
*/

#include<iostream>
#include<string>
#include<algorithm>
#include<map>
#define MAXN 103
#define MAXLEN 1000
using namespace std;

struct DATA
{
	char name[MAXLEN];
	int cnt;
	bool operator<(const DATA &t)const
	{
		if(cnt==t.cnt)
			return strcmp(name,t.name)<0;
		return cnt>t.cnt;
	}
}data[MAXN];
map<string,int> msi;
char str[MAXLEN];
int tot;

bool input()
{
	tot=0;
	msi.clear();
	while(gets(str))
	{
		if(str[0]=='0')
			return false;
		else if(str[0]=='1')
			break;

		if(isupper(str[0]))
		{
			++tot;
			strcpy(data[tot].name,str);
			data[tot].cnt=0;
		}
		else
		{
			if(msi.find(str)==msi.end())
			{
				data[tot].cnt++;
				msi[str]=tot;
			}
			else
			{
				int t=msi[str];
				if(t!=tot && t!=-1)
				{
					--data[t].cnt;
					msi[str]=-1;
				}
			}
		}
	}

	return true;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	while(input())
	{
		sort(data+1,data+tot+1);
		for(int i=1;i<=tot;++i)
			printf("%s %d\n",data[i].name,data[i].cnt);
	}

	return 0;
}
