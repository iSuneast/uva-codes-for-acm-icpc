/*
11001 - Necklace

math...
���һ������Ŀ���Ȳ����������ƹ�ʽ...
��n*0.3*sqrt(v/n-v0)������n��ֵ
	 n*0.3*sqrt(v/n-v0)
	=0.3*sqrt(v*n-v0*n*n)
sqrt()��������������
��n=-v/(2*(-v0))=v/(2*v0)ʱ,����ֵ���
�������������...
n��С������
	=0.5ʱ,�޽�0
	>0.5ʱ,��Ϊn+1
	<0.5��,��Ϊn

������ѧ֪ʶ..
��������...
*/

#include<iostream>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int vt,v0;
	while(scanf("%d%d",&vt,&v0)!=EOF && (vt||v0))
	{
		if(vt<=v0)
			puts("0");
		else
		{
			int t=vt/(2*v0);
			int t2=vt-2*v0*t;
			if(t2==v0)
				puts("0");
			else if(t2>v0)
				printf("%d\n",t+1);
			else
				printf("%d\n",t);
		}
	}

	return 0;
}
