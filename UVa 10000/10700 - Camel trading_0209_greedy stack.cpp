/*
10700 - Camel trading
*/

#include<iostream>
#include<stack>

using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);
	int cas,p;
	long long maximum,minimum,t;
	char c[20];
	stack<long long> smax,smin;
	cin>>cas;
	while(cas--)
	{
		p=0;
		while(1)
		{
			cin>>t;
			smax.push(t);smin.push(t);
			c[p]=getchar();
			if(c[p]!='+' && c[p]!='*')
				break;
			p++;
		}
		maximum=1;minimum=0;
		while(p--)
		{
			if(c[p]=='+')
			{
				minimum+=smin.top();smin.pop();

				t=smax.top();smax.pop();
				t+=smax.top();smax.pop();smax.push(t);
			}
			else
			{
				t=smin.top();smin.pop();
				t*=smin.top();smin.pop();smin.push(t);

				maximum*=smax.top();smax.pop();
			}
		}
		maximum*=smax.top();smax.pop();
		minimum+=smin.top();smin.pop();

		cout<<"The maximum and minimum are "<<maximum
			<<" and "<<minimum<<"."<<endl;
	}

return 0;
}
