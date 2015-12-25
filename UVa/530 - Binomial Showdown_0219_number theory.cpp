/*
530 - Binomial Showdown
....
...similar to 369
....
我不得不说...
做这种题目...
我很无语...
*/

#include<iostream>

using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);

	double ans;
	long n,m,i,cnt;
	while(cin>>n>>m && (n||m))
	{
		if(n==m || m==0)
		{
			cout<<1<<endl;
			continue;
		}
		else if(n==m+1 || m==1)
		{
			cout<<n<<endl;
			continue;
		}
		if(m >= n/2)
			m=n-m;
		i=2;
		ans=m+1;
		cnt=ans+1;
		while(1)
		{
			ans*=cnt++;
			ans/=i++;
			if(n==cnt-1 || i==n-m+1)
				break;
		}
		printf("%.lf\n",ans);
	}

return 0;
}
