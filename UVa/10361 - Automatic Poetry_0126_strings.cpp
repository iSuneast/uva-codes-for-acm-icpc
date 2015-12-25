/*
10361 - Automatic Poetry
...
		20100126
		zero.suneast
*/

#include<iostream>
#include<cstring>

using namespace std;

char buf1[2][100],buf2[2][100],line[200];
int n,p,i;

void line1()
{
	gets(line);
	p=0;
	while(line[p]!='<')
		putchar(line[p++]);
	p++;i=0;
	while(line[p]!='>')
		putchar(line[p]),buf1[0][i++]=line[p++];
	p++;i=0;
	while(line[p]!='<')
		putchar(buf1[1][i++]=line[p++]);
	p++;i=0;
	while(line[p]!='>')
		putchar(line[p]),buf2[0][i++]=line[p++];
	strcpy(buf2[1],line+p+1);
	puts(buf2[1]);
}

void line2()
{
	gets(line);
	p=0;
	while(line[p]!='.')
		putchar(line[p++]);
	cout<<buf2[0]<<buf1[1]<<buf1[0]<<buf2[1]<<endl;
}


int main()
{
//	freopen("in.txt","r",stdin);
	cin>>n;getchar();
	while(n--)
	{
		memset(buf1,0,sizeof(buf1));
		memset(buf2,0,sizeof(buf2));
		line1();
		line2();
	}

return 0;
}
