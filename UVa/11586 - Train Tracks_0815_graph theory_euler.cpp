/*
11586 - Train Tracks

graph theory...
euler...
欧拉回路的判定条件...
*/

#include<iostream>

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int dataset;
	char buf[2010];
	scanf("%d",&dataset);	gets(buf);
	while(dataset--)
	{
		gets(buf);
		char *token=strtok(buf," ");
		int m=0,f=0;
		while(token)
		{
			token[0]=='M'?++m:++f;
			token[1]=='M'?++m:++f;
			token=strtok(NULL," ");
		}
		puts(m==f && m%2==0?"LOOP":"NO LOOP");
	}

	return 0;
}
