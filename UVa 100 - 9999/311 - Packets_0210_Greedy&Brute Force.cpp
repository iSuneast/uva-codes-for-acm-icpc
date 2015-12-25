/*
311 - Packets
...
额....非常贪心....非常暴力的解法....
*/

#include<iostream>

using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);
	int a,b,c,d,e,f;
	while(cin>>a>>b>>c>>d>>e>>f && (a||b||c||d||e||f))
	{
		if(e)				//5*5
			f+=e,a-=11*e;
		if(d)				//4*4
		{
			f+=d;
			if(b>5*d)
				b-=5*d;
			else
				a-=(20*d-b*4),
				b=0;
		}
		if(c)				//3*3
		{
			f+=c/4;
			if(c%=4)
			{
				f++;
				if(c==1)
				{
					if(b>5)
						b-=5,
						a-=7;
					else
						a-=(27-b*4),
						b=0;
				}
				else if(c==2)
				{
					if(b>3)
						b-=3,
						a-=6;
					else
						a-=(18-b*4),
						b=0;
				}
				else
				{
					if(b)
						b--,
						a-=5;
					else
						a-=9;
				}
			}
		}
		if(b)
		{
			f+=b/9;
			if(b%=9)
			{
				f++;
				a-=(9-b)*4;
			}
		}
		if(a>0)
		{
			f+=a/36;
			if(a%36)
				f++;
		}
		cout<<f<<endl;
	}

return 0;
}
