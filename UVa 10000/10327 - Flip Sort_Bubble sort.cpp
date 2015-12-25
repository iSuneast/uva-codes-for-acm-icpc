/*
10327 - Flip Sort
...
晕。。
和以前做过的一体一摸一样。。
*/

#include<iostream>

using namespace std;

int main()
{
	freopen("in.txt","r",stdin);
	int n,num[1010],ans,i,j;
	while(cin>>n)
	{
		for(i=0;i<n;i++)
			cin>>num[i];
		ans=0;
		for(i=0;i<n;i++)
			for(j=1;i+j<n;j++)
				if(num[j-1]>num[j])
					swap(num[j-1],num[j]),
					ans++;
		cout<<"Minimum exchange operations : "<<ans<<endl;
	}
return 0;
}
