/*
256 - Quirksome Squares
*/

#include<iostream>
#include<cmath>

using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);
	int n;
	while(cin>>n)
	{
		int ran=pow(10.0,n),t=pow(10.0,n/2);
		for(long i=0;i<ran;i++)
		{
			if(pow((double)(i/t+i%t),2)==i)
				switch(n)
				{
				case 2:
					printf("%02d\n",i);
					break;
				case 4:
					printf("%04d\n",i);
					break;
				case 6:
					printf("%06d\n",i);
					break;
				case 8:
					printf("%08d\n",i);
					break;
				}
		}

	}

return 0;
}
