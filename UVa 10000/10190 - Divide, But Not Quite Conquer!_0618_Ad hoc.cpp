/*
10190 - Divide, But Not Quite Conquer!

Ad hoc...
这题的tricky真多...
题目说n和m"non-negative"
也就是说可以为0,因此不注意的话就除零RE了...
m=1的时候如果不特判的话由于n/=m最后还是n所以TLE了...
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
