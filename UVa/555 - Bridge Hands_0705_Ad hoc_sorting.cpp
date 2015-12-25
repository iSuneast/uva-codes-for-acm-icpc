/*
555 - Bridge Hands

brute force...
sorting
Ad hoc...
有个很恶心的tricky...
不过这个tricky估计是针对我用hash[]表来映射不同的值导致冲突...
这个bug还真的是很难查啊...

比如对"SWNE",用hash['S']=0,hash['W']=1...可以简化代码
然后对"CDSH",里面也有个'S'...无语...
*/

#include<iostream>
#include<algorithm>
#define MAXN 128
using namespace std;
typedef pair<char,char> pcc;

const char *hand="SWNE";
pcc poker[4][25];
char buf[MAXN];
int hash[MAXN],sz[4];
void init();

int cmp(const pcc a,const pcc b)
{
	if(a.first==b.first)
		return hash[ a.second ]<hash[ b.second ];
	return hash[ a.first ]<hash[ b.first ];
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	init();
	while(scanf("%s",buf)!=EOF && buf[0]!='#')
	{
		memset(poker,0,sizeof(poker));
		memset(sz,0,sizeof(sz));
		int p=(hash[ tolower(buf[0]) ]+1)%4;

		memset(buf,0,sizeof(buf));
		scanf("%s",buf);
		for(int i=0;buf[i];i+=2)
		{
			poker[p][ sz[p]++ ]=make_pair(buf[i],buf[i+1]);
			p=(p+1)%4;
		}
		memset(buf,0,sizeof(buf));
		scanf("%s",buf);
		for(int i=0;buf[i];i+=2)
		{
			poker[p][ sz[p]++ ]=make_pair(buf[i],buf[i+1]);
			p=(p+1)%4;
		}

		for(int i=0;i<4;++i)
		{
			sort(poker[i],poker[i]+sz[i],cmp);
			printf("%c:",hand[i]);
			for(int j=0;j<sz[i];++j)
				printf(" %c%c",poker[i][j].first,poker[i][j].second);
			putchar('\n');
		}
	}

	return 0;
}

void init()
{
	memset(hash,0x7f,sizeof(hash));
	hash['s']=hash['C']=0;
	hash['w']=hash['D']=1;
	hash['n']=hash['S']=2;
	hash['e']=hash['H']=3;

	hash['2']=2;
	hash['3']=3;
	hash['4']=4;
	hash['5']=5;
	hash['6']=6;
	hash['7']=7;
	hash['8']=8;
	hash['9']=9;
	hash['T']=10;
	hash['J']=11;
	hash['Q']=12;
	hash['K']=13;
	hash['A']=14;
}
