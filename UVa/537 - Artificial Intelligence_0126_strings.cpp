/*
537 - Artificial Intelligence?
*/

#include<iostream>

using namespace std;

char buf[1000],unit[2];
double var[2];

void pick(char *p,int i)
{
	char pre[100];
	unit[i]=p[-1];
	sscanf(p+1,"%lf%s",var+i,pre);
	switch(pre[0])
	{
	case 'm':
		var[i]*=0.001;
		break;
	case 'k':
		var[i]*=1000;
		break;
	case 'M':
		var[i]*=1000000;
	}
}

void calc()
{
	if((unit[0]=='P')&&(unit[1]=='U'))
	{
		printf("I=%.2lfA",var[0]/var[1]);
		return ;
	}
	if((unit[1]=='P')&&(unit[0]=='U'))
	{
		printf("I=%.2lfA",var[1]/var[0]);
		return ;
	}
	if((unit[0]=='P')&&(unit[1]=='I'))
	{
		printf("U=%.2lfV",var[0]/var[1]);
		return ;
	}
	if((unit[1]=='P')&&(unit[0]=='I'))
	{
		printf("U=%.2lfV",var[1]/var[0]);
		return ;
	}
	printf("P=%.2lfW",var[0]*var[1]);
}

int main()
{
//	freopen("in.txt","r",stdin);
	int k,cas=1;
	cin>>k;getchar();
	while(k--)
	{
		gets(buf);
		pick(strchr(buf,'='),0);
		pick(strchr(buf+1+(strchr(buf,'=')-buf),'='),1);
		cout<<"Problem #"<<cas++<<endl;
		calc();
		cout<<"\n\n";
	}

return 0;
}
