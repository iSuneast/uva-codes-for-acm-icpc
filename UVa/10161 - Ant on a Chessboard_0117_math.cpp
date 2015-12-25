/*
10161 - Ant on a Chessboard
*/

#include<iostream>
#include<cmath>

using namespace std;

long n,c,i,j,step;

void odd()
{
	i=1;j=c;
	while(i<c&&step)
		i++,step--;
	while(j>0&&step)
		j--,step--;
}

void even()
{
	i=c;j=1;
	while(j<c&&step)
		j++,step--;
	while(i>0&&step)
		i--,step--;
}

int main()
{
	while(cin>>n&&n)
	{
		c=(long)ceil(sqrt(n));
		step=n-(c-1)*(c-1)-1;
		if(c%2)
			odd();
		else
			even();
		cout<<j<<' '<<i<<endl;
	}

return 0;
}