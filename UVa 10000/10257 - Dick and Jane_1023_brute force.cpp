/*
10257 - Dick and Jane

brute force...

obvious,Dick=12
Spot = Puff + s + {0,1}
Puff = Yertle + p + {0,1}
Spot = Yertle + y + {0,1}
Spot + Puff + Yertle = j + 12
so, we can enum {0,1} set to find the correct answer.
*/

#include<iostream>
using namespace std;

int s,p,y,j;

void process()
{
	j+=12;
	for(int c=0;;++c)
	{
		for(int d=0;d<2;++d)
		{
			int b=c+p+d;
			for(int d1=0;d1<2;++d1)
			{
				for(int d2=0;d2<2;++d2)
				{
					int a=min(b+s+d1,c+y+d2);
					if(a+b+c==j)
					{
						printf("%d %d %d\n",a,b,c);
						return ;
					}
				}
			}
		}
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	while(scanf("%d%d%d%d",&s,&p,&y,&j)!=EOF)
	{
		process();
	}

	return 0;
}
