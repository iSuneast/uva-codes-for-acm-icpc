/*
10493 - Cats, with or without Hats

math...
���ƹ�ʽ�ͳ�����..
	1 -> n
Ҳ����˵,һֻ��ñ�ӵ�è������չΪnֻûñ�ӵ�è
Ȼ��������չ�Ƿǳ��ؼ���,ò��û�й���...
����ֻҪ��������ͻᷢ��˵,��������һֻè����չ,�������һ����
{ n | 1+ (n-1)}	���Է����²�����nֻè���Ա�ʾΪ1+(n-1),ֻҪ�������1�����ݹ���չ�Ϳ�����
��kΪ��չ�Ĵ���,����û��ñ�ӵ�èm=(k-1)*(n-1)+n=k*(n-1)+1
��	k=(m-1)/(n-1)
è������=k*n+1

��Ȼk���������Ļ�,����ǲ����ڵ�
��n=1ʱ,m=1�Ļ�����������ֽ�,�����޽�
*/

#include<iostream>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF && (n||m))
	{
		if(n==1)
		{
			if(m==1)
				printf("%d %d Multiple\n",n,m);
			else
				printf("%d %d Impossible\n",n,m);
		}
		else
		{
			if((m-1)%(n-1)==0)
				printf("%d %d %d\n",n,m,(m-1)/(n-1)*n+1);
			else
				printf("%d %d Impossible\n",n,m);
		}
	}

	return 0;
}
