/*
195 - Anagram

permutation...
全排列问题的变形...
做这种题果然有技巧...

A<a<B<b...
看似很复杂..其实只要将字符的ASCII码做个重映射即可...
也就是说:把字符串的ASCII映射为A<a<B<b...的新的编码...
输出时改回来即可..
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
