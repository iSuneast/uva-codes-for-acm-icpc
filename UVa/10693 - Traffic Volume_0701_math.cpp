/*
10693 - Traffic Volume

math...
û�㶮��Ŀ��ʲô= =
*/

#include<iostream>
#include<cmath>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	double l,f;
	while(cin>>l>>f && (l||f))
		printf("%.8lf %.8lf\n",sqrt(2.0*l*f),3600*sqrt(f/2.0/l));

	return 0;
}
