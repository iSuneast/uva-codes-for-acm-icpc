/*
11219 - How old are you?

Ad hoc...
����,�ر���ˮ��һ��Ҫ����Դ�...
����һ��Ҫ��ȫ
*/

#include<iostream>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int dataset;
	scanf("%d",&dataset);
	for(int cas=1;cas<=dataset;++cas)
	{
		int d,m,y,dd,mm,yy;
		scanf("%d/%d/%d",&d,&m,&y);
		scanf("%d/%d/%d",&dd,&mm,&yy);

		int old=y-yy;
		if(m==mm && d<dd)		//����"--"�����
			--old;
		else if(m<mm)
			--old;

		if(old>130)
			printf("Case #%d: Check birth date\n",cas);
		else if(old<0)
			printf("Case #%d: Invalid birth date\n",cas);
		else
			printf("Case #%d: %d\n",cas,old);
	}

	return 0;
}
