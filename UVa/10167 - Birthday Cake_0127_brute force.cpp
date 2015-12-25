/*
10167 - Birthday Cake
...
暴力枚举....
*/

#include<iostream>

using namespace std;

int n;

struct point
{
	int x,y;
}che[200];

void calc()
{
	int a,b,t,i,cnt,flag;
	for(a=-500;a<=500;a++)
		for(b=-500;b<=500;b++)
		{
			cnt=flag=0;
			for(i=0;i<2*n;i++)			//这里...我WA了好多次....
			{
				t=che[i].x*a+che[i].y*b;
				if(t>0)
					cnt++;
				else if(t<0)
					cnt--;
				else
				{
					flag=1;
					break;
				}
			}
			if(!cnt&&!flag)
			{
				cout<<a<<' '<<b<<endl;
				return;
			}
		}
}

int main()
{
//	freopen("in.txt","r",stdin);
	int i;
	while(cin>>n&&n)
	{
		for(i=0;i<2*n;i++)
			cin>>che[i].x>>che[i].y;
		calc();
	}

return 0;
}
