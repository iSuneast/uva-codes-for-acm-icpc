/*
11309 - Counting Chaos

Ad hoc...
求时间HH:MM里面的回文..
直接暴力枚举即可..
*/

#include<iostream>
#define MAXN 1450
using namespace std;

char cur[10],next[MAXN][10];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int tot=0;
	for(int hour=0;hour<24;++hour)
		for(int minute=0;minute<60;++minute)
		{
			sprintf(next[tot],"%02d:%02d",hour,minute);
			sprintf(cur,"%d%02d",hour,minute);
			int l=strlen(cur),p=0;
			bool done=true;
			while(p<l && cur[p]=='0')
				++p;
			l-=p;
			for(int i=0;i<l/2;++i)
				if(cur[i+p]!=cur[l-1-i+p])
				{
					done=false;
					break;
				}
				if(done)
					++tot;
		}
		int dataset;
		cin>>dataset;
		while(dataset--)
		{
			cin>>cur;
			bool got=false;
			for(int i=0;i<tot;++i)
				if(strcmp(cur,next[i])<0)
				{
					puts(next[i]);
					got=true;
					break;
				}
				if(!got)
					puts(next[0]);
		}

		return 0;
}
