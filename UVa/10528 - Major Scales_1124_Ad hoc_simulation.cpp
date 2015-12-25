/*
10528 - Major Scales

Ad hoc...
just simulate as the problem say...

it's really a simple problem
if and only if you read the problem description carefully
and make sure you have already understand it...

you'd better calm down to understand the problem...

first, we general a table indicate set of a major tone T
e.g: F, the major scale is: F, G, A, A#, C, D, E

if we read in a scale G, we know it can be general by F
so F is a candidate answer here...
keep tracking until final
if we can get a candidate answer satisfy with all tone
then it's an answer...
*/

#include<iostream>
#include<string>
#include<map>
#define MAJOR_TONES 8
#define TONE 12
using namespace std;

const int jump[]={2,2,1,2,2,2,1};
bool tone[TONE][TONE];
char scale[][3]={
	"C",
	"C#",
	"D",
	"D#",
	"E",
	"F",
	"F#",
	"G",
	"G#",
	"A",
	"A#",
	"B",
	"C"
};
map<string,int> msi;
int major[TONE];

void init()
{
	for(int i=0;i<TONE;++i)
	{
		msi[ scale[i] ]=i;
		for(int j=0,p=i;j<MAJOR_TONES;++j)
			tone[i][ p=(p+jump[j])%TONE ]=true;
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	init();
	char buf[10];
	while(scanf("%s",buf)!=EOF && strcmp(buf,"END"))
	{
		memset(major,0,sizeof(major));
		int cnt=0;
		do
		{
			++cnt;
			for(int i=0,p=msi[buf];i<TONE;++i)
				if(tone[i][p])
					++major[i];
		}while(getchar()!=10 && scanf("%s",buf)!=EOF);

		for(int i=0,p=0;i<TONE;++i)
		{
			if(major[i]!=cnt)
				continue;
			if(p)
				putchar(' ');
			++p;
			printf("%s",scale[i]);
		}
		putchar(10);
	}

	return 0;
}
