/*
11475 - Extend to Palindrome

第一次的KMP...
写错好多东西啊...
*/

#include<iostream>
#define MAXN 100010
using namespace std;
char str[MAXN],buf[MAXN];
int pi[MAXN],l;

void init()
{
	pi[0]=-1;
	int k=-1;
	for(int q=1;q<l;q++)
	{
		while(k>=0 && buf[k+1]!=buf[q])
			k=pi[k];
		if(buf[k+1]==buf[q])
			++k;
		pi[q]=k;
	}
}

void kmp()
{
	int q=-1,m=l;
	for(int i=0;i<l;i++)
	{
		while(q>=0 && buf[q+1]!=str[i])
			q=pi[q];
		if(buf[q+1]==str[i])
			q++;
	}
	cout<<(buf+q+1)<<endl;
}

int main()
{
//	freopen("in.txt","r",stdin);

	int i;
	while(gets(str))
	{
		l=strlen(str);
		for(i=0;i<l;i++)
			buf[i]=str[l-1-i];
		buf[l]='\0';
		init();
		cout<<str;
		kmp();
	}

return 0;
}
