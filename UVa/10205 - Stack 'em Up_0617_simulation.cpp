/*
10205 - Stack 'em Up

simulation...
直接模拟即可...
题目的意思不好理解...
费点心加点耐心就可以了...
*/

#include<iostream>
#define MAXCARD 52
#define MAXN 110
using namespace std;

struct CARDS
{
	int s[MAXCARD];
}card[MAXN];

int state[MAXCARD],tmp[MAXCARD];
char buf[20],suit[4][10],v[13][10];

void init()
{
	strcpy(suit[0],"Clubs");
	strcpy(suit[1],"Diamonds");
	strcpy(suit[2],"Hearts");
	strcpy(suit[3],"Spades");

	strcpy(v[0],"2");
	strcpy(v[1],"3");
	strcpy(v[2],"4");
	strcpy(v[3],"5");
	strcpy(v[4],"6");
	strcpy(v[5],"7");
	strcpy(v[6],"8");
	strcpy(v[7],"9");
	strcpy(v[8],"10");
	strcpy(v[9],"Jack");
	strcpy(v[10],"Queen");
	strcpy(v[11],"King");
	strcpy(v[12],"Ace");
}

void process(CARDS &cur)
{
	memcpy(tmp,state,sizeof(tmp));
	for(int i=0;i<MAXCARD;++i)
		state[i]=tmp[ cur.s[i]-1 ];
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	init();
	int dataset;
	scanf("%d",&dataset);

	while(dataset--)
	{
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;++i)
			for(int j=0;j<MAXCARD;++j)
				scanf("%d",&card[i].s[j]);

		for(int i=0;i<MAXCARD;++i)
			state[i]=i;

		gets(buf);
		while(gets(buf) && buf[0])
			process(card[ atoi(buf)-1 ]);

		for(int i=0;i<MAXCARD;++i)
			printf("%s of %s\n",v[ state[i]%13 ],suit[ state[i]/13 ]);

		if(dataset)
			putchar('\n');
	}

	return 0;
}
