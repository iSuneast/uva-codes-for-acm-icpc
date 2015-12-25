/*
11103 - WFF 'N PROOF

greedy...
我就知道说要是re的话一定是代码的某个地方有问题....
不可能说本机运行的好好的
到了oj就re

所以re后仔细检查代码才是应该做的
*/

#include<iostream>
#include<string>
#include<stack>
#define MAXN 256
using namespace std;

int hash[MAXN];

void init()
{
	hash['p']=1;
	hash['q']=1;
	hash['r']=1;
	hash['s']=1;
	hash['t']=1;

	hash['K']=2;
	hash['A']=2;
	hash['C']=2;
	hash['E']=2;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	init();
	string s,t;
	while(cin>>s && s!="0")
	{
		int l=s.length(),cnt=0;
		stack<string> op,var;

		for(int i=0;i<l;++i)
		{
			if(hash[ s[i] ]==1)
				var.push(t=s[i]);
			else if(hash[ s[i] ]==2)
				op.push(t=s[i]);
			else
				++cnt;
		}

		if(cnt && !var.empty())
		{
			s="";
			while(cnt--)
				s+="N";
			s+=var.top();
			var.pop();
			var.push( s );
		}

		while(!op.empty() && !var.empty())
		{
			s=var.top();
			var.pop();
			if(var.empty())
			{
				var.push(s);
				break;
			}
			s=op.top()+s+var.top();
			var.pop();
			op.pop();

			var.push(s);
		}

		if(!var.empty())
			cout<<var.top()<<endl;
		else
			puts("no WFF possible");
	}

	return 0;
}
