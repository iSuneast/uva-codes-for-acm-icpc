/*
412 - Pi
...
做题要保持头脑简单...
不要老是往复杂的方向去想...
*/

#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

int gcd(int a,int b)
{
	return b==0?a:gcd(b,a%b);
}

int main()
{
//	freopen("in.txt","r",stdin);

	int n,num[55];
	while(cin>>n && n)
	{
		int i,j,cnt=0;
		long double pi;
		for(i=0;i<n;i++)
			cin>>num[i];
		sort(num,num+n);
		for(i=1;i<n;i++)
			for(j=0;j<i;j++)
				if(gcd(num[i],num[j])==1)
					cnt++;
		if(!cnt)
			cout<<"No estimate for this data set."<<endl;
		else
			printf("%.6lf\n",sqrt(3.0*n*(n-1)/cnt));
	}

return 0;
}
