/*
11056 - Formula 1

Ad hoc...
how a simple problem...
just a sort function will do...
remember that...
"case-insensitive comparisons"
*/

#include<iostream>
#include<algorithm>
#define MAXN 103
using namespace std;

struct DATA
{
	char name[23],mirror[23];
	long long timeSpend;
	bool operator<(const DATA &t)const
	{
		if(timeSpend==t.timeSpend)
			return strcmp(mirror,t.mirror)<0;
		return timeSpend<t.timeSpend;
	}
}data[MAXN];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int n,min,sec,ms,i,j;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<n;++i)
		{
			scanf("%s%*s%d%*s%d%*s%d%*s",data[i].name,&min,&sec,&ms);
			for(j=0;data[i].name[j];++j)
				data[i].mirror[j]=tolower(data[i].name[j]);
			data[i].mirror[j]=0;
			data[i].timeSpend=(static_cast<long long>(min)*60+sec)*1000+ms;
		}
		sort(data,data+n);
		i=0;
		while(i<n)
		{
			printf("Row %d\n",i/2+1);
			puts(data[i++].name);
			if(i<n)
				puts(data[i++].name);
		}
		putchar(10);
	}

	return 0;
}
