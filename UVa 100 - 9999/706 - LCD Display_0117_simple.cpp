/*
706 - LCD Display

必须枚举出所有的显示器状态.
保持头脑的清醒是一个不出错的前提.
*/

#include<iostream>
#include<cstring>

using namespace std;
int s,len,n;
char c,str[10];
int lcd[10][7]=
{{1,1,1,0,1,1,1},
{0,0,1,0,0,1,0},
{1,0,1,1,1,0,1},
{1,0,1,1,0,1,1},
{0,1,1,1,0,1,0},
{1,1,0,1,0,1,1},
{1,1,0,1,1,1,1},
{1,0,1,0,0,1,0},
{1,1,1,1,1,1,1},
{1,1,1,1,0,1,1}};

void acr(int p)
{
	int i,j;
	for(i=0;i<len;i++)
	{
		cout<<' ';
		c=lcd[str[i]-'0'][p]?'-':' ';
		for(j=0;j<s;j++)
			cout<<c;
		cout<<' ';
		if(i<len-1)
			cout<<' ';
	}
	cout<<endl;
}

void ver(int p)
{
	int i,j;
	for(i=0;i<len;i++)
	{
		printf("%c",lcd[str[i]-'0'][p]?'|':' ');
		for(j=0;j<s;j++)
			cout<<' ';
		printf("%c",lcd[str[i]-'0'][p+1]?'|':' ');
		if(i<len-1)
			cout<<' ';
	}
	cout<<endl;
}

int main()
{
//	freopen("in.txt","r",stdin);

	int i;
	while(cin>>s>>n&&(s||n))
	{
		sprintf(str,"%d",n);
		len=strlen(str);
		acr(0);
		for(i=0;i<s;i++)
			ver(1);
		acr(3);
		for(i=0;i<s;i++)
			ver(4);
		acr(6);
		cout<<endl;
	}

return 0;
}