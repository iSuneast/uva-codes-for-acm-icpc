/*
11744 - Parallel Carry Adder

simulation...
*/

#include<iostream>
#define MAXN 35
using namespace std;

char a[MAXN],b[MAXN];
char bound[]="10000000000000000000000000000000";
char empty[]="00000000000000000000000000000000";

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int dataset;
	scanf("%d",&dataset);
	while(dataset--)
	{
		a[0]=b[0]='0';
		scanf("%s%s",a+1,b+1);
		printf("%s %s\n",a+1,b+1);
		while(strcmp(b,empty))
		{
			for(int i=1;i<32;++i)
				if(a[i]==b[i])
				{
					a[i]='0';
					if(b[i]=='1')
						b[i-1]='1';
					b[i]='0';
				}
				else
				{
					a[i]='1';
					b[i]='0';
				}
			printf("%s ",a+1);
			if(strcmp(b,bound)>=0)
			{
				puts("overflow");
				break;
			}
			else
				puts(b+1);
		}
		if(dataset)
			putchar('\n');
	}

	return 0;
}
