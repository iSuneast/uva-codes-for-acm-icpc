/*
860 - Entropy Text Analyzer

Ad hoc...
一定要考虑特殊情况...
无解的时候如果不特殊判断的话,会输出乱码的...
token有" ,.:;!?\"()"
按题目说的写就可以了...
不要担心是精度误差引起的
*/

#include<iostream>
#include<cmath>
#include<map>
#define MAXN 100010
#define MAXLEN 23
using namespace std;

const char eoi[]="****END_OF_INPUT****";
const char eot[]="****END_OF_TEXT****";
char buf[MAXN];
int tot,n;
map<string,int> msi;
char dic[MAXN][MAXLEN];

void process()
{
	char *token=strtok(buf," ,.:;!?\"()");
	while(token)
	{
		int p=0;
		while(token[p])
		{
			if(isupper(token[p]))
				token[p]=tolower(token[p]);
			++p;
		}
		if(msi.find(token)==msi.end())
		{
			msi[token]=1;
			strcpy(dic[tot++],token);
		}
		else
			msi[token]++;
		++n;
		token=strtok(NULL," ,.:;!?\"()");
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	while(gets(buf) && strcmp(buf,eoi))
	{
		if(strcmp(buf,eot)==0)
		{
			printf("%d %.1lf %.0lf\n",0,0.0,0.0);
			continue;
		}
		msi.clear();
		n=tot=0;

		do
			process();
		while(gets(buf) && strcmp(buf,eot));

		if(!tot)
		{
			printf("%d %.1lf %.0lf\n",0,0.0,0.0);
			continue;
		}
		
		double et=0;
		int pi;
		for(int i=0;i<tot;++i)
		{
			pi=msi[ dic[i] ];
			et+=pi*(log10(n+0.0)-log10(pi+0.0));
		}
		et/=n;
		double e_rel=et*100.0/log10(n+0.0);

		printf("%d %.1lf %.0lf\n",n,et,e_rel);
	}

	return 0;
}

/*in
"""
****END_OF_TEXT****
****END_OF_INPUT****
*/
