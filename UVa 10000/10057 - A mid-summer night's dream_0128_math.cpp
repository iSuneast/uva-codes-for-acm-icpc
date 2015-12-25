/*
10057 - A mid-summer night's dream.
...
要严谨一点...
*/

#include<iostream>
#include<algorithm>

using namespace std;

int num[1000010];

int cmp(const int a,const int b)
{
	return a<b;
}

int main()
{
//	freopen("in.txt","r",stdin);
	int n,i,ans0,ans1,ans2,t;
	while(cin>>n)
	{
		for(i=0;i<n;i++)
			scanf("%d",num+i);
		sort(num,num+n,cmp);
		ans0=num[(n-1)/2];
		ans1=0;
		if(n%2)
		{
			for(i=0;i<n;i++)
				if(num[i]==ans0)
					ans1++;
			ans2=1;	
		}
		else
		{
			t=num[(n+1)/2];
			for(i=0;i<n;i++)
				if(num[i]==ans0||num[i]==t)
					ans1++;
			ans2=t-ans0+1;
		}
		cout<<ans0<<' '<<ans1<<' '<<ans2<<endl;
	}

return 0;
}
