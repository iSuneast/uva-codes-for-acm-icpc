/*
202 - Repeating Decimals

simulation...
���ȱ�����ȷ,һ�������ѭ����
ע�⵽˵{ n%m | [0,m) } ��֪
С�����m�����ͻ����ѭ��
�жϳ���ѭ��,���ǿ�n%mʲôʱ���ٴγ���,���ǿ�nʲôʱ���ٴγ���
����,�������¼n���ֵ�λ��,�Ϳ����ж�ѭ��λ����
*/

#include<iostream>
#define MAXN 3010
using namespace std;

char d[MAXN],t[MAXN];
int fa[MAXN];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int n,m,p;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		printf("%d/%d = %d.",n,m,n/m);
		n%=m;

		memset(fa,-1,sizeof(fa));
		for(p=0;p<m && n;++p)
		{
			d[p]=n*10/m+'0';
			if(fa[n]!=-1)
				break;
			fa[n]=p;
			n=n*10%m;
		}
		d[p]=0;

		if(!n)
		{
			printf("%s(0)\n",d);
			puts("   1 = number of digits in repeating cycle");
		}
		else
		{
			int i,cnt=0;
			for(i=0;i<fa[n];++i)
				putchar(d[i]);
			putchar('(');
			for(;i<p && cnt<50;++i,++cnt)
				putchar(d[i]);
			if(cnt==50)
				printf("...");
			puts(")");
			printf("   %d = number of digits in repeating cycle\n",p-fa[n]);
		}
		putchar(10);
	}

	return 0;
}
