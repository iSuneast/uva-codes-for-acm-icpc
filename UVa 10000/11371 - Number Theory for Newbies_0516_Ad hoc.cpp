/*
11371 - Number Theory for Newbies

Ad hoc...
好猥琐的题目啊...
竟然忘记了会溢出...
貌似没要求说a,b要<=2000000000
所以,直接做就可以了
*/

#include<iostream>
#include<algorithm>
using namespace std;

int cmp(const char a,const char b)
{
	return a>b;
};

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	char var[15];
	long long a,b;
	while(cin>>var)
	{
		sort(var,var+strlen(var),cmp);
		sscanf(var,"%lld",&a);
		sort(var,var+strlen(var));
		for(int i=0;i<strlen(var);++i)
			if(var[i]!='0')
			{
				swap(var[0],var[i]);
				break;
			}
		sscanf(var,"%lld",&b);
		printf("%lld - %lld = %lld = 9 * %lld\n",a,b,a-b,(a-b)/9);
	}

	return 0;
}
