/*
195 - Anagram

permutation...
ȫ��������ı���...
���������Ȼ�м���...

A<a<B<b...
���ƺܸ���..��ʵֻҪ���ַ���ASCII��������ӳ�伴��...
Ҳ����˵:���ַ�����ASCIIӳ��ΪA<a<B<b...���µı���...
���ʱ�Ļ�������..
*/

#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("195.txt","w",stdout);

	int dataset;
	cin>>dataset;
	char str[1000];
	while(dataset--)
	{
		scanf("%s",str);
		int l=strlen(str),i;
		for(i=0;i<l;++i)
			if(isupper(str[i]))
				str[i]=(str[i]-'A')*2;
			else
				str[i]=(str[i]-'a')*2+1;
		sort(str,str+l);
		do
		{
			for(i=0;i<l;++i)
				if(str[i]%2)
					putchar((char)(((str[i]-1)/2)+'a'));
				else
					putchar((char)((str[i]>>1)+'A'));
				putchar('\n');
		}while(next_permutation(str,str+l));
	}

	return 0;
}
