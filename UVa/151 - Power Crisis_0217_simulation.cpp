/*
151 - Power Crisis
...
*/

#include<iostream>

using namespace std;

int region[110],n,key;

bool accept()
{
	int cnt=n,i,p=1;
	memset(region,0,sizeof(region));
	while(--cnt)
	{
		region[p]=1;
		i=key;
		while(i--)
		{
			p=(p+1)%n;
			if(region[p])
				while(region[p])
					p=(p+1)%n;
		}
		if(region[13])
			return false;
	}
	return true;
}

int main()
{
//	freopen("in.txt","r",stdin);
	while(cin>>n && n)
	{
		key=1;
		if(n!=13)
			while(!accept())
				key++;
		cout<<key<<endl;
	}

return 0;
}
