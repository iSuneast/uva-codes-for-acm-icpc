/*
350 - Pseudo-Random Numbers
数论...
同余方程..
*/

#include<iostream>

using namespace std;

int main()
{
	freopen("in.txt","r",stdin);
	int z,i,m,l,cas=1,ans,ran,t;
	while(cin>>z>>i>>m>>l&&(z||i||m||l))
	{
		ans=0;
		ran=l;
		z%=m;
		i%=m;
		t=ran=(z*ran+i)%m;

		while(++ans)
		{
			t=(z*t+i)%m;
			if(ran==l||t==ran)
				break;
		}
		cout<<"Case "<<cas<<": "<<ans<<endl;
		cas++;
	}


return 0;
}
