/*
10718 - Bit Mask
*/

#include<iostream>

using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("10718.txt","w",stdout);

	unsigned int n,ln,l,u,lu,m,t,i;
	int bitn[40];
	while(cin>>n>>l>>u)
	{
		memset(bitn,0,sizeof(bitn));
		t=u;lu=0;
		while(t)
			lu++,t/=2;
		ln=0;t=n;
		while(t)
			bitn[ln++]=t%2,t/=2;

		m=0;   
		while(lu--)
		{
			t=m+(1<<lu);
			if(t<=u)
			{
				if(t>l)			//可以不加
				{
					if(!bitn[lu])
						m=t;
				}
				else
					m=t;
			}
		}
		cout<<m<<endl;
	}

return 0;
}
