/*
 * 10268 - 498-bis
 *
 * Horner Rule~
 * ���ɷ���
 * ����ֵpx, ����ֵΪppx, ��
 * ppx = ppx = ppx*x + px
 * px = px*x + A[i]
 *
 * ����Ҳ��������ɷ����...
 * ��Ŀ˵,�������int��Χ,��Ȼ�м�����������,�����������ʵ��ȡ2^32ģ����
 * �����Խ����û��Ӱ���~
 *
 * happy coding~
 */

#include<iostream>
using namespace std;

char buf[1000000];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	for(int x; scanf("%d%*c",&x)!=EOF; )
	{
		gets(buf);
		int px=0, ppx=0;
		for(char *token=strtok(buf," "); token; token=strtok(NULL," "))
		{
			ppx = ppx*x + px;
			px = px*x + atol(token);
		}

		printf("%d\n", ppx);
	}

	return 0;
}
