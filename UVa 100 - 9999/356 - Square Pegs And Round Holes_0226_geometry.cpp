/*
356 - Square Pegs And Round Holes
*/

#include<iostream>

using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);

	double r2,n;
	bool first=true;
	while(cin>>n)
	{
		if(first)
			first=false;
		else
			cout<<endl;
		r2=(n-0.5)*(n-0.5);
		int cnt=0;
		for(int i=1;i<n;i++)
			for(int j=1;j<n;j++)
				if(i*i+j*j<=r2)
					cnt++;
		cout<<"In the case n = "
			<<n<<", "<<(2*n-1)*4<<" cells contain segments of the circle."<<endl
			<<"There are "
			<<cnt*4<<" cells completely contained in the circle."<<endl;
	}

return 0;
}
