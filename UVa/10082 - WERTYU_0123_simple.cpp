/*
10082 - WERTYU
....
��,�����õļ��̸��ҵĲ�һ��....
���ʹ���...
*/

#include<iostream>

using namespace std;

int main()
{
	char *pad="`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
	char c;
	int i;
	while((c=getchar())!=EOF)
	{
		for(i=1;pad[i]&&pad[i]!=c;i++)
			;
		if(pad[i])
			putchar(pad[i-1]);
		else
			putchar(c);
	}


return 0;
}
