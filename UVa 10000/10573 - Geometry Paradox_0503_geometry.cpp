#include<iostream>
#include<cmath>
#define pi acos(-1.0)
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int dataset;
	cin>>dataset;
	char s[100];
	while(dataset--)
	{
		double a,b;
		scanf("%lf",&a);
		gets(s);
		char *token=strtok(s," ");
		int cnt=0;
		if(token)
		{
			sscanf(token,"%lf",&b);
			++cnt;
		}
		if(cnt==0)
		{
			if(a<0)
				a=-a;
			printf("%.4lf\n",pi*a*a/8.0);
		}
		else
			printf("%.4lf\n",2.0*pi*a*b);
	}

	return 0;
}
