/*
10222 - Decode the Mad man
*/

#include<iostream>

using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);

	char *pad_lower="`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./";
	char c;
	int i;
	while((c=getchar())!=EOF)
	{
		if(isupper(c))
			c+=32;
		for(i=2; pad_lower[i] && pad_lower[i]!=c;i++)
			;
		if(pad_lower[i])
			putchar(pad_lower[i-2]);
		else
			putchar(c);
	}

return 0;
}
