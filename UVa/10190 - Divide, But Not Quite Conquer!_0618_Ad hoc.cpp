/*
10190 - Divide, But Not Quite Conquer!

Ad hoc...
�����tricky���...
��Ŀ˵n��m"non-negative"
Ҳ����˵����Ϊ0,��˲�ע��Ļ��ͳ���RE��...
m=1��ʱ����������еĻ�����n/=m�����n����TLE��...
*/

#include<iostream>
using namespace std;

bool chk(int n,int m)
{
	while(true)
	{
		if(n%m==0)
			n/=m;
		else
			return false;
		if(n==1)
			return true;
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF)
		if(n<=1 || m<=1 || !chk(n,m))
			puts("Boring!");
		else
		{
			while(n!=1)
			{
				printf("%d ",n);
				n/=m;
			}
			puts("1");
		}

	return 0;
}
