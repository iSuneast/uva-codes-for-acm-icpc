/*
10182 - Bee Maja

simulation...
直接模拟即可...
*/

#include<iostream>
#define MAXN 101018
using namespace std;

pair<int,int> key[MAXN+3];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int cur=2,ring=0;
	key[1]=make_pair(0,0);
	while(cur<MAXN)
	{
		++ring;
		key[cur++]=make_pair(ring-1,1);

		int p=ring-1,x=ring-1,y=1;
		while(p--)
			key[cur++]=make_pair(--x,++y);

		p=ring;
		while(p--)
			key[cur++]=make_pair(--x,y);

		p=ring;
		while(p--)
			key[cur++]=make_pair(x,--y);

		p=ring;
		while(p--)
			key[cur++]=make_pair(++x,--y);

		p=ring;
		while(p--)
			key[cur++]=make_pair(++x,y);

		p=ring;
		while(p--)
			key[cur++]=make_pair(x,++y);
	}

	while(scanf("%d",&cur)!=EOF)
		printf("%d %d\n",key[cur].first,key[cur].second);

	return 0;
}
