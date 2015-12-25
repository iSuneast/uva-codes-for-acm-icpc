/*
11278 - One-Handed Typist

Ad hoc...
手工暴力题...
把题目的表打对就成功了...
*/

#include<iostream>
using namespace std;

const char key[]=	"`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./~!@#$%^&*()_+QWERTYUIOP{}|ASDFGHJKL:\"ZXCVBNM<>?";
const char modify[]="`123qjlmfp/[]456.orsuyb;=\\789aehtdck-0zx,inwvg'~!@#QJLMFP?{}$%^>ORSUYB:+|&*(AEHTDCK_)ZX<INWVG\"";

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	char c;
	while((c=getchar())!=EOF)
	{
		int p=0;
		while(key[p] && key[p]!=c)
			++p;
		if(key[p])
			putchar(modify[p]);
		else
			putchar(c);
	}

	return 0;
}
