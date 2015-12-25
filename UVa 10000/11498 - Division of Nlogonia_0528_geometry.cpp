/*
11498 - Division of Nlogonia

geometry...
判断点在坐标系的哪个方位即可
*/

#include<iostream>
using namespace std;

struct point
{
	int x,y;
}division,cur;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int n;
	while(scanf("%d",&n)!=EOF && n)
	{
		scanf("%d%d",&division.x,&division.y);
		while(n--)
		{
			scanf("%d%d",&cur.x,&cur.y);
			if(cur.x==division.x || cur.y==division.y)
				puts("divisa");
			else if(cur.x>division.x)
			{
				if(cur.y>division.y)
					puts("NE");
				else
					puts("SE");
			}
			else
			{
				if(cur.y>division.y)
					puts("NO");
				else
					puts("SO");
			}
		}
	}

	return 0;
}
