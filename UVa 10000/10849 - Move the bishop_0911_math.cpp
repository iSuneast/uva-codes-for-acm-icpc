/*
10849 - Move the bishop

math...
just check the two position is in the same diagonal
*
* when the two point is the same, 0
* difference of X && Y is the same, 1 
*
or in the diagonal diagonal
*
* difference of X && Y have the same parity, 2
*
*/

#include<iostream>
#include<cmath>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int dataset,n,m;
	scanf("%d",&dataset);
	while(dataset--)
	{
		scanf("%d%d",&n,&m);
		int x1,y1,x2,y2;
		while(n--)
		{
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			if(x1==x2 && y1==y2)
				puts("0");
			else if(abs(x1-x2)==abs(y1-y2))
				puts("1");
			else if((abs(x1-x2)-abs(y1-y2))%2==0)
				puts("2");
			else
				puts("no move");
		}
	}

	return 0;
}
