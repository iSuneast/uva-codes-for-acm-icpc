/*
514 - Rails
...
≥ı ºªØ¥ÌŒÛ....
‘Œ...
*/

#include<iostream>
#include<stack>

using namespace std;

int n,tar[1010],flag=0;

void calc()
{
	stack<int> s;
	int a,b;
	a=1;
	b=0;
	while(b<n)
	{
		if(tar[b]==a)
			a++,b++;
		else if(!s.empty()&&(tar[b]==s.top()))
			s.pop(),b++;
		else if(a<=n)
			s.push(a),a++;
		else
		{
			cout<<"No"<<endl;
			return ;
		}
	}
	cout<<"Yes"<<endl;
}

int main()
{
	int i;
	while(cin>>n&&n)
	{
		while(cin>>tar[0])
			if(tar[0]!=0)
			{
				for(i=1;i<n;i++)
					cin>>tar[i];
				calc();
			}
			else
				break;
			cout<<endl;
	}

return 0;
}
