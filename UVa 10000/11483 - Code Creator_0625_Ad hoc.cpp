/*
11483 - Code Creator

Ad hoc...
直接做...
没什么好说的...

sample数据有问题...
*/

#include<iostream>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int n,cas=1;
	char buf[110];
	while(scanf("%d",&n)!=EOF && n)
	{
		gets(buf);

		printf("Case %d:\n",cas++);
		puts("#include<string.h>");
		puts("#include<stdio.h>");
		puts("int main()");
		puts("{");

		while(n--)
		{
			printf("printf(\"");

			gets(buf);
			int l=strlen(buf);
			for(int i=0;i<l;++i)
				if(buf[i]=='\\')
					printf("\\\\");
				else if(buf[i]=='"')
					printf("\\\"");
				else
					putchar(buf[i]);

			puts("\\n\");");
		}

		puts("printf(\"\\n\");");
		puts("return 0;");
		puts("}");
	}

	return 0;
}
