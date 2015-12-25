/*
 * 10268 - 498-bis
 *
 * Horner Rule~
 * 霍纳法则
 * 函数值px, 导数值为ppx, 则
 * ppx = ppx = ppx*x + px
 * px = px*x + A[i]
 *
 * 导数也是满足霍纳法则的...
 * 题目说,最后结果在int范围,虽然中间运算可能溢出,但是溢出了其实是取2^32模运算
 * 这样对结果是没有影响的~
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
