/*
11040 - Add bricks in the wall

dp...
its quite a simple problem if you have observe the important property
var[i][j]=var[i+1][j]+var[i+1][j+1]
var[i+1][j]=var[i+2][j]+var[i+2][j+1]
var[i+1][j+1]=var[i+2][j+1]+var[i+2][j+2]
so...
var[i][j]=var[i+2][j]+var[i+2][j+1]*2+var[i+2][j+2]
var[i][j], var[i+2][j], var[i+2][j+2] are known...
need more hints£¿
*/

#include<iostream>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int dataset,var[13][13];
	scanf("%d",&dataset);
	while(dataset--)
	{
		for(int i=1;i<=9;i+=2)
		{
			for(int j=1;j<=i;j+=2)
				scanf("%d",&var[i][j]);
		}

		for(int i=1;i<9;i+=2)
		{
			for(int j=1;j<=i;j+=2)
			{
				var[i+2][j+1]=(var[i][j]-var[i+2][j]-var[i+2][j+2])/2;
				var[i+1][j]=var[i+2][j]+var[i+2][j+1];
				var[i+1][j+1]=var[i+2][j+1]+var[i+2][j+2];
			}
		}
		for(int i=1;i<=9;++i)
		{
			printf("%d",var[i][1]);
			for(int j=2;j<=i;++j)
				printf(" %d",var[i][j]);
			putchar(10);
		}
	}

	return 0;
}
