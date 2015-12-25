/*
10281 - Average Speed
*/

#include<stdio.h>
#include<string.h>
int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	
	int x;
	long y,nowh,nowm,nows,h,m,s;
	double dis=0,speed=0,t;
	char time[10],buf[10];
	while(scanf("%s",time)!=EOF)
	{
		gets(buf);
		nowh=(time[0]-'0')*10+time[1]-'0';
		nowm=(time[3]-'0')*10+time[4]-'0';
		nows=(time[6]-'0')*10+time[7]-'0';
		y=(nowh-h)*3600+(nowm-m)*60+(nows-s);
		dis+=(speed*((double)y/3600));
		if(!strlen(buf))
			printf("%s %.2lf km\n",time,dis);
		else
			sscanf(buf,"%lf",&speed);
		h=nowh,m=nowm,s=nows;
	}
	return 0;
}