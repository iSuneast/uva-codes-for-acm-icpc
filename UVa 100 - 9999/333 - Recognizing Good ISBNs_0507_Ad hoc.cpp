/*
333 - Recognizing Good ISBNs

Ad hoc...
UVa又挂了...
为什么每次都要卡在水题上...
*/

#include<iostream>
using namespace std;

char buf[100];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	while(gets(buf))
	{
		int key=0,l=strlen(buf),p=10,digit=0;
		int start=0,end=l;
		while(start<end && buf[start]==' ')
			++start;
		while(end>0 && buf[end-1]==' ')
			--end;
		for(l=0;start<end;++l,++start)
			buf[l]=buf[start];
		buf[l]=0;
		bool found=false,x=false;;
		for(int i=0;i<l;++i)
			if(isdigit(buf[i]))
			{
				key+=(buf[i]-'0')*p--;
				++digit;
			}
			else if(buf[i]=='X' && p==1)
			{
				key+=10*p--;
				x=true;
			}
		if(p || key%11 || found || (x && digit!=9) || (!x && digit!=10))
			printf("%s is incorrect.\n",buf);
		else
			printf("%s is correct.\n",buf);
	}

	return 0;
}
