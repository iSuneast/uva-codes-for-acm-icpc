/*
712 - S-Trees

data struct...
�ó�����Ŀ...
���˺ܶ��Ŷ�...
�����˾ͻ�����...
ˮ��...û���д���...

��ʵ���Ǹ���һ����ȫ�����������һ��ڵ��bfs����
Ȼ�����һϵ�дӸ��ڵ�����ı���
�����������Ҷ�ӽڵ��ֵ
ֱ�ӻ�������Ϊʮ����,Ȼ��������һ���Ӧ��ֵ����
*/

#include<iostream>
#define MAXN 256
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int n,m,cas=1;
	char s[MAXN],t[16];
	while(scanf("%d",&n)!=EOF && n)
	{
		while(n--)
			scanf("%s",s);
		scanf("%s",s);
		scanf("%d",&m);

		printf("S-Tree #%d:\n",cas++);
		while(m--)
		{
			scanf("%s",t);
			int i=0,var=0;
			while(t[i])
				var=var*2+t[i++]-'0';
			cout<<s[var];
		}
		puts("\n");
	}

	return 0;
}
