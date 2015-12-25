/*
10276 - Hanoi Tower Troubles Again!

Greedy...
*/

#include<iostream>
#include<cmath>
#define MAXN 50
using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);

	int dataset;
	cin>>dataset;
	while(dataset--)
	{
		int n,key=0,i,t,top[MAXN];
		bool more=true;
		cin>>n;
		memset(top,0,sizeof(top));
		while(more)
		{
			++key;
			more=false;
			for(i=0;i<n;++i)
				if(!top[i])
				{
					top[i]=key;
					more=true;
					break;
				}
				else
				{
					t=sqrt(top[i]+key);
					if(t*t==top[i]+key)
					{
						top[i]=key;
						more=true;
						break;
					}
				}
		}
		cout<<key-1<<endl;
	}

return 0;
}
