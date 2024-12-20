/*
11344 - The Huge One

number theory...
大整数求模..
*/

#include<iostream>
#define MAXN 1010
using namespace std;

char var[1010];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int dataset;
	scanf("%d",&dataset);
	while(dataset--)
	{
		scanf("%s",var);
		int cnt,num[15];
		scanf("%d",&cnt);
		bool wonderful=true;
		for(int i=0;i<cnt;++i)
		{
			scanf("%d",num+i);
			char *p=var;
			int carry=0;
			while(*p)
			{
				carry=carry*10+(*p++)-'0';
				carry%=num[i];
			}
			if(carry)
				wonderful=false;
		}
		if(wonderful)
			printf("%s - Wonderful.\n",var);
		else
			printf("%s - Simple.\n",var);
	}

	return 0;
}
