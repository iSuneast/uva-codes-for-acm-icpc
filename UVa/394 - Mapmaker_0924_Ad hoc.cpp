/*
394 - Mapmaker

Ad hoc...
be careful about the presentation...
no trick...
*/

#include<iostream>
#include<string>
#include<map>
#include<vector>
#define MAXN 1000
using namespace std;
typedef pair<int,int> pii;
struct Mapmaker
{
	char name[13];
	int base,size,D;
	int c[13];
}mapMaker[MAXN];

int n,r;
map<string,int> msi;
char name[13];
pii d[13];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	freopen("314","w",stdout);
#endif

	int up,low,p;
	while(scanf("%d%d",&n,&r)!=EOF)
	{
		msi.clear();
		for(int i=0;i<n;++i)
		{
			scanf("%s%d%d%d",mapMaker[i].name,
				&mapMaker[i].base,&mapMaker[i].size,&mapMaker[i].D);
			msi[ mapMaker[i].name ]=i;

			for(int j=1;j<=mapMaker[i].D;++j)
			{
				scanf("%d%d",&low,&up);
				d[j]=make_pair(low,up);
			}

			mapMaker[i].c[ mapMaker[i].D ]=mapMaker[i].size;
			mapMaker[i].c[0]=mapMaker[i].base;
			mapMaker[i].c[0]-=mapMaker[i].size*d[ mapMaker[i].D  ].first;
			for(int j=mapMaker[i].D-1;j>0;--j)
			{
				mapMaker[i].c[j]=mapMaker[i].c[j+1]*(d[j+1].second-d[j+1].first+1);
				mapMaker[i].c[0]-=mapMaker[i].c[j]*d[j].first;
			}
		}
		while(r--)
		{
			scanf("%s",name);
			int i=msi[name],key=mapMaker[i].c[0];
			bool first=true;

			printf("%s[",mapMaker[i].name);
			for(int j=1;j<=mapMaker[i].D;++j)
			{
				scanf("%d",&p);
				key+=mapMaker[i].c[j]*p;

				if(!first)
					printf(", ");
				first=false;
				printf("%d",p);
			}

			printf("] = %d\n",key);
		}
	}

	return 0;
}
