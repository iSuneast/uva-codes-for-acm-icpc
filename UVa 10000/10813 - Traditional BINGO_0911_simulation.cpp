/*
10813 - Traditional BINGO

simulation...
just a simple simulation game...
be care of the "diagonal", it means diagonal && anti-diagonal
and for col=3,row=3, we should only need to count 4 matched number
*/

#include<iostream>
using namespace std;

int row[7],col[7];
int posRow[80],posCol[80];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int dataset,var;
	scanf("%d",&dataset);
	while(dataset--)
	{
		memset(posRow,0,sizeof(posRow));
		memset(posCol,0,sizeof(posCol));

		for(int i=1;i<=5;++i)
		{
			for(int j=1;j<=5;++j)
			{
				if(i==3 && j==3)
					continue;
				scanf("%d",&var);
				posRow[var]=i;
				posCol[var]=j;
			}
			row[i]=col[i]=5;
		}
		row[3]=col[3]=4;

		int key=-1,dia=4,antiDia=4;
		for(int i=1;i<=75;++i)
		{
			scanf("%d",&var);
			if(posRow[var] && key==-1)
			{
				if(!(--row[ posRow[var] ]))
					key=i;
				if(!(--col[ posCol[var] ]))
					key=i;
				if(posRow[var]==posCol[var] && !(--dia))
					key=i;
				if(posRow[var]+posCol[var]==6 && !(--antiDia))
					key=i;
			}
		}

		printf("BINGO after %d numbers announced\n",key);
	}

	return 0;
}
