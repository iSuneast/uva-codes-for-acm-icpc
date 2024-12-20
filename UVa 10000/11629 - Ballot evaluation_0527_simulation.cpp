/*
11629 - Ballot evaluation

simulation...
太不和谐了...
竟然有精度问题...
*/

#include<iostream>
#include<sstream>
#include<string>
#include<map>
#define eps 1e-9
using namespace std;

void judge(bool key)
{
	if(key)
		puts("correct.");
	else
		puts("incorrect.");
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int p,g;
	while(scanf("%d%d",&p,&g)!=EOF)
	{
		map<string,int> msd;
		char party[25];
		double vote;

		while(p--)
		{
			scanf("%s%lf",party,&vote);
			msd[party]=(vote+eps)*10;
		}
		gets(party);

		string buf,a,b;
		for(int cas=1;cas<=g;++cas)
		{
			getline(cin,buf);
			stringstream sin(buf);
			int cur=0,key;
			while(sin>>a)
			{
				sin>>b;
				cur+=msd[a];
				if(b!="+")
				{
					sin>>a;
					sscanf(a.c_str(),"%d",&key);
					key*=10;
					printf("Guess #%d was ",cas);
					if(b=="<")
						judge(cur<key);
					else if(b==">")
						judge(cur>key);
					else if(b=="<=")
						judge(cur<=key);
					else if(b==">=")
						judge(cur>=key);
					else if(b=="=")
						judge(cur==key);
				}
			}
		}
	}

	return 0;
}
