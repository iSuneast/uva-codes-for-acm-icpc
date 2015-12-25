/*
10878 - Decode the tape
*/

#include<iostream>

using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);
	char buf[30];
	int c,i,p;
	gets(buf);
	while(gets(buf)&&strcmp(buf,"___________"))
	{
		p=7;c=0;
		for(i=1;i<11;i++)
			if(buf[i]==' ')
				p--;
			else if(buf[i]=='o')
				c+=(1<<p),p--;
		putchar(c);
	}

return 0;
}
