/*
369 - Combinations
...
看来做ACM题,数学思维是很重要的...
....
埋头苦做...
or 只看不做都是不对的....
...
重要的还有是...
时刻以数学家的眼光着手一道题..
*/

#include<iostream>
#include<vector>

using namespace std;

int gcd (int u, int v)
{
	return v==0?u:gcd(v,u%v);
}

int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("more.txt","w",stdout);

	unsigned long n,m,r,h,j;
	vector<int> n1,m1;
	while(cin>>n>>m && (n||m))
    {
		int i;
		r=1;
		n1.clear();
		m1.clear();
		for(i=n-m+1;i<n+1;i++)
			n1.push_back(i);
		for(i=2;i<m+1;i++)
			m1.push_back(i);
		for(i=0;i<n1.size();i++)
			for(j=0;j<m1.size();j++)
			{
				h=gcd(n1[i],m1[j]);
				if(n1[i]>1 && m1[j]>1 && h>1)
					n1[i]/=h,m1[j]/=h;
			}
		for(i=0;i<n1.size();i++)
			r*=n1[i];
		cout<<n<<" things taken "<<m<<" at a time is "<<r<<" exactly."<<endl;
	}
	return 0;
}

/*				WA----don't know why
#include<iostream>

using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("more.txt","w",stdout);
	long double n,m,i,ans;
	int cnt;
	while(cin>>n>>m && (n||m))
	{
		printf("%.0lf things taken %.0lf at a time is ",n,m);
		ans=1;i=1;

		if(n-m>m)
		{
			n=n-m+1;
			cnt=m;
		}
		else
		{
			cnt=n-m;
			n=m+1;
		}
		while(cnt-->0)
			ans*=(n++)/(i++);
		printf("%.0lf exactly.\n",ans);
	}

return 0;
}

*/