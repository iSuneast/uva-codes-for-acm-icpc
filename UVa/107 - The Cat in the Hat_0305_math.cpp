/*
107 - The Cat in the Hat

*/

#include<iostream>
using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);

	int a,b;
	while(cin>>a>>b && (a||b))
	{
		if(b==1)		//特殊讨论,此时a必是2^i
		{
			int i,t=1;
			for(i=1;i<=a;i++)
				if(a==t)
					break;
				else
					t=t<<1;
			cout<<i-1<<' '<<t*2-1<<endl;
		}
		else for(int i=2;i<=a;i++)	//穷举所有的N,找到解就输出
			if(a%(i+1)==0 && b%i==0)
			{
				int ta=a,tb=b;
				while(ta%(i+1)==0 && tb%i==0)
				{
					ta/=(i+1);
					tb/=i;
				}
				if(ta==1 && tb==1)
				{
					cout<<(b-1)/(i-1)<<' '<<a*(i+1)-b*i<<endl;
					break;
				}
			}
	}

return 0;
}
