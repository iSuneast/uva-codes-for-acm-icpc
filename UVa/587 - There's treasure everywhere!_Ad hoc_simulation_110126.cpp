/*
 * 587 - There's treasure everywhere!
 *
 * Ad hoc..
 * simulation...
 *
 * no trick...
 *
 * happy coding..
 */

#include<iostream>
#include<cmath>
#define MAXN 203
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	const double slash=sqrt(2.0)/2.0;
	char op[MAXN],s[3];
	int n;
	for(int cas=1; gets(op) && strcmp(op,"END"); ++cas)
	{
		double x=0,y=0;
		for(char *token=strtok(op,",."); token; token=strtok(NULL,",."))
		{
			sscanf(token,"%d%s",&n,s);
			if(strlen(s)==1)
			{
				if(s[0]=='N')
					y+=n;
				else if(s[0]=='S')
					y-=n;
				else if(s[0]=='E')
					x+=n;
				else
					x-=n;
			}
			else
			{
				if(s[0]=='N')
					y+=slash*n;
				else
					y-=slash*n;
				if(s[1]=='E')
					x+=slash*n;
				else
					x-=slash*n;
			}
		}

		printf("Map #%d\n",cas);
		printf("The treasure is located at (%.3lf,%.3lf).\n",x,y);
		printf("The distance to the treasure is %.3lf.\n",sqrt( pow(x,2.0) + pow(y,2.0) ));
		putchar(10);
	}

	return 0;
}
