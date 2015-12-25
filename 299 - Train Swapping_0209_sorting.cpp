/*
299 - Train Swapping
*/

#include<iostream>

using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);
	int n,l,train[60],i,j,ans;
	cin>>n;
	while(n--)
	{
		cin>>l;
		for(i=0;i<l;i++)
			cin>>train[i];
		ans=0;
		for(i=0;i<l;i++)
			for(j=1;j<l-i;j++)
				if(train[j-1]>train[j])
					swap(train[j],train[j-1]),
					ans++;
	cout<<"Optimal train swapping takes "<<ans<<" swaps."<<endl;
	}

return 0;
}
