/*
11565 - Simple Equations

Ad hoc...
��Ŀû�����...
x,y,z�ǿ���Ϊ������,����Ҫ����
x<y<z�Ĺ�ϵ,�������b������
ö�����Ӽ���...
��x+y+z=a,�ɵ�
z=a-x-y.
����ö��x,y,�Ϳ���O(1)���z,
Ȼ���жϼ�����ʽ�Ƿ��������...
*/

#include<iostream>
#include<algorithm>
#define MAXN 100003
using namespace std;

int fac[MAXN],cnt,a,b,c;

void process()
{
	scanf("%d%d%d",&a,&b,&c);
	cnt=0;
	for(int i=1;i<=b;++i)
		if(b%i==0)
		{
			fac[cnt++]=i;
			fac[cnt++]=-i;
		}
	sort(fac,fac+cnt);

	for(int i=0;i<cnt;++i)
		for(int j=i+1;j<cnt;++j)
		{
			int x=fac[i],y=fac[j],z=a-x-y;
			long long var=1;
			var=var*x*y*z;
			if(z<=y || var<=0 || var!=b)
				continue;

			if(x*x+y*y+z*z==c)
			{
				printf("%d %d %d\n",x,y,z);
				return ;
			}
		}
	puts("No solution.");
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int dataset;
	scanf("%d",&dataset);
	while(dataset--)
		process();

	return 0;
}
